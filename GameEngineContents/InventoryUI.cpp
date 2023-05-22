#include "PrecompileHeader.h"
#include "InventoryUI.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>

InventoryUI::InventoryUI()
{
}

InventoryUI::~InventoryUI()
{
}

void InventoryUI::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	InventoryUIRender = CreateComponent<GameEngineUIRenderer>();
	InventoryUIRender->SetTexture("InventoryBase.png");
	InventoryUIRender->GetTransform()->SetLocalPosition({400.0f,0.0f,0.0f });
	InventoryUIRender->GetTransform()->SetLocalScale(InventoryUIScale);


	//	

}
void InventoryUI::Update(float _Delta)
{
}