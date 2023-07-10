#include "PrecompileHeader.h"
#include "Minotaurs.h"
#include "Player.h"
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
Minotaurs::Minotaurs() 
{
}

Minotaurs::~Minotaurs() 
{
}

void Minotaurs::Start()
{
	MinotaursRender = CreateComponent<GameEngineSpriteRenderer>(1);
	MinotaursRender->SetTexture("BigWhiteSkelIdle.png");
	MinotaursRender->GetTransform()->SetLocalScale(Scale);
	MinotaursRender->CreateAnimation({ .AnimationName = "MinotaursTakcle", .SpriteName = "MinotaursTakcle", .Loop = false , .ScaleToTexture = false });
	MinotaursRender->CreateAnimation({ .AnimationName = "MinotaursIdle", .SpriteName = "MinotaursIdle", .Loop = true , .ScaleToTexture = false });
	MinotaursRender->CreateAnimation({ .AnimationName = "MinotaursAttack", .SpriteName = "MinotaursAttack", .Loop = false , .ScaleToTexture = false });
	ChangeState(MinotaursState::IDLE);
	TargetAreaCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	TargetAreaCol->GetTransform()->SetLocalPosition({ 280.0f,-40.0f,0.f });
	TargetAreaCol->GetTransform()->SetLocalScale(AreaScale);
	TargetAreaCol->SetColType(ColType::AABBBOX2D);

	MinotaursCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	MinotaursCol->GetTransform()->SetLocalPosition({0.0f,-30.0f,0.f });
	MinotaursCol->GetTransform()->SetLocalScale(ColScale);
	MinotaursCol->SetColType(ColType::AABBBOX2D);

	TakcleCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TakcleCol->GetTransform()->SetLocalPosition({ 0.0f,-30.0f,0.f });
	TakcleCol->GetTransform()->SetLocalScale(TakcleColScale);
	TakcleCol->SetColType(ColType::AABBBOX2D);
	TakcleCol->Off();

	AttackCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	AttackCol->GetTransform()->SetLocalPosition({ 70.0f,-30.0f,0.f });
	AttackCol->GetTransform()->SetLocalScale(AttackColScale);
	AttackCol->SetColType(ColType::AABBBOX2D);
	AttackCol->Off();

	HpBaseRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpBaseRender->SetTexture("MonsterHpBase.png");
	HpBaseRender->GetTransform()->SetLocalScale(HpBaseScale);
	HpBaseRender->GetTransform()->SetLocalPosition({ -35.0f,-110.0f,0.0f });
	HpBaseRender->Off();

	HpRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpRender->SetTexture("MonsterHpBar.png");
	HpRender->GetTransform()->SetLocalScale(HpBarScale);
	HpRender->GetTransform()->SetLocalPosition({ -35.0f,-110.0f,0.0f });
	HpRender->Off();

	DeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadRender->SetTexture("Die10.png");
	DeadRender->CreateAnimation({ .AnimationName = "MinoDead", .SpriteName = "BossDead",.FrameInter = 0.07f,.Loop = false , .ScaleToTexture = true });
	DeadRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
}

void Minotaurs::Update(float _DeltaTime)
{	
	UpdateState(_DeltaTime);
	SetCollision(_DeltaTime);
}

bool Minotaurs::IsFlipCheck()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetWorldPosition();
	float4 MyPos = GetTransform()->GetLocalPosition();
	if (PlayerPos.x - MyPos.x < 0.f)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Minotaurs::IsAreaIn()
{
	if (TargetAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Minotaurs::SetCollision(float _Delta)
{
	HpRender->ImageClippingX(static_cast<float>(MinoHp) / static_cast<float>(MaxMinoHp), ClipXDir::Left);

	if (TakcleCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(MinoTackle);
	}
	if (TakcleCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(MinoAttack);
	}
	if (MinotaursCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		HpRender->On();
		HpBaseRender->On();
		AreaIn = true;
		if (MinoBlink == false)
		{
			//나중에 ui작업때 캐릭터가 갖고있는 swich로 무기에 따라 정해주자.
			MinoHp -= WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E);
			MinotaursRender->ColorOptionValue.MulColor.r = 1.0f;
			MinotaursRender->ColorOptionValue.MulColor.g = 0.1f;
			MinotaursRender->ColorOptionValue.MulColor.b = 0.1f;
			MinoBlink = true;
		}

	}
	else {
		if (MinoBlink == true)
		{

			Invincibilitytime += _Delta;
			if (Invincibilitytime > 0.05f)
			{
				MinotaursRender->ColorOptionValue.MulColor.r = 1.0f;
				MinotaursRender->ColorOptionValue.MulColor.g = 1.0f;
				MinotaursRender->ColorOptionValue.MulColor.b = 1.0f;
				MinoBlink = false;
				Invincibilitytime = 0.0f;
			}
		}
	}
}

