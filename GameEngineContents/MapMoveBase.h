#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 : 여기서 맵이동 기능 제공
class MapMoveBase : public GameEngineActor
{
public:
	static MapMoveBase* MapMoveBasePtr;
	// constrcuter destructer
	MapMoveBase();
	~MapMoveBase();

	// delete Function
	MapMoveBase(const MapMoveBase& _Other) = delete;
	MapMoveBase(MapMoveBase&& _Other) noexcept = delete;
	MapMoveBase& operator=(const MapMoveBase& _Other) = delete;
	MapMoveBase& operator=(MapMoveBase&& _Other) noexcept = delete;
	void MapMove(float _DeltaTime , float4 _Pos);

	std::shared_ptr<class FadeEffect> FEffect;


	float4 SetNextMapPos(float4 _Pos)
	{
		Pos = _Pos;
		return Pos;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Pos = float4::Zero;
	float CheckTime_0 = 0.0f;
	float CheckTime_1 = 0.0f;
	bool Value_0 = false;
	bool Value_1 = false;

};

