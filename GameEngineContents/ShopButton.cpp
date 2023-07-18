#include "PrecompileHeader.h"
#include "ShopButton.h"
#include "UIFontRender.h"
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>

ShopButton* ShopButton::ShopButtonPtr = nullptr;

ShopButton::ShopButton()
{
	ShopButtonPtr = this;
}

ShopButton::~ShopButton()
{
}

void ShopButton::Start()
{
	Render = CreateComponent<GameEngineUIRenderer>(151);
	Render->Off();

	Render_Select = CreateComponent<GameEngineUIRenderer>(151);
	Render_Select->Off();

	ExplaneRender = CreateComponent<GameEngineUIRenderer>(152);
	ExplaneRender->Off();
}

void ShopButton::Update(float _Delta)
{

	GameEngineCamera* Camera = Render->GetCamera();

	// ·£´õ·¯ 
	float4x4 ViewPort = Camera->GetViewPort();
	float4x4 Proj = Camera->GetProjection();
	float4x4 View = Camera->GetView();

	float4 Mouse = GameEngineInput::GetMousePosition();

	Mouse *= ViewPort.InverseReturn();
	Mouse *= Proj.InverseReturn();
	Mouse *= View.InverseReturn();


	CollisionData MouseData;
	MouseData.SPHERE.Center = Mouse.DirectFloat3;
	MouseData.SPHERE.Radius = 0.0f;

	if (true == GameEngineTransform::AABB2DToSpehre2D(Render->GetTransform()->GetCollisionData(), MouseData))
	{
		ExplaneRender->On();
		Render_Select->On();
		Render->Off();
		if (true == GameEngineInput::IsUp("EngineMouseLeft"))
		{
			if (nullptr != Click)
			{
				Click();
			}
		}
	}
	else
	{	
		Render->On();
		Render_Select->Off();
		ExplaneRender->Off();
	}
}


