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
	FontSet();
}

void FoodBar::Update(float _Delta)
{
	CurSatityRender->SetText(std::to_string(Player::MainPlayer->GetData().GetSatiety()));

}

void FoodBar::FontSet()
{
	CurSatityRender = CreateComponent<UIFontRender>(90);
	CurSatityRender->SetFont(font);
	CurSatityRender->SetFontFlag(FW1_CENTER);
	CurSatityRender->SetScale(15);
	CurSatityRender->SetColor(float4::White);
	CurSatityRender->SetText("/");
	CurSatityRender->GetTransform()->SetLocalPosition({ -555.0f,-310.0f,0.0f });

	CurSatityRender = CreateComponent<UIFontRender>(90);
	CurSatityRender->SetFont(font);
	CurSatityRender->SetFontFlag(FW1_CENTER);
	CurSatityRender->SetScale(24);
	CurSatityRender->SetColor(float4::White);
	CurSatityRender->GetTransform()->SetLocalPosition({ -575.0f,-305.0f,0.0f });

	MaxSatityRender = CreateComponent<UIFontRender>(90);
	MaxSatityRender->SetFont(font);
	MaxSatityRender->SetFontFlag(FW1_CENTER);
	MaxSatityRender->SetScale(24);
	MaxSatityRender->SetColor(float4::White);
	MaxSatityRender->SetText("100");
	MaxSatityRender->GetTransform()->SetLocalPosition({ -530.0f,-305.0f,0.0f }); 
}

