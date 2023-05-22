#include "PrecompileHeader.h"
#include "Stage2_1.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage2_1::Stage2_1()
{
}

Stage2_1::~Stage2_1()
{
}

void Stage2_1::Start()
{
	Stage2_1Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage2_1Render->SetTexture("TunakReady_1.png");
	Stage2_1Render->GetTransform()->SetLocalPosition({ 13528.0f,0.0f,0.0f });
	Stage2_1Render->GetTransform()->SetLocalScale(Stage2_1Scale);

}


void Stage2_1::Update(float _DeltaTime)
{

}

//12888+ 13528