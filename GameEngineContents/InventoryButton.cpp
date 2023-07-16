#include "PrecompileHeader.h"
#include "InventoryButton.h"
#include "UIFontRender.h"
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>

InventoryButton* InventoryButton::InventoryButtonPtr = nullptr;

InventoryButton::InventoryButton()
{
	InventoryButtonPtr = this;
}

InventoryButton::~InventoryButton()
{
}

void InventoryButton::Start()
{
	Render = CreateComponent<GameEngineUIRenderer>(151);
	Render->SetTexture("ItemBase00.png");
	Render->GetTransform()->SetWorldScale({ 76.0f,76.0f,0.0f });

	Render_Select = CreateComponent<GameEngineUIRenderer>(151);
	Render_Select->SetTexture("ItemBase01.png");
	Render_Select->GetTransform()->SetWorldScale({ 76.0f,76.0f,0.0f });

	Render_Select->Off();
	ExplaneRender = CreateComponent<GameEngineUIRenderer>(152);
	ExplaneRender->GetTransform()->SetWorldScale({ 396.0f,360.0f,1.0f });

	ItmeRender = CreateComponent<GameEngineUIRenderer>(152);
	ItmeRender->GetTransform()->SetWorldScale({ 44.0f,-132.0f,1.0f });

}

void InventoryButton::Update(float _Delta)
{

	GameEngineCamera* Camera = Render->GetCamera();

	// ·£´õ·¯ 
	float4x4 ViewPort = Camera->GetViewPort();
	float4x4 Proj = Camera->GetProjection();
	float4x4 View = Camera->GetView();

	Mouse = GameEngineInput::GetMousePosition();

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
			PressValue = false;
			if (nullptr != Click)
			{
				Click();
			}
		}
		if (true == GameEngineInput::IsDown("EngineMouseLeft"))
		{
			PressValue = true;
		}
	
		if (true == GameEngineInput::IsPress("EngineMouseLeft"))
		{
			ExplaneRender->Off();
		}
		else 
		{
			ExplaneRender->On();
		}
	}
	else
	{
		Render->On();
		Render_Select->Off();
		ExplaneRender->Off();

	}
	if (I_Data.ItemNumber == 1)
	{


		int a = 0;
	}
}
