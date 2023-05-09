#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


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
	Render1->GetTransform()->SetLocalPosition({0.0f,0.0f,-1000.0f });
	Render1->GetTransform()->SetLocalScale({ 128.0f, 128.0f });



}
bool awds = false;
bool awds1 = false;
bool awds2 = false;
bool awds3 = false;

void Player::Update(float _DeltaTime)
{
	
	//std::shared_ptr<GameEngineTexture> Ptr = GameEngineTexture::Find("townbg1.png");
	

		float CurColPos = GetTransform()->GetLocalPosition().x;
		float CurColPosY = GetTransform()->GetLocalPosition().y;
		

	int Speed = 300.0f;
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
		GetTransform()->SetLocalPosition({ 3030,-219 });
		awds = true;
	}
	if (awds1 == false && CurColPos > 3909.0f) {
		GetTransform()->SetLocalPosition({ 4250,-319 });
		awds1 = true;
	}
	if (awds2 == false && CurColPos > 6389) {
		GetTransform()->SetLocalPosition({ 8023,560 });
		awds2 = true;
	}
	//if (awds3 == false && CurColPos > 6900) {
	//	GetTransform()->SetLocalPosition({ 8600,560 });
	//	awds3 = true;
	//}

}
// 이건 디버깅용도나 
void Player::Render(float _Delta)
{
	// GetTransform()->AddLocalRotation({0.0f, 0.0f, 360.0f * _Delta});
};
