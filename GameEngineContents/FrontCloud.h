#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class FrontCloud : public GameEngineActor
{
public:
	// constrcuter destructer
	FrontCloud();
	~FrontCloud();

	// delete Function
	FrontCloud(const FrontCloud& _Other) = delete;
	FrontCloud(FrontCloud&& _Other) noexcept = delete;
	FrontCloud& operator=(const FrontCloud& _Other) = delete;
	FrontCloud& operator=(FrontCloud&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 FrontCloudScale = { 2560.0f,720.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> FrontCloudRender;
};

