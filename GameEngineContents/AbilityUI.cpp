#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "AbilityUI.h"
#include "Player.h"
#include "UIFontRender.h"
#include "ContentButton.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
AbilityUI* AbilityUI::AbilityUIPtr = nullptr;
AbilityUI::AbilityUI() 
{
	AbilityUIPtr = this;
}

AbilityUI::~AbilityUI() 
{
}

void AbilityUI::PlusStat()
{
	if (IsValue == false)
	{

		IsValue = true;
	}
	else if (ResetValue == true)
	{
		Player::MainPlayer->GetData().SetAttackSpeed(Player::MainPlayer->GetData().GetAttackSpeed() - A_AttackSpeed);
		Player::MainPlayer->GetData().SetMoveSpeed(Player::MainPlayer->GetData().GetMoveSpeed() - A_Speed);
		Player::MainPlayer->GetData().SetDefense(Player::MainPlayer->GetData().GetDefense() - A_Aamor);
		Player::MainPlayer->GetData().SetCriticalChance(Player::MainPlayer->GetData().GetCriticalChance() - A_Cri);
		Player::MainPlayer->GetData().SetEvasion(Player::MainPlayer->GetData().GetEvasion() - static_cast<int>(A_Evasion));
		Player::MainPlayer->GetData().SetPlayerMaxHP(Player::MainPlayer->GetData().GetPlayerMaxHP() - A_MaxHP);
		ResetValue = false;
	}



}

void AbilityUI::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	AbilityBaseBG = CreateComponent<GameEngineUIRenderer>(150);
	AbilityBaseBG->SetTexture("PlayWindowBG.png");
	AbilityBaseBG->ColorOptionValue.MulColor.a = 0.8f;
	AbilityBaseBG->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	AbilityBaseBG->GetTransform()->SetLocalScale(AbilityUIScale);

	AbilityBase = CreateComponent<GameEngineUIRenderer>(150);
	AbilityBase->SetTexture("AbilityBase_1.png");
	AbilityBase->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	AbilityBase->GetTransform()->SetLocalScale(AbilityUIScale);

	//버튼
	Button_RedRender = CreateComponent<GameEngineUIRenderer>(151);
	Button_RedRender->SetTexture("AbilityBackgroundButton_Wrath.png");
	Button_RedRender->GetTransform()->SetLocalPosition(Button_RedPos);
	Button_RedRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_RedRender->Off();

	Button_GreenRender = CreateComponent<GameEngineUIRenderer>(151);
	Button_GreenRender->SetTexture("AbilityBackgroundButton_Swiftness.png");
	Button_GreenRender->GetTransform()->SetLocalPosition(Button_GreenPos);
	Button_GreenRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_GreenRender->Off();

	Button_WhiteRender = CreateComponent<GameEngineUIRenderer>(151);
	Button_WhiteRender->SetTexture("AbilityBackgroundButton_Patience.png");
	Button_WhiteRender->GetTransform()->SetLocalPosition(Button_WhitePos);
	Button_WhiteRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_WhiteRender->Off();

	Button_BlueRender = CreateComponent<GameEngineUIRenderer>(151);
	Button_BlueRender->SetTexture("AbilityBackgroundButton_Arcane.png");
	Button_BlueRender->GetTransform()->SetLocalPosition(Button_BluePos);
	Button_BlueRender->GetTransform()->SetLocalScale(Button_Scale);
	Button_BlueRender->Off();

	Button_YellowRender = CreateComponent<GameEngineUIRenderer>(151);
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
	FontCreate();
	ButtonCreate();
}

void AbilityUI::Update(float _Delta)
{
	SetCollision();
	SetFont();
	StatCalCulation();
}


void AbilityUI::SetCollision()
{
	if (Button_RedCol->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{

		Button_RedRender->On();
		if (Point != 0 && GameEngineInput::IsUp("ClickMouse"))
		{

			Point--;
			Anger++;
			//어빌리티 스텟 올라가는 함수
		}
	}
	else
	{
		Button_RedRender->Off();
	}
	if (Button_GreenCol->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_GreenRender->On();
		if (Point != 0 && GameEngineInput::IsUp("ClickMouse")) {
			Fast++;
			Player::MainPlayer->GetData().SetAttackSpeed(Player::MainPlayer->GetData().GetAttackSpeed() + A_AttackSpeed);
			Player::MainPlayer->GetData().SetMoveSpeed(Player::MainPlayer->GetData().GetMoveSpeed() + A_Speed);

			Point--;
			//어빌리티 스텟 올라가는 함수

		}
	}
	else
	{
		Button_GreenRender->Off();
	}
	if (Button_WhiteCol->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_WhiteRender->On();
		if (Point != 0 && GameEngineInput::IsUp("ClickMouse")) {
			Patience++;
			Player::MainPlayer->GetData().SetDefense(Player::MainPlayer->GetData().GetDefense() + A_Aamor);
			Point--;
			//어빌리티 스텟 올라가는 함수

		}
	}
	else
	{
		Button_WhiteRender->Off();
	}
	if (Button_BlueCol->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_BlueRender->On();
		if (Point != 0 && GameEngineInput::IsUp("ClickMouse")) {
			Mystery++;
			Player::MainPlayer->GetData().SetCriticalChance(Player::MainPlayer->GetData().GetCriticalChance() + A_Cri);
			Player::MainPlayer->GetData().SetEvasion(Player::MainPlayer->GetData().GetEvasion() + static_cast<int>(A_Evasion));
			Point--;
			//어빌리티 스텟 올라가는 함수

		}
	}
	else
	{
		Button_BlueRender->Off();
	}
	if (Button_YellowCol->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Button_YellowRender->On();
		if (Point != 0 && GameEngineInput::IsUp("ClickMouse")) {
			Avarice++;
			Player::MainPlayer->GetData().SetPlayerMaxHP(Player::MainPlayer->GetData().GetPlayerMaxHP() + 2);
			Point--;
			//어빌리티 스텟 올라가는 함수

		}
	}
	else
	{
		Button_YellowRender->Off();
	}
	if (GameEngineInput::IsUp("ESC"))
	{
	//	PlusStat();
		Off();
	}
}

void AbilityUI::FontCreate()
{
	AngerFont = CreateComponent<UIFontRender>(153);
	AngerFont->SetFont(font);
	AngerFont->SetFontFlag(FW1_CENTER);
	AngerFont->SetScale(48);
	AngerFont->SetColor(AngerColor);
	AngerFont->GetTransform()->SetLocalPosition({ -500.0f,40.0f,0.0f });
	
	AngerFontBG_0 = CreateComponent<UIFontRender>(152);
	AngerFontBG_0->SetFont(font);
	AngerFontBG_0->SetFontFlag(FW1_CENTER);
	AngerFontBG_0->SetScale(48);
	AngerFontBG_0->SetColor(float4::Black);
	AngerFontBG_0->GetTransform()->SetLocalPosition({ -500.0f,43.0f,0.0f });
	
	AngerFontBG_3 = CreateComponent<UIFontRender>(152);
	AngerFontBG_3->SetFont(font);
	AngerFontBG_3->SetFontFlag(FW1_CENTER);
	AngerFontBG_3->SetScale(48);
	AngerFontBG_3->SetColor(float4::Black);
	AngerFontBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	AngerFontBG_3->GetTransform()->SetLocalPosition({ -503.0f,40.0f,0.0f });
	
	AngerFontBG_1 = CreateComponent<UIFontRender>(152);
	AngerFontBG_1->SetFont(font);
	AngerFontBG_1->SetFontFlag(FW1_CENTER);
	AngerFontBG_1->SetScale(48);
	AngerFontBG_1->SetColor(float4::Black);
	AngerFontBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	AngerFontBG_1->GetTransform()->SetLocalPosition({ -497.0f,40.0f,0.0f });
	
	AngerFontBG_2 = CreateComponent<UIFontRender>(152);
	AngerFontBG_2->SetFont(font);
	AngerFontBG_2->SetFontFlag(FW1_CENTER);
	AngerFontBG_2->SetScale(48);
	AngerFontBG_2->SetColor(float4::Black);
	AngerFontBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	AngerFontBG_2->GetTransform()->SetLocalPosition({ -500.0f,37.0f,0.0f });

	FastFont = CreateComponent<UIFontRender>(153);
	FastFont->SetFont(font);
	FastFont->SetFontFlag(FW1_CENTER);
	FastFont->SetScale(48);
	FastFont->SetColor(FastColor);
	FastFont->GetTransform()->SetLocalPosition({ -235.0f,40.0f,0.0f });

	FastFontBG_0 = CreateComponent<UIFontRender>(152);
	FastFontBG_0->SetFont(font);
	FastFontBG_0->SetFontFlag(FW1_CENTER);
	FastFontBG_0->SetScale(48);
	FastFontBG_0->SetColor(float4::Black);
	FastFontBG_0->GetTransform()->SetLocalPosition({ -235.0f,43.0f,0.0f });

	FastFontBG_3 = CreateComponent<UIFontRender>(152);
	FastFontBG_3->SetFont(font);
	FastFontBG_3->SetFontFlag(FW1_CENTER);
	FastFontBG_3->SetScale(48);
	FastFontBG_3->SetColor(float4::Black);
	FastFontBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	FastFontBG_3->GetTransform()->SetLocalPosition({ -238.0f,40.0f,0.0f });

	FastFontBG_1 = CreateComponent<UIFontRender>(152);
	FastFontBG_1->SetFont(font);
	FastFontBG_1->SetFontFlag(FW1_CENTER);
	FastFontBG_1->SetScale(48);
	FastFontBG_1->SetColor(float4::Black);
	FastFontBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	FastFontBG_1->GetTransform()->SetLocalPosition({ -232.0f,40.0f,0.0f });
	
	FastFontBG_2 = CreateComponent<UIFontRender>(152);
	FastFontBG_2->SetFont(font);
	FastFontBG_2->SetFontFlag(FW1_CENTER);
	FastFontBG_2->SetScale(48);
	FastFontBG_2->SetColor(float4::Black);
	FastFontBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	FastFontBG_2->GetTransform()->SetLocalPosition({ -235.0f,37.0f,0.0f });

	PatienceFont = CreateComponent<UIFontRender>(153);
	PatienceFont->SetFont(font);
	PatienceFont->SetFontFlag(FW1_CENTER);
	PatienceFont->SetScale(48);
	PatienceFont->SetColor(PatienceColor);
	PatienceFont->GetTransform()->SetLocalPosition({ 22.0f,40.0f,0.0f });

	PatienceFontBG_0 = CreateComponent<UIFontRender>(152);
	PatienceFontBG_0->SetFont(font);
	PatienceFontBG_0->SetFontFlag(FW1_CENTER);
	PatienceFontBG_0->SetScale(48);
	PatienceFontBG_0->SetColor(float4::Black);
	PatienceFontBG_0->GetTransform()->SetLocalPosition({ 22.0f,43.0f,0.0f });
	
	PatienceFontBG_3 = CreateComponent<UIFontRender>(152);
	PatienceFontBG_3->SetFont(font);
	PatienceFontBG_3->SetFontFlag(FW1_CENTER);
	PatienceFontBG_3->SetScale(48);
	PatienceFontBG_3->SetColor(float4::Black);
	PatienceFontBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PatienceFontBG_3->GetTransform()->SetLocalPosition({ 25.0f,40.0f,0.0f });
	
	PatienceFontBG_1 = CreateComponent<UIFontRender>(152);
	PatienceFontBG_1->SetFont(font);
	PatienceFontBG_1->SetFontFlag(FW1_CENTER);
	PatienceFontBG_1->SetScale(48);
	PatienceFontBG_1->SetColor(float4::Black);
	PatienceFontBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PatienceFontBG_1->GetTransform()->SetLocalPosition({ 19.0f,40.0f,0.0f });
	
	PatienceFontBG_2 = CreateComponent<UIFontRender>(152);
	PatienceFontBG_2->SetFont(font);
	PatienceFontBG_2->SetFontFlag(FW1_CENTER);
	PatienceFontBG_2->SetScale(48);
	PatienceFontBG_2->SetColor(float4::Black);
	PatienceFontBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PatienceFontBG_2->GetTransform()->SetLocalPosition({ 22.0f,37.0f,0.0f });

	MysteryFont = CreateComponent<UIFontRender>(153);
	MysteryFont->SetFont(font);
	MysteryFont->SetFontFlag(FW1_CENTER);
	MysteryFont->SetScale(48);
	MysteryFont->SetColor(MysteryColor);
	MysteryFont->GetTransform()->SetLocalPosition({ 270.0f,40.0f,0.0f });

	MysteryFontBG_0 = CreateComponent<UIFontRender>(152);
	MysteryFontBG_0->SetFont(font);
	MysteryFontBG_0->SetFontFlag(FW1_CENTER);
	MysteryFontBG_0->SetScale(48);
	MysteryFontBG_0->SetColor(float4::Black);
	MysteryFontBG_0->GetTransform()->SetLocalPosition({ 270.0f,43.0f,0.0f });
	
	MysteryFontBG_3 = CreateComponent<UIFontRender>(152);
	MysteryFontBG_3->SetFont(font);
	MysteryFontBG_3->SetFontFlag(FW1_CENTER);
	MysteryFontBG_3->SetScale(48);
	MysteryFontBG_3->SetColor(float4::Black);
	MysteryFontBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	MysteryFontBG_3->GetTransform()->SetLocalPosition({ 273.0f,40.0f,0.0f });
	
	MysteryFontBG_1 = CreateComponent<UIFontRender>(152);
	MysteryFontBG_1->SetFont(font);
	MysteryFontBG_1->SetFontFlag(FW1_CENTER);
	MysteryFontBG_1->SetScale(48);
	MysteryFontBG_1->SetColor(float4::Black);
	MysteryFontBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	MysteryFontBG_1->GetTransform()->SetLocalPosition({ 267.0f,40.0f,0.0f });
	
	MysteryFontBG_2 = CreateComponent<UIFontRender>(152);
	MysteryFontBG_2->SetFont(font);
	MysteryFontBG_2->SetFontFlag(FW1_CENTER);
	MysteryFontBG_2->SetScale(48);
	MysteryFontBG_2->SetColor(float4::Black);
	MysteryFontBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	MysteryFontBG_2->GetTransform()->SetLocalPosition({ 270.0f,37.0f,0.0f });

	AvariceFont = CreateComponent<UIFontRender>(153);
	AvariceFont->SetFont(font);
	AvariceFont->SetFontFlag(FW1_CENTER);
	AvariceFont->SetScale(48);
	AvariceFont->SetColor(AvariceColor);
	AvariceFont->GetTransform()->SetLocalPosition({ 525.0f,40.0f,0.0f });

	AvariceFontBG_0 = CreateComponent<UIFontRender>(152);
	AvariceFontBG_0->SetFont(font);
	AvariceFontBG_0->SetFontFlag(FW1_CENTER);
	AvariceFontBG_0->SetScale(48);
	AvariceFontBG_0->SetColor(float4::Black);
	AvariceFontBG_0->GetTransform()->SetLocalPosition({ 525.0f,43.0f,0.0f });
	
	AvariceFontBG_3 = CreateComponent<UIFontRender>(152);
	AvariceFontBG_3->SetFont(font);
	AvariceFontBG_3->SetFontFlag(FW1_CENTER);
	AvariceFontBG_3->SetScale(48);
	AvariceFontBG_3->SetColor(float4::Black);
	AvariceFontBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	AvariceFontBG_3->GetTransform()->SetLocalPosition({ 528.0f,40.0f,0.0f });
	
	AvariceFontBG_1 = CreateComponent<UIFontRender>(152);
	AvariceFontBG_1->SetFont(font);
	AvariceFontBG_1->SetFontFlag(FW1_CENTER);
	AvariceFontBG_1->SetScale(48);
	AvariceFontBG_1->SetColor(float4::Black);
	AvariceFontBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	AvariceFontBG_1->GetTransform()->SetLocalPosition({ 522.0f,40.0f,0.0f });
	
	AvariceFontBG_2 = CreateComponent<UIFontRender>(152);
	AvariceFontBG_2->SetFont(font);
	AvariceFontBG_2->SetFontFlag(FW1_CENTER);
	AvariceFontBG_2->SetScale(48);
	AvariceFontBG_2->SetColor(float4::Black);
	AvariceFontBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	AvariceFontBG_2->GetTransform()->SetLocalPosition({ 525.0f,37.0f,0.0f });

	AngerValue = CreateComponent<UIFontRender>(153);
	AngerValue->SetFont(font);
	AngerValue->SetFontFlag(FW1_RIGHT);
	AngerValue->SetScale(18);
	AngerValue->SetColor(float4::Green);
	AngerValue->GetTransform()->SetLocalPosition({ -500.0f,-100.0f,0.0f });

	FastValue = CreateComponent<UIFontRender>(152);
	FastValue->SetFont(font);
	FastValue->SetFontFlag(FW1_RIGHT);
	FastValue->SetScale(18);
	FastValue->SetColor(float4::Green);
	FastValue->GetTransform()->SetLocalPosition({ -235.0f,-89.0f,0.0f });

	FastValue1 = CreateComponent<UIFontRender>(152);
	FastValue1->SetFont(font);
	FastValue1->SetFontFlag(FW1_RIGHT);
	FastValue1->SetScale(18);
	FastValue1->SetColor(float4::Green);
	FastValue1->GetTransform()->SetLocalPosition({ -235.0f,-112.0f,0.0f });

	PatienceValue = CreateComponent<UIFontRender>(152);
	PatienceValue->SetFont(font);
	PatienceValue->SetFontFlag(FW1_RIGHT);
	PatienceValue->SetScale(18);
	PatienceValue->SetColor(float4::Green);
	PatienceValue->GetTransform()->SetLocalPosition({ 15.0f,-100.0f,0.0f });

	MysteryValue = CreateComponent<UIFontRender>(152);
	MysteryValue->SetFont(font);
	MysteryValue->SetFontFlag(FW1_RIGHT);
	MysteryValue->SetScale(18);
	MysteryValue->SetColor(float4::Green);
	MysteryValue->GetTransform()->SetLocalPosition({ 267.0f,-89.0f,0.0f });
	
	MysteryValue1 = CreateComponent<UIFontRender>(152);
	MysteryValue1->SetFont(font);
	MysteryValue1->SetFontFlag(FW1_RIGHT);
	MysteryValue1->SetScale(18);
	MysteryValue1->SetColor(float4::Green);
	MysteryValue1->GetTransform()->SetLocalPosition({ 282.0f,-109.0f,0.0f });

	AvariceValue = CreateComponent<UIFontRender>(152);
	AvariceValue->SetFont(font);
	AvariceValue->SetFontFlag(FW1_RIGHT);
	AvariceValue->SetScale(18);
	AvariceValue->SetColor(float4::Green);
	AvariceValue->GetTransform()->SetLocalPosition({ 510.0f,-99.0f,0.0f });
}

void AbilityUI::SetFont()
{
	AngerFont->SetText(std::to_string(Anger));
	AngerFontBG_0->SetText(std::to_string(Anger));
	AngerFontBG_1->SetText(std::to_string(Anger));
	AngerFontBG_2->SetText(std::to_string(Anger));
	AngerFontBG_3->SetText(std::to_string(Anger));

	FastFont->SetText(std::to_string(Fast));
	FastFontBG_0->SetText(std::to_string(Fast));
	FastFontBG_1->SetText(std::to_string(Fast));
	FastFontBG_2->SetText(std::to_string(Fast));
	FastFontBG_3->SetText(std::to_string(Fast));

	PatienceFont->SetText(std::to_string(Patience));
	PatienceFontBG_0->SetText(std::to_string(Patience));
	PatienceFontBG_1->SetText(std::to_string(Patience));
	PatienceFontBG_2->SetText(std::to_string(Patience));
	PatienceFontBG_3->SetText(std::to_string(Patience)); 

	MysteryFont->SetText(std::to_string(Mystery));
	MysteryFontBG_0->SetText(std::to_string(Mystery));
	MysteryFontBG_1->SetText(std::to_string(Mystery));
	MysteryFontBG_2->SetText(std::to_string(Mystery));
	MysteryFontBG_3->SetText(std::to_string(Mystery));

	AvariceFont->SetText(std::to_string(Avarice));
	AvariceFontBG_0->SetText(std::to_string(Avarice));
	AvariceFontBG_1->SetText(std::to_string(Avarice));
	AvariceFontBG_2->SetText(std::to_string(Avarice));
	AvariceFontBG_3->SetText(std::to_string(Avarice));

	AngerValue->SetText("+" + std::to_string(A_Power));
	FastValue->SetText("+" + SubString(std::to_string(A_Speed), 1));
	FastValue1->SetText("+" + SubString(std::to_string(A_AttackSpeed), 1));
	PatienceValue->SetText("+" + SubString(std::to_string(A_Aamor), 1));
	MysteryValue->SetText("+" + SubString(std::to_string(A_Evasion), 1));
	MysteryValue1->SetText("+" + SubString(std::to_string(A_Cri),1));
	AvariceValue->SetText("+" + std::to_string(A_MaxHP));
	PointFont->SetText("남은 포인트 : " + std::to_string(Point));

}

void AbilityUI::StatCalCulation()
{
	A_Power = Anger * 2;
	A_Speed = Fast*0.5f;
	A_AttackSpeed = Fast * 0.5f;
	A_Aamor = Patience * 1.5f;
	A_Evasion = Mystery *0.5f;
	A_Cri = Mystery * 0.5f;
	A_MaxHP = Avarice * 2;

}

void AbilityUI::ButtonCreate()
{
	
	ResetFont = CreateComponent<UIFontRender>(155);
	ResetFont->SetFont(font1);
	ResetFont->SetFontFlag(FW1_CENTER);
	ResetFont->SetScale(32);
	ResetFont->SetColor(float4::White);
	ResetFont->GetTransform()->SetWorldPosition({ 304.0f,-299.0f,0.0f });
	ResetFont->SetText("초기화");

	PointFont = CreateComponent<UIFontRender>(155);
	PointFont->SetFont(font1);
	PointFont->SetFontFlag(FW1_CENTER);
	PointFont->SetScale(32);
	PointFont->SetColor(float4::White);
	PointFont->GetTransform()->SetWorldPosition({ 514.0f,-299.0f,0.0f });
	
	ResetButton = GetLevel()->CreateActor<ContentButton>();
	ResetButton->GetTransform()->SetParent(GetTransform());
	ResetButton->GetTransform()->SetLocalPosition({ 304.0f,-319.0f,0.0f });
	ResetButton->GetRender()->SetTexture("ResetButton.png");
	ResetButton->GetRender()->GetTransform()->SetWorldScale({ 180.0f,68.0f,0.0f });
	ResetButton->GetRender_Select()->SetTexture("ResetButton.png");
	ResetButton->GetRender_Select()->GetTransform()->SetWorldScale({ 180.0f,68.0f,0.0f });
	ResetButton->SetEvent([this]()
		{
			Player::MainPlayer->GetData().SetAttackSpeed(Player::MainPlayer->GetData().GetAttackSpeed() - A_AttackSpeed);
			Player::MainPlayer->GetData().SetMoveSpeed(Player::MainPlayer->GetData().GetMoveSpeed() - A_Speed);
			Player::MainPlayer->GetData().SetDefense(Player::MainPlayer->GetData().GetDefense() - A_Aamor);
			Player::MainPlayer->GetData().SetCriticalChance(Player::MainPlayer->GetData().GetCriticalChance() - A_Cri);
			Player::MainPlayer->GetData().SetEvasion(Player::MainPlayer->GetData().GetEvasion() - static_cast<int>(A_Evasion));
			Player::MainPlayer->GetData().SetPlayerMaxHP(Player::MainPlayer->GetData().GetPlayerMaxHP() - A_MaxHP);
			IsValue = false;
			ResetValue = true;
			Anger = 0;
			Fast = 0;
			Patience = 0;
			Mystery = 0;
			Avarice = 0;

			Point = Player::MainPlayer->GetData().GetPlayerLevel();
		});
}

std::string AbilityUI::SubString(std::string num, int pos)
{
	return num.substr(0, num.find('.') + pos + 1);
}
