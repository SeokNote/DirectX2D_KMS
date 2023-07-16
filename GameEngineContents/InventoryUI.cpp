#include "PrecompileHeader.h"
#include "InventoryUI.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "InventoryButton.h"
#include "ItemData.h"
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


	InventoryUIRender = CreateComponent<GameEngineUIRenderer>(150);
	InventoryUIRender->SetTexture("InventoryBase.png");
	InventoryUIRender->GetTransform()->SetLocalPosition({400.0f,0.0f,0.0f });
	InventoryUIRender->GetTransform()->SetLocalScale(InventoryUIScale);

	SetInventory();

}
void InventoryUI::Update(float _Delta)
{
	Inventory00->GetExplaneRender()->SetTexture(ItemData::MainItemData->GetExplaneRender());
	Inventory00->GetItmeRender()->SetTexture(ItemData::MainItemData->GetWeaponRender());
	MoveItem();
}

void InventoryUI::SetInventory()
{
	Inventory00 = GetLevel()->CreateActor<InventoryButton>();
	Inventory00->GetTransform()->SetParent(GetTransform());
	Inventory00->GetRender()->GetTransform()->SetLocalPosition(InventoryPos00);
	Inventory00->GetExplaneRender()->GetTransform()->SetLocalPosition(ExplanePos00);
	Inventory00->GetItmeRender()->GetTransform()->SetLocalPosition(InventoryPos00);
	Inventory00->GetRender_Select()->GetTransform()->SetLocalPosition(InventoryPos00);

	Inventory00->SetPressEvent([this]()
			{
			});
}

void InventoryUI::MoveItem()
{
	if (true == Inventory00->GetPressValue())
	{
		Inventory00->GetExplaneRender()->GetTransform()->SetLocalPosition(Inventory00->GetMousePos());
		Inventory00->GetItmeRender()->GetTransform()->SetLocalPosition(Inventory00->GetMousePos());
	}
	else
	{
		Inventory00->GetExplaneRender()->GetTransform()->SetLocalPosition(ExplanePos00);
		Inventory00->GetItmeRender()->GetTransform()->SetLocalPosition(InventoryPos00);
	}
}
