#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class ShopTextBox : public GameEngineActor
{
public:
	// constrcuter destructer
	ShopTextBox();
	~ShopTextBox();

	// delete Function
	ShopTextBox(const ShopTextBox& _Other) = delete;
	ShopTextBox(ShopTextBox&& _Other) noexcept = delete;
	ShopTextBox& operator=(const ShopTextBox& _Other) = delete;
	ShopTextBox& operator=(ShopTextBox&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> ShopTextBoxUI;
	std::shared_ptr<class GameEngineUIRenderer> ShopTextBoxUI_S;

	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
	//	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };
};

