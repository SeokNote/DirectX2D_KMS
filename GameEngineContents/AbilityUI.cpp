#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "AbilityUI.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
AbilityUI::AbilityUI() 
{
}

AbilityUI::~AbilityUI() 
{
}

void AbilityUI::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	AbilityBaseBG = CreateComponent<GameEngineUIRenderer>(2);
	AbilityBaseBG->SetTexture("PlayWindowBG.png");
	AbilityBaseBG->ColorOptionValue.MulColor.a = 0.8f;
	AbilityBaseBG->GetTransform()->SetLocalPosition({ 0.0f,0.0f,-100.0f });
	AbilityBaseBG->GetTransform()->SetLocalScale(AbilityUIScale);

	AbilityBase = CreateComponent<GameEngineUIRenderer>(2);
	AbilityBase->SetTexture("AbilityBase_1.png");
	AbilityBase->GetTransform()->SetLocalPosition({ 0.0f,0.0f,-200.0f });
	AbilityBase->GetTransform()->SetLocalScale(AbilityUIScale);

	//버튼
	Button_RedRender = CreateComponent<GameEngineUIRenderer>(2);
	Button_RedRender->SetTexture("AbilityBackgroundButton_Wrath.png");
	Button_RedRender->GetTransform()->SetLocalPosition(Button_RedPos);
	Button_RedRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_RedRender->Off();

	Button_GreenRender = CreateComponent<GameEngineUIRenderer>(2);
	Button_GreenRender->SetTexture("AbilityBackgroundButton_Swiftness.png");
	Button_GreenRender->GetTransform()->SetLocalPosition(Button_GreenPos);
	Button_GreenRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_GreenRender->Off();

	Button_WhiteRender = CreateComponent<GameEngineUIRenderer>(2);
	Button_WhiteRender->SetTexture("AbilityBackgroundButton_Patience.png");
	Button_WhiteRender->GetTransform()->SetLocalPosition(Button_WhitePos);
	Button_WhiteRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_WhiteRender->Off();

	Button_BlueRender = CreateComponent<GameEngineUIRenderer>(2);
	Button_BlueRender->SetTexture("AbilityBackgroundButton_Arcane.png");
	Button_BlueRender->GetTransform()->SetLocalPosition(Button_BluePos);
	Button_BlueRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_BlueRender->Off();

	Button_YellowRender = CreateComponent<GameEngineUIRenderer>(2);
	Button_YellowRender->SetTexture("AbilityBackgroundButton_Greed.png");
	Button_YellowRender->GetTransform()->SetLocalPosition(Button_YellowPos);
	Button_YellowRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_YellowRender->Off();
	{
		//collision
		Button_RedCol = CreateComponent<GameEngineCollision>();
		Button_RedCol->GetTransform()->SetLocalScale(Button_Scale);
		Button_RedCol->GetTransform()->SetLocalPosition(Button_RedPos);
		Button_RedCol->SetOrder(3002);

		Button_GreenCol = CreateComponent<GameEngineCollision>();
		Button_GreenCol->GetTransform()->SetLocalScale(Button_Scale);
		Button_GreenCol->GetTransform()->SetLocalPosition(Button_GreenPos);
		Button_GreenCol->SetOrder(3002);

		Button_WhiteCol = CreateComponent<GameEngineCollision>();
		Button_WhiteCol->GetTransform()->SetLocalScale(Button_Scale);
		Button_WhiteCol->GetTransform()->SetLocalPosition(Button_WhitePos);
		Button_WhiteCol->SetOrder(3002);

		Button_BlueCol = CreateComponent<GameEngineCollision>();
		Button_BlueCol->GetTransform()->SetLocalScale(Button_Scale);
		Button_BlueCol->GetTransform()->SetLocalPosition(Button_BluePos);
		Button_BlueCol->SetOrder(3002);

		Button_YellowCol = CreateComponent<GameEngineCollision>();
		Button_YellowCol->GetTransform()->SetLocalScale(Button_Scale);
		Button_YellowCol->GetTransform()->SetLocalPosition(Button_YellowPos);
		Button_YellowCol->SetOrder(3002);
	}
}

void AbilityUI::Update(float _Delta)
{
	if (Button_RedCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_RedRender->On();
		if (GameEngineInput::IsDown("ClickMouse")) 
		{
			//어빌리티 스텟 올라가는 함수
		}
	}
	else 
	{
		Button_RedRender->Off();
	}
	if (Button_GreenCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_GreenRender->On();
		if (GameEngineInput::IsDown("ClickMouse")) {

			//어빌리티 스텟 올라가는 함수

		}
	}
	else
	{
		Button_GreenRender->Off();
	}
	if (Button_WhiteCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_WhiteRender->On();
		if (GameEngineInput::IsDown("ClickMouse")) {

			//어빌리티 스텟 올라가는 함수

		}
	}
	else
	{
		Button_WhiteRender->Off();
	}
	if (Button_BlueCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_BlueRender->On();
		if (GameEngineInput::IsDown("ClickMouse")) {

			//어빌리티 스텟 올라가는 함수

		}
	}
	else
	{
		Button_BlueRender->Off();
	}
	if (Button_YellowCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_YellowRender->On();
		if (GameEngineInput::IsDown("ClickMouse")) {

			//어빌리티 스텟 올라가는 함수

		}
	}
	else
	{
		Button_YellowRender->Off();
	}
	if (GameEngineInput::IsDown("ESC"))
	{
		Death();
	}
}

