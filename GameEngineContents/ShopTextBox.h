#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
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
	std::shared_ptr<class GameEngineUIRenderer> ShopTextBoxUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> ShopTextBoxUI_S = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> ShopSelectTextUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> ShopSelectUI = nullptr;
	std::shared_ptr<class UIFontRender> TextStrting = nullptr;

	std::shared_ptr<class GameEngineCollision> ButtonCol_0 = nullptr;
	std::shared_ptr<class GameEngineCollision> ButtonCol_1 = nullptr;
	std::shared_ptr<class GameEngineCollision> ButtonCol_2 = nullptr;
	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
	float4 SelectTextBoxScale = { 240.f, 186.0f,0.0f };
	float4 SelectTextScale = { 290.f, 47.0f,0.0f };
	//	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };

	std::shared_ptr<class ShopUI> ShopUIPtr;
	std::string FirstDialog = "안녕하세요! 좋은 물건이 많이있어요!";

	int count = 0;
	float DelayTime = 0;
};

