#include "PrecompileHeader.h"
#include "TitleMouse.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>


TitleMouse::TitleMouse()
{
}

TitleMouse::~TitleMouse()
{
}

void TitleMouse::SetMousePos()
{

	float4 MousePos = GameEngineWindow::GetMousePosition();
}

void TitleMouse::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	TitleMouseRender = CreateComponent<GameEngineUIRenderer>();
	TitleMouseRender->SetTexture("BasicCursor.png");
	TitleMouseRender->GetTransform()->SetLocalScale(TitleMouseScale);

	MouseCollsion = CreateComponent<GameEngineCollision>();
	MouseCollsion->GetTransform()->SetLocalScale({1.0f,1.0f,1.0f});
	MouseCollsion->SetOrder(3000);
}	


void TitleMouse::Update(float _DeltaTime)
{
	float4 MousePos = GameEngineWindow::GetMousePosition();
	MousePos.x -= 640.0f;
	MousePos.y -= 370.0f;
	TitleMouseRender->GetTransform()->SetLocalPosition({MousePos.x, -MousePos.y,0.0f});
	MouseCollsion->GetTransform()->SetLocalPosition({ MousePos.x, -MousePos.y,0.0f });
}

