#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BelialLasor_R : public GameEngineActor
{
public:
	// constrcuter destructer
	BelialLasor_R();
	~BelialLasor_R();

	// delete Function
	BelialLasor_R(const BelialLasor_R& _Other) = delete;
	BelialLasor_R(BelialLasor_R&& _Other) noexcept = delete;
	BelialLasor_R& operator=(const BelialLasor_R& _Other) = delete;
	BelialLasor_R& operator=(BelialLasor_R&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void CollisionCheck(float _DeltaTime);
	float4 LasorScale = { -1280.0f,220.0f,0.0f };
	float4 LasorColScale = { -1280.0f,180.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> BelialLasorRender;
	std::shared_ptr<class GameEngineCollision> BelialLasorCol;
	int LasorDamage = 10;
	float InvinTime = 0.0f;
	bool InvinCheck = false;
};

