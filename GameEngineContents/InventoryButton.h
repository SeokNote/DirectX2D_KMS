#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ItemData.h"
// Ό³Έν :
class GameEngineUIRenderer;
class GameEngineCollision;
class InventoryButton : public GameEngineActor
{
public:
	static InventoryButton* InventoryButtonPtr;

	// constrcuter destructer
	InventoryButton();
	~InventoryButton();

	// delete Function
	InventoryButton(const InventoryButton& _Other) = delete;
	InventoryButton(InventoryButton&& _Other) noexcept = delete;
	InventoryButton& operator=(const InventoryButton& _Other) = delete;
	InventoryButton& operator=(InventoryButton&& _Other) noexcept = delete;
	void SetClick(std::function<void()> _Click)
	{
		Click = _Click;
	}
	void SetDrop(std::function<void()> _Drop)
	{
		Drop = _Drop;
	}
	void SetDropItem(std::function<void()> _DropItem)
	{
		DropItem = _DropItem;
	}
	void SetPressEvent(std::function<void()> _Press)
	{
		Press = _Press;
	}
	
	std::shared_ptr<GameEngineUIRenderer> GetRender()
	{
		return Render;
	}

	std::shared_ptr<GameEngineUIRenderer> GetExplaneRender()
	{
		return ExplaneRender;
	}
	std::shared_ptr<GameEngineUIRenderer> GetRender_Select()
	{
		return Render_Select;
	}
	std::shared_ptr<GameEngineUIRenderer> GetItmeRender()
	{
		return ItmeRender;
	}

	bool GetPressValue()
	{
		return PressValue;
	}
	bool GetSwichValue()
	{
		return SwichValue;
	}
	float4 GetMousePos()
	{
		return Mouse;
	}
	void SetItemData(WeaponDatas _Data)
	{
		I_Data.SetData(_Data);
	}
	ItemData& GetData()
	{
		return I_Data;
	}
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	ItemData I_Data = ItemData();
	std::shared_ptr<GameEngineUIRenderer> Render;
	std::shared_ptr<GameEngineUIRenderer> Render_Select;
	std::shared_ptr<GameEngineUIRenderer> ExplaneRender;
	std::shared_ptr<GameEngineUIRenderer> ItmeRender;

	std::function<void()> Click;
	std::function<void()> Drop;
	std::function<void()> DropItem;
	std::function<void()> Press;


	float4 YellowColor = { 1.0f,0.93f,0.721f };
	float4 Mouse = float4::Zero;
	bool PressValue = false;
	bool SwichValue = false;
};

