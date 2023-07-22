#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include"ContentsEnums.h"
// Ό³Έν :
class Candle : public GameEngineActor
{
public:
	// constrcuter destructer
	Candle();
	~Candle();

	// delete Function
	Candle(const Candle& _Other) = delete;
	Candle(Candle&& _Other) noexcept = delete;
	Candle& operator=(const Candle& _Other) = delete;
	Candle& operator=(Candle&& _Other) noexcept = delete;
	void SetCandleColor(float4 _Color)
	{
		Color = _Color;
	}
	void SetMyMap(MyMap _Map)
	{
		Stage1_M = _Map;
	}
protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> CandleRender = nullptr;
	std::shared_ptr<class PointLightEffect> LightEffect = nullptr;
	float Time = 0.0f;
	float4 Color = float4::Zero;
	MyMap Stage1_M = MyMap::None;
	MyMap Value = MyMap::None;
};

