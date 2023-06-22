#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TunakJumpEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	TunakJumpEffect();
	~TunakJumpEffect();

	// delete Function
	TunakJumpEffect(const TunakJumpEffect& _Other) = delete;
	TunakJumpEffect(TunakJumpEffect&& _Other) noexcept = delete;
	TunakJumpEffect& operator=(const TunakJumpEffect& _Other) = delete;
	TunakJumpEffect& operator=(TunakJumpEffect&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TunakJumpEffectRender;
	float Time = 0.0f;
	float StartAlpha = 0.8f;
	float AlphaTime = 0.0f;
	bool Check = false;
};

