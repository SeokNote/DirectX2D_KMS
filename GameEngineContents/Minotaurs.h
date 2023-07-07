#pragma once
#include <GameEngineCore/GameEngineActor.h>
// 설명 :
enum class MinotaursState
{
	IDLE,
	Tackle,
	ATTACK,
	DEAD,
};
class Minotaurs :public GameEngineActor
{
public:
	// constrcuter destructer
	Minotaurs();
	~Minotaurs();

	// delete Function
	Minotaurs(const Minotaurs& _Other) = delete;
	Minotaurs(Minotaurs&& _Other) noexcept = delete;
	Minotaurs& operator=(const Minotaurs& _Other) = delete;
	Minotaurs& operator=(Minotaurs&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	bool IsFlipCheck();
	bool IsAreaIn();
	void SetCollision(float _Delta);
	std::shared_ptr<class GameEngineSpriteRenderer> MinotaursRender;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadRender;
	std::shared_ptr<class GameEngineSpriteRenderer> HpBaseRender;
	std::shared_ptr<class GameEngineSpriteRenderer> HpRender;
	std::shared_ptr<class GameEngineCollision> TargetAreaCol;
	std::shared_ptr<class GameEngineCollision> MinotaursCol;
	std::shared_ptr<class GameEngineCollision> TakcleCol;
	std::shared_ptr<class GameEngineCollision> AttackCol;
	std::shared_ptr<class TunakDust_D> DustRender;
	void ChangeState(MinotaursState _State);
	void UpdateState(float _Time);
	MinotaursState StateValue = MinotaursState::IDLE;
	//FSM
	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void AttackStart();
	void AttackUpdate(float _Time);
	void AttackEnd();

	void DeadStart();
	void DeadUpdate(float _Time);
	void DeadEnd();
	float DirCheckTime = 0.0f;
	float DustTime = 0.0f;
	//태클
	float4 PrevPos = float4::Zero;
	float4 EndPos = float4::Zero;
	float WaitTakcle = 0.0f;
	float NextTakcle = 0.0f;
	//몬스터 정보
	float4 Scale = {224.0f,200.0f,0.0f};
	float4 ColScale = {180.0f,146.0f,0.0f };
	float4 TakcleColScale = { 150.0f,136.0f,0.0f };
	float4 AttackColScale = { 100.0f,136.0f,0.0f };
	float4 HpBaseScale = { 90.0f ,20.0f ,0.0f };
	float4 HpBarScale = { 80.0f ,12.0f ,0.0f };
	float4 AreaScale = { 500.0f,180.f,0.0f };
	bool AreaIn = false;
	bool IsFlip = false;
	float Invincibilitytime = 0.0f;
	int MinoHp = 150;
	int MaxMinoHp = 150;
	int MinoTackle = 5;
	int MinoAttack = 3;
};

