#include "PrecompileHeader.h"
#include "Town.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Town::Town()
{
}

Town::~Town()
{
}

void Town::Start()
{
	TownRender = CreateComponent<GameEngineSpriteRenderer>();
	TownRender->SetTexture("Town_0.png");
	TownRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	TownRender->GetTransform()->SetLocalScale(TownScale);

}


void Town::Update(float _DeltaTime)
{

}

