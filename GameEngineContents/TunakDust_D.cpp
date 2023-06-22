#include "PrecompileHeader.h"
#include "TunakDust_D.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
TunakDust_D::TunakDust_D()
{
}

TunakDust_D::~TunakDust_D()
{
}

void TunakDust_D::Start()
{
	//´õ½ºÆ®
	TunakDustRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakDustRender->SetTexture("DustSide_11.png");
	TunakDustRender->CreateAnimation({ .AnimationName = "TunakDust", .SpriteName = "TunakDust",.FrameInter = 0.07f, .Loop = false , .ScaleToTexture = true });
	TunakDustRender->ChangeAnimation("TunakDust");
}

void TunakDust_D::Update(float _DeltaTime)
{
	if (true == TunakDustRender->IsAnimationEnd())
	{
		Death();
	}
}


