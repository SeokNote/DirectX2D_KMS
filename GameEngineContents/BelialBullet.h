#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
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
	void SetBullet(float _DeltaTime);
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender_L;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender_R;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender_U;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletRender_D;

	std::shared_ptr<class GameEngineCollision> BelialBulletCol_0;
	std::shared_ptr<class GameEngineCollision> BelialBulletCol_1;
	std::shared_ptr<class GameEngineCollision> BelialBulletCol_2;
	std::shared_ptr<class GameEngineCollision> BelialBulletCol_3;
	float4 BulletColScale = { 50.0f,50.f,0.0f };
	float4 Dir = float4::Zero;
	float4 PivotPos = { 12080.0f,-250.0f,-770.0f };
	float4 LDir = float4::Zero;
	float4 RDir = float4::Zero;
	float4 UDir = float4::Zero;
	float4 DDir = float4::Zero;


	float4 LDir_t = float4::Zero;
	float4 RDir_t = float4::Zero;
	float4 UDir_t = float4::Zero;
	float4 DDir_t = float4::Zero;
	float DeathTime = 0.0f;
	float BulletSpeed = 500.0f;
	int BulletDamage= 2;
	//최초 충돌 나오면 다 바꿔주자.
	bool OnOffValue_0 = false;
	bool OnOffValue_1 = false;
	bool OnOffValue_2 = false;
	bool OnOffValue_3 = false;
};

