#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

// Ό³Έν :
class PlayerStat : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerStat();
	~PlayerStat();

	// delete Function
	PlayerStat(const PlayerStat& _Other) = delete;
	PlayerStat(PlayerStat&& _Other) noexcept = delete;
	PlayerStat& operator=(const PlayerStat& _Other) = delete;
	PlayerStat& operator=(PlayerStat&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;

private:

	float4 StatUIScale = { 470.0f,330.0f,0.0f };
	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };
	float4 ButtonScale = { 88.0f,76.0f,0.0f };

	std::shared_ptr<GameEngineUIRenderer> PlayerStatUI;
	std::shared_ptr<GameEngineUIRenderer> FoodStatUI;
	std::shared_ptr<GameEngineUIRenderer> ExitButton;
	std::shared_ptr<GameEngineUIRenderer> ExitButtonSelect;

	std::shared_ptr<class GameEngineCollision> ExitButtonCollsion;


};
