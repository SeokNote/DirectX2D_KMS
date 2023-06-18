#pragma once
#include <GameEngineCore/GameEngineActor.h>
// 설명 :
enum class BossHeadState
{
	IDLE,
	MOVE,
	DEAD,
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
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void BelialSwordPlay(float _Time);
	float4 MainBGPos =  { 12080.0f,-250.0f,-740.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> BelialHeadRender;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBGRender;

	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletComponet;

	std::shared_ptr<class BelialBullet> BelialBulletPtr;

	std::shared_ptr<class BossSword> BossSwordPtr_0 = nullptr;
	BossHeadState StateValue = BossHeadState::IDLE;

	void ChangeState(BossHeadState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void DeadStart();
	void DeadUpdate(float _Time);
	void DeadEnd();

	//패턴 시간체크
	float TimeCheck_0 = 0.0f;
	float TimeCheck_1 = 0.0f;
	float SubBGTime = 0.0f;

	float SwordTime = 0.0f;
	int SwordIndex = 0;
	std::shared_ptr<class BossSword> BossSwordPtr_1 = nullptr;
	std::shared_ptr<class BossSword> BossSwordPtr_2 = nullptr;
	std::shared_ptr<class BossSword> BossSwordPtr_3 = nullptr;
	std::shared_ptr<class BossSword> BossSwordPtr_4 = nullptr;
	std::shared_ptr<class BossSword> BossSwordPtr_5 = nullptr;

	float YInvers= -100.f;


	//칼 꽂히는 범위
	float StartX = 11800.0f;
};

