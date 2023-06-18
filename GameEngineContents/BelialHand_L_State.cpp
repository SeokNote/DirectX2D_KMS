#include "PrecompileHeader.h"
#include "BelialHand_L.h"
#include "BelialBullet.h"
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
void BelialHand_L::ChangeState(LeftHandState _State)
{
	LeftHandState NextState = _State;
	LeftHandState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case LeftHandState::IDLE:
		IdleStart();
		break;
	case LeftHandState::MOVE:
		MoveStart();
		break;
	case LeftHandState::LASOR:
		LasorStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case LeftHandState::IDLE:
		IdleEnd();
		break;
	case LeftHandState::MOVE:
		MoveEnd();
		break;
	case LeftHandState::LASOR:
		LasorEnd();
		break;
	default:
		break;
	}
}

void BelialHand_L::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case LeftHandState::IDLE:
		IdleUpdate(_Time);
		break;
	case LeftHandState::MOVE:
		MoveUpdate(_Time);
		break;
	case LeftHandState::LASOR:
		LasorUpdate(_Time);
		break;
	default:
		break;
	}
}


void BelialHand_L::IdleStart()
{
	LeftHandRender->ChangeAnimation("LeftHandIdle");
}
void BelialHand_L::IdleUpdate(float _Time)
{
	
	//일단 확인용으로 조건은 5초로 해놓는다.
	M_StartTime += _Time;
	if (M_StartTime > 5.0f)
	{
		ChangeState(LeftHandState::MOVE);
		M_StartTime = 0.0f;
	}
}
void BelialHand_L::IdleEnd()
{
}

void BelialHand_L::MoveStart()
{
	//처음 들어오면 플레이어의 y값을 얻는다
	PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	HandPos = LeftHandRender->GetTransform()->GetLocalPosition();
	YPos = PlayerPos.y;
}
void BelialHand_L::MoveUpdate(float _Time)
{
	CurPos = LeftHandRender->GetTransform()->GetLocalPosition();
	if (PlayerPos.y - HandPos.y > 0.0f)
	{
		LeftHandRender->GetTransform()->AddLocalPosition({0.0f,2.0f,0.0f});
		if (CurPos.y > YPos)
		{
			ChangeState(LeftHandState::LASOR);
		}
	}
	else
	{
		LeftHandRender->GetTransform()->AddLocalPosition({ 0.0f,-2.0f,0.0f });
		if (CurPos.y < YPos)
		{
			ChangeState(LeftHandState::LASOR);
		}
	}
}
void BelialHand_L::MoveEnd()
{
}
void BelialHand_L::LasorStart()
{
	LeftHandRender->ChangeAnimation("LeftHandLasor");
}
void BelialHand_L::LasorUpdate(float _Time)
{
	if (true == LeftHandRender->IsAnimationEnd())
	{
		ChangeState(LeftHandState::IDLE);
	}
}
void BelialHand_L::LasorEnd()
{
}
