#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BelialBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	BelialBullet();
	~BelialBullet();

	// delete Function
	BelialBullet(const BelialBullet& _Other) = delete;
	BelialBullet(BelialBullet&& _Other) noexcept = delete;
	BelialBullet& operator=(const BelialBullet& _Other) = delete;
	BelialBullet& operator=(BelialBullet&& _Other) noexcept = delete;

	//static std::shared_ptr<BelialBullet> CreateBelialBullet(GameEngineLevel* _Level, const float4& _Pos);
	void SetBulletDir(float4 _Dir)
	{
		Dir = _Dir;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	void SetBullet();
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender_L;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender_R;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender_U;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender_D;

	float4 Dir = float4::Zero;
	float4 PivotPos = { 12080.0f,-250.0f,-740.0f };
	float4 LDir = float4::Zero;
	float4 RDir = float4::Zero;
	float4 UDir = float4::Zero;
	float4 DDir = float4::Zero;


	float4 LDir_t = float4::Zero;
	float4 RDir_t = float4::Zero;
	float4 UDir_t = float4::Zero;
	float4 DDir_t = float4::Zero;
	float DeathTime = 0.0f;
};

