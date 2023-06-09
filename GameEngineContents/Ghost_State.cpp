#include "PrecompileHeader.h"
#include "Ghost.h"
#include "Player.h"

#include <GameEngineCore/GameEngineTexture.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineSprite.h>
void Ghost::ChangeState(GhostState _State)
{
	GhostState NextState = _State;
	GhostState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case GhostState::IDLE:
		IdleStart();
		break;
	case GhostState::MOVE:
		MoveStart();
		break;
	case GhostState::DEAD:
		DeadStart();
		break;
	case GhostState::ATTACK:
		AttackStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case GhostState::IDLE:
		IdleEnd();
		break;
	case GhostState::MOVE:
		MoveEnd();
		break;
	case GhostState::DEAD:
		DeadEnd();
		break;
	case GhostState::ATTACK:
		AttackEnd();
		break;
	default:
		break;
	}

}

void Ghost::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case GhostState::IDLE:
		IdleUpdate(_Time);
		break;
	case GhostState::MOVE:
		MoveUpdate(_Time);
		break;
	case GhostState::DEAD:
		DeadUpdate(_Time);
		break;
	case GhostState::ATTACK:
		AttackUpdate(_Time);
		break;
	default:
		break;
	}
}

void Ghost::IdleStart()
{
	GhostRender->ChangeAnimation("GhostIdle");

}

void Ghost::IdleUpdate(float _Time)
{
	if (StartMove == true)
	{
		ChangeState(GhostState::MOVE);
	}
}

void Ghost::IdleEnd()
{
}

void Ghost::MoveStart()
{
	GhostRender->ChangeAnimation("GhostIdle");
}

void Ghost::MoveUpdate(float _Time)
{
	if (Hp < 0)
	{
		ChangeState(GhostState::DEAD);
	}
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	MyPos = GetTransform()->GetLocalPosition();
	float4 Dir = (PlayerPos - MyPos).NormalizeReturn();
	if (AttackMove == false)
	{
		GetTransform()->AddLocalPosition({ _Time *100.0f* Dir.x,_Time * 100.0f * Dir.y ,0.0f });
	}
	else
	{
		ChangeState(GhostState::ATTACK);
	}
}

void Ghost::MoveEnd()
{
}

void Ghost::AttackStart()
{
	GhostRender->ChangeAnimation("GhostAttack");

}

void Ghost::AttackUpdate(float _Time)
{
	if (Hp < 0)
	{
		ChangeState(GhostState::DEAD);
	}
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	MyPos = GetTransform()->GetLocalPosition();
	float4 Dir = (PlayerPos - MyPos).NormalizeReturn();
	GetTransform()->AddLocalPosition({ _Time * 200.0f * Dir.x,_Time * 200.0f * Dir.y ,0.0f });
}

void Ghost::AttackEnd()
{
}

void Ghost::DeadStart()
{
	GhostRender->Off();
	DeadRender->ChangeAnimation("GhostDead");
	HpRender->Death();
	HpBaseRender->Death();
	BodyCol->Off();
}

void Ghost::DeadUpdate(float _Time)
{
	if (DeadRender->IsAnimationEnd())
	{
		Death();
	}
}

void Ghost::DeadEnd()
{
}
