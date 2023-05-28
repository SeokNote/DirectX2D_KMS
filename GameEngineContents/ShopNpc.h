#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class ShopNpc : public GameEngineActor
{
public:
	// constrcuter destructer
	ShopNpc();
	~ShopNpc();

	// delete Function
	ShopNpc(const ShopNpc& _Other) = delete;
	ShopNpc(ShopNpc&& _Other) noexcept = delete;
	ShopNpc& operator=(const ShopNpc& _Other) = delete;
	ShopNpc& operator=(ShopNpc&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 ShopNpcScale = { 52.0f,84.0f,0.0f };
	float4 FScale = { 52.0f,56.0f,0.0f };

	std::shared_ptr<class GameEngineSpriteRenderer> ShopNpcRender;
	std::shared_ptr<class GameEngineSpriteRenderer> FRender;

	std::shared_ptr<class GameEngineCollision> ShopNpcCol;


	//Position
	float4 ShopNpcPos1 = { 1790.0f,43.0f,-750.f };
	float4 FRenderPos = { 1790.0f,133.0f,-750.f };


	std::shared_ptr<class ShopUI> ShopUIPtr;
	std::shared_ptr<class InventoryUI> InventoryUIPtr;

	int IndexCount = 0;
};

