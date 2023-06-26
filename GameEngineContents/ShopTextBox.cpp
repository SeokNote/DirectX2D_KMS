#include "PrecompileHeader.h"
#include "ShopTextBox.h"
#include "Player.h"
#include "UICountBase.h"
#include "ShopUI.h"
#include "InventoryUI.h"
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


	ShopTextBoxUI = CreateComponent<GameEngineUIRenderer>(2);
	ShopTextBoxUI->SetTexture("ShopTextBoxBase.png");
	ShopTextBoxUI->GetTransform()->SetLocalPosition({ 0.0f, -250.0f , -100.0f });
	ShopTextBoxUI->GetTransform()->SetLocalScale(TextBoxScale);

	ShopTextBoxUI_S = CreateComponent<GameEngineUIRenderer>(2);
	ShopTextBoxUI_S->SetTexture("TextBoxBase_1.png");
	ShopTextBoxUI_S->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -100.0f });
	ShopTextBoxUI_S->GetTransform()->SetLocalScale(SelectBoxScale);

	ShopSelectTextUI = CreateComponent<GameEngineUIRenderer>(2);
	ShopSelectTextUI->SetTexture("SelectText_2.png");
	ShopSelectTextUI->GetTransform()->SetLocalPosition({ 480.0f, -35.0f , -200.0f });
	ShopSelectTextUI->GetTransform()->SetLocalScale(SelectTextBoxScale);

	ShopSelectUI = CreateComponent<GameEngineUIRenderer>(2);
	ShopSelectUI->SetTexture("SelectTextBG_1.png");
	ShopSelectUI->GetTransform()->SetLocalScale(SelectTextScale);
	ShopSelectUI->Off();

	ButtonCol_0 = CreateComponent<GameEngineCollision>();
	ButtonCol_0->GetTransform()->SetLocalScale(SelectTextScale);
	ButtonCol_0->GetTransform()->SetLocalPosition({ 480.0f, -30.0f ,0.0f });
	ButtonCol_0->SetOrder(3011);

	ButtonCol_1 = CreateComponent<GameEngineCollision>();
	ButtonCol_1->GetTransform()->SetLocalScale(SelectTextScale);
	ButtonCol_1->GetTransform()->SetLocalPosition({ 480.0f, 30.0f , 0.0f });
	ButtonCol_1->SetOrder(3011);

	ButtonCol_2 = CreateComponent<GameEngineCollision>();
	ButtonCol_2->GetTransform()->SetLocalScale(SelectTextScale);
	ButtonCol_2->GetTransform()->SetLocalPosition({ 480.0f, -93.0f ,0.0f });
	ButtonCol_2->SetOrder(3011);
}
bool ShopCheck = false;
void ShopTextBox::Update(float _Delta)
{
	if (ButtonCol_0->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ShopSelectUI->On();
		ShopSelectUI->GetTransform()->SetLocalPosition({ 480.0f, -30.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {

			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();
		}
	}
	else if (ButtonCol_1->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ShopSelectUI->On();
		ShopSelectUI->GetTransform()->SetLocalPosition({ 480.0f, 30.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {
			int a = 0;
			if (ShopCheck == false)
			{
				ShopUIPtr = GetLevel()->CreateActor<ShopUI>();
				ShopCheck = true;
			}
			Player::MainPlayer->SetUICount(1);
			UICountBase::MainUICountBase->SetUICount(1);
			Death();
			ShopCheck = false;

		}
	}

	else if (ButtonCol_2->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ShopSelectUI->On();
		ShopSelectUI->GetTransform()->SetLocalPosition({ 480.0f, -93.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {
			int a = 0;
			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();

		}
	}
	else {
		ShopSelectUI->Off();
	}	

}

