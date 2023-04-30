#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SoundButton : public GameEngineActor
{
public:
	// constrcuter destructer
	SoundButton();
	~SoundButton();

	// delete Function
	SoundButton(const SoundButton& _Other) = delete;
	SoundButton(SoundButton&& _Other) noexcept = delete;
	SoundButton& operator=(const SoundButton& _Other) = delete;
	SoundButton& operator=(SoundButton&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 SoundButtonScale = { 80.0f,48.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> SoundButtonRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> SoundButtonRender_2;
};

