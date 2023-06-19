#include "PrecompileHeader.h"
#include "Tunak.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
Tunak::Tunak()
{
}

Tunak::~Tunak()
{
}

void Tunak::Start()
{
	TunakRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakRender->SetTexture("SkellBossLeftHandIdle0.png");
	TunakRender->GetTransform()->SetLocalScale({ 456.0f,468.0f,0.0f });
	TunakRender->CreateAnimation({ .AnimationName = "TunakIdle", .SpriteName = "TunakIdle", .Loop = true , .ScaleToTexture = false });
//	TunakRender->CreateAnimation({ .AnimationName = "TunakJumpAttack", .SpriteName = "TunakJumpAttack", .Loop = false , .ScaleToTexture = true });
	TunakRender->ChangeAnimation("TunakIdle");



	//TunakCol = CreateComponent<GameEngineCollision>();

}

void Tunak::Update(float _DeltaTime)
{
	TestTime += _DeltaTime;

}

