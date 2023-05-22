#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage2_Layout_2 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage2_Layout_2();
	~Stage2_Layout_2();

	// delete Function
	Stage2_Layout_2(const Stage2_Layout_2& _Other) = delete;
	Stage2_Layout_2(Stage2_Layout_2&& _Other) noexcept = delete;
	Stage2_Layout_2& operator=(const Stage2_Layout_2& _Other) = delete;
	Stage2_Layout_2& operator=(Stage2_Layout_2&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage2_Layout_2Scale = { 3840.0f,1200.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage2_Layout_2Render;

	float4 Center = { Stage2_Layout_2Scale.x / 2.0f , Stage2_Layout_2Scale.y / 2.0f, 0.0f };

};

