#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ¼³¸í :
class GoblinBomb :public GameEngineActor
{
public:
	// constrcuter destructer
	GoblinBomb();
	~GoblinBomb();

	// delete Function
	GoblinBomb(const GoblinBomb& _Other) = delete;
	GoblinBomb(GoblinBomb&& _Other) noexcept = delete;
	GoblinBomb& operator=(const GoblinBomb& _Other) = delete;
	GoblinBomb& operator=(GoblinBomb&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void SetGroundBG(float _DeltaTime);
	void CreatBomb(float _DeltaTime);
	void BombDeath(float _DeltaTime);
	std::shared_ptr<class GameEngineSpriteRenderer> GoblinBombRender;
	std::shared_ptr<class GameEngineSpriteRenderer> GoblinBombEffectRender;
	std::shared_ptr<class GameEngineSpriteRenderer> BGRender;

	float4 BGScale = { 10.0f,800.0f,0.0f };
	float StartAlpha = 0.6f;
	float AlphaTime = 0.0f;
	float BombSpeed = 700.0f;

	//ºÒ°ª
	bool StartPatton = false;
	bool IsCheck = false;
	bool IsCheck_1 = false;
	bool DeadTime = false;
	//ÆøÅº »ý¼º½Ã°£
	float StartBomb = 0.0f;
};

