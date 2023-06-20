#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ¼³¸í :
class GroundBomb :public GameEngineActor
{
public:
	// constrcuter destructer
	GroundBomb();
	~GroundBomb();

	// delete Function
	GroundBomb(const GroundBomb& _Other) = delete;
	GroundBomb(GroundBomb&& _Other) noexcept = delete;
	GroundBomb& operator=(const GroundBomb& _Other) = delete;
	GroundBomb& operator=(GroundBomb&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void SetGroundBG(float _DeltaTime);
	void CreatBomb(float _DeltaTime);
	void BombDeath(float _DeltaTime);
	std::shared_ptr<class GameEngineSpriteRenderer> GroundBombBGRender;
	std::shared_ptr<class GameEngineSpriteRenderer> GroundBombRender;

	std::shared_ptr<class GameEngineSpriteRenderer> GroundBombBGRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> GroundBombRender_1;

	std::shared_ptr<class GameEngineSpriteRenderer> GroundBombBGRender_2;
	std::shared_ptr<class GameEngineSpriteRenderer> GroundBombRender_2;

	std::shared_ptr<class GameEngineSpriteRenderer> BombBGRender_0;
	std::shared_ptr<class GameEngineSpriteRenderer> BombBGRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> BombBGRender_2;

	//º¯¼ö
	float4 BGScale = { 150.0f,800.0f,0.0f };
	float4 BombScale = { 300.0f,800.0f,0.0f };

	float Time = 0.0f;
	float StartAlpha = 0.6f;
	float AlphaTime = 0.0f;
	bool Check = false;
	float DeadTime = 0.0f;
	//ÆøÅº º¯¼ö
	bool BombCheck = false;
	float StartBomb = 0.0f;
};

