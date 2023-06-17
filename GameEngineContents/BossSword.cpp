#include"PrecompileHeader.h"
#include "BossSword.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
BossSword::BossSword() 
{
}

BossSword::~BossSword() 
{
}

void BossSword::Start()
{

	SwordRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordRender->SetTexture("BossSword.png");
	SwordRender->GetTransform()->SetLocalScale({ 84.0f,-260.0f,0.0f });
	//SwordRender->GetTransform()->SetLocalPosition({ -2300.0f,0.0f,-800.0f });
	SwordRender->CreateAnimation({ .AnimationName = "BossSwordIdle", .SpriteName = "BossSwordIdle", .Loop = true , .ScaleToTexture = false });

	SwordDeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordDeadRender->SetTexture("IcicleDestroyFX3.png");
	//SwordDeadRender->GetTransform()->SetLocalPosition({ -2300.0f,0.0f,-800.0f });
	SwordDeadRender->CreateAnimation({ .AnimationName = "BossSwordDead", .SpriteName = "BossSwordDead", .Loop = false , .ScaleToTexture = true });
	//SwordDeadRender->ChangeAnimation("BossSwordDead");

	SwordEffectRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordEffectRender->SetTexture("BossSwordCharge8.png");
	//SwordEffectRender->GetTransform()->SetLocalPosition({ -2300.0f,0.0f,-800.0f });
	SwordEffectRender->CreateAnimation({ .AnimationName = "BossSwordCharge", .SpriteName = "BossSwordCharge", .ScaleToTexture = true });

	SwordFxRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordFxRender->SetTexture("BossSwordFX.png");
	SwordRender->GetTransform()->SetLocalScale({ 84.0f,-280.0f,0.0f });
	//SwordFxRender->GetTransform()->SetLocalPosition({ -2300.0f,0.0f,-800.0f });
	SwordFxRender->CreateAnimation({ .AnimationName = "BossSwordAtteck", .SpriteName = "BossSwordAtteck", .Loop=false ,.ScaleToTexture = true });
	SwordFxRender->ChangeAnimation("BossSwordAtteck");
	SwordFxRender->Off();

	SwordColRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordColRender->SetTexture("BossSwordHitFX5.png");
	//SwordColRender->GetTransform()->SetLocalPosition({ -2300.0f,0.0f,-800.0f });
	SwordColRender->CreateAnimation({ .AnimationName = "BossSwordFx", .SpriteName = "BossSwordFx", .Loop = false , .ScaleToTexture = true });
	ChangeState(BossSwordState::IDLE);
}

void BossSword::Update(float _DeltaTime)
{
	PixelCheck();
	UpdateState(_DeltaTime);

}

bool BossSword::PixelCheck()
{
	float4 Pos = SwordRender->GetTransform()->GetWorldPosition();
	PixelMapResultPos = Player::MainPlayer->PixelCalculation(Pos, { 0.0f,0.0f,0.0f }, { 2560.f,720.0f });
	Ptr = GameEngineTexture::Find("TownCol_3.png");
	Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y));
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