#include "PrecompileHeader.h"
#include "ShopTextBox.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

ShopTextBox::ShopTextBox()
{
}

ShopTextBox::~ShopTextBox()
{
}

void ShopTextBox::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	ShopTextBoxUI = CreateComponent<GameEngineUIRenderer>();
	ShopTextBoxUI->SetTexture("ShopTextBoxBase.png");
	ShopTextBoxUI->GetTransform()->SetLocalPosition({ 0.0f, -250.0f , -100.0f });
	ShopTextBoxUI->GetTransform()->SetLocalScale(TextBoxScale);

	ShopTextBoxUI_S = CreateComponent<GameEngineUIRenderer>();
	ShopTextBoxUI_S->SetTexture("SelectTextBoxBase.png");
	ShopTextBoxUI_S->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -100.0f });
	ShopTextBoxUI_S->GetTransform()->SetLocalScale(SelectBoxScale);
}

void ShopTextBox::Update(float _Delta)
{
}

