#pragma once
#include <GameEngineCore\GameEngineLevel.h>

// Ό³Έν :
class IntroLevel : public GameEngineLevel
{
public:
	// constrcuter destructer
	IntroLevel();
	~IntroLevel();

	// delete Function
	IntroLevel(const IntroLevel& _Other) = delete;
	IntroLevel(IntroLevel&& _Other) noexcept = delete;
	IntroLevel& operator=(const IntroLevel& _Other) = delete;
	IntroLevel& operator=(IntroLevel&& _Other) noexcept = delete;

	std::shared_ptr<class FadeEffect> FEffect;


protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	//void LevelChangeStart() override;
	//void LevelChangeEnd() override;
private:
	float NextTime = 0.0f;
};

