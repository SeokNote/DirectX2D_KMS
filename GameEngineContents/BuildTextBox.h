#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BuildTextBox : public GameEngineActor
{
public:
	// constrcuter destructer
	BuildTextBox();
	~BuildTextBox();

	// delete Function
	BuildTextBox(const BuildTextBox& _Other) = delete;
	BuildTextBox(BuildTextBox&& _Other) noexcept = delete;
	BuildTextBox& operator=(const BuildTextBox& _Other) = delete;
	BuildTextBox& operator=(BuildTextBox&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> BuildTextBoxUI;
	std::shared_ptr<class GameEngineUIRenderer> BuildTextBoxUI_S;

	std::shared_ptr<class GameEngineCollision> ButtonCol_0;
	std::shared_ptr<class GameEngineCollision> ButtonCol_1;
	std::shared_ptr<class GameEngineCollision> ButtonCol_2;

	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
//	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };

	float4 ButtonColScale = { 300.0f,60.0f,0.0f };

	float4 ButtonPos_0 = { 480.0f, -30.0f , -100.0f };
	float4 ButtonPos_1 = { 480.0f, -30.0f , -100.0f };
	float4 ButtonPos_2 = { 480.0f, -30.0f , -100.0f };

	int IndexCount = 0;
};

