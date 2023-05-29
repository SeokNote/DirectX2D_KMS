#include "PrecompileHeader.h"
#include "FoodUI.h"
#include "TempleNpc.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>

FoodUI::FoodUI()
{
}

FoodUI::~FoodUI()
{
}

void FoodUI::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	FoodUIRender = CreateComponent<GameEngineUIRenderer>();
	FoodUIRender->SetTexture("FoodUI.png");
	FoodUIRender->GetTransform()->SetLocalScale(FoodUIScale);

	ExitButtonRender = CreateComponent<GameEngineUIRenderer>();
	ExitButtonRender->SetTexture("ExitButton1_1.png");
	ExitButtonRender->GetTransform()->SetLocalScale(ExitButtonScale);
	ExitButtonRender->GetTransform()->SetLocalPosition(ExitButtonPos);

	ExitButtonSelectRender = CreateComponent<GameEngineUIRenderer>();
	ExitButtonSelectRender->SetTexture("ExitButton1_0.png");
	ExitButtonSelectRender->GetTransform()->SetLocalScale(ExitButtonScale);
	ExitButtonSelectRender->GetTransform()->SetLocalPosition(ExitButtonPos);
	ExitButtonSelectRender->Off();

	FoodUIExitCol = CreateComponent<GameEngineCollision>();
	FoodUIExitCol->GetTransform()->SetLocalPosition(ExitButtonPos);
	FoodUIExitCol->GetTransform()->SetLocalScale(ExitButtonScale);
	FoodUIExitCol->SetOrder(2998);
	//	

}
void FoodUI::Update(float _Delta)
{
	if (FoodUIExitCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ExitButtonRender->Off();
		ExitButtonSelectRender->On();
		if (GameEngineInput::IsDown("ClickMouse"))
		{
			TempleNpcPtr->SetIndexCount(0);
			Death();
		}
	}
	else {
		ExitButtonSelectRender->Off();
		ExitButtonRender->On();
	}
}