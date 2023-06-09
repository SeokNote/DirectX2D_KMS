#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
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
	std::shared_ptr<class GameEngineUIRenderer> BuildSelectTextUI;
	std::shared_ptr<class GameEngineUIRenderer> BuildSelectUI;

	std::shared_ptr<class GameEngineCollision> ButtonCol_0;
	std::shared_ptr<class GameEngineCollision> ButtonCol_1;
	std::shared_ptr<class GameEngineCollision> ButtonCol_2;

	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
	float4 SelectTextBoxScale = { 202.f, 181.0f,0.0f };
	float4 SelectTextScale = { 290.f, 47.0f,0.0f };

//	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };



	int IndexCount = 0;
};

