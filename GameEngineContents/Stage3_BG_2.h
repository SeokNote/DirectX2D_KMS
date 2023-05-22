#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage3_BG_2 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage3_BG_2();
	~Stage3_BG_2();

	// delete Function
	Stage3_BG_2(const Stage3_BG_2& _Other) = delete;
	Stage3_BG_2(Stage3_BG_2&& _Other) noexcept = delete;
	Stage3_BG_2& operator=(const Stage3_BG_2& _Other) = delete;
	Stage3_BG_2& operator=(Stage3_BG_2&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage3_BG_2Scale = { 5120.0f,480.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage3_BG_2Render;

	float4 Center = { Stage3_BG_2Scale.x / 2.0f , Stage3_BG_2Scale.y / 2.0f, 0.0f };

};

