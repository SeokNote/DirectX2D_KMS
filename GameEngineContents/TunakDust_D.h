#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TunakDust_D : public GameEngineActor
{
public:
	// constrcuter destructer
	TunakDust_D();
	~TunakDust_D();

	// delete Function
	TunakDust_D(const TunakDust_D& _Other) = delete;
	TunakDust_D(TunakDust_D&& _Other) noexcept = delete;
	TunakDust_D& operator=(const TunakDust_D& _Other) = delete;
	TunakDust_D& operator=(TunakDust_D&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TunakDustRender;
	float DeadTime = 0.0f;
};

