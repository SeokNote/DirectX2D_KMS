#include "PrecompileHeader.h"
#include "Stage_3.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage_3::Stage_3()
{
}

Stage_3::~Stage_3()
{
}

void Stage_3::Start()
{
	Stage_3Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage_3Render->SetTexture("Stage_03.png");
	Stage_3Render->GetTransform()->SetLocalPosition({ 7980.0f,0.0f,0.0f });
	Stage_3Render->GetTransform()->SetLocalScale(Stage_3Scale);

}


void Stage_3::Update(float _DeltaTime)
{

}

