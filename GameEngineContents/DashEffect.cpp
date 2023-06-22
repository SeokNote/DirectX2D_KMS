#include "PrecompileHeader.h"
#include "DashEffect.h"
#include "Player.h"

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
DashEffect::DashEffect() 
{
}

DashEffect::~DashEffect() 
{
}

void DashEffect::Start()
{
	PlayerDashRender_0 = CreateComponent<GameEngineSpriteRenderer>(1);
	PlayerDashRender_0->SetTexture("DashEffect.png");
	PlayerDashRender_0->GetTransform()->SetLocalScale({ 128.0f, 128.0f });

	PlayerDashRender_0->ColorOptionValue.MulColor.x = 1.0f;
	PlayerDashRender_0->ColorOptionValue.MulColor.y = 1.0f;
	PlayerDashRender_0->ColorOptionValue.MulColor.z = 1.0f;
	PlayerDashRender_0->ColorOptionValue.MulColor.a = StartAlpha;
}

void DashEffect::Update(float _Delta)
{
	Time += _Delta;
	AlphaTime += _Delta;

	PlayerDashRender_0->ColorOptionValue.MulColor.a -= (StartAlpha * _Delta) / 0.3f;
	Check = Player::MainPlayer->GetFilpCheck();
	if (Check == true)
	{
		PlayerDashRender_0->GetTransform()->SetLocalNegativeScaleX();
	}
	else if (Check == false)
	{
		PlayerDashRender_0->GetTransform()->SetLocalPositiveScaleX();
	}
	if (Time > 0.3)
	{
		Death();
		Time = 0.0f;
	}
}

