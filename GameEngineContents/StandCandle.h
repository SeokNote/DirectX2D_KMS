#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include"ContentsEnums.h"
// Ό³Έν :
class StandCandle : public GameEngineActor
{
public:
	// constrcuter destructer
	StandCandle();
	~StandCandle();

	// delete Function
	StandCandle(const StandCandle& _Other) = delete;
	StandCandle(StandCandle&& _Other) noexcept = delete;
	StandCandle& operator=(const StandCandle& _Other) = delete;
	StandCandle& operator=(StandCandle&& _Other) noexcept = delete;
	void SetStandCandleColor(float4 _Color)
	{
		Color = _Color;
	}
	void S_SetMyMap(MyMap _Map)
	{
		Stage1_M = _Map;
	}
protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> StandCandleRender = nullptr;
	std::shared_ptr<class PointLightEffect> LightEffect = nullptr;
	float Time = 0.0f;
	float4 Color = float4::Zero;
	MyMap Stage1_M = MyMap::None;
	MyMap Value = MyMap::None;
};

