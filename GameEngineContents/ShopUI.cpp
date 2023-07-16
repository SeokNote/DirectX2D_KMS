#include "PrecompileHeader.h"
#include "ShopUI.h"
#include "InventoryUI.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "ContentButton.h"
#include "InventoryButton.h"
#include "ItemData.h"
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


	ShopUIRender = CreateComponent<GameEngineUIRenderer>(150);
	ShopUIRender->SetTexture("ShopBase.png");
	ShopUIRender->GetTransform()->SetLocalPosition({ -400.0f,0.0f,0.0f });
	ShopUIRender->GetTransform()->SetLocalScale(ShopUIScale);

	ItemRender0 = CreateComponent<GameEngineUIRenderer>(151);
	ItemRender0->SetTexture("CosmosUI.png");
	ItemRender0->GetTransform()->SetLocalPosition({ -580.0f,190.0f,0.0f });
	ItemRender0->GetTransform()->SetLocalScale(ItemScale);

	
	//	
	InventoryUIPtr = GetLevel()->CreateActor<InventoryUI>();

	SetItem();
}
void ShopUI::Update(float _Delta)
{
	if (GameEngineInput::IsDown("ESC"))
	{
		InventoryUIPtr->Off();
		Death();
	}
}

void ShopUI::SetItem()
{
	ItemButton0 = GetLevel()->CreateActor<ContentButton>();
	ItemButton0->GetTransform()->SetParent(GetTransform());
	ItemButton0->GetTransform()->SetLocalPosition({ -369.0f,171.0f,0.0f });
	ItemButton0->GetRender()->SetTexture("ItemBase0.png");
	ItemButton0->GetRender()->GetTransform()->SetWorldScale({ 334.0f,105.0f,0.0f });
	ItemButton0->GetRender_Select()->SetTexture("ItemSelect0.png");
	ItemButton0->GetRender_Select()->GetTransform()->SetWorldScale({ 334.0f,105.0f,0.0f });
	ItemButton0->GetExplaneRender()->SetTexture("SpaceWeaponEx.png");
	ItemButton0->GetExplaneRender()->GetTransform()->SetLocalPosition({ 370.0f,-125.0f,0.0f });
	ItemButton0->GetExplaneRender()->GetTransform()->SetWorldScale({ 396.0f,360.0f,1.0f });
	ItemButton0->SetEvent([this]()
		{
			ItemData::MainItemData->SetItemNumber(1);
			ItemData::MainItemData->SetWeaponRender("CosmosUI.png");
			ItemData::MainItemData->SetExplaneRender("SpaceWeaponEx.png");
			ItemButton0->Death();
			ItemRender0->Death();
		});
}
