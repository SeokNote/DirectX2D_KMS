#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BatBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	BatBullet();
	~BatBullet();

	// delete Function
	BatBullet(const BatBullet& _Other) = delete;
	BatBullet(BatBullet&& _Other) noexcept = delete;
	BatBullet& operator=(const BatBullet& _Other) = delete;
	BatBullet& operator=(BatBullet&& _Other) noexcept = delete;
	static void CreatBatBullet(GameEngineLevel* _Level , float _Range , float4 _Deg, float4 _Pos);
	void MoveBullet(float _Delta ,float4 Deg);
	static void SetStartValue(bool _Value)
	{
		MoveStart = _Value;
	}
	static void SetBulletDir(float4 _DIR)
	{
		Dir = _DIR;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void SetCollison();
	void PixelCollision();
	void MidPixelCollision();

	std::shared_ptr<class GameEngineTexture> Ptr = nullptr;
	std::shared_ptr<class GameEngineTexture> Ptr2 = nullptr;

	float4 PixelCalculation(float4 _TargetPos, float4 _MapCenterPos, float4 _TransColPos);
	GameEnginePixelColor Pixel = GameEnginePixelColor::Black;
	GameEnginePixelColor Pixel2 = GameEnginePixelColor::Black;

	float4 MapCenter = float4::Zero;
	float4 TransColPos = float4::Zero;
	float4 TargetPos = float4::Zero;
	float4 PixelMapResultPos = float4::Zero;
	GameEnginePixelColor MiddleGround = { static_cast<unsigned char>(255),  static_cast<unsigned char>(0),  static_cast<unsigned char>(255),  static_cast<unsigned char>(255) };
	std::shared_ptr<class GameEngineSpriteRenderer> BulletRender;
	std::shared_ptr<class GameEngineCollision> AttackCol;
	float4 Scale = { 56.0f,56.0f,0.0f };
	static bool MoveStart;
	static float4 Dir;
	int Damege = 3;
	float DeadTime = 0.0f;
	float DeadTime1 = 0.0f;
	bool ColCheck = false;
	bool MiddleCheck = false;
	bool Value = false;
};

