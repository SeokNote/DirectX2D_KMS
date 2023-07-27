#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "GoblinBomb.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>
GameEngineSoundPlayer GoblinBomb::GoblimBombBGM;
GoblinBomb::GoblinBomb() 
{
}

GoblinBomb::~GoblinBomb() 
{
}

void GoblinBomb::Start()
{
	BGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BGRender->SetTexture("TunakGroundBG.png");
	BGRender->GetTransform()->SetLocalScale(BGScale);
	BGRender->ColorOptionValue.MulColor.x = 1.0f;
	BGRender->ColorOptionValue.MulColor.y = 1.0f;
	BGRender->ColorOptionValue.MulColor.z = 1.0f;
	BGRender->ColorOptionValue.MulColor.a = StartAlpha;

	GoblinBombRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GoblinBombRender->SetTexture("Goblin00.png");
	GoblinBombRender->GetTransform()->SetLocalPosition({ 0.0f,330.f,0.0f });
	GoblinBombRender->CreateAnimation({ .AnimationName = "GoblinBombIdle", .SpriteName = "GoblinBombIdle", .Loop = true , .ScaleToTexture = true });

	GoblinBombEffectRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GoblinBombEffectRender->SetTexture("HeavyExplosion12.png");
	GoblinBombEffectRender->GetTransform()->SetLocalPosition({ 0.0f,-40.f,0.0f });
	GoblinBombEffectRender->CreateAnimation({ .AnimationName = "GoblinBombEffect", .SpriteName = "GoblinBombEffect", .Loop = false , .ScaleToTexture = true });
	
	GoblinBombCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	GoblinBombCol->GetTransform()->SetLocalScale(ColScale);
	GoblinBombCol->SetColType(ColType::AABBBOX2D);
	GoblinBombCol->Off();
}

void GoblinBomb::Update(float _DeltaTime)
{
	SetGroundBG(_DeltaTime);
	CreatBomb(_DeltaTime);
	BombDeath(_DeltaTime);
	GoblinCollision();
}

void GoblinBomb::BGMSet()
{
	if (true == GoblimBombBGM.IsValid())
	{
		bool IsPlayValue = false;
		GoblimBombBGM.isPlaying(&IsPlayValue);
		if (IsPlayValue == true)
		{

			return;
		}


	}
	GoblimBombBGM = GameEngineSound::Play("explodeBrighter.wav");
}

void GoblinBomb::GoblinCollision()
{
	if (Player::MainPlayer->GetABSValue() == false && FirstAttack == false && GoblinBombCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(GoblinDamage);
		FirstAttack = true;
	}
}

void GoblinBomb::SetGroundBG(float _DeltaTime)
{
	AlphaTime += _DeltaTime;

	if (BGRender->ColorOptionValue.MulColor.g > 0)
	{
		BGRender->ColorOptionValue.MulColor.g -= (_DeltaTime) * 3.0f;
	}
	else
	{
		BGRender->ColorOptionValue.MulColor.g = 0.0f;
	}

	if (BGRender->ColorOptionValue.MulColor.b > 0)
	{
		BGRender->ColorOptionValue.MulColor.b -= (_DeltaTime) * 3.0f;
	}
	else
	{
		BGRender->ColorOptionValue.MulColor.b = 0.0f;
	}

	if (BGRender->ColorOptionValue.MulColor.r > 0)
	{
		BGRender->ColorOptionValue.MulColor.r += (_DeltaTime) * 5.0f;
	}
	else
	{
		BGRender->ColorOptionValue.MulColor.r = 1.0f;
	}

	if (BGRender->ColorOptionValue.MulColor.a > 0)
	{
		BGRender->ColorOptionValue.MulColor.a -= (_DeltaTime) * 1.0f;
	}
	else
	{
		BGRender->ColorOptionValue.MulColor.a = 0.0f;
		StartPatton = true;
	}
	if (BGScale.x < 30.0f)
	{
		BGRender->GetTransform()->AddLocalScale({ _DeltaTime * 50,0.0f,0.0f });
	}


}

void GoblinBomb::CreatBomb(float _DeltaTime)
{
	float4 BombPos = GoblinBombRender->GetTransform()->GetLocalPosition();
	if (IsCheck== false && StartPatton == true)
	{
		GoblinBombRender->ChangeAnimation("GoblinBombIdle");
		IsCheck = true;
	}
	if (IsCheck == true)
	{
		StartBomb += _DeltaTime;
		if (StartBomb > 0.2f)
		{
			GoblinBombRender->GetTransform()->AddLocalPosition({ 0.0f, -_DeltaTime * BombSpeed,0.0f });

		}
	}
	if (BombPos.y <= -153 && IsCheck_1 ==false)
	{
		BGMSet();
		GoblinBombCol->On();
		GoblinBombRender->Off();
		GoblinBombCol->GetTransform()->SetLocalPosition({ BombPos.x,BombPos.y+60.0f,0.0f});
		GoblinBombEffectRender->ChangeAnimation("GoblinBombEffect");
		IsCheck_1 = true;
	}
}

void GoblinBomb::BombDeath(float _DeltaTime)
{
	if (IsCheck_1 == true)
	{
		if (true == GoblinBombEffectRender->IsAnimationEnd())
		{
			Death();
			IsCheck_1 = false;
		}
	}
}
