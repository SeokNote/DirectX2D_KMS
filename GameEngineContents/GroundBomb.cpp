#include "PrecompileHeader.h"
#include "GroundBomb.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineBase/GameEngineRandom.h>

GroundBomb::GroundBomb() 
{
}

GroundBomb::~GroundBomb() 
{
}

void GroundBomb::Start()
{
	float X = GameEngineRandom::MainRandom.RandomFloat(14700.0f, 14840.0f);
	GroundBombBGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GroundBombBGRender->SetTexture("TunakGroundBG.png");
	GroundBombBGRender->GetTransform()->SetLocalScale(BGScale); 

	GroundBombRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GroundBombRender->SetTexture("GeyserFx06.png");
	GroundBombRender->GetTransform()->SetLocalScale(BombScale);
	GroundBombRender->GetTransform()->SetLocalPosition({ 0.0f,240.f,0.0f});
	GroundBombRender->CreateAnimation({ .AnimationName = "GroundBomb", .SpriteName = "GroundBomb", .Loop = false , .ScaleToTexture = false });

	GroundBombBGRender->ColorOptionValue.MulColor.x = 1.0f;
	GroundBombBGRender->ColorOptionValue.MulColor.y = 1.0f;
	GroundBombBGRender->ColorOptionValue.MulColor.z = 1.0f;
	GroundBombBGRender->ColorOptionValue.MulColor.a = StartAlpha;

	BombBGRender_0 = CreateComponent<GameEngineSpriteRenderer>(1);
	BombBGRender_0->SetTexture("SpikeStoneFront13.png");
	BombBGRender_0->GetTransform()->SetLocalPosition({ 0.0f ,-125.f,0.0f });
	BombBGRender_0->CreateAnimation({ .AnimationName = "BombBG_0", .SpriteName = "BombBG", .FrameInter=0.04f,.Loop = false , .ScaleToTexture = true });



}

void GroundBomb::Update(float _DeltaTime)
{
	DeadTime += _DeltaTime;
	SetGroundBG(_DeltaTime);
	CreatBomb(_DeltaTime);
	BombDeath(_DeltaTime);
}

void GroundBomb::SetGroundBG(float _DeltaTime)
{
	AlphaTime += _DeltaTime;

	if (GroundBombBGRender->ColorOptionValue.MulColor.g > 0)
	{
		GroundBombBGRender->ColorOptionValue.MulColor.g -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender->ColorOptionValue.MulColor.g = 0.0f;
	}
	if (GroundBombBGRender->ColorOptionValue.MulColor.b > 0)
	{
		GroundBombBGRender->ColorOptionValue.MulColor.b -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender->ColorOptionValue.MulColor.b = 0.0f;
	}
	if (GroundBombBGRender->ColorOptionValue.MulColor.r > 0)
	{
		GroundBombBGRender->ColorOptionValue.MulColor.r += (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender->ColorOptionValue.MulColor.r = 1.0f;
	}
	if (GroundBombBGRender->ColorOptionValue.MulColor.a > 0)
	{
		GroundBombBGRender->ColorOptionValue.MulColor.a -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender->ColorOptionValue.MulColor.a = 0.0f;
	}
	if (BGScale.x < 250.0f)
	{
		GroundBombBGRender->GetTransform()->AddLocalScale({ _DeltaTime * 100,0.0f,0.0f });
	}

	
}

void GroundBomb::CreatBomb(float _DeltaTime)
{
	if (BombCheck==false && GroundBombBGRender->ColorOptionValue.MulColor.a == 0.0f)
	{
		StartBomb += _DeltaTime;
		if (StartBomb > 0.4f)
		{
			GroundBombRender->ChangeAnimation("GroundBomb");
			BombBGRender_0->ChangeAnimation("BombBG_0");
			BombCheck = true;
			StartBomb = 0.0f;
		}
	}
}

void GroundBomb::BombDeath(float _DeltaTime)
{
	DeadTime += _DeltaTime;
	if (DeadTime > 4.0f)
	{
		Death();
	}
}

