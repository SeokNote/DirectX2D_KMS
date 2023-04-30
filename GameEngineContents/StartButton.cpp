#include "PrecompileHeader.h"
#include "StartButton.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


StartButton::StartButton()
{
}

StartButton::~StartButton()
{
}

void StartButton::Start()
{
	StartButtonRender_1 = CreateComponent<GameEngineSpriteRenderer>();
	StartButtonRender_1->SetTexture("PlayOff_Kor.png");
	StartButtonRender_1->GetTransform()->SetLocalPosition({ 0,-100,0 });
	StartButtonRender_1->GetTransform()->SetLocalScale(StartButtonScale);

	StartButtonRender_2 = CreateComponent<GameEngineSpriteRenderer>();
	StartButtonRender_2->SetTexture("PlayOn_Kor.png");
	StartButtonRender_2->GetTransform()->SetLocalPosition({ 0,-100,0 });
	StartButtonRender_2->GetTransform()->SetLocalScale(StartButtonScale);
	StartButtonRender_2->Off();
}


void StartButton::Update(float _DeltaTime)
{

}

