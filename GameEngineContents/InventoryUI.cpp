#include "PrecompileHeader.h"
#include "InventoryUI.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "InventoryButton.h"
#include "ItemData.h"
InventoryUI* InventoryUI::InventoryUIPtr = nullptr;
InventoryUI::InventoryUI()
{
	InventoryUIPtr = this;
}

InventoryUI::~InventoryUI()
{
}

void InventoryUI::InventoryOn()
{
	InventoryUIRender->On();
	WeaponInven0->GetExplaneRender()->On();
	WeaponInven0->GetItmeRender()->On();
	WeaponInven0->GetRender_Select()->On();
	WeaponInven0->GetRender()->On();
	WeaponInven1->GetExplaneRender()->On();
	WeaponInven1->GetItmeRender()->On();
	WeaponInven1->GetRender_Select()->On();
	WeaponInven1->GetRender()->On();
	Inventory00->GetExplaneRender()->On();
	Inventory00->GetItmeRender()->On();
	Inventory00->GetRender_Select()->On();
	Inventory00->GetRender()->On();
	IsOff = true;
}

void InventoryUI::InventoryOff()
{
	InventoryUIRender->Off();
	WeaponInven0->GetExplaneRender()->Off();
	WeaponInven0->GetItmeRender()->Off();
	WeaponInven0->GetRender_Select()->Off();
	WeaponInven0->GetRender()->Off();
	WeaponInven1->GetExplaneRender()->Off();
	WeaponInven1->GetItmeRender()->Off();
	WeaponInven1->GetRender_Select()->Off();
	WeaponInven1->GetRender()->Off();
	Inventory00->GetExplaneRender()->Off();
	Inventory00->GetItmeRender()->Off();
	Inventory00->GetRender_Select()->Off();
	Inventory00->GetRender()->Off();
	IsOff = false;

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
	Inventory00->GetExplaneRender()->SetTexture(Inventory00->GetData().ItemExplaneRender);
	Inventory00->GetItmeRender()->SetTexture(Inventory00->GetData().ItemRender);
	WeaponInven0->GetExplaneRender()->SetTexture(WeaponInven0->GetData().ItemExplaneRender);
	WeaponInven0->GetItmeRender()->SetTexture(WeaponInven0->GetData().ItemRender);
	WeaponInven1->GetExplaneRender()->SetTexture(WeaponInven1->GetData().ItemExplaneRender);
	WeaponInven1->GetItmeRender()->SetTexture(WeaponInven1->GetData().ItemRender);
	MoveItem();
	CheckData = WeaponInven0->GetData().WeaponType;
}

void InventoryUI::SetInventory()
{
	Inventory00 = GetLevel()->CreateActor<InventoryButton>();

	Inventory00->GetTransform()->SetParent(GetTransform());
	Inventory00->GetRender()->GetTransform()->SetLocalPosition(InventoryPos00);
	Inventory00->GetExplaneRender()->GetTransform()->SetLocalPosition(ExplanePos00);
	Inventory00->GetItmeRender()->GetTransform()->SetLocalPosition(InventoryPos00);
	Inventory00->GetRender_Select()->GetTransform()->SetLocalPosition(InventoryPos00);
	Inventory00->SetClick([this]()
		{
			if (Inventory00->GetData().WeaponType != WeaponDatas::VACANCY)
			{
				Prev = PrevClick::INVENTORT0;
			}
		});
	Inventory00->SetDropItem([this]()
		{
			switch (Prev)
			{
			case PrevClick::NONE:
				Prev = PrevClick::NONE;
				break;
			case PrevClick::INVENTORT0:
				Inventory00->SetItemData(Inventory00->GetData().WeaponType);
				break;
			case PrevClick::W_INVENTORT0:
				PrevData = Inventory00->GetData().WeaponType;
				Inventory00->SetItemData(WeaponInven0->GetData().WeaponType);
				WeaponInven0->SetItemData(PrevData);
				Prev = PrevClick::NONE;
				break;
			case PrevClick::W_INVENTORT1:
				PrevData = Inventory00->GetData().WeaponType;
				Inventory00->SetItemData(WeaponInven1->GetData().WeaponType);
				WeaponInven1->SetItemData(PrevData);
				Prev = PrevClick::NONE;
				break;
			default:
				break;
			}
			});
	Inventory00->SetDrop([this]()
			{
				AreaOut = true;
			});
	WeaponInven0 = GetLevel()->CreateActor<InventoryButton>();
	WeaponInven0->SetItemData(WeaponDatas::GreatWeapon);
	WeaponInven0->GetTransform()->SetParent(GetTransform());
	WeaponInven0->GetRender()->GetTransform()->SetLocalPosition(W_InventoryPos0);
	WeaponInven0->GetRender()->SetTexture("W_ItemBase00.png");
	WeaponInven0->GetRender_Select()->SetTexture("W_ItemBase01.png");
	WeaponInven0->GetExplaneRender()->GetTransform()->SetLocalPosition(W_ExplanePos0);
	WeaponInven0->GetItmeRender()->GetTransform()->SetLocalPosition(W_InventoryPos0);
	WeaponInven0->GetRender_Select()->GetTransform()->SetLocalPosition(W_InventoryPos0);
	WeaponInven0->SetClick([this]()
		{
			if (WeaponInven0->GetData().WeaponType != WeaponDatas::VACANCY)
			{
				Prev = PrevClick::W_INVENTORT0;
			}
		});
	WeaponInven0->SetDrop([this]()
		{
			AreaOut = true;
		});
	WeaponInven0->SetDropItem([this]()
		{
			switch (Prev)
			{
			case PrevClick::NONE:
				Prev = PrevClick::NONE;
				break;
			case PrevClick::INVENTORT0:
				PrevData = WeaponInven0->GetData().WeaponType;
				WeaponInven0->SetItemData(Inventory00->GetData().WeaponType);
				Inventory00->SetItemData(PrevData);
				Prev = PrevClick::NONE;
				break;
			case PrevClick::W_INVENTORT0:
				WeaponInven0->SetItemData(WeaponInven0->GetData().WeaponType);
				break;
			case PrevClick::W_INVENTORT1:
				PrevData = WeaponInven0->GetData().WeaponType;
				WeaponInven0->SetItemData(WeaponInven1->GetData().WeaponType);
				WeaponInven1->SetItemData(PrevData);
				Prev = PrevClick::NONE;
				break;
			default:
				break;
			}
		});
	WeaponInven1 = GetLevel()->CreateActor<InventoryButton>();
	WeaponInven1->GetTransform()->SetParent(GetTransform());
	WeaponInven1->GetRender()->GetTransform()->SetLocalPosition(W_InventoryPos1);
	WeaponInven1->GetRender()->SetTexture("W_ItemBase00.png");
	WeaponInven1->GetRender_Select()->SetTexture("W_ItemBase01.png");
	WeaponInven1->GetExplaneRender()->GetTransform()->SetLocalPosition(W_ExplanePos1);
	WeaponInven1->GetItmeRender()->GetTransform()->SetLocalPosition(W_InventoryPos1);
	WeaponInven1->GetRender_Select()->GetTransform()->SetLocalPosition(W_InventoryPos1);
	WeaponInven1->SetClick([this]()
		{
			if (WeaponInven1->GetData().WeaponType != WeaponDatas::VACANCY)
			{
				Prev = PrevClick::W_INVENTORT1;
			}
		});
	WeaponInven1->SetDrop([this]()
		{
			AreaOut = true;
		});
	WeaponInven1->SetDropItem([this]()
		{
			switch (Prev)
			{
			case PrevClick::NONE:
				Prev = PrevClick::NONE;
				break;
			case PrevClick::INVENTORT0:
				PrevData = WeaponInven1->GetData().WeaponType;
				WeaponInven1->SetItemData(Inventory00->GetData().WeaponType);
				Inventory00->SetItemData(PrevData);
				Prev = PrevClick::NONE;
				break;
			case PrevClick::W_INVENTORT0:
				PrevData = WeaponInven1->GetData().WeaponType;
				WeaponInven1->SetItemData(WeaponInven0->GetData().WeaponType);
				WeaponInven0->SetItemData(PrevData);
				Prev = PrevClick::NONE;
				break;
			case PrevClick::W_INVENTORT1:
				WeaponInven1->SetItemData(WeaponInven1->GetData().WeaponType);
				break;
			default:
				break;
			}
		});
}

void InventoryUI::MoveItem()
{
	float4 MousePos = Inventory00->GetMousePos();
	if (true == Inventory00->GetPressValue())
	{
		if(Inventory00->GetData().WeaponType!=WeaponDatas::VACANCY)
		{
			Inventory00->GetExplaneRender()->GetTransform()->SetLocalPosition({ MousePos.x,MousePos.y,0.0f });
			Inventory00->GetItmeRender()->GetTransform()->SetLocalPosition({ MousePos.x,MousePos.y,0.0f });
			
		}

	}
	if (Inventory00->GetData().WeaponType != WeaponDatas::VACANCY && AreaOut == true)
	{
		Inventory00->GetExplaneRender()->GetTransform()->SetLocalPosition(ExplanePos00);
		Inventory00->GetItmeRender()->GetTransform()->SetLocalPosition(InventoryPos00);
		Prev = PrevClick::NONE;
		AreaOut = false;
	}
	if (true == WeaponInven0->GetPressValue())
	{
		if (WeaponInven0->GetData().WeaponType != WeaponDatas::VACANCY)
		{
			WeaponInven0->GetExplaneRender()->GetTransform()->SetWorldPosition({ MousePos.x,MousePos.y,0.0f });
			WeaponInven0->GetItmeRender()->GetTransform()->SetWorldPosition({ MousePos.x,MousePos.y,0.0f });

		}

	}
	if (WeaponInven0->GetData().WeaponType != WeaponDatas::VACANCY && AreaOut == true)
	{
		WeaponInven0->GetExplaneRender()->GetTransform()->SetWorldPosition(W_ExplanePos0);
		WeaponInven0->GetItmeRender()->GetTransform()->SetWorldPosition(W_InventoryPos0);
		Prev = PrevClick::NONE;
		AreaOut = false;
	}
	if (true == WeaponInven1->GetPressValue())
	{
		if (WeaponInven1->GetData().WeaponType != WeaponDatas::VACANCY)
		{
			WeaponInven1->GetExplaneRender()->GetTransform()->SetWorldPosition({ MousePos.x,MousePos.y,0.0f });
			WeaponInven1->GetItmeRender()->GetTransform()->SetWorldPosition({ MousePos.x,MousePos.y,0.0f });

		}

	}
	if (WeaponInven1->GetData().WeaponType != WeaponDatas::VACANCY && AreaOut == true)
	{
		WeaponInven1->GetExplaneRender()->GetTransform()->SetWorldPosition(W_ExplanePos1);
		WeaponInven1->GetItmeRender()->GetTransform()->SetWorldPosition(W_InventoryPos1);
		Prev = PrevClick::NONE;
		AreaOut = false;
	}

}
