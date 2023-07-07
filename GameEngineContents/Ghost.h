#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class GhostState
{
	IDLE,
	ATTACK,
	MOVE,
	DEAD,
};
// 설명 :
class Ghost :public GameEngineActor
{
public:
	// constrcuter destructer
	Ghost();
	~Ghost();

	// delete Function
	Ghost(const Ghost& _Other) = delete;
	Ghost(Ghost&& _Other) noexcept = delete;
	Ghost& operator=(const Ghost& _Other) = delete;
	Ghost& operator=(Ghost&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void SetCollision(float _DeltaTime);
	void Flip();
	std::shared_ptr<class GameEngineSpriteRenderer> GhostRender;
	std::shared_ptr<class GameEngineSpriteRenderer> DeadRender;
	std::shared_ptr<class GameEngineCollision> TargetAreaCol;
	std::shared_ptr<class GameEngineCollision> AttackAreaCol;
	std::shared_ptr<class GameEngineCollision> BodyCol;
	std::shared_ptr<class GameEngineSpriteRenderer> HpBaseRender;
	std::shared_ptr<class GameEngineSpriteRenderer> HpRender;
	void ChangeState(GhostState _State);
	void UpdateState(float _Time);

	//FSM
	GhostState StateValue = GhostState::IDLE;

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
	//패턴
	bool StartMove = false;
	bool AttackMove = false;
	//몬스터 정보
	float Invincibilitytime = 0.0f;
	float4 Scale = { 80.0f,80.0f,0.0f };
	float4 HpBaseScale = { 70.0f ,20.0f ,0.0f };
	float4 HpBarScale = { 64.0f ,12.0f ,0.0f };
	float4 AreaScale = { 640.0f,640.f,0.0f };
	float4 AttackAreaScale = { 320.0f,320.f,0.0f };
	float4 MyPos = float4::Zero;

	int MaxHp = 50;
	int Hp = 50;
	int Damege = 3;
};

