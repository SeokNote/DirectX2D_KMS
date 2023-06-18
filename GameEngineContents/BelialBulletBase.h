#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "BelialHead.h"
// Ό³Έν :
class BelialBulletBase : public GameEngineActor
{
public:
	// constrcuter destructer
	BelialBulletBase();
	~BelialBulletBase();

	// delete Function
	BelialBulletBase(const BelialBulletBase& _Other) = delete;
	BelialBulletBase(BelialBulletBase&& _Other) noexcept = delete;
	BelialBulletBase& operator=(const BelialBulletBase& _Other) = delete;
	BelialBulletBase& operator=(BelialBulletBase&& _Other) noexcept = delete;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBaseRender_0;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBaseRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBaseRender_2;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBaseRender_3;

	float4 pos = BelialHead::MainBelialHead->GetTransform()->GetWorldPosition();

	float ZDir = 0.0f;
	float4 Dir = float4::Zero;
};

