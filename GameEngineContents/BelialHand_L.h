#pragma once
#include <GameEngineCore/GameEngineActor.h>
// 설명 :
enum class LeftHandState
{
	IDLE,
	MOVE,
	LASOR,
	DEAD,
};
class BelialHand_L : public GameEngineActor
{
public:
	static BelialHand_L* MainBelialHand_L;

	// constrcuter destructer
	BelialHand_L();
	~BelialHand_L();

	// delete Function
	BelialHand_L(const BelialHand_L& _Other) = delete;
	BelialHand_L(BelialHand_L&& _Other) noexcept = delete;
	BelialHand_L& operator=(const BelialHand_L& _Other) = delete;
	BelialHand_L& operator=(BelialHand_L&& _Other) noexcept = delete;

	bool GetPattonCheck()
	{
		return NextPatton;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 LeftHandPos = { 11650.0f,-300.0f,-750.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> LeftHandRender;
	std::shared_ptr<class GameEngineSpriteRenderer> LeftLasorRender;
	std::shared_ptr<class BelialLasor> LasorPtr;
	//FSM
	LeftHandState StateValue = LeftHandState::IDLE;
	void ChangeState(LeftHandState _State);
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
	float HandSpeed = 600.0f;
	float4 HandPos = float4::Zero;
	float4 CurPos = float4::Zero;
	float4 PlayerPos = float4::Zero;
	float YPos = 0.0f;
	bool NextPatton = false;
	
};

