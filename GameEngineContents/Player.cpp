#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "PixelCollision.h"

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
	if (false == GameEngineInput::IsKey("PlayerMoveLeft"))
	{
		GameEngineInput::CreateKey("PlayerMoveLeft", 'A');
		GameEngineInput::CreateKey("PlayerMoveRight", 'D');
		GameEngineInput::CreateKey("PlayerMoveUp", 'Q');
		GameEngineInput::CreateKey("PlayerMoveDown", 'E');
		GameEngineInput::CreateKey("PlayerMoveForward", 'W');
		GameEngineInput::CreateKey("PlayerMoveBack", 'S');
	}




	Render1 = CreateComponent<GameEngineSpriteRenderer>();
	Render1->SetTexture("CharIdle0.png");
	Render1->GetTransform()->SetLocalPosition({0.0f,0.0f,0.0f });
	Render1->GetTransform()->SetLocalScale({ 128.0f, 128.0f });


	PlayerCol = CreateComponent<GameEngineCollision>();
	PlayerCol->GetTransform()->SetLocalScale({ 30.0f, 30.0f });
	PlayerCol->SetOrder(3333);

}
bool awds = false;
bool awds1 = false;
bool awds2 = false;
bool awds3 = false;
bool awds4 = false;
bool awds5 = false;
bool awds6 = false;

void Player::Update(float _DeltaTime)
{
	float4 PlayerPos = GetTransform()->GetLocalPosition();

	PlayerCol->GetTransform()->SetLocalPosition({ PlayerPos.x,PlayerPos.y,0.0f});

	CurMap =SetMyMap(CurMap);
	int Speed = 300.0f;
	std::string Name = "";
	Name = "Stage_1";
	//NomalPixel->GetMapPixel(Name.c_str(), { 0,0,0 }, { 2560,720,0 });
	float4 MapCenter = { 0.0f,0.0f,0.0f };
	float4 TransColPos = { 2560.0f,720 };
	float4 ColPlayerPos = MapCenter + TransColPos - PlayerPos;
	std::shared_ptr<GameEngineTexture> Ptr = GameEngineTexture::Find("TownCol_1.png");

	GameEnginePixelColor Pixel = Ptr->GetPixel(ColPlayerPos.x, ColPlayerPos.y+65);
	Pixel.a = 0;
	if (Pixel == GameEnginePixelColor::Black) {
		//GetTransform()->AddLocalPosition(-float4::Down * Speed * _DeltaTime);
	}

		//CulMap = PlayLevel::MainPlayLevel->GetMyMap(CulMap);
		float CurColPos = GetTransform()->GetLocalPosition().x;
		float CurColPosY = GetTransform()->GetLocalPosition().y;
		

	if (true == GameEngineInput::IsPress("PlayerMoveLeft"))
	{
		GetTransform()->AddLocalPosition(float4::Left * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveRight"))
	{
		GetTransform()->AddLocalPosition(float4::Right * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveUp"))
	{
		GetTransform()->AddLocalPosition(float4::Up * Speed * _DeltaTime);
	}
	if (true == GameEngineInput::IsPress("PlayerMoveDown"))
	{
		GetTransform()->AddLocalPosition(float4::Down * Speed * _DeltaTime);
	}

	//충돌이 나오면던전에 충돌하면 1초뒤에 이동하자
	if (awds==false && CurColPos > 1400.0f) {
		GetTransform()->SetLocalPosition({ 3030,-219 }); //스테이지 1  2660~ 3940
		awds = true;
	}
	if (awds1 == false && CurColPos > 3909.0f) {
		GetTransform()->SetLocalPosition({ 4250,-319 }); //스테이지 2 4040 ~ 6600
		awds1 = true;
	}
	if (awds2 == false && CurColPos > 6389) {
		GetTransform()->SetLocalPosition({ 8023,560 }); //스테이지 3 6700 ~ 9260
		awds2 = true;
	}
	if (awds3 == false && CurColPos > 8500) {
		GetTransform()->SetLocalPosition({ 9500,560 }); //스테이지 4 9360~ 11280
		awds3 = true;
	}
	if (awds4 == false && CurColPos > 10500) {
		GetTransform()->SetLocalPosition({ 11480,560 }); // 1층 보스 11380 ~ 12388
		awds4 = true;
	}
	if (awds5 == false && CurColPos > 12750) {
		GetTransform()->SetLocalPosition({ 13150 ,-38 }); // 2층 보스전스테이지 12888 ~ 14168
		awds5 = true;
	}
	if (awds6 == false && CurColPos > 14000) {
		GetTransform()->SetLocalPosition({ 14368,38 }); // 2층 보스 14268.0f ~ 15868.0f
		awds6 = true;
	}
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
// 이건 디버깅용도나 
void Player::Render(float _Delta)
{
	// GetTransform()->AddLocalRotation({0.0f, 0.0f, 360.0f * _Delta});
};
