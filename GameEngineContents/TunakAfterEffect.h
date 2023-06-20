#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TunakAfterEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	TunakAfterEffect();
	~TunakAfterEffect();

	// delete Function
	TunakAfterEffect(const TunakAfterEffect& _Other) = delete;
	TunakAfterEffect(TunakAfterEffect&& _Other) noexcept = delete;
	TunakAfterEffect& operator=(const TunakAfterEffect& _Other) = delete;
	TunakAfterEffect& operator=(TunakAfterEffect&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TunakAfterEffectRender;
	float Time = 0.0f;
	float StartAlpha = 0.8f;
	float AlphaTime = 0.0f;
	bool Check = false;
};

