#include "PrecompileHeader.h"
#include "Player.h"
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "PixelCollision.h"
#include <GameEngineCore/GameEngineSprite.h>
// State
void Player::ChangeState(PlayerState _State)
{
	PlayerState NextState = _State;
	PlayerState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case PlayerState::IDLE:
		IdleStart();
		break;
	case PlayerState::MOVE:
		MoveStart();
		break;
	case PlayerState::JUMP:
		JumpStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case PlayerState::IDLE:
		IdleEnd();
		break;
	case PlayerState::MOVE:
		MoveEnd();
		break;
	case PlayerState::JUMP:
		JumpEnd();
		break;
	default:
		break;
	}

}

void Player::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case PlayerState::IDLE:
		IdleUpdate(_Time);
		break;
	case PlayerState::MOVE:
		MoveUpdate(_Time);
		break;
	case PlayerState::JUMP:
		JumpUpdate(_Time);
		break;
	default:
		break;
	}
}


void Player::IdleStart()
{
	if (true == GroundCheck())
	{
		PlayerRender->ChangeAnimation("Player_Idle");

	}
	else {
		PlayerRender->ChangeAnimation("Player_Jump");

	}

}
void Player::IdleUpdate(float _Time)
{

	if (GameEngineInput::IsPress("LeftMove") || GameEngineInput::IsPress("RightMove"))
	{
		ChangeState(PlayerState::MOVE);
	}

	if (GameEngineInput::IsDown("UpMove"))
	{
		ChangeState(PlayerState::JUMP);
	}
	if (false == GameEngineInput::IsDown("UpMove"))
	{
		MoveDir = float4::Zero;
	}



}
void Player::IdleEnd() {

}

void Player::MoveStart()
{
	PlayerRender->ChangeAnimation("Player_Move");
}
void Player::MoveUpdate(float _Time)
{
	if (
		false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove")
		)
	{
		if(true == GroundCheck())
		{
			ChangeState(PlayerState::IDLE);

		}

	}
	float4 MoveRange = float4::Zero;

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveRange += float4::Left;

			if (true == GameEngineInput::IsDown("UpMove"))
			{
				ChangeState(PlayerState::JUMP);
			}
	}

	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveRange += float4::Right;

		if (true == GameEngineInput::IsDown("UpMove"))
		{
			ChangeState(PlayerState::JUMP);
		}

	}

	MoveRange.Normalize();
	MoveDir.x = MoveRange.x;
}
void Player::MoveEnd()
{

}
bool JumpCheck = false;
void Player::JumpStart()
{
	PlayerRender->ChangeAnimation("Player_Jump");
	MoveDir += {0.0f, 3.1f, 0.f};
	Fall = true;
}
void Player::JumpUpdate(float _Time)
{
	float aa = GameEngineInput::GetPressTime("UpMove");

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir.x = -1.0f;
	}

	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir.x = 1.0f;
	}
	if (true == GroundCheck())
	{
		JumpCheck = false;
		Fall = false;
		MoveDir.y = 0.0f;
		ChangeState(PlayerState::IDLE);
	}
	else if (true == Fall && false == GroundCheck()) 
	{
		if (MoveDir.y != 0.0f) 
		{
			if (aa>0.3f && false == JumpCheck) {
				MoveDir += { 0.0f, 1.0f, 0.0f };
				JumpCheck = true;;
			}
			else  {
				MoveDir -= { 0.0f, 8.0f * _Time, 0.0f };
			}
		}
	}
	
}
void Player::JumpEnd() 
{
}