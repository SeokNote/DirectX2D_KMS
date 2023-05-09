#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage_3 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage_3();
	~Stage_3();

	// delete Function
	Stage_3(const Stage_3& _Other) = delete;
	Stage_3(Stage_3&& _Other) noexcept = delete;
	Stage_3& operator=(const Stage_3& _Other) = delete;
	Stage_3& operator=(Stage_3&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage_3Scale = { 2560.0f,1280.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage_3Render;
};

