#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class SmallBatState
{
	IDLE,
	ATTACK,
	MOVE,
	DEAD,
};
// 설명 :
class SmallBat :public GameEngineActor
{
public:
	// constrcuter destructer
	SmallBat();
	~SmallBat();

	// delete Function
	SmallBat(const SmallBat& _Other) = delete;
	SmallBat(SmallBat&& _Other) noexcept = delete;
	SmallBat& operator=(const SmallBat& _Other) = delete;
	SmallBat& operator=(SmallBat&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void SetCollision(float _DeltaTime);
	void Flip();
	std::shared_ptr<class GameEngineSpriteRenderer> SmallBatRender;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadRender;
	std::shared_ptr<class GameEngineCollision> TargetAreaCol;
	std::shared_ptr<class GameEngineCollision> AttackAreaCol;
	std::shared_ptr<class GameEngineCollision> BodyCol;
	std::shared_ptr<class GameEngineSpriteRenderer> HpBaseRender;
	std::shared_ptr<class GameEngineSpriteRenderer> HpRender;
	void ChangeState(SmallBatState _State);
	void UpdateState(float _Time);

	//FSM
	SmallBatState StateValue = SmallBatState::IDLE;

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void DeadStart();
	void DeadUpdate(float _Time);
	void DeadEnd();
	//패턴
	bool StartMove = false;
	bool AttackMove = false;
	//몬스터 정보
	float Invincibilitytime = 0.0f;
	float4 Scale = { 128.0f,128.0f,0.0f };
	float4 HpBaseScale = { 70.0f ,20.0f ,0.0f };
	float4 HpBarScale = { 64.0f ,12.0f ,0.0f };
	float4 AreaScale = { 640.0f,640.f,0.0f };
	float4 AttackAreaScale = { 320.0f,320.f,0.0f };
	float4 MyPos = float4::Zero;
	bool SmallBatBlink = false;
	int MaxHp = 40;
	int Hp = 40;
	int Damege = 3;
};

