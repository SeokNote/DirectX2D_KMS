#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ItemData.h"
// Ό³Έν :
class ShopUI : public GameEngineActor
{
public:
	// constrcuter destructer
	ShopUI();
	~ShopUI();

	// delete Function
	ShopUI(const ShopUI& _Other) = delete;
	ShopUI(ShopUI&& _Other) noexcept = delete;
	ShopUI& operator=(const ShopUI& _Other) = delete;
	ShopUI& operator=(ShopUI&& _Other) noexcept = delete;
protected:
	void Start();
	void Update(float _Delta) override;
	void SetItem();
private:

	float4 ShopUIScale = { 492.0f,720.0f,0.0f };
	float4 ItemScale = { 44.0f,132.0f,0.0f };

	std::shared_ptr<class GameEngineUIRenderer> ShopUIRender;
	std::shared_ptr<class GameEngineUIRenderer> MapTabBaseBG;
	std::shared_ptr<class GameEngineUIRenderer> ItemRender0;
	std::shared_ptr<class InventoryUI> InventoryUIPtr;
	std::shared_ptr<class ShopButton> ItemButton0;

	WeaponDatas WeaponType = WeaponDatas::SpaceSword;

};

