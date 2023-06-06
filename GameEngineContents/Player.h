#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "PlayLevel.h"
#include "PixelCollision.h"
// Ό³Έν :
enum class PlayerState
{
	IDLE,
	MOVE,
	JUMP,
	FALL,
};
class Player : public GameEngineActor
{
public:
	static Player* MainPlayer;

	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;



	std::shared_ptr<class GameEngineSpriteRenderer> GetPlayerPtr()
	{
		return PlayerRender;
	}
	MyMap SetMyMap(MyMap _MyMap);

	bool GroundCheck();
	bool MiddleCheck();
	bool TopCheck();
	bool LeftSideCheck();
	bool RightSideCheck();
	float4 PixelCalculation(float4 _TargetPos, float4 _MapCenterPos, float4 _TransColPos);


	int SetUICount(int _Value) {
		UICount = _Value;
		return UICount;
	}
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;


private:
	void Filp();

	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerRender;

	std::shared_ptr<class GameEngineSpriteRenderer> PlayerTopRender;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerBottoomRender;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerSideRender;

	std::shared_ptr<class GameEngineCollision> PlayerCol;
	std::shared_ptr<class GameEngineTexture> Ptr = nullptr;
	bool IsGround = false;
	bool Fall = false;
	GameEnginePixelColor Pixel = GameEnginePixelColor::Black;
	MyMap CurMap = MyMap::None;
	PixelCollision* NomalPixel = nullptr;


	std::shared_ptr<class GameEngineSpriteRenderer> TestColMap;

	float4 MapCenter = float4::Zero;
	float4 TransColPos = float4::Zero;
	float4 TargetPos = float4::Zero;
	float4 PixelMapResultPos = float4::Zero;


	// State
	void ChangeState(PlayerState _State);
	void UpdateState(float _Time);

	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void MoveStart();
	void MoveUpdate(float _Time);
	void MoveEnd();

	void JumpStart();
	void JumpUpdate(float _Time);
	void JumpEnd();

	void FallStart();
	void FallUpdate(float _Time);
	void FallEnd();
	PlayerState StateValue = PlayerState::IDLE;
	float4 MoveDir = float4::Zero;
	float4 MoveRange = float4::Zero;
	float MoveSpeed = 300.f;


	float JumpTime = 0.0f;
	int JumpCount = 0;

	float StartYpos = 0.0f;
	float EndYpos = 0.0f;
	GameEnginePixelColor MiddleGround = { 255, 0, 255, 255 };
	bool Falling = false;
	bool IsMiddle = false;
	float CheckTime = 0.0f;
	float4 PlayerTop = { 0.0f,15.0f,0.f };
	float4 PlayerSide = { -25.0f,0.0f,0.f };
	int UICount = 0;
};
