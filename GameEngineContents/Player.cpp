#include "PrecompileHeader.h"
#include "Player.h"
#include "PixelCollision.h"
#include "PlayMouse.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>

Player* Player::MainPlayer = nullptr;

Player::Player()
{
	MainPlayer = this;

}

Player::~Player()
{
	if (this == MainPlayer)
	{
		MainPlayer = nullptr;
	}

}






void Player::Start()
{

	if (nullptr == GameEngineSprite::Find("PlayerDead"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("MainPlayer");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("PlayerDead").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("PlayerIdle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("PlayerJump").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("PlayerRun").GetFullPath());

	}



	PlayerRender = CreateComponent<GameEngineSpriteRenderer>(1);
	PlayerRender->SetTexture("CharIdle0.png");
	PlayerRender->GetTransform()->SetLocalScale({ 128.0f, 128.0f });
	PlayerRender->CreateAnimation({ .AnimationName = "Player_Dead", .SpriteName = "PlayerDead", .ScaleToTexture = false });
	PlayerRender->CreateAnimation({ .AnimationName = "Player_Idle", .SpriteName = "PlayerIdle", .ScaleToTexture = false });
	PlayerRender->CreateAnimation({ .AnimationName = "Player_Jump", .SpriteName = "PlayerJump", .ScaleToTexture = false });
	PlayerRender->CreateAnimation({ .AnimationName = "Player_Move", .SpriteName = "PlayerRun",.FrameInter = 0.09f,.ScaleToTexture = false });

	PlayerRender->ChangeAnimation("Player_Idle");

	PlayerTopRender = CreateComponent<GameEngineSpriteRenderer>(1);
	PlayerTopRender->SetTexture("TopBottom.png");
	PlayerTopRender->GetTransform()->SetLocalScale({ 58.0f, 4.0f });

	PlayerBottoomRender = CreateComponent<GameEngineSpriteRenderer>(1);
	PlayerBottoomRender->SetTexture("TopBottom.png");
	PlayerBottoomRender->GetTransform()->SetLocalScale({ 58.0f, 4.0f });

	//PlayerSideRender = CreateComponent<GameEngineSpriteRenderer>(1);
	//PlayerSideRender->SetTexture("PlayerSideCol.png");
	//PlayerSideRender->GetTransform()->SetLocalScale({ 128.0f, 128.0f });




	TestColMap = CreateComponent<GameEngineSpriteRenderer>(1);
	TestColMap->SetTexture("TownCol_0.png");
	TestColMap->GetTransform()->SetLocalScale({ 5120.0f,1440.0f,-710.0f });

	PlayerCol = CreateComponent<GameEngineCollision>();
	PlayerCol->GetTransform()->SetLocalScale({ 64.0f, 64.0f });
	PlayerCol->SetOrder(3333);

}

void Player::Update(float _DeltaTime)
{
	float4 PlayerPos = GetTransform()->GetLocalPosition();

	PlayerCol->GetTransform()->SetWorldPosition({ PlayerPos.x,PlayerPos.y,0.0f});
	PlayerTopRender->GetTransform()->SetWorldPosition({ PlayerPos.x,PlayerPos.y+15.0f,PlayerPos.z });
	PlayerBottoomRender->GetTransform()->SetWorldPosition({ PlayerPos.x,PlayerPos.y - 65.0f,PlayerPos.z });

	CurMap =SetMyMap(CurMap);
	UpdateState(_DeltaTime);
	GetTransform()->AddLocalPosition(MoveDir * MoveSpeed * _DeltaTime);
	Filp();

}


MyMap Player::SetMyMap(MyMap _MyMap)
{
	float4 PlayerPos = GetTransform()->GetLocalPosition();
	if (PlayerPos.x > -2560.0f && PlayerPos.x < 2560) {
		_MyMap = MyMap::Town;
		return _MyMap;
	}
	if (PlayerPos.x > 2660.0f && PlayerPos.x < 3940) {
		_MyMap = MyMap::Stage1_1;

		return _MyMap;
	}
	if (PlayerPos.x > 3940 && PlayerPos.x < 6600) {
		_MyMap = MyMap::Stage1_2;

		return _MyMap;
	}
	if (PlayerPos.x > 6700.0f && PlayerPos.x < 9260.0f) {
		_MyMap = MyMap::Stage1_3;

		return _MyMap;
	}
	if (PlayerPos.x > 9360.0f && PlayerPos.x < 11280.0f) {
		_MyMap = MyMap::Stage1_4;

		return _MyMap;
	}
	if (PlayerPos.x > 11380.0f && PlayerPos.x < 12788.0f) {
		_MyMap = MyMap::Stage1_Boss;

		return _MyMap;
	}
	if (PlayerPos.x > 12888.0f && PlayerPos.x < 14168.0f) {
		_MyMap = MyMap::Stage2_1;

		return _MyMap;
	}
	if (PlayerPos.x > 14268.0f && PlayerPos.x < 15868.0f) {
		_MyMap = MyMap::Stage2_Boss;

		return _MyMap;
	}
	if (PlayerPos.x > 15968.0f && PlayerPos.x < 17568.0f) {
		_MyMap = MyMap::Stage3_1;

		return _MyMap;
	}
	if (PlayerPos.x > 17668.0f && PlayerPos.x < 20228.0f) {

		_MyMap = MyMap::Stage3_Boss;
		return _MyMap;
	}
}

bool Player::GroundCheck()
{
	float4 PlayerPos = GetTransform()->GetLocalPosition();
	float4 BottomPos = PlayerBottoomRender->GetTransform()->GetWorldPosition();
	CurMap = SetMyMap(CurMap);
	switch (CurMap)
	{
	case MyMap::None:
		break;
	case MyMap::Town:
		PixelMapResultPos = PixelCalculation(BottomPos,{0.0f,0.0f,0.0f},{2560.f,720.0f});
		Ptr = GameEngineTexture::Find("TownCol_3.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y));
		Pixel.a = 0;
		if (Pixel == GameEnginePixelColor::Black)
		{
			return true;
			PlayerRender->ChangeAnimation("Player_Idle");
		}
		else 
		{
			return false;
		}
		break;
	case MyMap::Stage1_1:
		PixelMapResultPos = PixelCalculation(BottomPos, { 3300.0f,0.0f,0.0f }, { 640.0f,360 });
		Ptr = GameEngineTexture::Find("StageCol_1.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y));
		Pixel.a = 0;
		if (Pixel == GameEnginePixelColor::Black)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage1_2:
		break;
	case MyMap::Stage1_3:
		break;
	case MyMap::Stage1_4:
		break;
	case MyMap::Stage1_Boss:
		break;
	case MyMap::Stage2_1:
		break;
	case MyMap::Stage2_Boss:
		break;
	case MyMap::Stage3_1:
		break;
	case MyMap::Stage3_Boss:
		break;
	default:
		break;
	}

}

bool Player::MiddleCheck()
{
	float4 PlayerPos = GetTransform()->GetLocalPosition();
	float4 BottomPos = PlayerTopRender->GetTransform()->GetWorldPosition();
	CurMap = SetMyMap(CurMap);
	switch (CurMap)
	{
	case MyMap::None:
		break;
	case MyMap::Town:
		PixelMapResultPos = PixelCalculation(BottomPos, { 0.0f,0.0f,0.0f }, { 2560.f,720.0f });
		Ptr = GameEngineTexture::Find("TownCol_3.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y+80.0f));
		if (true == Falling && Pixel == MiddleGround)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage1_1:
		PixelMapResultPos = PixelCalculation(BottomPos, { 3300.0f,0.0f,0.0f }, { 640.0f,360 });
		Ptr = GameEngineTexture::Find("StageCol_1.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y));
		Pixel.a = 0;
		if (Falling==false && Pixel == GameEnginePixelColor::Black)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage1_2:
		break;
	case MyMap::Stage1_3:
		break;
	case MyMap::Stage1_4:
		break;
	case MyMap::Stage1_Boss:
		break;
	case MyMap::Stage2_1:
		break;
	case MyMap::Stage2_Boss:
		break;
	case MyMap::Stage3_1:
		break;
	case MyMap::Stage3_Boss:
		break;
	default:
		break;
	}
}

float4 Player::PixelCalculation(float4 _TargetPos, float4 _MapCenterPos, float4 _TransColPos)
{
	TargetPos = _TargetPos;
	PixelMapResultPos.x = _TargetPos.x + _TransColPos.x - _MapCenterPos.x;
	PixelMapResultPos.y = _TransColPos.y - _TargetPos.y;
	return PixelMapResultPos;
}
void Player::Filp()
{
	float4 MousePos = GameEngineWindow::GetMousePosition();
	MousePos.x -= 640.0f;
	if (0 > MousePos.x) {
		PlayerRender->GetTransform()->SetLocalNegativeScaleX();
	}
	else {
		PlayerRender->GetTransform()->SetLocalPositiveScaleX();

	}

};

//디버깅용도나 
void Player::Render(float _Delta)
{
	// GetTransform()->AddLocalRotation({0.0f, 0.0f, 360.0f * _Delta});
}
