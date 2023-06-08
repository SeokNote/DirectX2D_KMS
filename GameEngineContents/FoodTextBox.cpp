#include "PrecompileHeader.h"
#include "FoodTextBox.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

FoodTextBox::FoodTextBox()
{
}

FoodTextBox::~FoodTextBox()
{
}

void FoodTextBox::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	FoodTextBoxUI = CreateComponent<GameEngineUIRenderer>();
	FoodTextBoxUI->SetTexture("FoodTextBoxBase.png");
	FoodTextBoxUI->GetTransform()->SetLocalPosition({ 0.0f, -250.0f , -100.0f });
	FoodTextBoxUI->GetTransform()->SetLocalScale(TextBoxScale);

	FoodTextBoxUI_S = CreateComponent<GameEngineUIRenderer>();
	FoodTextBoxUI_S->SetTexture("SelectTextBoxBase.png");
	FoodTextBoxUI_S->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -100.0f });
	FoodTextBoxUI_S->GetTransform()->SetLocalScale(SelectBoxScale);
}

void FoodTextBox::Update(float _Delta)
{
}

