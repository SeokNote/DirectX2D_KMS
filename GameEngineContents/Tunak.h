#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class TunakState
{
	IDLE,
	SPIKE_R,
	SPIKE_S,
	SPIKE_U,
	SPIKE_E,

};
// 설명 :
class Tunak : public GameEngineActor
{
public:
	// constrcuter destructer
	Tunak();
	~Tunak();

	// delete Function
	Tunak(const Tunak& _Other) = delete;
	Tunak(Tunak&& _Other) noexcept = delete;
	Tunak& operator=(const Tunak& _Other) = delete;
	Tunak& operator=(Tunak&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 TunakScale = { 456.0f,468.0f,0.0f };
	void CalBezierBulletTransform(const float4& _Start, const float4& _Height, const float4& _End, float _Ratio);
	std::shared_ptr<class GameEngineSpriteRenderer> TunakRender;
	std::shared_ptr<class GameEngineCollision> TunakCol;
	//FSM
	TunakState StateValue = TunakState::IDLE;
	void ChangeState(TunakState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void SPIKE_RStart();
	void SPIKE_RUpdate(float _Time);
	void SPIKE_REnd();

	void SPIKE_SStart();
	void SPIKE_SUpdate(float _Time);
	void SPIKE_SEnd();

	void SPIKE_UStart();
	void SPIKE_UUpdate(float _Time);
	void SPIKE_UEnd();

	void SPIKE_EStart();
	void SPIKE_EUpdate(float _Time);
	void SPIKE_EEnd();
	//테스트
	float TestTime = 0.0f;
	float TestTime_0 = 0.0f;
	float TestTime_1 = 0.0f;
	float TestTime_2 = 0.0f;

	//투낙 spike 패턴
	float4 CurPos = float4::Zero;
	float4 SpikeEndPos = { 15580.0f,180.f,-800.0f };
	float4 SpikeHeight = float4::Zero;
	float InterRatio = 0.0f;
	float AfterImageTime = 0.0f;
	std::shared_ptr<class TunakAfterEffect> TunakAfter_E;

	
};

