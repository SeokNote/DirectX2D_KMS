#include "PrecompileHeader.h"
#include "TrainTextBox.h"
#include "Trainning.h"
#include "Player.h"
#include "AbilityUI.h"
#include "UICountBase.h"
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
	TrainTextBoxUI_S->SetTexture("TextBoxBase_1.png");
	TrainTextBoxUI_S->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -100.0f });
	TrainTextBoxUI_S->GetTransform()->SetLocalScale(SelectBoxScale);

	TrainSelectTextUI = CreateComponent<GameEngineUIRenderer>(2);
	TrainSelectTextUI->SetTexture("SelectText_3.png");
	TrainSelectTextUI->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -200.0f });
	TrainSelectTextUI->GetTransform()->SetLocalScale(SelectTextBoxScale);

	TrainSelectUI = CreateComponent<GameEngineUIRenderer>(2);
	TrainSelectUI->SetTexture("SelectTextBG_1.png");
	TrainSelectUI->GetTransform()->SetLocalScale(SelectTextScale);
	TrainSelectUI->Off();

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
bool TrainningCheck = false;
void TrainTextBox::Update(float _Delta)
{
	if (ButtonCol_0->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		TrainSelectUI->On();
		TrainSelectUI->GetTransform()->SetLocalPosition({ 480.0f, -30.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {

			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();
		}
	}
	else if (ButtonCol_1->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		TrainSelectUI->On();
		TrainSelectUI->GetTransform()->SetLocalPosition({ 480.0f, 30.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {
			int a = 0;
			if (TrainningCheck == false)
			{
			  //¾îºô¸®Æ¼ UI¶ç¿ì±â
				AbilityUIPtr = GetLevel()->CreateActor<AbilityUI>();
			}
			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();

		}
	}

	else if (ButtonCol_2->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		TrainSelectUI->On();
		TrainSelectUI->GetTransform()->SetLocalPosition({ 480.0f, -93.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {
			int a = 0;
			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();

		}
	}
	else {
		TrainSelectUI->Off();
	}	

}

