#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class TunakSpawner : public GameEngineActor
{
public:
	static TunakSpawner* MainTunakSpawner;
	// constrcuter destructer
	TunakSpawner();
	~TunakSpawner();

	// delete Function
	TunakSpawner(const TunakSpawner& _Other) = delete;
	TunakSpawner(TunakSpawner&& _Other) noexcept = delete;
	TunakSpawner& operator=(const TunakSpawner& _Other) = delete;
	TunakSpawner& operator=(TunakSpawner&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TunakSpawnerRender;
	std::shared_ptr<class GameEngineCollision> TunakSpawnerCol;
	float4 Scale = { 128.0f,128.0f,0.0f };
	bool TunakCreate = false;
};

