#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class BelialSpawner : public GameEngineActor
{
public:
	static BelialSpawner* MainBelialSpawner;
	// constrcuter destructer
	BelialSpawner();
	~BelialSpawner();

	// delete Function
	BelialSpawner(const BelialSpawner& _Other) = delete;
	BelialSpawner(BelialSpawner&& _Other) noexcept = delete;
	BelialSpawner& operator=(const BelialSpawner& _Other) = delete;
	BelialSpawner& operator=(BelialSpawner&& _Other) noexcept = delete;
	bool GetBelialCreat()
	{
		return BelialCreat;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BelialSpawnerRender;
	std::shared_ptr<class GameEngineCollision> BelialSpawnerCol;
	float4 Scale = { 128.0f,128.0f,0.0f };
	bool BelialCreat = false;
};

