#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossStage_1 : public GameEngineActor
{
public:
	// constrcuter destructer
	BossStage_1();
	~BossStage_1();

	// delete Function
	BossStage_1(const BossStage_1& _Other) = delete;
	BossStage_1(BossStage_1&& _Other) noexcept = delete;
	BossStage_1& operator=(const BossStage_1& _Other) = delete;
	BossStage_1& operator=(BossStage_1&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 BossStage_1Scale = { 1408.0f,1344,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> BossStage_1Render;
};

