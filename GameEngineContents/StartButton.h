#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class StartButton : public GameEngineActor
{
public:
	// constrcuter destructer
	StartButton();
	~StartButton();

	// delete Function
	StartButton(const StartButton& _Other) = delete;
	StartButton(StartButton&& _Other) noexcept = delete;
	StartButton& operator=(const StartButton& _Other) = delete;
	StartButton& operator=(StartButton&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 StartButtonScale = { 144.0f,48.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> StartButtonRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> StartButtonRender_2;

};

