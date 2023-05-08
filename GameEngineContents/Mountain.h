#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Mountain : public GameEngineActor
{
public:
	// constrcuter destructer
	Mountain();
	~Mountain();

	// delete Function
	Mountain(const Mountain& _Other) = delete;
	Mountain(Mountain&& _Other) noexcept = delete;
	Mountain& operator=(const Mountain& _Other) = delete;
	Mountain& operator=(Mountain&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 MountainScale = { 5120.0f,568.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> MountainRender;

	float Num = 0.0f;
	float4 PlayerPos = float4::Zero;
	float4 MoveValue = float4::Zero;
	float4 Center = { MountainScale.x / 2.0f , MountainScale.y / 2.0f, 0.0f };
};

