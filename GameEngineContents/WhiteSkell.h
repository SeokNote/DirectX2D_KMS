#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class WhiteSkellState
{
	IDLE,
	MOVE,
	FALL,
	CHASE,
	ATTACK,
	DEAD,
};
// 설명 :
class WhiteSkell :public GameEngineActor
{
public:
	// constrcuter destructer
	WhiteSkell();
	~WhiteSkell();

	// delete Function
	WhiteSkell(const WhiteSkell& _Other) = delete;
	WhiteSkell(WhiteSkell&& _Other) noexcept = delete;
	WhiteSkell& operator=(const WhiteSkell& _Other) = delete;
	WhiteSkell& operator=(WhiteSkell&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void SetCollision(float _DeltaTime);
	bool GroundCheck();
	void FlipCheck();
	std::shared_ptr<class GameEngineSpriteRenderer> WhiteSkellRender;
	std::shared_ptr<class GameEngineSpriteRenderer> AreaInRender;
	std::shared_ptr<class GameEngineCollision> SkellBodyCol;
	std::shared_ptr<class GameEngineCollision> TargetAreaCol;
	std::shared_ptr<class GameEngineCollision> AttackAreaCol;

	void ChangeState(WhiteSkellState _State);
	void UpdateState(float _Time);
	float4 PixelCalculation(float4 _TargetPos, float4 _MapCenterPos, float4 _TransColPos);
	std::shared_ptr<class GameEngineTexture> Ptr = nullptr;
	GameEnginePixelColor Pixel = GameEnginePixelColor::Black;
	float4 PixelMapResultPos = float4::Zero;
	float4 TargetPos = float4::Zero;
	WhiteSkellState StateValue = WhiteSkellState::IDLE;

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void ChaseStart();
	void ChaseUpdate(float _Time);
	void ChaseEnd();

	void FallStart();
	void FallUpdate(float _Time);
	void FallEnd();

	void AttackStart();
	void AttackUpdate(float _Time);
	void AttackEnd();

	void DeadStart();
	void DeadUpdate(float _Time);
	void DeadEnd();
	//FSM
	float AttackTerm = 0.0f;
	float MoveTerm = 0.0f;
	float MoveSpeed = 250.0f;
	float4 PrevPos = float4::Zero;
	float4 CurPos = float4::Zero;
	float4 AreaPos = { 500.0f,120.0f,0.0f };
	float4 PlayerPos = float4::Zero;
	bool InArea = false;
	bool IsFlip = false;
	int FlipCount = 0;
	float Invincibilitytime = 0.0f;
	//몬스터 정보
	float4 Scale = { 284.0f,192.0f,0.0f };
	float4 ColScale = { 132.0f,120.0f,0.0f };
	float4 AttackColScale = { 114.0f,118.0f,0.0f };
	int Damege = 3;
	float4 InScale = { 56.0f,58.0f,0.0f };
	int SkellHP = 80;

};

