#include "PrecompileHeader.h"
#include "TunakAfterEffect.h"

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
TunakAfterEffect::TunakAfterEffect()
{
}

TunakAfterEffect::~TunakAfterEffect()
{
}

void TunakAfterEffect::Start()
{
	TunakAfterEffectRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakAfterEffectRender->SetTexture("TunakShoulderTackle15.png");
	TunakAfterEffectRender->GetTransform()->SetLocalScale({ 456.0f, 468.0f });

	TunakAfterEffectRender->ColorOptionValue.MulColor.x = 1.0f;
	TunakAfterEffectRender->ColorOptionValue.MulColor.y = 1.0f;
	TunakAfterEffectRender->ColorOptionValue.MulColor.z = 1.0f;
	TunakAfterEffectRender->ColorOptionValue.MulColor.a = StartAlpha;
}

void TunakAfterEffect::Update(float _Delta)
{
	Time += _Delta;
	AlphaTime += _Delta;

	TunakAfterEffectRender->ColorOptionValue.MulColor.a -= (StartAlpha * _Delta) / 0.3f;
	if (Time > 0.3)
	{
		Death();
	}
}

