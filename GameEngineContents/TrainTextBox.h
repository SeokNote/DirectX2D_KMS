#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class TrainTextBox : public GameEngineActor
{
public:
	// constrcuter destructer
	TrainTextBox();
	~TrainTextBox();

	// delete Function
	TrainTextBox(const TrainTextBox& _Other) = delete;
	TrainTextBox(TrainTextBox&& _Other) noexcept = delete;
	TrainTextBox& operator=(const TrainTextBox& _Other) = delete;
	TrainTextBox& operator=(TrainTextBox&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> TrainTextBoxUI;
	std::shared_ptr<class GameEngineUIRenderer> TrainTextBoxUI_S;

	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
	//	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };
};

