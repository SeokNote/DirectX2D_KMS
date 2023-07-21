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
	SmallBatRender->ChangeAnimation("SmallBat");

}

void SmallBat::IdleUpdate(float _Time)
{
	if (StartMove == true)
	{
		ChangeState(SmallBatState::MOVE);
	}
}

void SmallBat::IdleEnd()
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
