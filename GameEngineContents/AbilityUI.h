#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
// Ό³Έν :
class AbilityUI : public GameEngineActor
{
public:
	// constrcuter destructer
	AbilityUI();
	~AbilityUI();

	// delete Function
	AbilityUI(const AbilityUI& _Other) = delete;
	AbilityUI(AbilityUI&& _Other) noexcept = delete;
	AbilityUI& operator=(const AbilityUI& _Other) = delete;
	AbilityUI& operator=(AbilityUI&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;

private:

	float4 AbilityUIScale = { 1280.0f,720.0f,0.0f };
	float4 ExitButtonScale = { 96.0f,96.0f,0.0f };

	float4 Button_RedPos = { -494.0f,-225.0f,-250.0f };
	float4 Button_GreenPos= { -233.0f,-225.0f,-250.0f };
	float4 Button_WhitePos= { 20.0f,-225.0f,-250.0f };
	float4 Button_BluePos = { 269.0f,-225.0f,-250.0f };
	float4 Button_YellowPos = {522.0f,-225.0f,-250.0f};

	float4 Button_Scale = { 72.0f,72.0f,0.0f };

	std::shared_ptr<GameEngineUIRenderer> AbilityBase;
	std::shared_ptr<GameEngineUIRenderer> AbilityBaseBG;

	std::shared_ptr<GameEngineUIRenderer> Button_RedRender;
	std::shared_ptr<GameEngineUIRenderer> Button_GreenRender;
	std::shared_ptr<GameEngineUIRenderer> Button_WhiteRender;
	std::shared_ptr<GameEngineUIRenderer> Button_BlueRender;
	std::shared_ptr<GameEngineUIRenderer> Button_YellowRender;

	std::shared_ptr<class GameEngineCollision> Button_RedCol;
	std::shared_ptr<class GameEngineCollision> Button_GreenCol;
	std::shared_ptr<class GameEngineCollision> Button_WhiteCol;
	std::shared_ptr<class GameEngineCollision> Button_BlueCol;
	std::shared_ptr<class GameEngineCollision> Button_YellowCol;

};

