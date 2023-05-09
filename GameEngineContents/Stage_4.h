#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage_4 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage_4();
	~Stage_4();

	// delete Function
	Stage_4(const Stage_4& _Other) = delete;
	Stage_4(Stage_4&& _Other) noexcept = delete;
	Stage_4& operator=(const Stage_4& _Other) = delete;
	Stage_4& operator=(Stage_4&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage_4Scale = { 1920.0f,720.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage_4Render;
};

