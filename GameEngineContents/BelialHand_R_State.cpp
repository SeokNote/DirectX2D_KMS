#include "PrecompileHeader.h"
#include "BelialHand_R.h"
#include "BelialHand_L.h"
#include "BelialBullet.h"
#include "BelialHead.h"
#include "Player.h"
#include "BelialLasor_R.h"
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
void BelialHand_R::ChangeState(RightHandState _State)
{
	RightHandState NextState = _State;
	RightHandState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case RightHandState::IDLE:
		IdleStart();
		break;
	case RightHandState::MOVE:
		MoveStart();
		break;
	case RightHandState::LASOR:
		LasorStart();
		break;
	case RightHandState::DEAD:
		DeathStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case RightHandState::IDLE:
		IdleEnd();
		break;
	case RightHandState::MOVE:
		MoveEnd();
		break;
	case RightHandState::LASOR:
		LasorEnd();
		break;
	case RightHandState::DEAD:
		DeathEnd();
		break;
	default:
		break;
	}
}

void BelialHand_R::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case RightHandState::IDLE:
		IdleUpdate(_Time);
		break;
	case RightHandState::MOVE:
		MoveUpdate(_Time);
		break;
	case RightHandState::LASOR:
		LasorUpdate(_Time);
		break;
	case RightHandState::DEAD:
		DeathUpdate(_Time);
		break;
	default:
		break;
	}
}


void BelialHand_R::IdleStart()
{
	RightHandRender->ChangeAnimation("LeftHandIdle");
}
void BelialHand_R::IdleUpdate(float _Time)
{
	if (RightHandRender->ColorOptionValue.MulColor.a < 1.0f)
	{
		RightHandRender->ColorOptionValue.MulColor.a += _Time * 0.5f;
	}
	if (true == BelialHead::MainBelialHead->GetHandStop())
	{
		ChangeState(RightHandState::DEAD);
	}

	//왼쪽 패턴이 끝나면 실행.
	if (true == BelialHand_L::MainBelialHand_L->GetPattonCheck())
	{
		ChangeState(RightHandState::MOVE);
	}
}
void BelialHand_R::IdleEnd()
{
}

void BelialHand_R::MoveStart()
{
	//처음 들어오면 플레이어의 y값을 얻는다
	PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	HandPos = RightHandRender->GetTransform()->GetLocalPosition();
	YPos = PlayerPos.y;
}
void BelialHand_R::MoveUpdate(float _Time)
{
	if (true == BelialHead::MainBelialHead->GetHandStop())
	{
		ChangeState(RightHandState::DEAD);
	}
	CurPos = RightHandRender->GetTransform()->GetLocalPosition();
	if (PlayerPos.y - HandPos.y > 0.0f)
	{
		RightHandRender->GetTransform()->AddLocalPosition({ 0.0f,HandSpeed* _Time,0.0f });
		if (CurPos.y > YPos)
		{
			ChangeState(RightHandState::LASOR);
		}
	}
	else
	{
		RightHandRender->GetTransform()->AddLocalPosition({ 0.0f,-HandSpeed* _Time,0.0f });
		if (CurPos.y < YPos)
		{
			ChangeState(RightHandState::LASOR);
		}
	}
}
void BelialHand_R::MoveEnd()
{
}
void BelialHand_R::LasorStart()
{
	RightHandRender->ChangeAnimation("LeftHandLasor");
	FirstLasor = false;

}
void BelialHand_R::LasorUpdate(float _Time)
{
	size_t Frame = RightHandRender->GetCurrentFrame();
	if (FirstLasor == false && Frame == 8)
	{
		GameEngineSound::Play("jumperLaserFire.wav");
		LasorPtr_1 = GetLevel()->CreateActor<BelialLasor_R>();
		LasorPtr_1->GetTransform()->SetLocalPosition({ CurPos.x - 630.0f,CurPos.y - 20.0f,-850.0f });
		FirstLasor = true;
	}
	if (true == RightHandRender->IsAnimationEnd())
	{
		ChangeState(RightHandState::IDLE);
		LasorPtr_1->Death();
	}
}
void BelialHand_R::LasorEnd()
{
}

void BelialHand_R::DeathStart()
{
	RightHandRender->ChangeAnimation("LeftHandIdle");
	
}

void BelialHand_R::DeathUpdate(float _Time)
{
	if (RightHandRender->GetCurrentFrame() == 3)
	{
		RightHandRender->SetAnimPauseOn();
	}
}

void BelialHand_R::DeathEnd()
{
}
