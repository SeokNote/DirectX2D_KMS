#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Door :public GameEngineActor
{
public:
	// constrcuter destructer
	Door();
	~Door();
	std::shared_ptr<class FadeEffect> FEffect;
	// delete Function
	Door(const Door& _Other) = delete;
	Door(Door&& _Other) noexcept = delete;
	Door& operator=(const Door& _Other) = delete;
	Door& operator=(Door&& _Other) noexcept = delete;

	void MapMove(float _DeltaTime, float4 _Pos);

	void SetNextPos(float4 _Pos)
	{
		NextPos = _Pos;
	}
	void SetDoorPos(float4 _Pos)
	{
		DoorPos = _Pos;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 DoorPos = float4::Zero;
	float4 NextPos = float4::Zero;
	float4 PrevPos = float4::Zero;

	float4 DoorScale = { 50.0f,50.0f,0.0f };
	float CheckTime_0 = 0.0f;
	float CheckTime_1 = 0.0f;
	bool Value_0 = false;
	bool Value_1 = false;
	bool FirstCol = false;

	std::shared_ptr<class GameEngineCollision> DoorCol;

};
