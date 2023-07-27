#include "PrecompileHeader.h"
#include "WhiteSkell.h"
#include "Player.h"
#include "ContentsEnums.h"
#include "TextUI.h"
#include "WeaponBase.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
WhiteSkell::WhiteSkell() 
{
}

WhiteSkell::~WhiteSkell() 
{
}

void WhiteSkell::Start()
{
	WhiteSkellRender = CreateComponent<GameEngineSpriteRenderer>(1);
	WhiteSkellRender->SetTexture("BigWhiteSkelIdle.png");
	WhiteSkellRender->GetTransform()->SetLocalScale(Scale);
	WhiteSkellRender->CreateAnimation({ .AnimationName = "WhiteSkellMove", .SpriteName = "WhiteSkellMove", .Loop = true , .ScaleToTexture = false });
	WhiteSkellRender->CreateAnimation({ .AnimationName = "WhiteSkellIdle", .SpriteName = "WhiteSkellIdle", .Loop = true , .ScaleToTexture = false });
	WhiteSkellRender->CreateAnimation({ .AnimationName = "WhiteSkellAttack", .SpriteName = "WhiteSkellAttack", .Loop = false , .ScaleToTexture = false });
	WhiteSkellRender->ChangeAnimation("WhiteSkellIdle");

	TargetAreaCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	TargetAreaCol->GetTransform()->SetLocalPosition({ 280.0f,-40.0f,0.f });
	TargetAreaCol->GetTransform()->SetLocalScale(AreaPos);
	TargetAreaCol->SetColType(ColType::AABBBOX2D);

	SpownRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SpownRender->CreateAnimation({ .AnimationName = "SpownAni", .SpriteName = "SpownAni",.FrameInter = 0.1f, .Loop = false , .ScaleToTexture = true });

	SkellBodyCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	SkellBodyCol->GetTransform()->SetLocalPosition({ -70.0f,-40.0f,0.f });
	SkellBodyCol->GetTransform()->SetLocalScale(ColScale);
	SkellBodyCol->SetColType(ColType::AABBBOX2D);

	AttackAreaCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	AttackAreaCol->GetTransform()->SetLocalScale(AttackColScale);
	AttackAreaCol->SetColType(ColType::AABBBOX2D);
	AttackAreaCol->Off();

	AreaInRender = CreateComponent<GameEngineSpriteRenderer>(1);
	AreaInRender->SetTexture("ExMark03.png");
	AreaInRender->GetTransform()->SetLocalScale(InScale);
	AreaInRender->GetTransform()->SetLocalPosition({ -30.0f,70.0f,0.0f });
	AreaInRender->Off();

	HpBaseRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpBaseRender->SetTexture("MonsterHpBase.png");
	HpBaseRender->GetTransform()->SetLocalScale(HpBaseScale);
	HpBaseRender->GetTransform()->SetLocalPosition({ -60.0f,-110.0f,0.0f });
	HpBaseRender->Off();

	HpRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpRender->SetTexture("MonsterHpBar.png");
	HpRender->GetTransform()->SetLocalScale(HpBarScale);
	HpRender->GetTransform()->SetLocalPosition({ -60.0f,-110.0f,0.0f });
	HpRender->Off();

	DeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadRender->SetTexture("Die10.png");
	DeadRender->CreateAnimation({ .AnimationName = "SkellDead", .SpriteName = "BossDead",.FrameInter = 0.07f,.Loop = false , .ScaleToTexture = true });
	DeadRender->GetTransform()->SetLocalPosition({ -60.0f,0.0f,0.0f });

	ParticleRender0 = CreateComponent<GameEngineSpriteRenderer>(1);
	ParticleRender0->SetTexture("WhiteSkellPTK0.png");
	ParticleRender0->GetTransform()->SetLocalScale({40.0f,40.0f,0.0f});
	ParticleRender0->GetTransform()->SetLocalPosition({ -60.0f,0.0f,-5.0f });
	ParticleRender0->Off();

	ParticleRender1 = CreateComponent<GameEngineSpriteRenderer>(1);
	ParticleRender1->SetTexture("WhiteSkellPTK1.png");
	ParticleRender1->GetTransform()->SetLocalScale({12.0f,20.0f,0.0f});
	ParticleRender1->GetTransform()->SetLocalPosition({ -60.0f,0.0f,-3.0f });
	ParticleRender1->Off();

	ParticleRender2 = CreateComponent<GameEngineSpriteRenderer>(1);
	ParticleRender2->SetTexture("WhiteSkellPTK2.png");
	ParticleRender2->GetTransform()->SetLocalScale({ 40.0f,36.0f,0.0f });
	ParticleRender2->GetTransform()->SetLocalPosition({ -60.0f,0.0f,-4.0f });
	ParticleRender2->Off();

	ParticleRender3 = CreateComponent<GameEngineSpriteRenderer>(1);
	ParticleRender3->SetTexture("WhiteSkellPTK3.png");
	ParticleRender3->GetTransform()->SetLocalScale({ 36.0f,28.0f,0.0f });
	ParticleRender3->GetTransform()->SetLocalPosition({ -60.0f,0.0f,0.0f });
	ParticleRender3->Off();
	ChangeState(WhiteSkellState::IDLE);

}

void WhiteSkell::Update(float _DeltaTime)
{
	UpdateState(_DeltaTime);
	SetCollision(_DeltaTime);
	FlipCheck();
}
void WhiteSkell::CalBezierTransform(std::shared_ptr<GameEngineSpriteRenderer> _Render , const float4& _Start, const float4& _Height, const float4& _End, float _Ratio)
{
	float4 M0 = float4::LerpClamp(_Start, _Height, _Ratio);
	float4 M1 = float4::LerpClamp(_Height, _End, _Ratio);
	float4 Pos = float4::LerpClamp(M0, M1, _Ratio);


	_Render->GetTransform()->SetWorldPosition(Pos);

}
void WhiteSkell::SetCollision(float _DeltaTime)
{
	HpRender->ImageClippingX(static_cast<float>(SkellHP) / static_cast<float>(MaxHP), ClipXDir::Left);

	if (Player::MainPlayer->GetABSValue() == false && AttackAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(Damege);
	}
	if (TargetAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{

		InArea = true;
	}
	else
	{
		//InArea = false;

	}
	if (SkellBodyCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		HpRender->On();
		HpBaseRender->On();
		InArea = true;
		if (SkellBlink == false)
		{
			GameEngineSound::Play("Hit_Monster.wav");
			//나중에 ui작업때 캐릭터가 갖고있는 swich로 무기에 따라 정해주자.
			SkellHP -= WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E);
			TextUI::TextCreat(GetLevel(), GetTransform()->GetLocalPosition(), float4::White,
				std::to_string(WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E)), true ,32);
			WhiteSkellRender->ColorOptionValue.MulColor.r = 1.0f;
			WhiteSkellRender->ColorOptionValue.MulColor.g = 0.1f;
			WhiteSkellRender->ColorOptionValue.MulColor.b = 0.1f;
			SkellBlink = true;
		}

	}
	else {
		if (SkellBlink == true)
		{

			Invincibilitytime += _DeltaTime;
			if (Invincibilitytime > 0.05f)
			{
				WhiteSkellRender->ColorOptionValue.MulColor.r = 1.0f;
				WhiteSkellRender->ColorOptionValue.MulColor.g = 1.0f;
				WhiteSkellRender->ColorOptionValue.MulColor.b = 1.0f;
				SkellBlink = false;
				Invincibilitytime = 0.0f;
			}
		}
	}
}

bool WhiteSkell::GroundCheck(float4 _Pos,float _Pivot)
{
	PixelMapResultPos = PixelCalculation(_Pos, { 5320.0f,0.0f,0.0f }, { 1280.0f,720.0f });
	Ptr = GameEngineTexture::Find("StageCol_2.png");
	Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y + _Pivot));
	Pixel.a = 0;
	if (Pixel == GameEnginePixelColor::Black)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void WhiteSkell::FlipCheck()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 MyPos = GetTransform()->GetLocalPosition();
	if (PlayerPos.x - MyPos.x < 0)
	{
		IsFlip = true;
	}
	else 
	{
		IsFlip = false;
	}
}
float4 WhiteSkell::PixelCalculation(float4 _TargetPos, float4 _MapCenterPos, float4 _TransColPos)
{
	TargetPos = _TargetPos;
	PixelMapResultPos.x = _TargetPos.x + _TransColPos.x - _MapCenterPos.x;
	PixelMapResultPos.y = _TransColPos.y - _TargetPos.y;
	return PixelMapResultPos;
}