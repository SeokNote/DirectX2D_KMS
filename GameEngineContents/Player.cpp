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
}

Player::~Player()
{
}


void Player::Update(float _DeltaTime)
{
	MainPlayer = this;
	float RotSpeed = 180.0f;

	float Speed = 200.0f;
	GetLevel()->GetMainCamera()->GetTransform()->SetWorldPosition(GetTransform()->GetWorldPosition());

	if (true == GameEngineInput::IsPress("PlayerSpeedBoost"))
	{
		Speed = 500.0f;
	}

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
	//if (true == GameEngineInput::IsPress("PlayerMoveForward"))
	//{
	//	GetTransform()->AddLocalPosition(GetTransform()->GetLocalForwardVector() * Speed * _DeltaTime);
	//	// GetTransform()->AddLocalPosition(float4::Forward * Speed * _DeltaTime);
	//}
	//if (true == GameEngineInput::IsPress("PlayerMoveBack"))
	//{
	//	GetTransform()->AddLocalPosition(float4::Back * Speed * _DeltaTime);
	//}

	/*if (true == GameEngineInput::IsPress("PlayerRotY+"))
	{
		GetTransform()->AddLocalRotation({ 0.0f, RotSpeed * _DeltaTime, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerRotY-"))
	{
		GetTransform()->AddLocalRotation({ 0.0f, -RotSpeed * _DeltaTime, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerRotZ+"))
	{
		GetTransform()->AddLocalRotation({ 0.0f, 0.0f, RotSpeed * _DeltaTime });
	}
	if (true == GameEngineInput::IsPress("PlayerRotZ-"))
	{
		GetTransform()->AddLocalRotation({ 0.0f, 0.0f, -RotSpeed * _DeltaTime });
	}
	if (true == GameEngineInput::IsPress("PlayerRotX+"))
	{
		GetTransform()->AddLocalRotation({ RotSpeed * _DeltaTime, 0.0f, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerRotX-"))
	{
		GetTransform()->AddLocalRotation({ -RotSpeed * _DeltaTime, 0.0f, 0.0f });
	}

	float ScaleSpeed = 10.0f;

	if (true == GameEngineInput::IsPress("PlayerScaleY+"))
	{
		GetTransform()->AddLocalScale({ 0.0f, ScaleSpeed * _DeltaTime, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleY-"))
	{
		GetTransform()->AddLocalScale({ 0.0f, -ScaleSpeed * _DeltaTime, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleZ+"))
	{
		GetTransform()->AddLocalScale({ 0.0f, 0.0f, ScaleSpeed * _DeltaTime });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleZ-"))
	{
		GetTransform()->AddLocalScale({ 0.0f, 0.0f, -ScaleSpeed * _DeltaTime });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleX+"))
	{
		GetTransform()->AddLocalScale({ ScaleSpeed * _DeltaTime, 0.0f, 0.0f });
	}
	if (true == GameEngineInput::IsPress("PlayerScaleX-"))
	{
		GetTransform()->AddLocalScale({ -ScaleSpeed * _DeltaTime, 0.0f, 0.0f });
	}*/
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

		GameEngineInput::CreateKey("PlayerScaleY+", 'Y');
		GameEngineInput::CreateKey("PlayerScaleY-", 'U');
		GameEngineInput::CreateKey("PlayerScaleZ+", 'H');
		GameEngineInput::CreateKey("PlayerScaleZ-", 'J');
		GameEngineInput::CreateKey("PlayerScaleX+", 'N');
		GameEngineInput::CreateKey("PlayerScaleX-", 'M');


		GameEngineInput::CreateKey("PlayerRotY+", VK_NUMPAD1);
		GameEngineInput::CreateKey("PlayerRotY-", VK_NUMPAD2);
		GameEngineInput::CreateKey("PlayerRotZ+", VK_NUMPAD4);
		GameEngineInput::CreateKey("PlayerRotZ-", VK_NUMPAD5);
		GameEngineInput::CreateKey("PlayerRotX+", VK_NUMPAD7);
		GameEngineInput::CreateKey("PlayerRotX-", VK_NUMPAD8);
		GameEngineInput::CreateKey("PlayerSpeedBoost", VK_LSHIFT);
	}


	// 나는 스케일을 1로 고정해 놓는게 좋다.
	//Render2 = CreateComponent<GameEngineSpriteRenderer>();
	//Render2->SetTexture("Sky_DayxS.png");
	//Render2->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	//Render2->GetTransform()->SetLocalScale({ 5120.0f,1408.0f,0.0f });

	//Render3 = CreateComponent<GameEngineSpriteRenderer>();
	//Render3->SetTexture("BG2.png");
	//Render3->GetTransform()->SetLocalPosition({ 0.0f,-420.0f,0.0f });
	//Render3->GetTransform()->SetLocalScale({ 5120.0f,568,0.0f });

	//Render4 = CreateComponent<GameEngineSpriteRenderer>();
	//Render4->SetTexture("BG3.png");
	//Render4->GetTransform()->SetLocalPosition({ 0.0f,-516.0f,0.0f });
	//Render4->GetTransform()->SetLocalScale({ 5120.0f,380,0.0f });

	//Render0 = CreateComponent<GameEngineSpriteRenderer>();
	//Render0->SetTexture("townbg.png");
	//Render0->GetTransform()->SetLocalScale({ 5120.0f,1408.0f,0.0f });



	Render1 = CreateComponent<GameEngineSpriteRenderer>();
	Render1->SetTexture("CharIdle0.png");
	Render1->GetTransform()->SetLocalPosition({0.0f,0.0f,0.0f });
	Render1->GetTransform()->SetLocalScale({ 128.0f, 128.0f });



}

// 이건 디버깅용도나 
void Player::Render(float _Delta)
{
	// GetTransform()->AddLocalRotation({0.0f, 0.0f, 360.0f * _Delta});
};
