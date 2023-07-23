#include "PrecompileHeader.h"
#include "GiantBat.h"
#include "Player.h"
#include "TextUI.h"
#include "ContentsEnums.h"
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
GiantBat::GiantBat()
{
}

GiantBat::~GiantBat()
{
}

void GiantBat::Start()
{
	Rad = GameEngineMath::PIE2 / A_Count;

	GiantBatRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GiantBatRender->SetTexture("BigWhiteSkelIdle.png");
	GiantBatRender->GetTransform()->SetLocalScale(Scale);
	GiantBatRender->CreateAnimation({ .AnimationName = "GiantBatAttack", .SpriteName = "GiantBatAttack", .Loop = false , .ScaleToTexture = false });
	GiantBatRender->CreateAnimation({ .AnimationName = "GiantBatIdle", .SpriteName = "GiantBatIdle", .Loop = true , .ScaleToTexture = false });
	GiantBatRender->CreateAnimation({ .AnimationName = "GiantBatDead", .SpriteName = "GiantBatDead", .Loop = false , .ScaleToTexture = false });

	GiantBatRender->ChangeAnimation("GiantBatIdle");
	SpownRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SpownRender->CreateAnimation({ .AnimationName = "SpownAni", .SpriteName = "SpownAni",.FrameInter = 0.1f, .Loop = false , .ScaleToTexture = true });



	HpBaseRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpBaseRender->SetTexture("MonsterHpBase.png");
	HpBaseRender->GetTransform()->SetLocalScale(HpBaseScale);
	HpBaseRender->GetTransform()->SetLocalPosition({ -10.0f,-75.0f,0.f });
	HpBaseRender->Off();

	HpRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpRender->SetTexture("MonsterHpBar.png");
	HpRender->GetTransform()->SetLocalScale(HpBarScale);
	HpRender->GetTransform()->SetLocalPosition({ -10.0f,-75.0f,0.f });
	HpRender->Off();

	DeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadRender->SetTexture("Die10.png");
	DeadRender->CreateAnimation({ .AnimationName = "GiantBatDead", .SpriteName = "BossDead",.FrameInter = 0.07f,.Loop = false , .ScaleToTexture = true });
	DeadRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });

	AttackAreaCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	AttackAreaCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
	AttackAreaCol->GetTransform()->SetLocalScale(AttackAreaScale);
	AttackAreaCol->SetColType(ColType::AABBBOX2D);

	BodyCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERBODY);
	BodyCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	BodyCol->GetTransform()->SetLocalScale(ColScale);
	BodyCol->SetColType(ColType::AABBBOX2D);
	SetDeg();
	ChangeState(GiantBatState::IDLE);

}

void GiantBat::Update(float _DeltaTime)
{

	UpdateState(_DeltaTime);
	SetCollision(_DeltaTime);
	Flip();

}
void GiantBat::SetDeg()
{
	for (int i = 0; i < A_Count; i++)
	{
		float4 Dir = { cos(Rad * i),sin(Rad * i),0.0f,0.0f };
		Degs.push_back(Dir);
	}
}
void GiantBat::SetCollision(float _DeltaTime)
{
	HpRender->ImageClippingX(static_cast<float>(Hp) / static_cast<float>(MaxHp), ClipXDir::Left);
	if (AttackAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		AttackMove = true;
	}
	if (BodyCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		HpRender->On();
		HpBaseRender->On();
		if (GiantBatBlink == false)
		{
			//나중에 ui작업때 캐릭터가 갖고있는 swich로 무기에 따라 정해주자.
			Hp -= WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E);
			TextUI::TextCreat(GetLevel(), GetTransform()->GetLocalPosition(), float4::White,
				std::to_string(WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E)), true,24);
			GiantBatRender->ColorOptionValue.MulColor.r = 1.0f;
			GiantBatRender->ColorOptionValue.MulColor.g = 0.1f;
			GiantBatRender->ColorOptionValue.MulColor.b = 0.1f;
			GiantBatBlink = true;
		}

	}
	else {
		if (GiantBatBlink == true)
		{

			Invincibilitytime += _DeltaTime;
			if (Invincibilitytime > 0.05f)
			{
				GiantBatRender->ColorOptionValue.MulColor.r = 1.0f;
				GiantBatRender->ColorOptionValue.MulColor.g = 1.0f;
				GiantBatRender->ColorOptionValue.MulColor.b = 1.0f;
				GiantBatBlink = false;
				Invincibilitytime = 0.0f;
			}
		}
	}
}

void GiantBat::Flip()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 MyPos = GetTransform()->GetLocalPosition();
	if (PlayerPos.x - MyPos.x > 0)
	{
		GiantBatRender->GetTransform()->SetLocalPositiveScaleX();
	}
	else
	{
		GiantBatRender->GetTransform()->SetLocalNegativeScaleX();

	}
}

