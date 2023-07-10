#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class RightHandState
{
	IDLE,
	MOVE,
	LASOR,
	DEAD,
};
// 설명 :
class BelialHand_R : public GameEngineActor
{
public:
	static BelialHand_R* MainBelialHand_R;

	// constrcuter destructer
	BelialHand_R();
	~BelialHand_R();

	// delete Function
	BelialHand_R(const BelialHand_R& _Other) = delete;
	BelialHand_R(BelialHand_R&& _Other) noexcept = delete;
	BelialHand_R& operator=(const BelialHand_R& _Other) = delete;
	BelialHand_R& operator=(BelialHand_R&& _Other) noexcept = delete;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 RightHandPos = { 12500.0f,-300.0f,-750.0f };
	float4 RightHandScale = { -228.0f,276.0f,0.0f };

	std::shared_ptr<class GameEngineSpriteRenderer> RightHandRender;
	std::shared_ptr<class GameEngineSpriteRenderer> RightLasorRender;
	std::shared_ptr<class BelialLasor_R> LasorPtr_1;
	//FSM
	RightHandState StateValue = RightHandState::IDLE;
	void ChangeState(RightHandState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void LasorStart();
	void LasorUpdate(float _Time);
	void LasorEnd();

	void DeathStart();
	void DeathUpdate(float _Time);
	void DeathEnd();

	//패턴시간체크
	float M_StartTime = 0.0f;

	//변수
	float4 HandPos = float4::Zero;
	float4 CurPos = float4::Zero;
	float4 PlayerPos = float4::Zero;
	float YPos = 0.0f;
	float HandSpeed = 600.0f;
	bool FirstLasor = false;
};

