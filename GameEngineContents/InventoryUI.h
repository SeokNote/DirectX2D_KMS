#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ItemData.h"
enum class PrevClick
{
	NONE,
	INVENTORT0,
	W_INVENTORT0,
	W_INVENTORT1,
};
// Ό³Έν :
class InventoryUI : public GameEngineActor
{
public:
	static InventoryUI* InventoryUIPtr;
	// constrcuter destructer
	InventoryUI();
	~InventoryUI();

	// delete Function
	InventoryUI(const InventoryUI& _Other) = delete;
	InventoryUI(InventoryUI&& _Other) noexcept = delete;
	InventoryUI& operator=(const InventoryUI& _Other) = delete;
	InventoryUI& operator=(InventoryUI&& _Other) noexcept = delete;
	std::shared_ptr<class InventoryButton> GetInven0()
	{
		return Inventory00;
	}
	std::shared_ptr<class InventoryButton> GetWeaponInven0()
	{
		return WeaponInven0;
	}
	std::shared_ptr<class InventoryButton> GetWeaponInven1()
	{
		return WeaponInven1;
	}
	std::shared_ptr<class GameEngineUIRenderer> GetInventoryUI()
	{
		return InventoryUIRender;
	}
protected:
	void Start();
	void Update(float _Delta) override;

private:
	void SetInventory();
	void MoveItem();
	float4 InventoryUIScale = { 492.0f,720.0f,0.0f };

	std::shared_ptr<class GameEngineUIRenderer> InventoryUIRender;
	std::shared_ptr<class GameEngineUIRenderer> MapTabBaseBG;

	std::shared_ptr<class InventoryButton> Inventory00;
	std::shared_ptr<class InventoryButton> WeaponInven0;
	std::shared_ptr<class InventoryButton> WeaponInven1;


	float4 InventoryPos00 = { 235.0f,-30.0f,0.0f };
	float4 ExplanePos00 = { 30.0f,-130.0f,0.0f };

	float4 W_InventoryPos0 = { 255.0f,189.0f,0.0f };
	float4 W_ExplanePos0 = { 30.0f,30.0f,0.0f };

	float4 W_InventoryPos1 = { 474.0f,189.0f,0.0f };
	float4 W_ExplanePos1 = { 130.0f,30.0f,0.0f };
	std::vector<class InventoryButton> InventoryButtons;
	bool AreaOut = false;
	int INVEN0index = 0;
	int wINVEN0index0 = 0;

	int wINVEN0index1 = 0;
	PrevClick Prev = PrevClick::NONE;
	WeaponDatas PrevData = WeaponDatas::VACANCY;
};
