#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossDoor_0 :public GameEngineActor
{
public:
	// constrcuter destructer
	BossDoor_0();
	~BossDoor_0();

	// delete Function
	BossDoor_0(const BossDoor_0& _Other) = delete;
	BossDoor_0(BossDoor_0&& _Other) noexcept = delete;
	BossDoor_0& operator=(const BossDoor_0& _Other) = delete;
	BossDoor_0& operator=(BossDoor_0&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BossDoor1Render;
	std::shared_ptr<class GameEngineCollision> BossDoor1Col;
	float4 Door1Pos = { 13267.0f,-68.0f,-750.f };
	float4 Door1Scale = { 220.0f,260.0f,0.f };
	float Time = 0.0f;
};

