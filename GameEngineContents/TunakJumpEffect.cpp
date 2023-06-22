#include "PrecompileHeader.h"
#include "TunakJumpEffect.h"

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
TunakJumpEffect::TunakJumpEffect()
{
}

TunakJumpEffect::~TunakJumpEffect()
{
}

void TunakJumpEffect::Start()
{
	TunakJumpEffectRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakJumpEffectRender->SetTexture("TunakJump006.png");
	TunakJumpEffectRender->GetTransform()->SetLocalScale({ 456.0f, 468.0f });

	TunakJumpEffectRender->ColorOptionValue.MulColor.x = 1.0f;
	TunakJumpEffectRender->ColorOptionValue.MulColor.y = 1.0f;
	TunakJumpEffectRender->ColorOptionValue.MulColor.z = 1.0f;
	TunakJumpEffectRender->ColorOptionValue.MulColor.a = StartAlpha;
}

void TunakJumpEffect::Update(float _Delta)
{
	Time += _Delta;
	AlphaTime += _Delta;

	TunakJumpEffectRender->ColorOptionValue.MulColor.a -= (StartAlpha * _Delta) / 0.3f;
	if (Time > 0.3)
	{
		Death();
	}
}

