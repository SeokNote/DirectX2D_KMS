#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
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
	std::shared_ptr<class GameEngineUIRenderer> FoodTextBoxUI;
	std::shared_ptr<class GameEngineUIRenderer> FoodTextBoxUI_S;

	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
	//	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };
};

