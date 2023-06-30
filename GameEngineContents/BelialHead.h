#pragma once
#include <GameEngineCore/GameEngineActor.h>
// 설명 :
enum class BossHeadState
{
	IDLE,
	MOVE,
	SWORD,
	DEAD,
	EVENT,
	EVENT2,
};
class BelialHead : public GameEngineActor
{
public:
	static BelialHead* MainBelialHead;
	// constrcuter destructer
	BelialHead();
	~BelialHead();

	// delete Function
	BelialHead(const BelialHead& _Other) = delete;
	BelialHead(BelialHead&& _Other) noexcept = delete;
	BelialHead& operator=(const BelialHead& _Other) = delete;
	BelialHead& operator=(BelialHead&& _Other) noexcept = delete;
	std::shared_ptr<class GameEngineSpriteRenderer> GetBGPtr()
	{
		return BelialBGRender;
	}
	bool IsBulletPatton()
	{
		return BulletPatton;
	}
	int GetBelialHP()
	{
		return BelialHp;
	}
	void SubBelialHP(int _Damage)
	{
		BelialHp -= _Damage;
	}
	bool GetHandStop()
	{
		return HandleStop;
	}
	bool GetHandStart()
	{
		return HandStart;
	}

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void DeathEvent(float _DeltaTime);
	void BelialCameraShack(int _Value);
	void BelialCollision(float _DeltaTime);
	void BelialSwordPlay(float _Time);
	float4 MainBGPos =  { 12080.0f,-250.0f,-740.0f };
	float4 HPBarBaseScale = { 500.0f,64.0f,0.f };
	float4 HPBarScale = { 400.0f,40.0f,0.0f };
	float4 HPBasePos = { 10.0f,-320.0f,0.0f };
	float4 HPPos = { 48.0f,-320.0f,0.0f };
	float4 HeadScale = { 280.0f,512.0f,0.0f };
	//카메라 쉐이크
	float PattonStart = 0.0f;
	float ShakeTime = 0.0f;
	float y = 0.0f;
	float x = 0.0f;
	bool ShackStart = false;
	bool DeadShack = false;
	float DeadShackTime = 0.0f;
	float ShackEnd = 0.0f;
	std::shared_ptr<class BossDeadEffect> BossDeadEffectPtr;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialHeadRender;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBGRender;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletComponet;
	std::shared_ptr<class GameEngineCollision> BelialCol;
	std::shared_ptr<class BelialHeadPice> BelialHeadPicePtr = nullptr;
	std::shared_ptr<class BelialBullet> BelialBulletRender = nullptr;
	std::shared_ptr<class BelialBulletBase> BelialBulletBasePtr = nullptr;

	std::shared_ptr<class GameEngineUIRenderer> BossHpBase;
	std::shared_ptr<class GameEngineUIRenderer > BossHpFront;
	std::shared_ptr<class GameEngineUIRenderer> BossHpBar;

	std::shared_ptr<class BelialHand_L> LeftPtr;
	std::shared_ptr<class BelialHand_R> RightPtr;

	BossHeadState StateValue = BossHeadState::IDLE;

	std::shared_ptr<class BossSword> BossSwordPtr_0 = nullptr;

	void ChangeState(BossHeadState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void SwordStart();
	void SwordUpdate(float _Time);
	void SwordEnd();

	void DeadStart();
	void DeadUpdate(float _Time);
	void DeadEnd();

	void EventStart();
	void EventUpdate(float _Time);
	void EventEnd();

	void Event2Start();
	void Event2Update(float _Time);
	void Event2End();
	//벨리알 
	float4 BelialColScale = { 200.0f,320.f,0.0f };
	float Invincibilitytime = 0.0f;
	int BelialHp = 1000;
	//패턴 불값
	bool IsBullet = true;
	bool BulletPatton = false;
	//패턴 시간체크
	float TimeCheck_0 = 0.0f;
	float TimeCheck_1 = 0.0f;
	float TimeCheck_2 = 0.0f;

	float SubBGTime = 0.0f;
	float BulletTime = 0.0f;
	float SwordTime = 0.0f;
	int SwordIndex = 0;
	std::shared_ptr<class BossSword> BossSwordPtr_1 = nullptr;
	std::shared_ptr<class BossSword> BossSwordPtr_2 = nullptr;
	std::shared_ptr<class BossSword> BossSwordPtr_3 = nullptr;
	std::shared_ptr<class BossSword> BossSwordPtr_4 = nullptr;
	std::shared_ptr<class BossSword> BossSwordPtr_5 = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> DeadBGRender;
	std::shared_ptr<class GameEngineUIRenderer> BossLayout;
	//카메라
	float4 ZoomPos = float4::Zero;
	bool CameraCtrl = false;
	float4 LayoutPos = { 0.0f,0.0f,-101.0f };

	float YInvers= -100.f;

	bool HandStop = false;
	bool HandStart = false;
	//칼 꽂히는 범위
	float StartX = 11800.0f;
	//벨리알 죽음
	bool IsDeath = false;
	bool HandleStop = false;
	bool IsDead = false;
	float DeadEffectTime = 0.0f;
	bool DeathShack = false;
	float DeadTime = 0.0f;
	float TimeCheck_D = 0.0f;
	float RatioValue = 0.0f;
	bool IsCreateHead = false;
	bool CheckValue = false;
	//테스트용
	float TestTime = 0.0f;

};

