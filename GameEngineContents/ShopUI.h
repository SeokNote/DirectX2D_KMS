#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
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

private:

	float4 ShopUIScale = { 492.0f,720.0f,0.0f };

	std::shared_ptr<class GameEngineUIRenderer> ShopUIRender;
	std::shared_ptr<class GameEngineUIRenderer> MapTabBaseBG;
};

//텝과 인벤토리 기초적인 틀만 만들기