#include "PrecompileHeader.h"
#include "TunakDust.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
TunakDust::TunakDust() 
{
}

TunakDust::~TunakDust() 
{
}

void TunakDust::Start()
{
	//´õ½ºÆ®
	TunakDustRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakDustRender->SetTexture("DustSide_11.png");
	TunakDustRender->CreateAnimation({ .AnimationName = "TunakDust_1", .SpriteName = "TunakDust_1",.FrameInter=0.07f, .Loop = false , .ScaleToTexture = true });
	TunakDustRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,90.0f });
	TunakDustRender->GetTransform()->SetLocalPosition({ 170.0f,0.0f,0.0f });

	TunakDustRender->ChangeAnimation("TunakDust_1");
}

void TunakDust::Update(float _DeltaTime)
{
	if (true == TunakDustRender->IsAnimationEnd())
	{
		Death();
	}
}

