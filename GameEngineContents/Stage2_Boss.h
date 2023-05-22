#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage2_Boss : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage2_Boss();
	~Stage2_Boss();

	// delete Function
	Stage2_Boss(const Stage2_Boss& _Other) = delete;
	Stage2_Boss(Stage2_Boss&& _Other) noexcept = delete;
	Stage2_Boss& operator=(const Stage2_Boss& _Other) = delete;
	Stage2_Boss& operator=(Stage2_Boss&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage2_BossScale = { 1600.0f,900.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage2_BossRender;
};

