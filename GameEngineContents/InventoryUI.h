#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class InventoryUI : public GameEngineActor
{
public:
	// constrcuter destructer
	InventoryUI();
	~InventoryUI();

	// delete Function
	InventoryUI(const InventoryUI& _Other) = delete;
	InventoryUI(InventoryUI&& _Other) noexcept = delete;
	InventoryUI& operator=(const InventoryUI& _Other) = delete;
	InventoryUI& operator=(InventoryUI&& _Other) noexcept = delete;

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
	float4 InventoryPos00 = { 235.0f,-30.0f,0.0f };
	float4 ExplanePos00 = { 30.0f,-130.0f,0.0f };

	
};
