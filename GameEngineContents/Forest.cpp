#include "PrecompileHeader.h"
#include "Forest.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Forest::Forest() 
{
}

Forest::~Forest() 
{
}

void Forest::Start()
{
	ForestRender = CreateComponent<GameEngineSpriteRenderer>();
	ForestRender->SetTexture("BG3.png");
	ForestRender->GetTransform()->SetLocalPosition({ 0.0f,-400.0f,0.0f });
	ForestRender->GetTransform()->SetLocalScale({ 5120.0f,380.0f,0.0f });
	
}


void Forest::Update(float _DeltaTime)
{
	PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float asda = (Center.x- PlayerPos.x) * (1.0f - 0.8f);
	asda -= 400.0f;
	ForestRender->GetTransform()->SetLocalPosition({ asda,-400.0f,0 });
}

