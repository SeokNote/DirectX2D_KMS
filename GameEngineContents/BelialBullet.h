#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BelialBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	BelialBullet();
	~BelialBullet();

	// delete Function
	BelialBullet(const BelialBullet& _Other) = delete;
	BelialBullet(BelialBullet&& _Other) noexcept = delete;
	BelialBullet& operator=(const BelialBullet& _Other) = delete;
	BelialBullet& operator=(BelialBullet&& _Other) noexcept = delete;

	//static std::shared_ptr<BelialBullet> CreateBelialBullet(GameEngineLevel* _Level, const float4& _Pos);

protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender;
	float4 awdsd = float4::Zero;
	float ZDir = 0.0f;
};

