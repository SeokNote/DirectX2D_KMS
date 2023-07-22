#include "PrecompileHeader.h"
#include "Ghost.h"
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
Ghost::Ghost() 
{
}

Ghost::~Ghost() 
{
}

void Ghost::Start()
{
	GhostRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GhostRender->SetTexture("BigWhiteSkelIdle.png");
	GhostRender->GetTransform()->SetLocalScale(Scale);
	GhostRender->CreateAnimation({ .AnimationName = "GhostAttack", .SpriteName = "GhostAttack", .Loop = true , .ScaleToTexture = false });
	GhostRender->CreateAnimation({ .AnimationName = "GhostIdle", .SpriteName = "GhostIdle", .Loop = true , .ScaleToTexture = false });
	GhostRender->ChangeAnimation("GhostIdle");
	SpownRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SpownRender->CreateAnimation({ .AnimationName = "SpownAni", .SpriteName = "SpownAni",.FrameInter = 0.1f, .Loop = false , .ScaleToTexture = true });

	TargetAreaCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	TargetAreaCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
	TargetAreaCol->GetTransform()->SetLocalScale(AreaScale);
	TargetAreaCol->SetColType(ColType::AABBBOX2D);

	AttackAreaCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	AttackAreaCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
	AttackAreaCol->GetTransform()->SetLocalScale(AttackAreaScale);
	AttackAreaCol->SetColType(ColType::AABBBOX2D);

	HpBaseRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpBaseRender->SetTexture("MonsterHpBase.png");
	HpBaseRender->GetTransform()->SetLocalScale(HpBaseScale);
	HpBaseRender->GetTransform()->SetLocalPosition({ 0.0f,-50.0f,0.f });
	HpBaseRender->Off();

	HpRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpRender->SetTexture("MonsterHpBar.png");
	HpRender->GetTransform()->SetLocalScale(HpBarScale);
	HpRender->GetTransform()->SetLocalPosition({ 0.0f,-50.0f,0.f });
	HpRender->Off();

	DeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadRender->SetTexture("Die10.png");
	DeadRender->CreateAnimation({ .AnimationName = "GhostDead", .SpriteName = "BossDead",.FrameInter = 0.07f,.Loop = false , .ScaleToTexture = true });
	DeadRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });

	BodyCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	BodyCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
	BodyCol->GetTransform()->SetLocalScale(Scale);
	BodyCol->SetColType(ColType::AABBBOX2D);
	ChangeState(GhostState::IDLE);

}

void Ghost::Update(float _DeltaTime)
{
	UpdateState(_DeltaTime);
	SetCollision(_DeltaTime);
	Flip();
}
void Ghost::SetCollision(float _DeltaTime)
{
	HpRender->ImageClippingX(static_cast<float>(Hp) / static_cast<float>(MaxHp), ClipXDir::Left);
	if (BodyCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(Damege);
	}
	if (TargetAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		StartMove = true;
	}
	if (AttackAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		AttackMove = true;
	}
	if (BodyCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		HpRender->On();
		HpBaseRender->On();
		if (GhostBlink == false)
		{
			//나중에 ui작업때 캐릭터가 갖고있는 swich로 무기에 따라 정해주자.
			Hp -= WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E);
			TextUI::TextCreat(GetLevel(), GetTransform()->GetLocalPosition(), float4::White,
				std::to_string(WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E)), true,24);
			GhostRender->ColorOptionValue.MulColor.r = 1.0f;
			GhostRender->ColorOptionValue.MulColor.g = 0.1f;
			GhostRender->ColorOptionValue.MulColor.b = 0.1f;
			GhostBlink = true;
		}

	}
	else {
		if (GhostBlink == true)
		{

			Invincibilitytime += _DeltaTime;
			if (Invincibilitytime > 0.05f)
			{
				GhostRender->ColorOptionValue.MulColor.r = 1.0f;
				GhostRender->ColorOptionValue.MulColor.g = 1.0f;
				GhostRender->ColorOptionValue.MulColor.b = 1.0f;
				GhostBlink = false;
				Invincibilitytime = 0.0f;
			}
		}
	}
}

void Ghost::Flip()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 MyPos = GetTransform()->GetLocalPosition();
	if (PlayerPos.x - MyPos.x > 0)
	{
		GhostRender->GetTransform()->SetLocalPositiveScaleX();
	}
	else
	{
		GhostRender->GetTransform()->SetLocalNegativeScaleX();

	}
}

