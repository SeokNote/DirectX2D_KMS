#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage3_Boss : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage3_Boss();
	~Stage3_Boss();

	// delete Function
	Stage3_Boss(const Stage3_Boss& _Other) = delete;
	Stage3_Boss(Stage3_Boss&& _Other) noexcept = delete;
	Stage3_Boss& operator=(const Stage3_Boss& _Other) = delete;
	Stage3_Boss& operator=(Stage3_Boss&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage3_BossScale = { 2560.0f,720,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage3_BossRender;
};

