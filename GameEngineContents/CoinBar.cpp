#include "PrecompileHeader.h"
#include "CoinBar.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

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


	PlayerCoinBarUI = CreateComponent<GameEngineUIRenderer>();
	PlayerCoinBarUI->SetTexture("GoldCoin7.png");
	PlayerCoinBarUI->GetTransform()->SetLocalPosition(PlayerCoinBarUIPos);
	PlayerCoinBarUI->GetTransform()->SetLocalScale(PlayerCoinBarUIScale);

}

void CoinBar::Update(float _Delta)
{
}

