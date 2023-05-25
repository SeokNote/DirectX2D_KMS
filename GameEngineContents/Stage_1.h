#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage_1 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage_1();
	~Stage_1();

	// delete Function
	Stage_1(const Stage_1& _Other) = delete;
	Stage_1(Stage_1&& _Other) noexcept = delete;
	Stage_1& operator=(const Stage_1& _Other) = delete;
	Stage_1& operator=(Stage_1&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage_1Scale = { 1280.0f,720.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage_1Render;
};

