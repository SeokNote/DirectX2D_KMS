#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "TunakWave.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>

TunakWave::TunakWave()
{
}

TunakWave::~TunakWave()
{
}

void TunakWave::Start()
{
	BGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BGRender->SetTexture("TunakGroundBG.png");
	BGRender->GetTransform()->SetLocalScale(BGScale);
	BGRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,90.0f });
	BGRender->ColorOptionValue.MulColor.x = 1.0f;
	BGRender->ColorOptionValue.MulColor.y = 1.0f;
	BGRender->ColorOptionValue.MulColor.z = 1.0f;
	BGRender->ColorOptionValue.MulColor.a = StartAlpha;

	TunakWaveRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakWaveRender->SetTexture("HeavyExplosion12.png");
	TunakWaveRender->GetTransform()->SetLocalPosition({ 40.0f,10.0f,0.0f });
	TunakWaveRender->CreateAnimation({ .AnimationName = "WaveEffect", .SpriteName = "WaveEffect", .Loop = true , .ScaleToTexture = true });
	
	TunakWaveRender_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakWaveRender_1->SetTexture("HeavyExplosion12.png");
	TunakWaveRender_1->GetTransform()->SetLocalScale(WaveScale);
	TunakWaveRender_1->GetTransform()->SetLocalNegativeScaleX();
	TunakWaveRender_1->GetTransform()->SetLocalPosition({ 40.0f,10.0f,0.0f });
	TunakWaveRender_1->CreateAnimation({ .AnimationName = "WaveEffect_1", .SpriteName = "WaveEffect", .Loop = true , .ScaleToTexture = false });

	TunakWaveCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakWaveCol->GetTransform()->SetLocalScale(WaveColScale);
	TunakWaveCol->SetColType(ColType::AABBBOX2D);
	TunakWaveCol->Off();

	TunakWaveCol_1 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakWaveCol_1->GetTransform()->SetLocalScale(WaveColScale);
	TunakWaveCol_1->SetColType(ColType::AABBBOX2D);
	TunakWaveCol_1->Off();
}

void TunakWave::Update(float _DeltaTime)
{
	SetGroundBG(_DeltaTime);
	CreatWave(_DeltaTime);
	WaveCollision();
	WaveDeath(_DeltaTime);
}

void TunakWave::WaveCollision()
{
	if (Player::MainPlayer->GetABSValue() == false && FirstAttack ==false && TunakWaveCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(WaveDamege);
		FirstAttack = true;
	}
	if (Player::MainPlayer->GetABSValue() == false && FirstAttack == false && TunakWaveCol_1->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(WaveDamege);
		FirstAttack = true;
	}
}

void TunakWave::SetGroundBG(float _DeltaTime)
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
		BGRender->ColorOptionValue.MulColor.r += (_DeltaTime) * 2.0f;
	}
	else
	{
		BGRender->ColorOptionValue.MulColor.r = 1.0f;
	}

	if (BGRender->ColorOptionValue.MulColor.a > 0)
	{
		BGRender->ColorOptionValue.MulColor.a -= (_DeltaTime) * 0.7f;
	}
	else
	{
		BGRender->ColorOptionValue.MulColor.a = 0.0f;
		StartPatton = true;
	}
	if (BGScale.x > 0.0f)
	{
		BGRender->GetTransform()->AddLocalScale({ -_DeltaTime * 200,0.0f,0.0f });
	}


}

void TunakWave::CreatWave(float _DeltaTime)
{
	AddSpeed = 0.0f;
	StartWave += _DeltaTime;
	if (StartWave > 1.5f)
	{
		TunakWaveCol_1->On();
		TunakWaveCol->On();

		TunakWaveRender->ChangeAnimation("WaveEffect");
		TunakWaveRender_1->ChangeAnimation("WaveEffect_1");
		StartWave = 0.0f;
		WaveStart = true;
	}
	if (WaveStart==true)
	{
		float4 Pos = TunakWaveRender->GetTransform()->GetLocalPosition();
		float4 Pos1 = TunakWaveRender_1->GetTransform()->GetLocalPosition();
		TunakWaveCol->GetTransform()->SetLocalPosition({ Pos.x,Pos.y,0.0f});
		TunakWaveCol_1->GetTransform()->SetLocalPosition({ Pos1.x,Pos1.y,0.0f});
		TunakWaveRender->GetTransform()->AddLocalPosition({ _DeltaTime*WaveSpeed,0.0f,0.0f});
		TunakWaveRender_1-> GetTransform()->AddLocalPosition({ -_DeltaTime * WaveSpeed,0.0f,0.0f });
	}
}

void TunakWave::WaveDeath(float _DeltaTime)
{
	DeadTime += _DeltaTime;
	if (DeadTime > 3.0f)
	{
		Death();
		DeadTime = 0.0f;
	}
}
