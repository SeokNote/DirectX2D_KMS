#include "PrecompileHeader.h"
#include "CoinBar.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "UIFontRender.h"

CoinBar::CoinBar()
{
}

CoinBar::~CoinBar()
{
}

void CoinBar::Start()
{

	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	PlayerCoinBarUI = CreateComponent<GameEngineUIRenderer>(90);
	PlayerCoinBarUI->SetTexture("GoldCoin7.png");
	PlayerCoinBarUI->GetTransform()->SetLocalPosition(PlayerCoinBarUIPos);
	PlayerCoinBarUI->GetTransform()->SetLocalScale(PlayerCoinBarUIScale);

	CoinFontRender = CreateComponent<UIFontRender>(90);
	CoinFontRender->SetFont("8-bit Operator+ SC");
	CoinFontRender->SetFontFlag(FW1_LEFT);
	CoinFontRender->SetScale(20);
	CoinFontRender->SetColor(float4::White);
	CoinFontRender->GetTransform()->SetLocalPosition({ -580.0f,-275.0f,0.0f });

	CoinFontRender_1 = CreateComponent<UIFontRender>(90);
	CoinFontRender_1->SetFont("8-bit Operator+ SC");
	CoinFontRender_1->SetFontFlag(FW1_LEFT);
	CoinFontRender_1->SetScale(20);
	CoinFontRender_1->SetColor(float4::White);
	CoinFontRender_1->GetTransform()->SetLocalPosition({ -580.0f,-274.0f,0.0f });


	
}

void CoinBar::Update(float _Delta)
{
	CoinFontRender->SetText(std::to_string(Player::MainPlayer->GetData().GetCoin()));
	CoinFontRender_1->SetText(std::to_string(Player::MainPlayer->GetData().GetCoin()));
}

