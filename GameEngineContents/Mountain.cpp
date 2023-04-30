#include "PrecompileHeader.h"
#include "Mountain.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Mountain::Mountain()
{
}

Mountain::~Mountain()
{
}

void Mountain::Start()
{
	MountainRender = CreateComponent<GameEngineSpriteRenderer>();
	MountainRender->SetTexture("BG2.png");
	MountainRender->GetTransform()->SetLocalPosition({ 0.0f,-180.0f,0.0f });
	MountainRender->GetTransform()-> SetLocalScale({ 5120.0f,380.0f,0.0f });
	float4 PlayerPos = float4::Zero;
	PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	int a = 0;
}


void Mountain::Update(float _DeltaTime)
{

}

