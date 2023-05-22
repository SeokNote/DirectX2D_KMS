#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage2_Layout_3 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage2_Layout_3();
	~Stage2_Layout_3();

	// delete Function
	Stage2_Layout_3(const Stage2_Layout_3& _Other) = delete;
	Stage2_Layout_3(Stage2_Layout_3&& _Other) noexcept = delete;
	Stage2_Layout_3& operator=(const Stage2_Layout_3& _Other) = delete;
	Stage2_Layout_3& operator=(Stage2_Layout_3&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage2_Layout_3Scale = { 3840.0f,1360.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage2_Layout_3Render;

	float4 Center = { Stage2_Layout_3Scale.x / 2.0f , Stage2_Layout_3Scale.y / 2.0f, 0.0f };

};

