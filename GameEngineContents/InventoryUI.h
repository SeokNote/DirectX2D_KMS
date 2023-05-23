#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
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

	float4 InventoryUIScale = { 492.0f,720.0f,0.0f };

	std::shared_ptr<class GameEngineUIRenderer> InventoryUIRender;
	std::shared_ptr<class GameEngineUIRenderer> MapTabBaseBG;
};

//텝과 인벤토리 기초적인 틀만 만들기