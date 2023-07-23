#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class SpawnStage1_1 : public GameEngineActor
{
public:
	static SpawnStage1_1* MainSpawnStage1_1;
	// constrcuter destructer
	SpawnStage1_1();
	~SpawnStage1_1();

	// delete Function
	SpawnStage1_1(const SpawnStage1_1& _Other) = delete;
	SpawnStage1_1(SpawnStage1_1&& _Other) noexcept = delete;
	SpawnStage1_1& operator=(const SpawnStage1_1& _Other) = delete;
	SpawnStage1_1& operator=(SpawnStage1_1&& _Other) noexcept = delete;
	bool GetBelialCreat()
	{
		return BelialCreat;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SpawnStage1_1Render = nullptr;
	std::shared_ptr<class GameEngineCollision> SpawnStage1_1Col = nullptr;
	std::shared_ptr<class SmallBat> MinoBat = nullptr;
	float4 Scale = { 128.0f,128.0f,0.0f };
	bool BelialCreat = false;
};

