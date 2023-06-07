#include "PrecompileHeader.h"
#include "DashBar.h"

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


	PlayerDashBarUI = CreateComponent<GameEngineUIRenderer>();
	PlayerDashBarUI->SetTexture("DashCount3.png");
	PlayerDashBarUI->GetTransform()->SetLocalPosition(PlayerDashBarUIPos);
	PlayerDashBarUI->GetTransform()->SetLocalScale(PlayerDashBarUIScale);

}

void DashBar::Update(float _Delta)
{
}

