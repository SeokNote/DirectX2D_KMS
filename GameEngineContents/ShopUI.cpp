#include "PrecompileHeader.h"
#include "ShopUI.h"
#include "InventoryUI.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
ShopUI::ShopUI()
{
}

ShopUI::~ShopUI()
{
}

void ShopUI::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	ShopUIRender = CreateComponent<GameEngineUIRenderer>(2);
	ShopUIRender->SetTexture("ShopBase.png");
	ShopUIRender->GetTransform()->SetLocalPosition({ -400.0f,0.0f,0.0f });
	ShopUIRender->GetTransform()->SetLocalScale(ShopUIScale);


	//	
	InventoryUIPtr = GetLevel()->CreateActor<InventoryUI>();
}
void ShopUI::Update(float _Delta)
{
	if (GameEngineInput::IsDown("ESC"))
	{
		InventoryUIPtr->Death();
		Death();
	}
}