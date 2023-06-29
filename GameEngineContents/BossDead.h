#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossDead : public GameEngineActor
{
public:
	// constrcuter destructer
	BossDead();
	~BossDead();

	// delete Function
	BossDead(const BossDead& _Other) = delete;
	BossDead(BossDead&& _Other) noexcept = delete;
	BossDead& operator=(const BossDead& _Other) = delete;
	BossDead& operator=(BossDead&& _Other) noexcept = delete;

	static std::shared_ptr<BossDead> CreateSubBG(GameEngineLevel* _Level, const float4& _Pos);

protected:
	void Start() override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BelialSubBGRender;

	float XValue = 100.0f;
	float YValue = 100.0f;
};

