#include "PrecompileHeader.h"
#include "SmallBat.h"
#include "Player.h"
#include "GoldCoin.h"
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
void SmallBat::ChangeState(SmallBatState _State)
{
	SmallBatState NextState = _State;
	SmallBatState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case SmallBatState::IDLE:
		IdleStart();
		break;
	case SmallBatState::IDLE2:
		Idle2Start();
		break;
	case SmallBatState::MOVE:
		MoveStart();
		break;
	case SmallBatState::DEAD:
		DeadStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case SmallBatState::IDLE:
		IdleEnd();
		break;
	case SmallBatState::IDLE2:
		Idle2End();
		break;
	case SmallBatState::MOVE:
		MoveEnd();
		break;
	case SmallBatState::DEAD:
		DeadEnd();
		break;
	default:
		break;
	}

}

void SmallBat::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case SmallBatState::IDLE:
		IdleUpdate(_Time);
		break;
	case SmallBatState::IDLE2:
		Idle2Update(_Time);
		break;
	case SmallBatState::MOVE:
		MoveUpdate(_Time);
		break;
	case SmallBatState::DEAD:
		DeadUpdate(_Time);
		break;
	default:
		break;
	}
}

void SmallBat::IdleStart()
{
	if (SpownValue == false)
	{
		SmallBatRender->Off();
		SpownRender->ChangeAnimation("SpownAni");
	}
	else
	{
		SmallBatRender->ChangeAnimation("SmallBat");

	}

}

void SmallBat::IdleUpdate(float _Time)
{
	if (SpownValue == false && SpownRender->IsAnimationEnd())
	{
		SpownValue = true;
		SmallBatRender->On();
		SmallBatRender->ChangeAnimation("SmallBat");
		SpownRender->Off();
		ChangeState(SmallBatState::IDLE2);

	}

}

void SmallBat::IdleEnd()
{
}

void SmallBat::Idle2Start()
{
	SmallBatRender->ChangeAnimation("SmallBat");

}

void SmallBat::Idle2Update(float _Time)
{
	if (SpownValue = true && StartMove == true)
	{
		ChangeState(SmallBatState::MOVE);
	}
}

void SmallBat::Idle2End()
{
}

void SmallBat::MoveStart()
{
	SmallBatRender->ChangeAnimation("SmallBat");
}

void SmallBat::MoveUpdate(float _Time)
{
	if (Hp < 0)
	{
		ChangeState(SmallBatState::DEAD);
	}
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	MyPos = GetTransform()->GetLocalPosition();
	float4 Dir = (PlayerPos - MyPos).NormalizeReturn();
	if (StartMove != false)
	{
		GetTransform()->AddLocalPosition({ _Time * 120.0f * Dir.x,_Time * 120.0f * Dir.y ,0.0f });
	}
}

void SmallBat::MoveEnd()
{
}
void SmallBat::DeadStart()
{
	SmallBatRender->Off();
	DeadRender->ChangeAnimation("SmallBatDead");
	HpRender->Death();
	HpBaseRender->Death();
	BodyCol->Off();
}

void SmallBat::DeadUpdate(float _Time)
{
	if (DeadRender->IsAnimationEnd())
	{
		GoldCoin::CoinCreat(GetLevel(), GetTransform()->GetLocalPosition(), true);

		Death();
	}
}

void SmallBat::DeadEnd()
{
}
