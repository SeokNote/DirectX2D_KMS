#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "BelialHead.h"
// Ό³Έν :
class BelialBulletBase_1 : public GameEngineActor
{
public:
	static BelialBulletBase_1* MainBelialBulletBase;
	// constrcuter destructer
	BelialBulletBase_1();
	~BelialBulletBase_1();

	// delete Function
	BelialBulletBase_1(const BelialBulletBase_1& _Other) = delete;
	BelialBulletBase_1(BelialBulletBase_1&& _Other) noexcept = delete;
	BelialBulletBase_1& operator=(const BelialBulletBase_1& _Other) = delete;
	BelialBulletBase_1& operator=(BelialBulletBase_1&& _Other) noexcept = delete;

	std::shared_ptr<class GameEngineSpriteRenderer> GetPtrasd()
	{
		return BelialBulletBase_1Render;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBase_1Render;
	float ZDir = 0.0f;
	float4 Dir = float4::Zero;
};

