#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class SpawnStage1_2 : public GameEngineActor
{
public:
	static SpawnStage1_2* MainSpawnStage1_2;
	// constrcuter destructer
	SpawnStage1_2();
	~SpawnStage1_2();

	// delete Function
	SpawnStage1_2(const SpawnStage1_2& _Other) = delete;
	SpawnStage1_2(SpawnStage1_2&& _Other) noexcept = delete;
	SpawnStage1_2& operator=(const SpawnStage1_2& _Other) = delete;
	SpawnStage1_2& operator=(SpawnStage1_2&& _Other) noexcept = delete;
	bool GetMonsterCreat()
	{
		return MonsterCreat;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SpawnStage1_2Render = nullptr;
	std::shared_ptr<class GameEngineCollision> SpawnStage1_2Col = nullptr;
	std::shared_ptr<class SmallBat> MinoBat = nullptr;
	float4 Scale = { 128.0f,128.0f,0.0f };
	bool MonsterCreat = false;
};

