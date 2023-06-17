#include "PrecompileHeader.h"
#include "BelialHead.h"
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
void BelialHead::ChangeState(BossHeadState _State)
{
	BossHeadState NextState = _State;
	BossHeadState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case BossHeadState::IDLE:
		IdleStart();
		break;
	case BossHeadState::MOVE:
		MoveStart();
		break;
	case BossHeadState::DEAD:
		DeadStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case BossHeadState::IDLE:
		IdleEnd();
		break;
	case BossHeadState::MOVE:
		MoveEnd();
		break;
	case BossHeadState::DEAD:
		DeadEnd();
		break;
	default:
		break;
	}

}

void BelialHead::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case BossHeadState::IDLE:
		IdleUpdate(_Time);
		break;
	case BossHeadState::MOVE:
		MoveUpdate(_Time);
		break;
	case BossHeadState::DEAD:
		DeadUpdate(_Time);
		break;
	default:
		break;
	}
}


void BelialHead::IdleStart()
{
	BelialHeadRender->ChangeAnimation("HeadIdle");
}
void BelialHead::IdleUpdate(float _Time)
{
	TimeCheck_0 += _Time;
	if (TimeCheck_0 > 5.0f)
	{
		TimeCheck_0 = 0.0f;
		ChangeState(BossHeadState::MOVE);
	}

}
void BelialHead::IdleEnd()
{
}

void BelialHead::MoveStart()
{

	BelialHeadRender->ChangeAnimation("HeadMove");
}
void BelialHead::MoveUpdate(float _Time)
{
	TimeCheck_1 += _Time;
	if (TimeCheck_1 > 5.0f)
	{
		ChangeState(BossHeadState::IDLE);
		TimeCheck_1 = 0.0f;
	}
}
void BelialHead::MoveEnd()
{
}
void BelialHead::DeadStart()
{

}
void BelialHead::DeadUpdate(float _Time)
{

}
void BelialHead::DeadEnd()
{
}
