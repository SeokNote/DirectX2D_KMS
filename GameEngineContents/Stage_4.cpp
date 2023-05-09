#include "PrecompileHeader.h"
#include "Stage_4.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage_4::Stage_4()
{
}

Stage_4::~Stage_4()
{
}

void Stage_4::Start()
{
	Stage_4Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage_4Render->SetTexture("Stage_04.png");
	Stage_4Render->GetTransform()->SetLocalPosition({ 10320.0f,0.0f,0.0f });
	Stage_4Render->GetTransform()->SetLocalScale(Stage_4Scale);

}


void Stage_4::Update(float _DeltaTime)
{

}

