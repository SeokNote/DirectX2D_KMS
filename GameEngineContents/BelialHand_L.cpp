#include "PrecompileHeader.h"
#include "BelialHand_L.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
BelialHand_L* BelialHand_L::MainBelialHand_L = nullptr;

BelialHand_L::BelialHand_L() 
{
	MainBelialHand_L = this;
}

BelialHand_L::~BelialHand_L() 
{

}

void BelialHand_L::Start()
{
	LeftHandRender = CreateComponent<GameEngineSpriteRenderer>(1);
	LeftHandRender->SetTexture("SkellBossLeftHandIdle0.png");
	LeftHandRender->GetTransform()->SetLocalPosition(LeftHandPos);
	LeftHandRender->CreateAnimation({ .AnimationName = "LeftHandIdle", .SpriteName = "HandIdle", .Loop = true , .ScaleToTexture = true });
	LeftHandRender->CreateAnimation({ .AnimationName = "LeftHandLasor", .SpriteName = "HandLasor", .Loop = false , .ScaleToTexture = true });
	LeftHandRender->ColorOptionValue.MulColor.a = 0.0f;

	ChangeState(LeftHandState::IDLE);

}

void BelialHand_L::Update(float _DeltaTime)
{
	UpdateState(_DeltaTime);

}

