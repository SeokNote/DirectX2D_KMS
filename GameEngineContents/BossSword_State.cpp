#include "PrecompileHeader.h"
#include "BossSword.h"
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
void BossSword::ChangeState(BossSwordState _State)
{
	BossSwordState NextState = _State;
	BossSwordState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case BossSwordState::IDLE:
		IdleStart();
		break;
	case BossSwordState::MOVE:
		MoveStart();
		break;
	case BossSwordState::DEAD:
		DeadStart();
		break;
	case BossSwordState::BOMB:
		BombStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case BossSwordState::IDLE:
		IdleEnd();
		break;
	case BossSwordState::MOVE:
		MoveEnd();
		break;
	case BossSwordState::DEAD:
		DeadEnd();
		break;
	case BossSwordState::BOMB:
		BombEnd();
		break;
	default:
		break;
	}

}

void BossSword::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case BossSwordState::IDLE:
		IdleUpdate(_Time);
		break;
	case BossSwordState::MOVE:
		MoveUpdate(_Time);
		break;
	case BossSwordState::DEAD:
		DeadUpdate(_Time);
		break;
	case BossSwordState::BOMB:
		BombUpdate(_Time);
		break;
	default:
		break;
	}
}


void BossSword::IdleStart()
{
	SwordDeadRender->ChangeAnimation("BossSwordDead");
	SwordEffectRender->ChangeAnimation("BossSwordCharge");
}
bool CheckSword_0 = false;
void BossSword::IdleUpdate(float _Time)
{
	TimeCheck_2 += _Time;
	SwordPos = SwordRender->GetTransform()->GetWorldPosition();
	PlayerPos = Player::MainPlayer->GetTransform()->GetWorldPosition();
	ZDeg = atan2(PlayerPos.y - SwordPos.y, PlayerPos.x - SwordPos.x) * GameEngineMath::RadToDeg;

	if (TimeCheck_2>0.5f)
	{
		SwordRender->ChangeAnimation("BossSwordIdle");
		SwordRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg-270 });
		SwordEffectRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg-270 });

	}
	SwordEffectRender->GetTransform()->SetWorldPosition(SwordPos);

	TimeCheck_0 += _Time;

	if (TimeCheck_0 > 2.0f)
	{
		ChangeState(BossSwordState::MOVE);
	}

}
void BossSword::IdleEnd() 
{
}

void BossSword::MoveStart()
{

	SwordEffectRender->Off();
	SwordFxRender->On();
	CurDir = (PlayerPos - SwordPos).NormalizeReturn();
}
void BossSword::MoveUpdate(float _Time)
{
	SwordFxRender->GetTransform()->SetLocalRotation({0.0f,0.0f, ZDeg - 90 });
	SwordRender->GetTransform()->AddLocalPosition({CurDir.x * SwordSpeed* _Time, CurDir.y * SwordSpeed*_Time,0.0f });
	SwordFxRender->GetTransform()->AddLocalPosition({ CurDir.x * SwordSpeed* _Time, CurDir.y * SwordSpeed* _Time,0.0f });
	if (PixelCheck() == true)
	{
		ColCurPos = SwordRender->GetTransform()->GetWorldPosition();
		ChangeState(BossSwordState::DEAD);
	}
}
void BossSword::MoveEnd()
{
}
void BossSword::DeadStart()
{
	ColCurPos.y += 45.0f;
	SwordFxRender->Off();
	SwordColRender->ChangeAnimation("BossSwordFx");
	SwordColRender->GetTransform()->SetWorldPosition(ColCurPos);
	ColCurPos.y -= 20.0f;
	SwordDeadRender->GetTransform()->SetWorldPosition(ColCurPos);
} 
void BossSword::DeadUpdate(float _Time)
{
	TimeCheck_1 += _Time;
	if (TimeCheck_1 > 1.0f)
	{
		ChangeState(BossSwordState::BOMB);
		TimeCheck_1 = 0.0f;

	}
}
void BossSword::DeadEnd()
{
}

void BossSword::BombStart()
{
	SwordRender->Off();
	SwordDeadRender->ChangeAnimation("BossSwordDead");
}

void BossSword::BombUpdate(float _Time)
{
	TimeCheck_3 += _Time;
	if (TimeCheck_3 > 1.0f)
	{
		Death();
		TimeCheck_3 = 0.0f;
	}
}

void BossSword::BombEnd()
{
}

