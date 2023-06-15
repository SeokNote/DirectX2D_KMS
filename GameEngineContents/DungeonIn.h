#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class DungeonIn : public GameEngineActor
{
public:
	// constrcuter destructer
	DungeonIn();
	~DungeonIn();

	// delete Function
	DungeonIn(const DungeonIn& _Other) = delete;
	DungeonIn(DungeonIn&& _Other) noexcept = delete;
	DungeonIn& operator=(const DungeonIn& _Other) = delete;
	DungeonIn& operator=(DungeonIn&& _Other) noexcept = delete;

	std::shared_ptr<class FadeEffect> FEffect;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 DungeonInScale = { 468.0f,340.0f,0.0f };
	float4 DungeonInColScale = { 50.0f,50.0f,0.0f };
	float4 DungeonInColPos = { 1235.0f,-555.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> DungeonInRender;


	//Position
	float4 DungeonInPos1 = { 1235.0f,-405.0f,-750.f };

	std::shared_ptr<class GameEngineCollision> DungeonInCol;

	bool Value = false;
	bool Value_1 = false;
	float CheckTime = 0.0f;
	float CheckTime_1 = 0.0f;

	int IndexCount = 0;

};

