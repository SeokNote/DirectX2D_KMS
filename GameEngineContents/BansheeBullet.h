#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BansheeBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	BansheeBullet();
	~BansheeBullet();

	// delete Function
	BansheeBullet(const BansheeBullet& _Other) = delete;
	BansheeBullet(BansheeBullet&& _Other) noexcept = delete;
	BansheeBullet& operator=(const BansheeBullet& _Other) = delete;
	BansheeBullet& operator=(BansheeBullet&& _Other) noexcept = delete;
	static void CreatBansheeBullet(GameEngineLevel* _Level, float _Range, float4 _Deg, float4 _Pos);
	void MoveBullet(float _Delta, float4 Deg);
	static void SetStartValue(bool _Value)
	{
		MoveStart = _Value;
	}
	void SetBulletDir(float4 _DIR)
	{
		Dir = _DIR;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void SetCollison();
	std::shared_ptr<class GameEngineSpriteRenderer> BulletRender;
	std::shared_ptr<class GameEngineCollision> AttackCol;
	float4 Scale = { 52.0f,56.0f,0.0f };
	static bool MoveStart;
	float4 Dir = float4::Zero;
	int Damege = 3;
	float DeadTime = 0.0f;
	float DeadTime1 = 0.0f;
	bool Value = false;
};

