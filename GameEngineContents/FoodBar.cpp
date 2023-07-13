#include "PrecompileHeader.h"
#include "FoodBar.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "UIFontRender.h"

FoodBar::FoodBar() 
{
}

FoodBar::~FoodBar() 
{
}

void FoodBar::Start()
{

	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	PlayerFoodUI = CreateComponent<GameEngineUIRenderer>(90);
	PlayerFoodUI->SetTexture("PlayerFoodUI.png");
	PlayerFoodUI->GetTransform()->SetLocalPosition(PlayerFoodUIPos);
	PlayerFoodUI->GetTransform()->SetLocalScale(PlayerFoodUIScale);

	PlayerFoodBarBG = CreateComponent<GameEngineUIRenderer>(90);
	PlayerFoodBarBG->SetTexture("FoodSmallBarBG.png");
	PlayerFoodBarBG->GetTransform()->SetLocalPosition({ -547.0f,-340.0f,0.0f });
	PlayerFoodBarBG->GetTransform()->SetLocalScale({65.0f,12.0f,0.0f});
	
	PlayerFoodBar = CreateComponent<GameEngineUIRenderer>(90);
	PlayerFoodBar->SetTexture("FoodSmallBar.png");
	PlayerFoodBar->GetTransform()->SetLocalPosition({ -547.0f,-340.0f,0.0f });
	PlayerFoodBar->GetTransform()->SetLocalScale({ 61.0f,10.0f,0.0f });

	FontSet();
}

void FoodBar::Update(float _Delta)
{
	CurSatityRender->SetText(std::to_string(Player::MainPlayer->GetData().GetSatiety()));
	CurSatityRender_0->SetText(std::to_string(Player::MainPlayer->GetData().GetSatiety()));
	PlayerFoodBar->ImageClippingX(static_cast<float>(100 - Player::MainPlayer->GetData().GetSatiety()) / static_cast<float>(Player::MainPlayer->GetData().GetMaxSatiety()), ClipXDir::Right);

}

void FoodBar::FontSet()
{
	CurSatityRender = CreateComponent<UIFontRender>(90);
	CurSatityRender->SetFont(font);
	CurSatityRender->SetFontFlag(FW1_CENTER);
	CurSatityRender->SetScale(20);
	CurSatityRender->SetColor(float4::White);
	CurSatityRender->SetText("/");
	CurSatityRender->GetTransform()->SetLocalPosition({ -555.0f,-303.0f,0.0f });

	CurSatityRender = CreateComponent<UIFontRender>(90);
	CurSatityRender->SetFont(font);
	CurSatityRender->SetFontFlag(FW1_CENTER);
	CurSatityRender->SetScale(20);
	CurSatityRender->SetColor(float4::White);
	CurSatityRender->GetTransform()->SetLocalPosition({ -575.0f,-305.0f,0.0f });

	CurSatityRender_0 = CreateComponent<UIFontRender>(90);
	CurSatityRender_0->SetFont(font);
	CurSatityRender_0->SetFontFlag(FW1_CENTER);
	CurSatityRender_0->SetScale(20);
	CurSatityRender_0->SetColor(float4::White);
	CurSatityRender_0->GetTransform()->SetLocalPosition({ -575.0f,-304.0f,0.0f });

	MaxSatityRender = CreateComponent<UIFontRender>(90);
	MaxSatityRender->SetFont(font);
	MaxSatityRender->SetFontFlag(FW1_CENTER);
	MaxSatityRender->SetScale(20);
	MaxSatityRender->SetColor(float4::White);
	MaxSatityRender->SetText("100");
	MaxSatityRender->GetTransform()->SetLocalPosition({ -530.0f,-305.0f,0.0f }); 

	MaxSatityRender_0 = CreateComponent<UIFontRender>(90);
	MaxSatityRender_0->SetFont(font);
	MaxSatityRender_0->SetFontFlag(FW1_CENTER);
	MaxSatityRender_0->SetScale(20);
	MaxSatityRender_0->SetColor(float4::White);
	MaxSatityRender_0->SetText("100");
	MaxSatityRender_0->GetTransform()->SetLocalPosition({ -530.0f,-304.0f,0.0f });
}

