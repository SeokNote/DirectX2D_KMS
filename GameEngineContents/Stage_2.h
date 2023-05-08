#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage_2 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage_2();
	~Stage_2();

	// delete Function
	Stage_2(const Stage_2& _Other) = delete;
	Stage_2(Stage_2&& _Other) noexcept = delete;
	Stage_2& operator=(const Stage_2& _Other) = delete;
	Stage_2& operator=(Stage_2&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage_2Scale = { 2560.0f,1280.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage_2Render;
};

