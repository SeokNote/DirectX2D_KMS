#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class BossSwordState
{
	IDLE,
	MOVE,
	DEAD,
	BOMB,
};
// 설명 :
class BossSword :public GameEngineActor
{
public:
	// constrcuter destructer
	BossSword();
	~BossSword();

	// delete Function
	BossSword(const BossSword& _Other) = delete;
	BossSword(BossSword&& _Other) noexcept = delete;
	BossSword& operator=(const BossSword& _Other) = delete;
	BossSword& operator=(BossSword&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> SwordRender;
	std::shared_ptr<class GameEngineSpriteRenderer> SwordDeadRender;
	std::shared_ptr<class GameEngineSpriteRenderer> SwordEffectRender;
	std::shared_ptr<class GameEngineSpriteRenderer> SwordFxRender;
	std::shared_ptr<class GameEngineSpriteRenderer> SwordColRender;
	std::shared_ptr<class GameEngineCollision> SwordCol;

	bool PixelCheck();
	void CollisionCheck(float _DeltaTime);
	void ChangeState(BossSwordState _State);
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

	void BombStart();
	void BombUpdate(float _Time);
	void BombEnd();
	BossSwordState StateValue = BossSwordState::IDLE;
	float4 PixelMapResultPos = float4::Zero;
	std::shared_ptr<class GameEngineTexture> Ptr = nullptr;
	GameEnginePixelColor Pixel = GameEnginePixelColor::Black;
	//값
	float TimeCheck_0 = 0.0f;
	float TimeCheck_1 = 0.0f;
	float TimeCheck_2 = 0.0f;
	float TimeCheck_3 = 0.0f;
	float SwordSpeed = 1500.0f;
	int SwordDamage = 3;
	float InvinTime = 0.0f;
	bool InvinCheck = false;
	//현재 각도값
	float4 CurDir = float4::Zero;
	float4 SwordPos = float4::Zero;
	float4 PlayerPos = float4::Zero;
	//충돌했을때의 위치
	float4 ColCurPos = float4::Zero;
	float ZDeg = 0.0f;
	bool IsGround = false;
	bool DeathValue = false;
};

