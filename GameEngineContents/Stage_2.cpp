#include "PrecompileHeader.h"
#include "Stage_2.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage_2::Stage_2()
{
}

Stage_2::~Stage_2()
{
}

void Stage_2::Start()
{
	Stage_2Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage_2Render->SetTexture("Stage_2.png");
	Stage_2Render->GetTransform()->SetLocalPosition({ 5320.0f,0.0f,0.0f });
	Stage_2Render->GetTransform()->SetLocalScale(Stage_2Scale);

}


void Stage_2::Update(float _DeltaTime)
{

}

