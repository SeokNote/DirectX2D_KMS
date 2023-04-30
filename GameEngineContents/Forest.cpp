#include "PrecompileHeader.h"
#include "Forest.h"

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
	ForestRender->GetTransform()->SetLocalPosition({ 0.0f,-360.0f,0.0f });
	ForestRender->GetTransform()->SetLocalScale({ 5120.0f,380.0f,0.0f });

}


void Forest::Update(float _DeltaTime)
{


}

