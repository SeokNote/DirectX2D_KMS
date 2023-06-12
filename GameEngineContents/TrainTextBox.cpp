#include "PrecompileHeader.h"
#include "TrainTextBox.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

TrainTextBox::TrainTextBox()
{
}

TrainTextBox::~TrainTextBox()
{
}

void TrainTextBox::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	TrainTextBoxUI = CreateComponent<GameEngineUIRenderer>(2);
	TrainTextBoxUI->SetTexture("TrainTextBoxBase.png");
	TrainTextBoxUI->GetTransform()->SetLocalPosition({ 0.0f, -250.0f , -100.0f });
	TrainTextBoxUI->GetTransform()->SetLocalScale(TextBoxScale);

	TrainTextBoxUI_S = CreateComponent<GameEngineUIRenderer>(2);
	TrainTextBoxUI_S->SetTexture("SelectTextBoxBase_2.png");
	TrainTextBoxUI_S->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -100.0f });
	TrainTextBoxUI_S->GetTransform()->SetLocalScale(SelectBoxScale);
}

void TrainTextBox::Update(float _Delta)
{
}

