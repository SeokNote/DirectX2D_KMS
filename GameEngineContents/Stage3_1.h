#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage3_1 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage3_1();
	~Stage3_1();

	// delete Function
	Stage3_1(const Stage3_1& _Other) = delete;
	Stage3_1(Stage3_1&& _Other) noexcept = delete;
	Stage3_1& operator=(const Stage3_1& _Other) = delete;
	Stage3_1& operator=(Stage3_1&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage3_1Scale = { 1600.0f,720,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage3_1Render;
};

