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
#include "DashEffect.h"
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
	case PlayerState::DASH:
		DashStart();
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
	case PlayerState::DASH:
		DashEnd();
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
	case PlayerState::DASH:
		DashUpdate(_Time);
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
	if (UICount == 0) 
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
	if (UICount == 0 && GameEngineInput::IsDown("DASH")) {
		ChangeState(PlayerState::DASH);
	}
	if (LeftSideCheck() == true)
	{
		MoveDir = float4::Zero;

	}

	
}
void Player::IdleEnd() {

}

void Player::MoveStart()
{
	MoveStartPoS = GetTransform()->GetLocalPosition();
	PlayerRender->ChangeAnimation("Player_Move");
	PlayerWalkEffectRender->ChangeAnimation("Player_WalkEffect");
}
void Player::MoveUpdate(float _Time)
{
	EffectTime += _Time;
	if (EffectTime > 0.3f)
	{
		MoveStartPoS = GetTransform()->GetLocalPosition();
		PlayerWalkEffectRender->ChangeAnimation("Player_WalkEffect");
		EffectTime = 0.0f;
	}
	if (UICount != 0)
	{
		MoveDir.x = 0.0f;
		ChangeState(PlayerState::IDLE);
	}
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
		if(true == LeftSideCheck())
		{
			MoveDir.x = 0.0f;
		}
		else
		{
			MoveDir.x = -1.0f;

		}
		if (true == GameEngineInput::IsDown("UpMove") || true ==GameEngineInput::IsDown("UpMove_1"))
			{
				Falling = false;
				ChangeState(PlayerState::JUMP);
			}
	}

	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		if (true == RightSideCheck())
		{
			MoveDir.x = 0.0f;
		}
		else
		{
			MoveDir.x = 1.0f;

		}		if (true == GameEngineInput::IsDown("UpMove") || true ==GameEngineInput::IsDown("UpMove_1"))
		{
			Falling = false;
			ChangeState(PlayerState::JUMP);
		}

	}
	if (UICount == 0 && GameEngineInput::IsDown("DASH")) {
		ChangeState(PlayerState::DASH);
	}

}
void Player::MoveEnd()
{
}
bool JumpCheck = false;
bool Check111 = false;
void Player::JumpStart()
{
	StartXpos = GetTransform()->GetLocalPosition().x;
	StartYpos = GetTransform()->GetLocalPosition().y;
	PlayerRender->ChangeAnimation("Player_Jump");
	MoveDir.y += 3.0f;
	PlayerJumpEffectRender->ChangeAnimation("Player_JumpEffect");
}
void Player::JumpUpdate(float _Time)
{
	UpDashTime += _Time;
	EndYpos = GetTransform()->GetLocalPosition().y;
	float Pos = EndYpos - StartYpos;
	float PushTime = GameEngineInput::GetPressTime("UpMove");
	if (Pos >= 198.0f) 
	{
		Check111 = true;
	}
	if (Check111 == true)
	{
		if (Pos <= 198.0f)
		{
			Falling = true;
		}
	}
	if(true == TopCheck())
	{
		MoveDir.y = 0.0f;
		ChangeState(PlayerState::FALL);
	}
	if (true == GameEngineInput::IsPress("LeftMove"))
	{
		//ChangeState(PlayerState::MOVE);
		if (true == LeftSideCheck())
		{
			MoveDir.x = 0.0f;
		}
		else
		{
			MoveDir.x = -1.0f;

		}
	}
	
	else if (true == GameEngineInput::IsPress("RightMove"))
	{
		//ChangeState(PlayerState::MOVE);

		if (true == RightSideCheck())
		{
			MoveDir.x = 0.0f;
		}
		else
		{
			MoveDir.x = 1.0f;

		}
	}
	//떨어지는 상태일때
	if(Falling ==true)
	{
		if (true == GroundCheck() || true == MiddleCheck())
		{
			if (CurMap == MyMap::Stage2_Boss)
			{
				float4 MyPos = GetTransform()->GetLocalPosition();

				GetTransform()->SetLocalPosition({ MyPos.x,-194.0f,MyPos.z });
			}
			JumpCheck = false;
			MoveDir.y = 0.0f;
			Check111 = false;
			IsMiddle = true; 
			ChangeState(PlayerState::IDLE);
			Falling = false;
		}
		if (true == MiddleCheck())
		{
			BeltCheck = true;
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
		BeltCheck = false;
	}
	if (UpDashTime > 0.2f)
	{
		if (UICount == 0 && GameEngineInput::IsDown("DASH")) {
			ChangeState(PlayerState::DASH);
			UpDashTime = 0.0f;
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
	if (UICount != 0)
	{
		MoveDir.x = 0.0f;
		ChangeState(PlayerState::IDLE);
	}
	CheckTime += _Time;
	if (Fall == false) 
	{
		Falling = true;
		if (true == GameEngineInput::IsPress("LeftMove"))
		{
			if (true == LeftSideCheck())
			{
				MoveDir.x = 0.0f;
			}
			else
			{
				MoveDir.x = -1.0f;

			}
		}

		else if (true == GameEngineInput::IsPress("RightMove"))
		{
			if (true == RightSideCheck())
			{
				MoveDir.x = 0.0f;
			}
			else
			{
				MoveDir.x = 1.0f;

			}
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
			BeltCheck = false;
			MoveDir.y = 0.0f;
			ChangeState(PlayerState::IDLE);
		}
		if (true == MiddleCheck())
		{ 
			BeltCheck = true;
			MoveDir.y = 0.0f;
			IsMiddle = true;
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
		// 밑점프를 눌렀을 때 들어오는곳 
		// 이때는 미들체크를 하면 안됐다.
		if (true == MiddleCheck())
		{
			BeltCheck = true;
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

void Player::DashStart()
{
	//대쉬키가 눌렸을때 그 때의 위치 값을 받는다,
	DashCurPos = GetTransform()->GetLocalPosition();
	PlayerRender->ChangeAnimation("Player_Jump");
	PrevDashPos = DashVector;
}

void Player::DashUpdate(float _Time)
{
	float4 PlayerPos = GetTransform()->GetLocalPosition();
	DashTime += _Time;
	DashEffectTime += _Time;
	GetTransform()->AddLocalPosition({ PrevDashPos.x* DashSpeed* _Time,PrevDashPos.y* DashSpeed * _Time ,0.0f});
	float YValue = (DashCurPos.y - PlayerPos.y);
	if (DashEffectTime > 0.05f)
	{
		Effect_Check = true;
		DashEffectTime = 0.0f;
	}
	if (Effect_Check == true)
	{
		DashEffectPtr = GetLevel()->CreateActor<DashEffect>();
		DashEffectPtr->GetTransform()->SetWorldPosition(PlayerPos);
		Effect_Check = false;
	}
	if (YValue > 0.0f)
	{
		GetTransform()->AddLocalPosition({ 0.0f,-PrevDashPos.y * DashSpeed * _Time ,0.0f});

	}
	if(DashTime>0.2)
	{

		ChangeState(PlayerState::FALL);
		DashTime = 0.0f;
	}
	if (LeftSideCheck() == true)
	{
		ChangeState(PlayerState::FALL);

	}
	if (RightSideCheck() == true)
	{
		ChangeState(PlayerState::FALL);

	}
	if (TopCheck() == true)
	{
		GetTransform()->AddLocalPosition({ 0.0f,-PrevDashPos.y * DashSpeed * _Time,0.0f });

	}

}



void Player::DashEnd()
{

}
