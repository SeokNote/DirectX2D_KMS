#include "PrecompileHeader.h"
#include "BelialHand_R.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
BelialHand_R* BelialHand_R::MainBelialHand_R = nullptr;
BelialHand_R::BelialHand_R() 
{
}

BelialHand_R::~BelialHand_R() 
{
}

void BelialHand_R::Start()
{
	RightHandRender = CreateComponent<GameEngineSpriteRenderer>(1);
	RightHandRender->SetTexture("SkellBossLeftHandIdle0.png");
	RightHandRender->GetTransform()->SetLocalScale(RightHandScale);
	RightHandRender->GetTransform()->SetLocalPosition(RightHandPos);
	RightHandRender->CreateAnimation({ .AnimationName = "LeftHandIdle", .SpriteName = "HandIdle", .Loop = true , .ScaleToTexture = false });
	RightHandRender->CreateAnimation({ .AnimationName = "LeftHandLasor", .SpriteName = "HandLasor", .Loop = false , .ScaleToTexture = false });
	RightHandRender->ColorOptionValue.MulColor.a = 0.0f;
	ChangeState(RightHandState::IDLE);

}

void BelialHand_R::Update(float _DeltaTime)
{
	UpdateState(_DeltaTime);

}
