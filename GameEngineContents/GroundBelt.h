#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GroundBelt : public GameEngineActor
{
public:
	// constrcuter destructer
	GroundBelt();
	~GroundBelt();

	// delete Function
	GroundBelt(const GroundBelt& _Other) = delete;
	GroundBelt(GroundBelt&& _Other) noexcept = delete;
	GroundBelt& operator=(const GroundBelt& _Other) = delete;
	GroundBelt& operator=(GroundBelt&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:

	float4 LasorScale = { 1280.0f,220.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> GroundBeltRender;
	std::shared_ptr<class GameEngineCollision> GroundBeltCol;

	float DeathTime = 0.0f;
};

