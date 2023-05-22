#include "PrecompileHeader.h"
#include "StartButton.h"
#include "PlayStartWindow.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>

#include "TitleMouse.h"

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

	StartButtonCollsion = CreateComponent<GameEngineCollision>();
	StartButtonCollsion->GetTransform()->SetLocalPosition({ 0,-100,0 });
	StartButtonCollsion->GetTransform()->SetLocalScale(StartButtonScale);
	StartButtonCollsion->SetOrder(2999);
}


void StartButton::Update(float _DeltaTime)
{

	if (StartButtonCollsion->Collision(3000, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (GameEngineInput::IsDown("ClickMouse")) {
			GetLevel()->CreateActor<PlayStartWindow>();
			int a = 0;
		}
		StartButtonRender_1->Off();
		StartButtonRender_2->On();
	}
	else {
		StartButtonRender_1->On();
		StartButtonRender_2->Off();
	}
}

