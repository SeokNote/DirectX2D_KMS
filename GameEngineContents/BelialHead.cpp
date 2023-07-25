#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "WeaponBase.h"
#include "BelialHead.h"
#include "BelialHeadSubBG.h"
#include "BossSword.h"
#include "Player.h"
#include "BelialBullet.h"
#include "BelialBulletBase.h"
#include "BossDeadEffect.h"
#include "BelialHeadPice.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>

BelialHead* BelialHead::MainBelialHead = nullptr;
/*
데미지가 25라고 하면 
2.5퍼센트가 깎여야함


그럼 a값은

(1000-25)/100 값으로
(최대체력 - 현재체력)/100
을 공용기능으로 넣자.
이번주까지 보스들과의 전투는 마무리 된 후에 이제 몬스터들 찍어낼듯.
그 다음주에 이제 몬스터 찍어내고 전투까지하고
그다음주에 이제 ui들 넣고 맵 애니메이션 
*/
//테스트
#include "BelialHand_L.h"
#include "BelialHand_R.h"
BelialHead::BelialHead()
{
	MainBelialHead = this;
}

BelialHead::~BelialHead()
{
}

void BelialHead::Start()
{

	BelialHeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialHeadRender->SetTexture("SkellBossIdle0.png");
	BelialHeadRender->CreateAnimation({ .AnimationName = "HeadIdle", .SpriteName = "HeadIdle", .Loop = true , .ScaleToTexture = true });
	BelialHeadRender->CreateAnimation({ .AnimationName = "HeadMove", .SpriteName = "HeadMove", .Loop = false , .ScaleToTexture = true });
	BelialHeadRender->CreateAnimation({ .AnimationName = "BelialBeforDead", .SpriteName = "BelialBeforDead", .Loop = false , .ScaleToTexture = true });
	BelialHeadRender->ColorOptionValue.MulColor.a = 0.0f;

	BelialBGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBGRender->SetTexture("BossSword.png");
	BelialBGRender->GetTransform()->SetWorldPosition(MainBGPos);
	BelialBGRender->GetTransform()->SetLocalScale({ 150.0f,150.0f,0.0f });
	BelialBGRender->CreateAnimation({ .AnimationName = "BelialMainBG", .SpriteName = "MainBG", .Loop = true , .ScaleToTexture = true });
	BelialBGRender->ChangeAnimation("BelialMainBG");
	ChangeState(BossHeadState::IDLE);

	//HPBar

	BossHpFront = CreateComponent<GameEngineUIRenderer>(1);
	BossHpFront->SetTexture("BossLifeBack.png");
	BossHpFront->GetTransform()->SetWorldPosition(HPBasePos);
	BossHpFront->GetTransform()->SetLocalScale(HPBarBaseScale);

	BossHpBase = CreateComponent<GameEngineUIRenderer>(1);
	BossHpBase->SetTexture("BossLifeBase.png");
	BossHpBase->GetTransform()->SetWorldPosition(HPBasePos);
	BossHpBase->GetTransform()->SetLocalScale(HPBarBaseScale);

	BossHpBar = CreateComponent<GameEngineUIRenderer>(1);
	BossHpBar->SetTexture("BossHpBar.png");
	BossHpBar->GetTransform()->SetWorldPosition(HPPos);
	BossHpBar->GetTransform()->SetLocalScale(HPBarScale);


	BelialCol = CreateComponent<GameEngineCollision>(ColOrder::BELIALHEAD);
	BelialCol->GetTransform()->SetLocalPosition({ 30.0f,-20.0f,0.f });
	BelialCol->GetTransform()->SetLocalScale(BelialColScale);
	BelialCol->SetColType(ColType::AABBBOX2D);
	BelialBulletBasePtr = GetLevel()->CreateActor<BelialBulletBase>();
	BelialBulletBasePtr->GetTransform()->SetWorldPosition({ 12080.0f,-250.0f,-800.0f });

	DeadBGRender = CreateComponent<GameEngineUIRenderer>(999);
	DeadBGRender->SetTexture("BossDeadBG.png");
	DeadBGRender->GetTransform()->SetWorldPosition(float4::Null);
	DeadBGRender->GetTransform()->SetLocalScale({ 1280.0f,720.0f,0.0f });
	DeadBGRender->Off();

	BossLayout = CreateComponent<GameEngineUIRenderer>(999);
	BossLayout->SetTexture("BossLayout.png");
	BossLayout->GetTransform()->SetWorldPosition(LayoutPos);
	BossLayout->GetTransform()->SetLocalScale({ 1280.0f,720.0f,0.0f });
	BossLayout->ColorOptionValue.MulColor.a = 0.0f;
	BossLayout->Off();

	LeftPtr =GetLevel()->CreateActor<BelialHand_L>();
	RightPtr = GetLevel()->CreateActor<BelialHand_R>();

}

void BelialHead::Update(float _DeltaTime)
{
	SubBGTime += _DeltaTime;
	if (IsDead==false && SubBGTime > 0.4f)
	{
		BelialHeadSubBG::CreateSubBG(GetLevel(), MainBGPos);
		SubBGTime = 0.0f;
	}
	UpdateState(_DeltaTime);
	BelialCollision(_DeltaTime);
	DeathEvent(_DeltaTime);
	//소드 재생성

}
bool HitCheck = false;
void BelialHead::DeathEvent(float _DeltaTime)
{
	float4 CurPos = GetTransform()->GetWorldPosition();
	if (DeathShack == true)
	{
		DeadTime += _DeltaTime;
		DeadShackTime += _DeltaTime;
		BelialCameraShack(30);
		if (DeadShackTime > 0.05f)
		{
			x = 0.f;
			DeadShackTime = 0.0f;
		}
		if (DeadTime > 5.0f)
		{
			TimeCheck_D += _DeltaTime;
			BelialHeadRender->Off();
			LeftPtr->Death();
			RightPtr->Death();
			BelialBGRender->Off();
			IsDead = true;
			IsCreateHead = true;
			if (TimeCheck_D > 0.2f)
			{
				GameEngineSound::Play("MonsterDie.wav");
				CurPos.x += 50.0f;
				CurPos.y -= 100.0f;
				CurPos.z = -850.0f;
				BossDeadEffectPtr = GetLevel()->CreateActor<BossDeadEffect>();
				BossDeadEffectPtr->GetTransform()->SetLocalPosition(CurPos);
				BossDeadEffectPtr->SetRaioPos(RatioValue);
				RatioValue += 50.0f;
				TimeCheck_D = 0.0f;
			}
		}
		if (DeadTime > 7.0f)
		{
			DeadTime = 0.0f;
			Death();
		}
	}
	if (CheckValue ==false && IsCreateHead == true)
	{
		CurPos.z = -100;
		BelialHeadPicePtr = GetLevel()->CreateActor<BelialHeadPice>();
		BelialHeadPicePtr->GetTransform()->SetLocalPosition(CurPos);
		CheckValue = true;
	}

}
void BelialHead::BelialCameraShack(int _Value)
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();

	x += 0.5;
	y = sin(x * 10.0f) * powf(0.5f, x);
	float a = x;
	float b = y;
	GetLevel()->GetMainCamera()->GetTransform()->SetWorldPosition({ CameraPos.x + (y * 10),CameraPos.y + abs(y * _Value),CameraPos.z });
}
void BelialHead::BelialCollision(float _DeltaTime)
{
	if (BelialCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (HitCheck == false)
		{
			GameEngineSound::Play("Hit_Monster.wav");
			//나중에 ui작업때 캐릭터가 갖고있는 swich로 무기에 따라 정해주자.
			BelialHp -= WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E);
			//여기서 hp클립
			BossHpBar->ImageClippingX(static_cast<float>(BelialHp)/1000.0f, ClipXDir::Left);
			BelialHeadRender->ColorOptionValue.MulColor.r = 1.0f;
			BelialHeadRender->ColorOptionValue.MulColor.g = 0.1f;
			BelialHeadRender->ColorOptionValue.MulColor.b = 0.1f;
			HitCheck = true;
		}
		
	}
	else {
		if (HitCheck == true)
		{

			Invincibilitytime += _DeltaTime;
			if (Invincibilitytime > 0.1f)
			{
				BelialHeadRender->ColorOptionValue.MulColor.r = 1.0f;
				BelialHeadRender->ColorOptionValue.MulColor.g = 1.0f;
				BelialHeadRender->ColorOptionValue.MulColor.b = 1.0f;
				HitCheck = false;
				Invincibilitytime = 0.0f;
			}
		}
	}
}

void BelialHead::BelialSwordPlay(float _Time)
{
	SwordTime += _Time;

	if (SwordTime > 0.2f)
	{
		SwordIndex++;
		if (SwordIndex < 6)
		{
			GameEngineSound::Play("LaserBow.wav");
			BossSwordPtr_0 = GetLevel()->CreateActor<BossSword>();
			BossSwordPtr_0->GetTransform()->SetWorldPosition({ StartX - YInvers ,50.0f,-801.0f });
			YInvers -= 100.0f;
		}
		SwordTime = 0.0f;
	}
}
