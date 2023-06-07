#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossDoor_2 :public GameEngineActor
{
public:
	// constrcuter destructer
	BossDoor_2();
	~BossDoor_2();

	// delete Function
	BossDoor_2(const BossDoor_2& _Other) = delete;
	BossDoor_2(BossDoor_2&& _Other) noexcept = delete;
	BossDoor_2& operator=(const BossDoor_2& _Other) = delete;
	BossDoor_2& operator=(BossDoor_2&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BossDoor3Render;
	std::shared_ptr<class GameEngineCollision> BossDoor3Col;
	float4 Door3Pos = { 3046,-135.0f,-801.0f };
	float4 Door3Scale = { 228.0f,260.0f,0.f };
	float Time = 0.0f;
};

