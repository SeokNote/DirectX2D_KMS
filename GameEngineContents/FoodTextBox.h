#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
class FoodTextBox : public GameEngineActor
{
public:
	// constrcuter destructer
	FoodTextBox();
	~FoodTextBox();

	// delete Function
	FoodTextBox(const FoodTextBox& _Other) = delete;
	FoodTextBox(FoodTextBox&& _Other) noexcept = delete;
	FoodTextBox& operator=(const FoodTextBox& _Other) = delete;
	FoodTextBox& operator=(FoodTextBox&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> FoodTextBoxUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> FoodTextBoxUI_S = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> FoodSelectTextUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> FoodSelectUI = nullptr;
	std::shared_ptr<class UIFontRender> TextStrting = nullptr;

	std::shared_ptr<class GameEngineCollision> ButtonCol_0 = nullptr;
	std::shared_ptr<class GameEngineCollision> ButtonCol_1 = nullptr;
	std::shared_ptr<class GameEngineCollision> ButtonCol_2 = nullptr;
	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
	float4 SelectTextBoxScale = { 240.f, 186.0f,0.0f };
	float4 SelectTextScale = { 290.f, 47.0f,0.0f };

	std::string FirstDialog = "오늘은 어떤 요리를 드시러 오셨나요?";
	int count = 0;
	float DelayTime = 0;
};

