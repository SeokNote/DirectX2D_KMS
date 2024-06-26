#include "PrecompileHeader.h"
#include "PlayLevel.h"
#include "FoodTextBox.h"
#include "Player.h"
#include "UICountBase.h"
#include "UIFontRender.h"
#include "FoodUI.h"
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


	FoodTextBoxUI = CreateComponent<GameEngineUIRenderer>(170);
	FoodTextBoxUI->SetTexture("FoodTextBoxBase.png");
	FoodTextBoxUI->GetTransform()->SetLocalPosition({ 0.0f, -250.0f , -100.0f });
	FoodTextBoxUI->GetTransform()->SetLocalScale(TextBoxScale);

	FoodTextBoxUI_S = CreateComponent<GameEngineUIRenderer>(170);
	FoodTextBoxUI_S->SetTexture("TextBoxBase_1.png");
	FoodTextBoxUI_S->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -100.0f });
	FoodTextBoxUI_S->GetTransform()->SetLocalScale(SelectBoxScale);

	FoodSelectTextUI = CreateComponent<GameEngineUIRenderer>(171);
	FoodSelectTextUI->SetTexture("SelectText_2.png");
	FoodSelectTextUI->GetTransform()->SetLocalPosition({ 480.0f, -35.0f , -200.0f });
	FoodSelectTextUI->GetTransform()->SetLocalScale(SelectTextBoxScale);

	FoodSelectUI = CreateComponent<GameEngineUIRenderer>(2);
	FoodSelectUI->SetTexture("SelectTextBG_1.png");
	FoodSelectUI->GetTransform()->SetLocalScale(SelectTextScale);
	FoodSelectUI->Off();

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

	TextStrting = CreateComponent<UIFontRender>(172);
	TextStrting->SetFont("Aa카시오페아");
	TextStrting->SetColor(float4::White);
	TextStrting->SetScale(40);
	TextStrting->SetFontFlag(FW1_LEFT);
	TextStrting->GetTransform()->SetLocalPosition({ -590.0f,-210.0f,-100.0f });

}
bool FoodCheck = false;
void FoodTextBox::Update(float _Delta)
{
	DelayTime += _Delta;
	if (DelayTime > 0.1f && FirstDialog.size() >= count)
	{
		GameEngineSound::Play("KeyBord.wav");
		TextStrting->SetText(FirstDialog.substr(0, count));
		count += 2;
		DelayTime = 0.0f;
	}
	if (ButtonCol_0->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		FoodSelectUI->On();
		FoodSelectUI->GetTransform()->SetLocalPosition({ 480.0f, -30.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {

			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();
		}
	}
	else if (ButtonCol_1->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		FoodSelectUI->On();
		FoodSelectUI->GetTransform()->SetLocalPosition({ 480.0f, 30.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {
			int a = 0;
			if (FoodCheck == false)
			{
				//레벨에서 돌리는 bgm을 끄고 
				GetLevel()->CreateActor<FoodUI>();
				FoodCheck = true;

			}
			Player::MainPlayer->SetUICount(1);
			UICountBase::MainUICountBase->SetUICount(1);
			Death();
			FoodCheck = false;

		}
	}

	else if (ButtonCol_2->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		FoodSelectUI->On();
		FoodSelectUI->GetTransform()->SetLocalPosition({ 480.0f, -93.0f ,-150.0f });
		if (GameEngineInput::IsDown("ClickMouse")) {
			int a = 0;
			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();

		}
	}
	else {
		FoodSelectUI->Off();
	}

}

