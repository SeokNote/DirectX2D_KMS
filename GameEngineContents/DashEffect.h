#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class DashEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	DashEffect();
	~DashEffect();

	// delete Function
	DashEffect(const DashEffect& _Other) = delete;
	DashEffect(DashEffect&& _Other) noexcept = delete;
	DashEffect& operator=(const DashEffect& _Other) = delete;
	DashEffect& operator=(DashEffect&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerDashRender_0;
	float Time = 0.0f;
	float StartAlpha = 0.5f;
	float AlphaTime = 0.0f;
	bool Check = false;
};

