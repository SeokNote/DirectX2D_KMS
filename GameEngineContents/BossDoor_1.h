#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossDoor_1 :public GameEngineActor
{
public:
	// constrcuter destructer
	BossDoor_1();
	~BossDoor_1();

	// delete Function
	BossDoor_1(const BossDoor_1& _Other) = delete;
	BossDoor_1(BossDoor_1&& _Other) noexcept = delete;
	BossDoor_1& operator=(const BossDoor_1& _Other) = delete;
	BossDoor_1& operator=(BossDoor_1&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BossDoor2Render;
	std::shared_ptr<class GameEngineCollision> BossDoor2Col;
	float4 Door2Pos = { 16314.0f,-118.0f, -750.0f };
	float4 Door2Scale = { 220.0f,260.0f,0.f };
	float Time = 0.0f;
};

