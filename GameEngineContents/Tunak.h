#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "Player.h"
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
};
// ¼³¸í :
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
	std::shared_ptr<class GroundBomb> GroundBombPtr_0;
	std::shared_ptr<class GroundBomb> GroundBombPtr_1;
	std::shared_ptr<class GroundBomb> GroundBombPtr_2;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletBG;
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


	//Å×½ºÆ®
	float TestTime = 0.0f;
	float TestTime_0 = 0.0f;
	float TestTime_1 = 0.0f;
	float TestTime_2 = 0.0f;

	//Åõ³« spike ÆÐÅÏ
	float4 CurPos = float4::Zero;
	float4 SpikeEndPos = { 15580.0f,180.f,-800.0f };
	float4 SpikeHeight = float4::Zero;
	float InterRatio = 0.0f;
	float AfterImageTime = 0.0f;
	std::shared_ptr<class TunakAfterEffect> TunakAfter_E;
	//Åõ³« Æø¹ß À§Ä¡
	float BombX = 0.0f;
	//Åõ³« ´õºí¾îÅÃ
	float DoubleAttackSpeed = 150.0f;
	float DoubleAttactTime = 0.0f;
	//Åõ³« ÃÑ¾Ë¹ß½ÎÀÕ
	float BulletTime = 0.0f;
	float StartTime = 0.0f;
	std::shared_ptr<class TunakBullet> TunakBulletPtr;
	bool BulletCheck = false;
	float4 BulletPos = { -100.0f,-100.0f,0.0f };
	float4 FlipBulletPos = { 100.0f,-100.0f,0.0f };

	//Åõ³« Á¡ÇÁ¾îÅÃ
	float4 EndPos = float4::Zero;
	float4 Height = float4::Zero;
	float JumpTime = 0.0f;
	float JumpSpeed = 0.0;
	float TimeCheck = 0.0f;//¶Ù±â±îÁöÀÇ ½Ã°£
	//Åõ³« °íºí¸°ÆÐÅÏ
	std::shared_ptr<class GoblinBomb> GoblinBomb_0;
	std::shared_ptr<class GoblinBomb> GoblinBomb_1;
	std::shared_ptr<class GoblinBomb> GoblinBomb_2;
	std::shared_ptr<class GoblinBomb> GoblinBomb_3;
	float GoblinPosX = 0.0f;
	float Tuom = 300.0f;
	bool IsGoblin = false;
	//Åõ³« ¼ñ´õÅÂÅ¬
	bool TackleCheck = false;
	float PattonTime_S = 0.0f;
	float TackleSpeed = 800.0f;
	//Åõ³« ´õ½ºÆ®
	std::shared_ptr<class TunakDust> TunakDustSPtr;
	std::shared_ptr<class TunakDust_D> TunakDustDPtr;
	float DustTime = 0.0f;
	float4 LeftDustPos = { 50.0f,-180.0f,0.0f };
	float4 RightDustPos = { -50.0f,-180.0f,0.0f };

	//º¯¼ö 
	bool IsFilp = false;
	float4 TunakPos = float4::Zero;
	float FlipTime = 0.0f;
	int RandomIndex = 0;
};

