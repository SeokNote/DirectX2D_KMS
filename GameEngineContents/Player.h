#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "PlayerDataBase.h"
#include "PlayLevel.h"
#include "PixelCollision.h"
// 설명 :
enum class PlayerState
{
	IDLE,
	MOVE,
	JUMP,
	FALL,
	DASH,
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

	bool GroundCheck(float4 _Pos);
	bool MiddleCheck(float4 _Pos);
	bool TopCheck();
	bool LeftSideCheck();
	bool RightSideCheck();
	float4 PixelCalculation(float4 _TargetPos, float4 _MapCenterPos, float4 _TransColPos);
	float SetBlinkTime(float _Value)
	{
		BlinkTime = _Value;
		return BlinkTime;
	}

	int SetUICount(int _Value) {
		UICount = _Value;
		return UICount;
	}
	int GetUICount()
	{
		return UICount;
	}
	int GetDashCount()
	{
		return DashCount;
	}
	bool GetFilpCheck()
	{
		return FilpCheck;
	}
	bool IsBeltCheck()
	{
		return BeltCheck;
	}
	PlayerDataBase& GetData()
	{
		return Data;
	}
	bool GetABSValue()
	{
		return IsAbsoult;
	}
	void Invincible(float _Delta);
protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;


private:
	void SetDebugKey();
	PlayerDataBase Data = PlayerDataBase();
	GameEngineSound Walk;
	void Filp();
	void HitCameraShack();
	void SetPlayerCollision(float _Delta);
	void DashPlusCount(float _Delta);
	bool CollisonCheck = false;
	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerRender;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerJumpEffectRender;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerWalkEffectRender;
	std::shared_ptr<class GameEngineUIRenderer> PlayerHitRender;

	std::shared_ptr<class DashEffect> DashEffectPtr;

	
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerTopRender;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayerBottoomRender;
	std::shared_ptr<class PointLightEffect> LightEffect = nullptr;

	std::shared_ptr<class GameEngineCollision> PlayerCol;
	std::shared_ptr<class GameEngineCollision> PlayerLeftCol;
	std::shared_ptr<class GameEngineCollision> PlayerRightCol;

	bool IsGround = false;
	bool Fall = false;
	GameEnginePixelColor Pixel = GameEnginePixelColor::Black;
	std::shared_ptr<class GameEngineTexture> Ptr = nullptr;

	MyMap CurMap = MyMap::None;
	PixelCollision* NomalPixel = nullptr;

	std::shared_ptr<class GameEngineSpriteRenderer> TestColMap = nullptr;
	std::shared_ptr<class GameEngineFontRenderer> ABSfont =nullptr;
	float4 MapCenter = float4::Zero;
	float4 TransColPos = float4::Zero;
	float4 TargetPos = float4::Zero;
	float4 PixelMapResultPos = float4::Zero;
	//플레이어 무적
	float BlinkTime = 0.0f;
	float InvincibleTime = 0.0f;
	bool IsInvincible = false;
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

	void DashStart();
	void DashUpdate(float _Time);
	void DashEnd();

	void ColRenderSet();
	PlayerState StateValue = PlayerState::IDLE;
	float4 MoveDir = float4::Zero;
	float4 MoveRange = float4::Zero;
	float MoveSpeed = 350.f;

	float EffectTime = 0.0f;
	float JumpTime = 0.0f;
	int JumpCount = 0;
	float StartXpos = 0.0f;
	float StartYpos = 0.0f;
	float4 MoveStartPoS = float4::Zero;
	float EndYpos = 0.0f;
	GameEnginePixelColor MiddleGround = { static_cast<unsigned char>(255),  static_cast<unsigned char>(0),  static_cast<unsigned char>(255),  static_cast<unsigned char>(255)};
	bool Falling = false;
	bool IsMiddle = false;
	float CheckTime = 0.0f;
	float4 PlayerTop = { 0.0f,15.0f,0.f };
	float4 PlayerSide = { -25.0f,0.0f,0.f };
	int UICount = 0;
	//카메라 쉐이크
	float ShakeTime = 0.0f;
	float y = 0.0f;
	float x = 0.0f;
	bool ShackCheck = false;
	//대쉬관련
	float4 BottomPos_0 = float4::Zero;
	float4 DashVector = float4::Zero;
	float ZDeg = 0.0f;
	int DashCount = 3;
	float DashTime = 0.0f;
	float4 DashCurPos = float4::Zero;
	float4 PrevDashPos = float4::Zero;
	float UpDashTime = 0.0f;
	float DashSpeed = 1000.0f;
	float DashPlus = 0.0f;
	//대쉬 이펙트 관련
	bool Effect_Check = false;
	float DashEffectTime = 0.0f;
	//포탈 충돌유무
	bool IsLeftPotal = false;
	bool IsRightPotal = false;

	//플립 예아니오
	bool FilpCheck = false;
	bool BeltCheck = false;
	//무적
	bool IsAbsoult = false;
	int ABSCount = 0;
};
