#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage2_Layout_4 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage2_Layout_4();
	~Stage2_Layout_4();

	// delete Function
	Stage2_Layout_4(const Stage2_Layout_4& _Other) = delete;
	Stage2_Layout_4(Stage2_Layout_4&& _Other) noexcept = delete;
	Stage2_Layout_4& operator=(const Stage2_Layout_4& _Other) = delete;
	Stage2_Layout_4& operator=(Stage2_Layout_4&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage2_Layout_4Scale = { 3840.0f,1360.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage2_Layout_4Render;

	float4 Center = { Stage2_Layout_4Scale.x / 2.0f , Stage2_Layout_4Scale.y / 2.0f, 0.0f };

};

