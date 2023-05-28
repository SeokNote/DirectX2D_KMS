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
	case PlayerState::FALL:
		FallStart();
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
	case PlayerState::FALL:
		FallEnd();
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
	case PlayerState::FALL:
		FallUpdate(_Time);
		break;
	default:
		break;
	}
}


void Player::IdleStart()
{
	if (true == GroundCheck()|| true ==MiddleCheck())
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

	if (GameEngineInput::IsPress("DownMove") && GameEngineInput::IsDown("UpMove_1"))
	{
		Fall = true;
		ChangeState(PlayerState::FALL);
	}
	else if (GameEngineInput::IsDown("UpMove") || GameEngineInput::IsDown("UpMove_1"))
	{
		ChangeState(PlayerState::JUMP);

	}
	if (false == GameEngineInput::IsDown("UpMove") && false == GameEngineInput::IsDown("UpMove_1"))
	{
		MoveDir = float4::Zero;
	}
	if (false == GroundCheck() && false == IsMiddle)
	{
			ChangeState(PlayerState::FALL);
	}
	if (true == GroundCheck() || IsMiddle == true) {
		Falling = false;
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
	if (true == IsMiddle)
	{
		Falling = true;
	}
	if (GroundCheck() == true)
	{
		Falling = false;
	}

	if(false == GroundCheck() && false == MiddleCheck())
	{
		ChangeState(PlayerState::FALL);
		Falling = false;
	}
	if (
		false == GameEngineInput::IsPress("LeftMove") &&
		false == GameEngineInput::IsPress("RightMove")
		)
	{
		if (GroundCheck() == true || true == IsMiddle) {
			ChangeState(PlayerState::IDLE);
			Falling = false;
		}
		
	}

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir.x = -1.0f;
		if (true == GameEngineInput::IsDown("UpMove") || true ==GameEngineInput::IsDown("UpMove_1"))
			{
				Falling = false;
				ChangeState(PlayerState::JUMP);
			}
	}

	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir.x = 1.0f;
		if (true == GameEngineInput::IsDown("UpMove") || true ==GameEngineInput::IsDown("UpMove_1"))
		{
			Falling = false;
			ChangeState(PlayerState::JUMP);
		}

	}
}
void Player::MoveEnd()
{
}
bool JumpCheck = false;
bool Check111 = false;
void Player::JumpStart()
{
	StartYpos = GetTransform()->GetLocalPosition().y;
	PlayerRender->ChangeAnimation("Player_Jump");
	MoveDir.y += 3.1f;
}
void Player::JumpUpdate(float _Time)
{
	EndYpos = GetTransform()->GetLocalPosition().y;
	float Pos = EndYpos - StartYpos;
	float PushTime = GameEngineInput::GetPressTime("UpMove");
	if (Pos >= 184.0f) 
	{
		Check111 = true;
	}
	if (Check111 == true)
	{
		if (Pos <= 184.0f)
		{
			Falling = true;
		}
	}

	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		MoveDir.x = -1.0f;
	}
	
	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		MoveDir.x = 1.0f;
	}
	//�������� �����϶�
	if(Falling ==true)
	{
		if (true == GroundCheck() || true == MiddleCheck())
		{
			JumpCheck = false;
			MoveDir.y = 0.0f;
			Check111 = false;
			IsMiddle = true; 
			ChangeState(PlayerState::IDLE);
			Falling = false;
		}
	}
	if (false == MiddleCheck() && false == GroundCheck())
	{
		if (MoveDir.y != 0.0f) 
		{
			if (PushTime >0.3f && false == JumpCheck) {
				MoveDir.y += 0.7f;
				JumpCheck = true;
				PushTime = 0.0f;
			}
			else  {
				MoveDir.y -= 7.5f * _Time;
			}
		}
	}
	
}
void Player::JumpEnd() 
{
}

void Player::FallStart()
{
	PlayerRender->ChangeAnimation("Player_Jump");

}
void Player::FallUpdate(float _Time)
{
	CheckTime += _Time;
	if (Fall == false) 
	{
		Falling = true;
		if (true == GameEngineInput::IsPress("LeftMove"))
		{
			MoveDir.x = -1.0f;
		}

		else if (true == GameEngineInput::IsPress("RightMove"))
		{
			MoveDir.x = 1.0f;
		}
		if (false == MiddleCheck())
		{
			MoveDir.y -= 7.5f * _Time;;
		}
		else
		{
			ChangeState(PlayerState::IDLE);

		}
		if (true == GroundCheck())
		{
			MoveDir.y = 0.0f;
			ChangeState(PlayerState::IDLE);
		}
		if (true == MiddleCheck())
		{ 
			MoveDir.y = 0.0f;
			ChangeState(PlayerState::IDLE);
			Falling = false;
		}
		if (
			true == GameEngineInput::IsPress("LeftMove") &&
			true == GameEngineInput::IsPress("RightMove")
			)
		{
			ChangeState(PlayerState::MOVE);
			return;
		}
	}
	else 
	{
		if (CheckTime > 0.3f) {
			Falling = true;
		}
		MoveDir.y -= 7.5f * _Time;;
		if (true == GroundCheck())
		{
			MoveDir.y = 0.0f;
			ChangeState(PlayerState::IDLE);
			IsMiddle = false;

			Fall = false;
		}	
		// �������� ������ �� �����°� 
		// �̶��� �̵�üũ�� �ϸ� �ȵƴ�.
		if (true == MiddleCheck())
		{
			CheckTime = 0.0f;
			ChangeState(PlayerState::IDLE);
			Falling = false;
			MoveDir.y = 0.0f;
			IsMiddle = true;
			Fall = false;
		}
	}

}
void Player::FallEnd()
{
}