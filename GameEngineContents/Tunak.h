#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Player.h"
#include "BossBase.h"
enum class TunakState
{
	IDLE,
	SPIKE_R,
	SPIKE_S,
	SPIKE_U,
	SPIKE_E,
	OVERPOWER,
	DOUBLEATTACK,
	SHOUT,
	JUMPATTACK,
	GoblimBomb,
	TACKLE,
	HALFPATTON_S,
	HALFPATTON_E,
	TunakDead,
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
	float4 TunakColScale = { 230.0f,238.0f,0.0f };
	float4 DoubleAttackScale = { 150.0f,238.0f,0.0f };
	float4 TakcleScale = { 100.0f,188.0f,0.0f };
	void DamegeCheck();
	void DeadEvent(float _DeltaTime);
	void TunakCameraShack(int _Value);
	void CalBezierBulletTransform(const float4& _Start, const float4& _Height, const float4& _End, float _Ratio);
	void TunakCollision(float _DeltaTime);
	std::shared_ptr<class GameEngineSpriteRenderer> TunakRender;
	std::shared_ptr<class GameEngineUIRenderer> DeadBGRender;
	std::shared_ptr<class GameEngineCollision> TunakCol;
	std::shared_ptr<class GameEngineCollision> TunakDoubleAttackCol;
	std::shared_ptr<class GameEngineCollision> TunakTackleCol;

	std::shared_ptr<class GroundBomb> GroundBombPtr_0;
	std::shared_ptr<class GroundBomb> GroundBombPtr_1;
	std::shared_ptr<class GroundBomb> GroundBombPtr_2;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletBG;

	std::shared_ptr<class BossDeadEffect> BossDeadEffectPtr;
	void TunakFlip();
	//FSM
	TunakState StateValue = TunakState::IDLE;
	void ChangeState(TunakState _State);
	void UpdateState(float _Time);
	MyMap CurMap = MyMap::None;
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

	void OverPowerStart();
	void OverPowerUpdate(float _Time);
	void OverPowerEnd();

	void DoubleAttackStart();
	void DoubleAttackUpdate(float _Time);
	void DoubleAttackEnd();

	void ShoutStart();
	void ShoutUpdate(float _Time);
	void ShoutEnd();

	void JumpAttackStart();
	void JumpAttackUpdate(float _Time);
	void JumpAttackEnd();

	void GoblinBombStart();
	void GoblinBombUpdate(float _Time);
	void GoblinBombEnd();

	void TackleStart();
	void TackleUpdate(float _Time);
	void TackleEnd();

	void HalfHp_SStart();
	void HalfHp_SUpdate(float _Time);
	void HalfHp_SEnd();

	void HalfHp_EStart();
	void HalfHp_EUpdate(float _Time);
	void HalfHp_EEnd();

	void TunakDeadStart();
	void TunakDeadUpdate(float _Time);
	void TunakDeadEnd();
	//시간값
	float TestTime = 0.0f;
	float TestTime_0 = 0.0f;
	float TestTime_1 = 0.0f;
	float TestTime_2 = 0.0f;
	//카메라 쉐이크
	float ShakeTime = 0.0f;
	float y = 0.0f;
	float x = 0.0f;
	bool ShackStart = false;
	bool DeadShack = false;
	float DeadShackTime = 0.0f;
	float ShackEnd = 0.0f;
	//투낙 hp바
	std::shared_ptr<class GameEngineUIRenderer> BossHpBase;
	std::shared_ptr<class GameEngineUIRenderer > BossHpFront;
	std::shared_ptr<class GameEngineUIRenderer> BossHpBar;
	float4 HPBarBaseScale = { 500.0f,64.0f,0.f };
	float4 HPBarScale = { 400.0f,40.0f,0.0f };
	float4 HPBasePos = { 10.0f,-320.0f,-100.0f };
	float4 HPPos = { 48.0f,-320.0f,-100.0f };
	//투낙 spike 패턴
	float4 CurPos = float4::Zero;
	float4 SpikeEndPos = { 15580.0f,180.f,-800.0f };
	float4 SpikeHeight = float4::Zero;
	float InterRatio = 0.0f;
	float AfterImageTime = 0.0f;
	float FrameTime = 0.0f;
	std::shared_ptr<class TunakAfterEffect> TunakAfter_E;
	//투낙 폭발 위치
	float BombX = 0.0f;
	//투낙 더블어택
	float DoubleAttackSpeed = 150.0f;
	float DoubleAttactTime = 0.0f;
	int DoubleAttackDamege = 3;
	float DoubleTime = 0.0f;
	//투낙 총알발싸잇
	float BulletTime = 0.0f;
	float StartTime = 0.0f;
	std::shared_ptr<class TunakBullet> TunakBulletPtr;
	bool BulletCheck = false;
	float4 BulletPos = { -100.0f,-100.0f,0.0f };
	float4 FlipBulletPos = { 100.0f,-100.0f,0.0f };

	//투낙 점프어택
	float4 EndPos = float4::Zero;
	float4 Height = float4::Zero;
	float JumpTime = 0.0f;
	float JumpSpeed = 0.0;
	float TimeCheck = 0.0f;//뛰기까지의 시간
	//투낙 고블린패턴
	std::shared_ptr<class GoblinBomb> GoblinBomb_0;
	std::shared_ptr<class GoblinBomb> GoblinBomb_1;
	std::shared_ptr<class GoblinBomb> GoblinBomb_2;
	std::shared_ptr<class GoblinBomb> GoblinBomb_3;
	float GoblinPosX = 0.0f;
	float Tuom = 300.0f;
	bool IsGoblin = false;
	//투낙 숄더태클
	bool TackleCheck = false;
	float PattonTime_S = 0.0f;
	float TackleSpeed = 800.0f;
	int TakcleDamage = 10;
	//투낙 더스트
	std::shared_ptr<class TunakDust> TunakDustSPtr;
	std::shared_ptr<class TunakDust_D> TunakDustDPtr;
	float DustTime = 0.0f;
	float4 LeftDustPos = { 50.0f,-180.0f,0.0f };
	float4 RightDustPos = { -50.0f,-180.0f,0.0f };
	//투낙 하프패턴
	float HalfSpeed = 1500.0f;
	float HalfAfterImage_T = 0.0f;
	float GoblinTime = 0.0f;
	float DownTime = 0.0f;
	bool HalfCheck = false;
	std::shared_ptr<class TunakJumpEffect> TunakJumpEffectPtr;
	int GoblinCount = 0;
	std::shared_ptr<class TunakWave> TunakWavePtr;
	//투낙 죽음
	float DeadEffectTime = 0.0f;
	float DeadTime = 0.0f;
	float TimeCheck_D = 0.0f;
	//변수 
	bool IsDead = false;
	bool IsFilp = false;
	float4 TunakPos = float4::Zero;
	float FlipTime = 0.0f; //플레이어 방향찾는 시간
	int RandomIndex = 0; //랜덤값
	bool TunakHitCheck = false; //히트체크
	int TunakHP = 1500;
	float Invincibilitytime = 0.0f; //무적시간
	float RatioValue = 0.0f; //폭팔후 이펙트 비율
};

