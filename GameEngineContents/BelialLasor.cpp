#include "PrecompileHeader.h"
#include "BelialLasor.h"
#include "BelialHand_L.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
BelialLasor::BelialLasor() 
{
}

BelialLasor::~BelialLasor() 
{
}

void BelialLasor::Start()
{
	BelialLasorRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialLasorRender->SetTexture("SkellBossLeftHandIdle0.png");
	BelialLasorRender->GetTransform()->SetLocalScale(LasorScale);
	BelialLasorRender->CreateAnimation({ .AnimationName = "LasorPattern", .SpriteName = "LasorPattern", .Loop = false , .ScaleToTexture = false });
	BelialLasorRender->ChangeAnimation("LasorPattern");

	
	//BelialLasorCol = CreateComponent<GameEngineCollision>();

}

void BelialLasor::Update(float _DeltaTime)
{
	if (BelialLasorRender->IsAnimationEnd())

	{
		Death();
	}
}

