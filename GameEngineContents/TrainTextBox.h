#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
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
	std::shared_ptr<class GameEngineUIRenderer> TrainTextBoxUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> TrainTextBoxUI_S = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> TrainSelectTextUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> TrainSelectUI = nullptr;
	std::shared_ptr<class UIFontRender> TextStrting = nullptr;

	std::shared_ptr<class GameEngineCollision> ButtonCol_0 = nullptr;
	std::shared_ptr<class GameEngineCollision> ButtonCol_1 = nullptr;
	std::shared_ptr<class GameEngineCollision> ButtonCol_2 = nullptr;

	static std::shared_ptr<class AbilityUI> AbilityUIPtr;
	std::string FirstDialog = "자네 왔군! 훈련할 텐가?";
	int count = 0;
	float DelayTime = 0;
	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
	float4 SelectTextBoxScale = { 227.f, 180.0f,0.0f };
	float4 SelectTextScale = { 290.f, 47.0f,0.0f };
	//	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };
};

