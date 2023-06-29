#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class BossBase :public GameEngineActor
{
public:
	// constrcuter destructer
	BossBase();
	~BossBase();

	// delete Function
	BossBase(const BossBase& _Other) = delete;
	BossBase(BossBase&& _Other) noexcept = delete;
	BossBase& operator=(const BossBase& _Other) = delete;
	BossBase& operator=(BossBase&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void MonsterCameraShack();
private:
	float ShakeTime = 0.0f;
	float y = 0.0f;
	float x = 0.0f;
};

