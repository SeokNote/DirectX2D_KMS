#include "PrecompileHeader.h"
#include "DashBar.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

DashBar::DashBar()
{
}

DashBar::~DashBar()
{
}

void DashBar::Start()
{

	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	PlayerDashBarUI3 = CreateComponent<GameEngineUIRenderer>(90);
	PlayerDashBarUI3->SetTexture("DashCount3.png");
	PlayerDashBarUI3->GetTransform()->SetLocalPosition(PlayerDashBarUIPos);
	PlayerDashBarUI3->GetTransform()->SetLocalScale(PlayerDashBarUIScale);
	PlayerDashBarUI3->Off();

	PlayerDashBarUI2 = CreateComponent<GameEngineUIRenderer>(90);
	PlayerDashBarUI2->SetTexture("DashCount2.png");
	PlayerDashBarUI2->GetTransform()->SetLocalPosition(PlayerDashBarUIPos);
	PlayerDashBarUI2->GetTransform()->SetLocalScale(PlayerDashBarUIScale);
	PlayerDashBarUI2->Off();

	PlayerDashBarUI1 = CreateComponent<GameEngineUIRenderer>(90);
	PlayerDashBarUI1->SetTexture("DashCount1.png");
	PlayerDashBarUI1->GetTransform()->SetLocalPosition(PlayerDashBarUIPos);
	PlayerDashBarUI1->GetTransform()->SetLocalScale(PlayerDashBarUIScale);
	PlayerDashBarUI1->Off();

	PlayerDashBarUI0 = CreateComponent<GameEngineUIRenderer>(90);
	PlayerDashBarUI0->SetTexture("DashCount0.png");
	PlayerDashBarUI0->GetTransform()->SetLocalPosition(PlayerDashBarUIPos);
	PlayerDashBarUI0->GetTransform()->SetLocalScale(PlayerDashBarUIScale);
	PlayerDashBarUI0->Off();

}

void DashBar::Update(float _Delta)
{
	switch (Player::MainPlayer->GetDashCount())
	{
	case 0:
		PlayerDashBarUI0->On();
		PlayerDashBarUI1->Off();
		PlayerDashBarUI2->Off();
		PlayerDashBarUI3->Off();
		break;
	case 1:
		PlayerDashBarUI0->Off();
		PlayerDashBarUI1->On();
		PlayerDashBarUI2->Off();
		PlayerDashBarUI3->Off();
		break;
	case 2:
		PlayerDashBarUI0->Off();
		PlayerDashBarUI1->Off();
		PlayerDashBarUI2->On();
		PlayerDashBarUI3->Off();
		break;
	case 3:
		PlayerDashBarUI0->Off();
		PlayerDashBarUI1->Off();
		PlayerDashBarUI2->Off();
		PlayerDashBarUI3->On();
		break;

	default:
		break;
	}
}

