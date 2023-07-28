#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "FoodUI.h"
#include "TempleNpc.h"
#include "Player.h"
#include "UICountBase.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ContentButton.h"
#include "UIFontRender.h"
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


	FoodUIRender = CreateComponent<GameEngineUIRenderer>(151);
	FoodUIRender->SetTexture("FoodUI.png");
	FoodUIRender->GetTransform()->SetLocalScale(FoodUIScale);

	ExitButtonRender = CreateComponent<GameEngineUIRenderer>(152);
	ExitButtonRender->SetTexture("ExitButton1_1.png");
	ExitButtonRender->GetTransform()->SetLocalScale(ExitButtonScale);
	ExitButtonRender->GetTransform()->SetLocalPosition(ExitButtonPos);

	ExitButtonSelectRender = CreateComponent<GameEngineUIRenderer>(152);
	ExitButtonSelectRender->SetTexture("ExitButton1_0.png");
	ExitButtonSelectRender->GetTransform()->SetLocalScale(ExitButtonScale);
	ExitButtonSelectRender->GetTransform()->SetLocalPosition(ExitButtonPos);
	ExitButtonSelectRender->Off();

	SatietyBGRender = CreateComponent<GameEngineUIRenderer>(153);
	SatietyBGRender->SetTexture("FoodGageBar.png");
	SatietyBGRender->GetTransform()->SetLocalScale({320.0f,46.0f,0.0f});
	SatietyBGRender->GetTransform()->SetLocalPosition({-351.0f,-314.0f,0.0f});
	
	FoodUIExitCol = CreateComponent<GameEngineCollision>();
	FoodUIExitCol->GetTransform()->SetLocalPosition(ExitButtonPos);
	FoodUIExitCol->GetTransform()->SetLocalScale(ExitButtonScale);
	FoodUIExitCol->SetOrder(2998);

	FoodBGRender = CreateComponent<GameEngineUIRenderer>(152);
	FoodBGRender->SetTexture("FoodUI.png");
	FoodBGRender->CreateAnimation({ .AnimationName = "FoodAni", .SpriteName = "FoodAni",.FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	FoodBGRender->GetTransform()->SetLocalPosition({242.0f,0.0f,0.0f});

	HPBaseRender = CreateComponent<GameEngineUIRenderer>(153);
	HPBaseRender->SetTexture("RestaurantLifeBaseBack.png");
	HPBaseRender->GetTransform()->SetLocalScale({ 220.0f,64.0f,0.0f });
	HPBaseRender->GetTransform()->SetLocalPosition({ 503.0f,-220.0f,0.0f });

	HPRender = CreateComponent<GameEngineUIRenderer>(153);
	HPRender->SetTexture("RestaurantLife.png");
	HPRender->GetTransform()->SetLocalScale({ 196.0f,40.0f,0.0f });
	HPRender->GetTransform()->SetLocalPosition({ 503.0f,-220.0f,0.0f });

	FoodBGRender->ChangeAnimation("FoodAni");
	SetButton();
	SetSatieyFont();
	PlayLevel::BGM.SetPause(true);
	FoodBGM = GameEngineSound::Play("Foodshop.wav");


}
void FoodUI::Update(float _Delta)
{
	if (FoodUIExitCol->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ExitButtonRender->Off();
		ExitButtonSelectRender->On();
		if (GameEngineInput::IsDown("ClickMouse"))
		{
			PlayLevel::BGM.SetPause(false);
			FoodBGM.Stop();
			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();
		}
	}
	else {
		ExitButtonSelectRender->Off();
		ExitButtonRender->On();
	}
	MoveFood(_Delta);
	FontUpdate();
}
/*음식 클릭시 해야할 행동들

배고픔 차기
설명에 따른 능력치 오르기(0) (위력은 무기가 완성된 후에 적용시키기)
돈깎기
고마워요 뜨기(0)
음식이 왼쪽 아래로 가면서 스르륵 사라지기 불값 주고 스르륵 움직이게 하기.
*/
void FoodUI::SetButton()
{
	BreadButton = GetLevel()->CreateActor<ContentButton>();
	BreadButton->GetTransform()->SetParent(GetTransform());
	BreadButton->GetTransform()->SetLocalPosition({ -402.0f,143.0f,0.0f });
	BreadButton->GetRender()->SetTexture("FoodBread_01.png");
	BreadButton->GetRender()->GetTransform()->SetWorldScale({ 400.0f,200.0f,0.0f });
	BreadButton->GetRender_Select()->SetTexture("FoodBread_02.png");
	BreadButton->GetRender_Select()->GetTransform()->SetWorldScale({ 400.0f,200.0f,0.0f });
	BreadButton->GetExplaneRender()->SetTexture("01_Bread.png");
	BreadButton->GetExplaneRender()->GetTransform()->SetWorldPosition({ 240.0f,-20.0f,0.0f });
	BreadButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 292.0f,120.0f,1.0f });
	BreadButton->SetEvent([this]()
		{
			if (Player::MainPlayer->GetData().GetSatiety() + 50 < 100 && Player::MainPlayer->GetData().GetCoin() > 540)
			{
				GameEngineSound::Play("FoodEat2.wav");
				BreadButton->GetRender()->SetTexture("FoodThank.png");
				BreadButton->GetRender_Select()->SetTexture("FoodThank.png");
				MoveBread = true;
				Player::MainPlayer->GetData().PlusDefense(5.8f);
				Player::MainPlayer->GetData().PlusSatiety(50);
				float PlusHp = static_cast<float>(Player::MainPlayer->GetData().GetPlayerMaxHP()) * 0.12f;
				Player::MainPlayer->GetData().PlusPlayerHP(static_cast<int>(PlusHp));
				Player::MainPlayer->GetData().SubCoin(540);


			}

		});
	TomatoButton = GetLevel()->CreateActor<ContentButton>();
	TomatoButton->GetTransform()->SetParent(GetTransform());
	TomatoButton->GetTransform()->SetLocalPosition({ -402.0f,-65.0f,0.0f });
	TomatoButton->GetRender()->SetTexture("FoodTomatoSoup_01.png");
	TomatoButton->GetRender()->GetTransform()->SetWorldScale({ 400.0f,200.0f,0.0f });
	TomatoButton->GetRender_Select()->SetTexture("FoodTomatoSoup_02.png");
	TomatoButton->GetRender_Select()->GetTransform()->SetWorldScale({ 400.0f,200.0f,0.0f });
	TomatoButton->GetExplaneRender()->SetTexture("04_TamatoSoup.png");
	TomatoButton->GetExplaneRender()->GetTransform()->SetWorldPosition({ 240.0f,-20.0f,0.0f });
	TomatoButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 292.0f,120.0f,1.0f });
	TomatoButton->SetEvent([this]()
		{	
			if (Player::MainPlayer->GetData().GetSatiety() + 46 < 100 && Player::MainPlayer->GetData().GetCoin()>380)
			{
				GameEngineSound::Play("FoodEat2.wav");
				TomatoButton->GetRender()->SetTexture("FoodThank.png");
				TomatoButton->GetRender_Select()->SetTexture("FoodThank.png");
				MoveTomato = true;
				Player::MainPlayer->GetData().PlusCriticalChance(7.1f);
				Player::MainPlayer->GetData().PlusDefense(9.f);
				Player::MainPlayer->GetData().PlusSatiety(46);
				float PlusHp = static_cast<float>(Player::MainPlayer->GetData().GetPlayerMaxHP()) * 0.092f;
				Player::MainPlayer->GetData().PlusPlayerHP(static_cast<int>(PlusHp));
				Player::MainPlayer->GetData().SubCoin(380);

			}
			

		});
}

void FoodUI::MoveFood(float _Delta)
{
	SatietyBGRender->ImageClippingX(static_cast<float>(100-Player::MainPlayer->GetData().GetSatiety()) / static_cast<float>(Player::MainPlayer->GetData().GetMaxSatiety()), ClipXDir::Right);
	HPRender->ImageClippingX(static_cast<float>(Player::MainPlayer->GetData().GetPlayerHP()) / static_cast<float>(Player::MainPlayer->GetData().GetPlayerMaxHP()), ClipXDir::Left);

	if (MoveBread == true)
	{
		BreadButton->GetExplaneRender()->GetTransform()->AddWorldPosition({ _Delta *300.0f,-_Delta * 300.0f,0.0f });
		if (BreadButton->GetExplaneRender()->ColorOptionValue.MulColor.a > 0)
		{
			BreadButton->GetExplaneRender()->ColorOptionValue.MulColor.a -= _Delta;

		}
		else
		{
			BreadButton->GetExplaneRender()->Death();
		}
	}
	if (MoveTomato == true)
	{
		TomatoButton->GetExplaneRender()->GetTransform()->AddWorldPosition({ _Delta * 300.0f,-_Delta * 300.0f,0.0f });
		if (TomatoButton->GetExplaneRender()->ColorOptionValue.MulColor.a > 0)
		{
			TomatoButton->GetExplaneRender()->ColorOptionValue.MulColor.a -= _Delta;

		}
		else
		{
			TomatoButton->GetExplaneRender()->Death();
		}
	}
}

void FoodUI::SetSatieyFont()
{
	PlayerFoodFont = CreateComponent<UIFontRender>(155);
	PlayerFoodFont->SetFont(font);
	PlayerFoodFont->SetFontFlag(FW1_CENTER);
	PlayerFoodFont->SetScale(48);
	PlayerFoodFont->SetColor(float4::White);
	PlayerFoodFont->GetTransform()->SetLocalPosition({ -420.0f,-285.0f,0.0f });

	PlayerFoodBG_0 = CreateComponent<UIFontRender>(154);
	PlayerFoodBG_0->SetFont(font);
	PlayerFoodBG_0->SetFontFlag(FW1_CENTER);
	PlayerFoodBG_0->SetScale(48);
	PlayerFoodBG_0->SetColor(float4::Black);
	PlayerFoodBG_0->GetTransform()->SetLocalPosition({ -420.0f,-288.0f,0.0f });

	PlayerFoodBG_1 = CreateComponent<UIFontRender>(154);
	PlayerFoodBG_1->SetFont(font);
	PlayerFoodBG_1->SetFontFlag(FW1_CENTER);
	PlayerFoodBG_1->SetScale(48);
	PlayerFoodBG_1->SetColor(float4::Black);
	PlayerFoodBG_1->GetTransform()->SetLocalPosition({ -420.0f,-282.0f,0.0f });

	PlayerFoodBG_2 = CreateComponent<UIFontRender>(154);
	PlayerFoodBG_2->SetFont(font);
	PlayerFoodBG_2->SetFontFlag(FW1_CENTER);
	PlayerFoodBG_2->SetScale(48);
	PlayerFoodBG_2->SetColor(float4::Black);
	PlayerFoodBG_2->GetTransform()->SetLocalPosition({ -423.0f,-285.0f,0.0f });

	PlayerFoodBG_3 = CreateComponent<UIFontRender>(154);
	PlayerFoodBG_3->SetFont(font);
	PlayerFoodBG_3->SetFontFlag(FW1_CENTER);
	PlayerFoodBG_3->SetScale(48);
	PlayerFoodBG_3->SetColor(float4::Black);
	PlayerFoodBG_3->GetTransform()->SetLocalPosition({ -417.0f,-285.0f,0.0f });

	SlashFont = CreateComponent<UIFontRender>(155);
	SlashFont->SetFont(font);
	SlashFont->SetFontFlag(FW1_CENTER);
	SlashFont->SetScale(37);
	SlashFont->SetColor(float4::White);
	SlashFont->SetText("/");
	SlashFont->GetTransform()->SetLocalPosition({ -370.0f,-293.0f,0.0f });

	SlashFont_0 = CreateComponent<UIFontRender>(154);
	SlashFont_0->SetFont(font);
	SlashFont_0->SetFontFlag(FW1_CENTER);
	SlashFont_0->SetScale(37);
	SlashFont_0->SetColor(float4::Black);
	SlashFont_0->SetText("/");
	SlashFont_0->GetTransform()->SetLocalPosition({ -370.0f,-290.0f,0.0f });

	SlashFont_1 = CreateComponent<UIFontRender>(154);
	SlashFont_1->SetFont(font);
	SlashFont_1->SetFontFlag(FW1_CENTER);
	SlashFont_1->SetScale(37);
	SlashFont_1->SetColor(float4::Black);
	SlashFont_1->SetText("/");
	SlashFont_1->GetTransform()->SetLocalPosition({ -370.0f,-296.0f,0.0f });

	SlashFont_2 = CreateComponent<UIFontRender>(154);
	SlashFont_2->SetFont(font);
	SlashFont_2->SetFontFlag(FW1_CENTER);
	SlashFont_2->SetScale(37);
	SlashFont_2->SetColor(float4::Black);
	SlashFont_2->SetText("/");
	SlashFont_2->GetTransform()->SetLocalPosition({ -373.0f,-293.0f,0.0f });

	SlashFont_3 = CreateComponent<UIFontRender>(154);
	SlashFont_3->SetFont(font);
	SlashFont_3->SetFontFlag(FW1_CENTER);
	SlashFont_3->SetScale(37);
	SlashFont_3->SetColor(float4::Black);
	SlashFont_3->SetText("/");
	SlashFont_3->GetTransform()->SetLocalPosition({ -367.0f,-293.0f,0.0f });

	PlayerMaxFood = CreateComponent<UIFontRender>(155);
	PlayerMaxFood->SetFont(font);
	PlayerMaxFood->SetFontFlag(FW1_CENTER);
	PlayerMaxFood->SetScale(48);
	PlayerMaxFood->SetColor(float4::White);
	PlayerMaxFood->SetText(std::to_string(Player::MainPlayer->GetData().GetMaxSatiety()));
	PlayerMaxFood->GetTransform()->SetLocalPosition({ -310.0f,-285.0f,0.0f });
		  
	PlayerMaxFood_0 = CreateComponent<UIFontRender>(154);
	PlayerMaxFood_0->SetFont(font);
	PlayerMaxFood_0->SetFontFlag(FW1_CENTER);
	PlayerMaxFood_0->SetScale(48);
	PlayerMaxFood_0->SetColor(float4::Black);
	PlayerMaxFood_0->SetText(std::to_string(Player::MainPlayer->GetData().GetMaxSatiety()));
	PlayerMaxFood_0->GetTransform()->SetLocalPosition({ -310.0f,-282.0f,0.0f });
		  
	PlayerMaxFood_1 = CreateComponent<UIFontRender>(154);
	PlayerMaxFood_1->SetFont(font);
	PlayerMaxFood_1->SetFontFlag(FW1_CENTER);
	PlayerMaxFood_1->SetScale(48);
	PlayerMaxFood_1->SetColor(float4::Black);
	PlayerMaxFood_1->SetText(std::to_string(Player::MainPlayer->GetData().GetMaxSatiety()));
	PlayerMaxFood_1->GetTransform()->SetLocalPosition({ -310.0f,-288.0f,0.0f });
		  
	PlayerMaxFood_2 = CreateComponent<UIFontRender>(154);
	PlayerMaxFood_2->SetFont(font);
	PlayerMaxFood_2->SetFontFlag(FW1_CENTER);
	PlayerMaxFood_2->SetScale(48);
	PlayerMaxFood_2->SetColor(float4::Black);
	PlayerMaxFood_2->SetText(std::to_string(Player::MainPlayer->GetData().GetMaxSatiety()));
	PlayerMaxFood_2->GetTransform()->SetLocalPosition({ -313.0f,-285.0f,0.0f });
		  
	PlayerMaxFood_3 = CreateComponent<UIFontRender>(154);
	PlayerMaxFood_3->SetFont(font);
	PlayerMaxFood_3->SetFontFlag(FW1_CENTER);
	PlayerMaxFood_3->SetScale(48);
	PlayerMaxFood_3->SetColor(float4::Black);
	PlayerMaxFood_3->SetText(std::to_string(Player::MainPlayer->GetData().GetMaxSatiety()));
	PlayerMaxFood_3->GetTransform()->SetLocalPosition({ -307.0f,-285.0f,0.0f });
	// 체력 폰트
	PlayerHPFont = CreateComponent<UIFontRender>(155);
	PlayerHPFont->SetFont(font);
	PlayerHPFont->SetFontFlag(FW1_CENTER);
	PlayerHPFont->SetScale(48);
	PlayerHPFont->SetColor(float4::White);
	PlayerHPFont->GetTransform()->SetLocalPosition({ 465.0f,-190.0f,0.0f });

	PlayerHPBG_0 = CreateComponent<UIFontRender>(154);
	PlayerHPBG_0->SetFont(font);
	PlayerHPBG_0->SetFontFlag(FW1_CENTER);
	PlayerHPBG_0->SetScale(48);
	PlayerHPBG_0->SetColor(float4::Black);
	PlayerHPBG_0->GetTransform()->SetLocalPosition({ 468.0f,-190.0f,0.0f });

	PlayerHPBG_1 = CreateComponent<UIFontRender>(154);
	PlayerHPBG_1->SetFont(font);
	PlayerHPBG_1->SetFontFlag(FW1_CENTER);
	PlayerHPBG_1->SetScale(48);
	PlayerHPBG_1->SetColor(float4::Black);
	PlayerHPBG_1->GetTransform()->SetLocalPosition({ 462.0f,-190.0f,0.0f });

	PlayerHPBG_2 = CreateComponent<UIFontRender>(154);
	PlayerHPBG_2->SetFont(font);
	PlayerHPBG_2->SetFontFlag(FW1_CENTER);
	PlayerHPBG_2->SetScale(48);
	PlayerHPBG_2->SetColor(float4::Black);
	PlayerHPBG_2->GetTransform()->SetLocalPosition({ 465.0f,-193.0f,0.0f });

	PlayerHPBG_3 = CreateComponent<UIFontRender>(154);
	PlayerHPBG_3->SetFont(font);
	PlayerHPBG_3->SetFontFlag(FW1_CENTER);
	PlayerHPBG_3->SetScale(48);
	PlayerHPBG_3->SetColor(float4::Black);
	PlayerHPBG_3->GetTransform()->SetLocalPosition({ 465.0f,-187.0f,0.0f });

	PlayerMaxHP = CreateComponent<UIFontRender>(155);
	PlayerMaxHP->SetFont(font);
	PlayerMaxHP->SetFontFlag(FW1_CENTER);
	PlayerMaxHP->SetScale(48);
	PlayerMaxHP->SetColor(float4::White);
	PlayerMaxHP->GetTransform()->SetLocalPosition({ 555.0f,-190.0f,0.0f });

	PlayerMaxHP_0 = CreateComponent<UIFontRender>(154);
	PlayerMaxHP_0->SetFont(font);
	PlayerMaxHP_0->SetFontFlag(FW1_CENTER);
	PlayerMaxHP_0->SetScale(48);
	PlayerMaxHP_0->SetColor(float4::Black);
	PlayerMaxHP_0->GetTransform()->SetLocalPosition({ 552.0f,-190.0f,0.0f });

	PlayerMaxHP_1 = CreateComponent<UIFontRender>(154);
	PlayerMaxHP_1->SetFont(font);
	PlayerMaxHP_1->SetFontFlag(FW1_CENTER);
	PlayerMaxHP_1->SetScale(48);
	PlayerMaxHP_1->SetColor(float4::Black);
	PlayerMaxHP_1->GetTransform()->SetLocalPosition({ 558.0f,-190.0f,0.0f });
	
	PlayerMaxHP_2 = CreateComponent<UIFontRender>(154);
	PlayerMaxHP_2->SetFont(font);
	PlayerMaxHP_2->SetFontFlag(FW1_CENTER);
	PlayerMaxHP_2->SetScale(48);
	PlayerMaxHP_2->SetColor(float4::Black);
	PlayerMaxHP_2->GetTransform()->SetLocalPosition({ 555.0f,-193.0f,0.0f });
	
	PlayerMaxHP_3 = CreateComponent<UIFontRender>(154);
	PlayerMaxHP_3->SetFont(font);
	PlayerMaxHP_3->SetFontFlag(FW1_CENTER);
	PlayerMaxHP_3->SetScale(48);
	PlayerMaxHP_3->SetColor(float4::Black);
	PlayerMaxHP_3->GetTransform()->SetLocalPosition({ 555.0f,-187.0f,0.0f });

	SlashFontHP = CreateComponent<UIFontRender>(155);
	SlashFontHP->SetFont(font);
	SlashFontHP->SetFontFlag(FW1_CENTER);
	SlashFontHP->SetScale(37);
	SlashFontHP->SetColor(float4::White);
	SlashFontHP->SetText("/");
	SlashFontHP->GetTransform()->SetLocalPosition({ 510.0f,-197.0f,0.0f });

	SlashFontHP_0 = CreateComponent<UIFontRender>(154);
	SlashFontHP_0->SetFont(font);
	SlashFontHP_0->SetFontFlag(FW1_CENTER);
	SlashFontHP_0->SetScale(37);
	SlashFontHP_0->SetColor(float4::Black);
	SlashFontHP_0->SetText("/");
	SlashFontHP_0->GetTransform()->SetLocalPosition({ 510.0f,-194.0f,0.0f });

	SlashFontHP_1 = CreateComponent<UIFontRender>(154);
	SlashFontHP_1->SetFont(font);
	SlashFontHP_1->SetFontFlag(FW1_CENTER);
	SlashFontHP_1->SetScale(37);
	SlashFontHP_1->SetColor(float4::Black);
	SlashFontHP_1->SetText("/");
	SlashFontHP_1->GetTransform()->SetLocalPosition({ 510.0f,-200.0f,0.0f });

	SlashFontHP_2 = CreateComponent<UIFontRender>(154);
	SlashFontHP_2->SetFont(font);
	SlashFontHP_2->SetFontFlag(FW1_CENTER);
	SlashFontHP_2->SetScale(37);
	SlashFontHP_2->SetColor(float4::Black);
	SlashFontHP_2->SetText("/");
	SlashFontHP_2->GetTransform()->SetLocalPosition({ 507.0f,-197.0f,0.0f });

	SlashFontHP_3 = CreateComponent<UIFontRender>(154);
	SlashFontHP_3->SetFont(font);
	SlashFontHP_3->SetFontFlag(FW1_CENTER);
	SlashFontHP_3->SetScale(37);
	SlashFontHP_3->SetColor(float4::Black);
	SlashFontHP_3->SetText("/");
	SlashFontHP_3->GetTransform()->SetLocalPosition({ 513.0f,-197.0f,0.0f });

	CoinRender = CreateComponent<UIFontRender>(154);
	CoinRender->SetFont(font);
	CoinRender->SetFontFlag(FW1_RIGHT);
	CoinRender->SetScale(48);
	CoinRender->SetColor(float4::White);
	CoinRender->GetTransform()->SetLocalPosition({ 550.0f,-283.0f,0.0f });
	
}

void FoodUI::FontUpdate()
{
	PlayerFoodFont->SetText(std::to_string(Player::MainPlayer->GetData().GetSatiety()));
	PlayerFoodBG_0->SetText(std::to_string(Player::MainPlayer->GetData().GetSatiety()));
	PlayerFoodBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetSatiety()));
	PlayerFoodBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetSatiety()));
	PlayerFoodBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetSatiety()));
	PlayerMaxHP->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerMaxHP_0->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerMaxHP_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerMaxHP_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerMaxHP_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()));
	PlayerHPBG_0->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()));
	PlayerHPBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()));
	PlayerHPBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()));
	PlayerHPBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()));
	CoinRender->SetText(std::to_string(Player::MainPlayer->GetData().GetCoin()));

}
