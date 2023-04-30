#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Sky : public GameEngineActor
{
public:
	// constrcuter destructer
	Sky();
	~Sky();

	// delete Function
	Sky(const Sky& _Other) = delete;
	Sky(Sky&& _Other) noexcept = delete;
	Sky& operator=(const Sky& _Other) = delete;
	Sky& operator=(Sky&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 SkyScale = { 5120.0f,568.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> SkyRender;
};

