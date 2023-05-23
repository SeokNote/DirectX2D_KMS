#include "PrecompileHeader.h"
#include "Stage_1.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage_1::Stage_1()
{
}

Stage_1::~Stage_1()
{
}

void Stage_1::Start()
{
	Stage_1Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage_1Render->SetTexture("Stage_1.png");
	Stage_1Render->GetTransform()->SetLocalPosition({3300.0f,0.0f,-100.0f });
	Stage_1Render->GetTransform()->SetLocalScale(Stage_1Scale);

}


void Stage_1::Update(float _DeltaTime)
{

}

