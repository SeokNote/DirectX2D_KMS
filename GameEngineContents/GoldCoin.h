#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "PixelCollision.h"

// 설명 :
class GoldCoin : public GameEngineActor
{
public:
	// constrcuter destructer
	GoldCoin();
	~GoldCoin();

	// delete Function
	GoldCoin(const GoldCoin& _Other) = delete;
	GoldCoin(GoldCoin&& _Other) noexcept = delete;
	GoldCoin& operator=(const GoldCoin& _Other) = delete;
	GoldCoin& operator=(GoldCoin&& _Other) noexcept = delete;
	void CoinSetting(float4 _Pos,bool _MoveValue);
	static void CoinCreat(GameEngineLevel* _Level, float4 _Pos, bool _MoveValue);
protected:
	void Start();
	void Update(float _Delta) override;
private:
	void SetCollision();
	bool MiddleCheck(float4 _Pos);
	void MoveCoin(float _Delta);
	std::shared_ptr<class GameEngineSpriteRenderer> GoldCoinRender;
	std::shared_ptr<class GameEngineCollision> BodyCol;
	float4 ColScale = { 28.0f,28.0f,0.0f };
	bool Value = false;
	float4 Pos = float4::Zero;
	float Ratio = 0.0f;
	float Time = 0.0f;
	bool IsCheck = false;
	bool GroundCheck = false;
	MyMap CurMap = MyMap::None;
	//픽셀 충돌
	float4 MapCenter = float4::Zero;
	float4 TransColPos = float4::Zero;
	float4 TargetPos = float4::Zero;
	float4 PixelMapResultPos = float4::Zero;
	GameEnginePixelColor MiddleGround = { static_cast<unsigned char>(255),  static_cast<unsigned char>(0),  static_cast<unsigned char>(255),  static_cast<unsigned char>(255) };
	GameEnginePixelColor Pixel = GameEnginePixelColor::Black;
	std::shared_ptr<class GameEngineTexture> Ptr = nullptr;
};

