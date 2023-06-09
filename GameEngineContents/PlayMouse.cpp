#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "PlayMouse.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
PlayMouse* PlayMouse::MainPlayMouse = nullptr;

PlayMouse::PlayMouse()
{
	MainPlayMouse = this;

}

PlayMouse::~PlayMouse()
{
}


void PlayMouse::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	PlayMouseRender = CreateComponent<GameEngineUIRenderer>(1000);
	PlayMouseRender->SetTexture("ShootingCursor.png");
	PlayMouseRender->GetTransform()->SetLocalScale(PlayMouseScale);

	PlayMouseCollsion = CreateComponent<GameEngineCollision>(ColOrder::PlayMouse);
	PlayMouseCollsion->GetTransform()->SetLocalScale({ 1.0f,1.0f,1.0f });
}


void PlayMouse::Update(float _DeltaTime)
{
	float4 MousePos = GameEngineWindow::GetMousePosition();
	MousePos.x -= 640.0f;
	MousePos.y -= 360.0f;
	PlayMouseRender->GetTransform()->SetLocalPosition({ MousePos.x, -MousePos.y,-900.0f });
	PlayMouseCollsion->GetTransform()->SetLocalPosition({ MousePos.x, -MousePos.y,0.0f });
}

