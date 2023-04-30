#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MidCloud : public GameEngineActor
{
public:
	// constrcuter destructer
	MidCloud();
	~MidCloud();

	// delete Function
	MidCloud(const MidCloud& _Other) = delete;
	MidCloud(MidCloud&& _Other) noexcept = delete;
	MidCloud& operator=(const MidCloud& _Other) = delete;
	MidCloud& operator=(MidCloud&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 MidCloudScale = { 180.0f,88.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> MidCloudRender;
};

