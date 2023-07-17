#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ItemData.h"
// Ό³Έν :
class GameEngineUIRenderer;
class GameEngineCollision;
class ShopButton : public GameEngineActor
{
public:
	static ShopButton* ShopButtonPtr;

	// constrcuter destructer
	ShopButton();
	~ShopButton();

	// delete Function
	ShopButton(const ShopButton& _Other) = delete;
	ShopButton(ShopButton&& _Other) noexcept = delete;
	ShopButton& operator=(const ShopButton& _Other) = delete;
	ShopButton& operator=(ShopButton&& _Other) noexcept = delete;
	void SetEvent(std::function<void()> _Click)
	{
		Click = _Click;
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
	ItemData& GetItemData()
	{
		return Data;
	}
protected:
	void Start() override;
	void Update(float _Delta) override;

private:
	ItemData Data = ItemData();
	std::shared_ptr<GameEngineUIRenderer> Render;
	std::shared_ptr<GameEngineUIRenderer> Render_Select;
	std::shared_ptr<GameEngineUIRenderer> ExplaneRender;
	std::function<void()> Click;

};

