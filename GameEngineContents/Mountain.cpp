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
	MountainRender->SetTexture("MountineBG.png");
	MountainRender->GetTransform()->SetLocalPosition({ 0.0f,-300.0f,0.0f });
	MountainRender->GetTransform()-> SetLocalScale({ 5120.0f,568.0f,0.0f });
}


void Mountain::Update(float _DeltaTime)
{
	PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float asda1 = (PlayerPos.x - Center.x) * (1.0f - 0.1f);
	asda1 += 2000.0f;
	MountainRender->GetTransform()->SetLocalPosition({ asda1,-300.0f,0.0f });

}

