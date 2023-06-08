#include "PrecompileHeader.h"
#include "BuildTextBox.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

BuildTextBox::BuildTextBox() 
{
}

BuildTextBox::~BuildTextBox() 
{
}

void BuildTextBox::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	BuildTextBoxUI = CreateComponent<GameEngineUIRenderer>();
	BuildTextBoxUI->SetTexture("BuildTextBoxBase.png");
	BuildTextBoxUI->GetTransform()->SetLocalPosition({ 0.0f, -250.0f , -100.0f });
	BuildTextBoxUI->GetTransform()->SetLocalScale(TextBoxScale);

	BuildTextBoxUI_S = CreateComponent<GameEngineUIRenderer>();
	BuildTextBoxUI_S->SetTexture("SeletTextBoxBase_1.png");
	BuildTextBoxUI_S->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -100.0f });
	BuildTextBoxUI_S->GetTransform()->SetLocalScale(SelectBoxScale);
}

void BuildTextBox::Update(float _Delta)
{
}

