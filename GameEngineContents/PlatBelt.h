#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class PlatBelt : public GameEngineActor
{
public:
	// constrcuter destructer
	PlatBelt();
	~PlatBelt();

	// delete Function
	PlatBelt(const PlatBelt& _Other) = delete;
	PlatBelt(PlatBelt&& _Other) noexcept = delete;
	PlatBelt& operator=(const PlatBelt& _Other) = delete;
	PlatBelt& operator=(PlatBelt&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:

	float4 LasorScale = { 1280.0f,220.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> PlatBeltRender;
	std::shared_ptr<class GameEngineSpriteRenderer> PlatBeltRender_1;
	std::shared_ptr<class GameEngineCollision> PlatBeltCol;

	float DeathTime = 0.0f;
	float4 TwoFloor = { 0.0f,130.0f,0.0f };
};

