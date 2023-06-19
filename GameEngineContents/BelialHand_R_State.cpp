#include "PrecompileHeader.h"
#include "BelialHand_R.h"
#include "BelialHand_L.h"
#include "BelialBullet.h"
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

	//���� ������ ������ ����.
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
	//ó�� ������ �÷��̾��� y���� ��´�
	PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	HandPos = RightHandRender->GetTransform()->GetLocalPosition();
	YPos = PlayerPos.y;
}
void BelialHand_R::MoveUpdate(float _Time)
{
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


}
void BelialHand_R::LasorUpdate(float _Time)
{
	size_t Frame = RightHandRender->GetCurrentFrame();
	if (Frame == 8)
	{
		LasorPtr_1 = GetLevel()->CreateActor<BelialLasor_R>();
		LasorPtr_1->GetTransform()->SetLocalPosition({ CurPos.x - 630.0f,CurPos.y - 20.0f,CurPos.z });
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
