#include "PrecompileHeader.h"
#include "Stage3_1.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage3_1::Stage3_1()
{
}

Stage3_1::~Stage3_1()
{
}

void Stage3_1::Start()
{
	Stage3_1Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage3_1Render->SetTexture("Stage3_1.png");
	Stage3_1Render->GetTransform()->SetLocalPosition({ 16768.0f,0.0f,0.0f });
	Stage3_1Render->GetTransform()->SetLocalScale(Stage3_1Scale);

}


void Stage3_1::Update(float _DeltaTime)
{

}

//12888+ 13528