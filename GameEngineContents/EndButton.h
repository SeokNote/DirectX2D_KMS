#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class EndButton : public GameEngineActor
{
public:
	// constrcuter destructer
	EndButton();
	~EndButton();

	// delete Function
	EndButton(const EndButton& _Other) = delete;
	EndButton(EndButton&& _Other) noexcept = delete;
	EndButton& operator=(const EndButton& _Other) = delete;
	EndButton& operator=(EndButton&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 EndButtonScale = { 84.0f,48.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> EndButtonRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> EndButtonRender_2;

};

