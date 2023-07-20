#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class GiantBatState
{
	IDLE,
	ATTACKREADY,
	ATTACK,
	DEAD,
};
// 설명 :
class GiantBat :public GameEngineActor
{
public:
	// constrcuter destructer
	GiantBat();
	~GiantBat();

	// delete Function
	GiantBat(const GiantBat& _Other) = delete;
	GiantBat(GiantBat&& _Other) noexcept = delete;
	GiantBat& operator=(const GiantBat& _Other) = delete;
	GiantBat& operator=(GiantBat&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void SetDeg();
	void SetCollision(float _DeltaTime);
	void Flip();
	std::shared_ptr<class GameEngineSpriteRenderer> GiantBatRender;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadRender;
	std::shared_ptr<class GameEngineCollision> TargetAreaCol;
	std::shared_ptr<class GameEngineCollision> AttackAreaCol;
	std::shared_ptr<class GameEngineCollision> BodyCol;
	std::shared_ptr<class GameEngineSpriteRenderer> HpBaseRender;
	std::shared_ptr<class GameEngineSpriteRenderer> HpRender;
	void ChangeState(GiantBatState _State);
	void UpdateState(float _Time);

	//FSM
	GiantBatState StateValue = GiantBatState::IDLE;

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void AttackReadyStart();
	void AttackReadyUpdate(float _Time);
	void AttackReadyEnd();

	void AttackStart();
	void AttackUpdate(float _Time);
	void AttackEnd();

	void DeadStart();
	void DeadUpdate(float _Time);
	void DeadEnd();

	float DeadTime = 0.0f;
	float AttackTime = 0.0f;
	//패턴
	bool StartMove = false;
	bool AttackMove = false;
	//몬스터 정보
	float Invincibilitytime = 0.0f;
	float NextState = 0.0f;
	float4 Scale = { 256.0f,256.0f,0.0f };
	float4 ColScale = { 128.0f,128.0f,0.0f };
	float4 HpBaseScale = { 85.0f ,20.0f ,0.0f };
	float4 HpBarScale = { 74.0f ,12.0f ,0.0f };
	float4 AreaScale = { 640.0f,640.f,0.0f };
	float4 AttackAreaScale = { 600.0f,600.f,0.0f };
	float4 MyPos = float4::Zero;
	bool GiantBatBlink = false;
	int MaxHp = 100;
	int Hp = 100;
	
	std::shared_ptr<class BatBullet> BulletPtr = nullptr;
	//공격변수
	std::vector<float4> Degs;
	int A_Count = 18;
	float Rad = 0.0f;
	float Delay = 0.0f;
	int Count = 0;
};

