#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class BossDeadEffect : public GameEngineActor
{
public:
	// constrcuter destructer
	BossDeadEffect();
	~BossDeadEffect();

	// delete Function
	BossDeadEffect(const BossDeadEffect& _Other) = delete;
	BossDeadEffect(BossDeadEffect&& _Other) noexcept = delete;
	BossDeadEffect& operator=(const BossDeadEffect& _Other) = delete;
	BossDeadEffect& operator=(BossDeadEffect&& _Other) noexcept = delete;

	void SetRaioPos(float _Value)
	{
		NextPos = _Value;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_0;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_1;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_2;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_3;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_4;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_5;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_6;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_7;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_8;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadEffecr_9;

	void SetDir();
	float EffectDir = GameEngineMath::PIE2 / 10.0f;
	float NextPos = 0.0f;
		
};

