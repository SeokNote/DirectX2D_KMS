#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage2_Layout_1 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage2_Layout_1();
	~Stage2_Layout_1();

	// delete Function
	Stage2_Layout_1(const Stage2_Layout_1& _Other) = delete;
	Stage2_Layout_1(Stage2_Layout_1&& _Other) noexcept = delete;
	Stage2_Layout_1& operator=(const Stage2_Layout_1& _Other) = delete;
	Stage2_Layout_1& operator=(Stage2_Layout_1&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage2_Layout_1Scale = { 1280.0f,720.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage2_Layout_1Render;
};

