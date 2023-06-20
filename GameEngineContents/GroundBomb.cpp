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
	GroundBombBGRender->GetTransform()->SetLocalPosition({ X,-100.f,-900.0f });

	GroundBombRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GroundBombRender->SetTexture("GeyserFx06.png");
	GroundBombRender->GetTransform()->SetLocalScale(BombScale);
	GroundBombRender->GetTransform()->SetLocalPosition({ X,140.f,-900.0f });
	GroundBombRender->CreateAnimation({ .AnimationName = "GroundBomb", .SpriteName = "GroundBomb", .Loop = false , .ScaleToTexture = false });

	GroundBombBGRender->ColorOptionValue.MulColor.x = 1.0f;
	GroundBombBGRender->ColorOptionValue.MulColor.y = 1.0f;
	GroundBombBGRender->ColorOptionValue.MulColor.z = 1.0f;
	GroundBombBGRender->ColorOptionValue.MulColor.a = StartAlpha;

	GroundBombBGRender_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	GroundBombBGRender_1->SetTexture("TunakGroundBG.png");
	GroundBombBGRender_1->GetTransform()->SetLocalScale(BGScale);
	GroundBombBGRender_1->GetTransform()->SetLocalPosition({ X-400.0f,-100.f,-900.0f });

	GroundBombRender_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	GroundBombRender_1->SetTexture("GeyserFx06.png");
	GroundBombRender_1->GetTransform()->SetLocalScale(BombScale);
	GroundBombRender_1->GetTransform()->SetLocalPosition({ X - 400.0f,140.f,-900.0f });
	GroundBombRender_1->CreateAnimation({ .AnimationName = "GroundBomb", .SpriteName = "GroundBomb", .Loop = false , .ScaleToTexture = false });

	GroundBombBGRender_1->ColorOptionValue.MulColor.x = 1.0f;
	GroundBombBGRender_1->ColorOptionValue.MulColor.y = 1.0f;
	GroundBombBGRender_1->ColorOptionValue.MulColor.z = 1.0f;
	GroundBombBGRender_1->ColorOptionValue.MulColor.a = StartAlpha;

	GroundBombBGRender_2 = CreateComponent<GameEngineSpriteRenderer>(1);
	GroundBombBGRender_2->SetTexture("TunakGroundBG.png");
	GroundBombBGRender_2->GetTransform()->SetLocalScale(BGScale);
	GroundBombBGRender_2->GetTransform()->SetLocalPosition({ X+400.0f,-100.f,-900.0f });

	GroundBombRender_2 = CreateComponent<GameEngineSpriteRenderer>(1);
	GroundBombRender_2->SetTexture("GeyserFx06.png");
	GroundBombRender_2->GetTransform()->SetLocalScale(BombScale);
	GroundBombRender_2->GetTransform()->SetLocalPosition({ X + 400.0f,140.f,-900.0f });
	GroundBombRender_2->CreateAnimation({ .AnimationName = "GroundBomb", .SpriteName = "GroundBomb", .Loop = false , .ScaleToTexture = false });

	GroundBombBGRender_2->ColorOptionValue.MulColor.x = 1.0f;
	GroundBombBGRender_2->ColorOptionValue.MulColor.y = 1.0f;
	GroundBombBGRender_2->ColorOptionValue.MulColor.z = 1.0f;
	GroundBombBGRender_2->ColorOptionValue.MulColor.a = StartAlpha;
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

	if (GroundBombBGRender_1->ColorOptionValue.MulColor.g > 0)
	{
		GroundBombBGRender_1->ColorOptionValue.MulColor.g -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender_1->ColorOptionValue.MulColor.g = 0.0f;
	}
	if (GroundBombBGRender_1->ColorOptionValue.MulColor.b > 0)
	{
		GroundBombBGRender_1->ColorOptionValue.MulColor.b -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender_1->ColorOptionValue.MulColor.b = 0.0f;
	}
	if (GroundBombBGRender_1->ColorOptionValue.MulColor.r > 0)
	{
		GroundBombBGRender_1->ColorOptionValue.MulColor.r += (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender_1->ColorOptionValue.MulColor.r = 1.0f;
	}
	if (GroundBombBGRender_1->ColorOptionValue.MulColor.a > 0)
	{
		GroundBombBGRender_1->ColorOptionValue.MulColor.a -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender_1->ColorOptionValue.MulColor.a = 0.0f;
	}
	if (BGScale.x < 250.0f)
	{
		GroundBombBGRender_1->GetTransform()->AddLocalScale({ _DeltaTime * 100,0.0f,0.0f });
	}

	if (GroundBombBGRender_2->ColorOptionValue.MulColor.g > 0)
	{
		GroundBombBGRender_2->ColorOptionValue.MulColor.g -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender_2->ColorOptionValue.MulColor.g = 0.0f;
	}
	if (GroundBombBGRender_2->ColorOptionValue.MulColor.b > 0)
	{
		GroundBombBGRender_2->ColorOptionValue.MulColor.b -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender_2->ColorOptionValue.MulColor.b = 0.0f;
	}
	if (GroundBombBGRender_2->ColorOptionValue.MulColor.r > 0)
	{
		GroundBombBGRender_2->ColorOptionValue.MulColor.r += (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender_2->ColorOptionValue.MulColor.r = 1.0f;
	}
	if (GroundBombBGRender_2->ColorOptionValue.MulColor.a > 0)
	{
		GroundBombBGRender_2->ColorOptionValue.MulColor.a -= (_DeltaTime) * 1.0f;
	}
	else
	{
		GroundBombBGRender_2->ColorOptionValue.MulColor.a = 0.0f;
	}
	if (BGScale.x < 250.0f)
	{
		GroundBombBGRender_2->GetTransform()->AddLocalScale({ _DeltaTime * 100,0.0f,0.0f });
	}
}

void GroundBomb::CreatBomb(float _DeltaTime)
{
	if (BombCheck==false && GroundBombBGRender->ColorOptionValue.MulColor.a == 0.0f)
	{
		StartBomb += _DeltaTime;
		if (StartBomb > 0.3f)
		{
			GroundBombRender->ChangeAnimation("GroundBomb");
			GroundBombRender_1->ChangeAnimation("GroundBomb");
			GroundBombRender_2->ChangeAnimation("GroundBomb");

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

