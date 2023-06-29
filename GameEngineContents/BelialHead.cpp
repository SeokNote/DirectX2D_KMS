#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "WeaponBase.h"
#include "BelialHead.h"
#include "BelialHeadSubBG.h"
#include "BossSword.h"
#include "Player.h"
#include "BelialBullet.h"
#include "BelialBulletBase.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

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

	BelialBGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBGRender->SetTexture("BossSword.png");
	BelialBGRender->GetTransform()->SetWorldPosition(MainBGPos);
	BelialBGRender->GetTransform()->SetLocalScale({ 150.0f,150.0f,0.0f });
	BelialBGRender->CreateAnimation({ .AnimationName = "BelialMainBG", .SpriteName = "MainBG", .Loop = true , .ScaleToTexture = true });
	BelialBGRender->ChangeAnimation("BelialMainBG");
	ChangeState(BossHeadState::IDLE);
	//죽을시 머리 부품들
	BelialHeadPice_0 = CreateComponent<GameEngineSpriteRenderer>(1);

	BelialHeadPice_0->SetTexture("BelialHeadOne.png");
	BelialHeadPice_0->GetTransform()->SetLocalPosition({0.0f,-80.0f,0.0f});
	BelialHeadPice_0->GetTransform()->SetLocalScale(HeadScale);
	BelialHeadPice_0->Off();

	BelialHeadPice_2 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialHeadPice_2->GetTransform()->SetLocalPosition({ 0.0f,40.0f,0.0f });
	BelialHeadPice_2->SetTexture("BelialHeadThree.png");
	BelialHeadPice_2->GetTransform()->SetLocalScale(HeadScale);
	BelialHeadPice_2->Off();

	BelialHeadPice_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialHeadPice_1->GetTransform()->SetLocalPosition({ 0.0f,10.0f,0.0f });
	BelialHeadPice_1->SetTexture("BelialHeadTwo.png");
	BelialHeadPice_1->GetTransform()->SetLocalScale(HeadScale);
	BelialHeadPice_1->Off();
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
	GetLevel()->CreateActor<BelialHand_L>();
	GetLevel()->CreateActor<BelialHand_R>();

}

void BelialHead::Update(float _DeltaTime)
{
	SubBGTime += _DeltaTime;
	if (SubBGTime > 0.4f)
	{
		BelialHeadSubBG::CreateSubBG(GetLevel(), MainBGPos);
		SubBGTime = 0.0f;
	}
	UpdateState(_DeltaTime);
	BelialCollision(_DeltaTime);
	BelialSwordPlay(_DeltaTime);
	//소드 재생성

}
bool HitCheck = false;
void BelialHead::BelialCollision(float _DeltaTime)
{
	if (BelialHp < 0)
	{
		int a = 0;
	}
	if (BelialCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (HitCheck == false)
		{
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

	if (SwordTime > 0.3f)
	{
		SwordIndex++;
		if (SwordIndex < 6)
		{

			BossSwordPtr_0 = GetLevel()->CreateActor<BossSword>();
			BossSwordPtr_0->GetTransform()->SetWorldPosition({ StartX - YInvers ,50.0f,-801.0f });
			YInvers -= 100.0f;
		}
		SwordTime = 0.0f;
	}
}
