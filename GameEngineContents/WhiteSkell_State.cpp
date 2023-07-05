#include "PrecompileHeader.h"
#include "WhiteSkell.h"
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
void WhiteSkell::ChangeState(WhiteSkellState _State)
{
	WhiteSkellState NextState = _State;
	WhiteSkellState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case WhiteSkellState::IDLE:
		IdleStart();
		break;
	case WhiteSkellState::MOVE:
		MoveStart();
		break;
	case WhiteSkellState::DEAD:
		DeadStart();
		break;
	case WhiteSkellState::ATTACK:
		AttackStart();
		break;
	case WhiteSkellState::FALL:
		FallStart();
		break;
	case WhiteSkellState::CHASE:
		ChaseStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case WhiteSkellState::IDLE:
		IdleEnd();
		break;
	case WhiteSkellState::MOVE:
		MoveEnd();
		break;
	case WhiteSkellState::DEAD:
		DeadEnd();
		break;
	case WhiteSkellState::ATTACK:
		AttackEnd();
		break;
	case WhiteSkellState::FALL:
		FallEnd();
		break;
	case WhiteSkellState::CHASE:
		ChaseEnd();
		break;
	default:
		break;
	}

}

void WhiteSkell::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case WhiteSkellState::IDLE:
		IdleUpdate(_Time);
		break;
	case WhiteSkellState::MOVE:
		MoveUpdate(_Time);
		break;
	case WhiteSkellState::DEAD:
		DeadUpdate(_Time);
		break;
	case WhiteSkellState::ATTACK:
		AttackUpdate(_Time);
		break;
	case WhiteSkellState::FALL:
		FallUpdate(_Time);
		break;
	case WhiteSkellState::CHASE:
		ChaseUpdate(_Time);
		break;
	default:
		break;
	}
}
bool IsFirstRender = false;
void WhiteSkell::IdleStart()
{
	WhiteSkellRender->ChangeAnimation("WhiteSkellIdle");
}

void WhiteSkell::IdleUpdate(float _Time)
{
	MoveTerm += _Time;
	if (GroundCheck() == false)
	{
		ChangeState(WhiteSkellState::FALL);
	}
	if (MoveTerm > 2.0f)
	{
		ChangeState(WhiteSkellState::MOVE);
		MoveTerm = 0.0f;
	}
	if (InArea == true)
	{

		AttackTerm += _Time;
		if (AttackTerm > 0.5f)
		{
			ChangeState(WhiteSkellState::ATTACK);
			AttackTerm = 0.0f;
		}
	}
}

void WhiteSkell::IdleEnd()
{
}

void WhiteSkell::MoveStart()
{
	FlipCount++;
	WhiteSkellRender->ChangeAnimation("WhiteSkellMove");
	PrevPos = GetTransform()->GetLocalPosition();
}

void WhiteSkell::MoveUpdate(float _Time)
{
	if (InArea == true)
	{
		ChangeState(WhiteSkellState::ATTACK);
	}
	CurPos = GetTransform()->GetLocalPosition();
	if (FlipCount % 2 != 0)
	{
		WhiteSkellRender->GetTransform()->SetLocalPositiveScaleX();
		WhiteSkellRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
		TargetAreaCol->GetTransform()->SetLocalPosition({ 230.0f,-40.0f,0.f });
		SkellBodyCol->GetTransform()->SetLocalPosition({ -70.0f,-40.0f,0.f });
		AttackAreaCol->GetTransform()->SetLocalPosition({ 40.0f,-40.0f,0.f });

		if (abs(CurPos.x - PrevPos.x) < 200.0f)
		{
			GetTransform()->AddLocalPosition({ MoveSpeed * _Time,0.0f,0.0f });
		}
		else 
		{
			ChangeState(WhiteSkellState::IDLE);
		}
	}
	else
	{
		WhiteSkellRender->GetTransform()->SetLocalNegativeScaleX();
		WhiteSkellRender->GetTransform()->SetLocalPosition({ -50.0f,0.0f,0.f });
		TargetAreaCol->GetTransform()->SetLocalPosition({ -230.0f,-40.0f,0.f });
		SkellBodyCol->GetTransform()->SetLocalPosition({ 0.0f,-40.0f,0.f });
		AttackAreaCol->GetTransform()->SetLocalPosition({ -80.0f,-40.0f,0.f });

		if (abs(CurPos.x - PrevPos.x) < 200.0f)
		{
			GetTransform()->AddLocalPosition({ -MoveSpeed * _Time,0.0f,0.0f });
		}
		else
		{
			ChangeState(WhiteSkellState::IDLE);
		}
	}
}

void WhiteSkell::MoveEnd()
{
}

void WhiteSkell::ChaseStart()
{
	WhiteSkellRender->ChangeAnimation("WhiteSkellAttack");
	AreaInRender->Off();

}

void WhiteSkell::ChaseUpdate(float _Time)
{
	if (WhiteSkellRender->GetCurrentFrame() > 1)
	{
		AttackAreaCol->On();
	}
	if (WhiteSkellRender->GetCurrentFrame() > 7)
	{
		AttackAreaCol->Off();
	}
	if (true == WhiteSkellRender->IsAnimationEnd())
	{
		ChangeState(WhiteSkellState::IDLE);

	}
}

void WhiteSkell::ChaseEnd()
{
}

void WhiteSkell::FallStart()
{
	WhiteSkellRender->ChangeAnimation("WhiteSkellIdle");


}

void WhiteSkell::FallUpdate(float _Time)
{
	if (GroundCheck() == false)
	{
		GetTransform()->AddLocalPosition({ 0.0f,-_Time * MoveSpeed,0.0f });
	}
	else
	{
		ChangeState(WhiteSkellState::IDLE);
	}
}

void WhiteSkell::FallEnd()
{
}
void WhiteSkell::AttackStart()
{
	PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	WhiteSkellRender->ChangeAnimation("WhiteSkellMove");

}

void WhiteSkell::AttackUpdate(float _Time)
{
	CurPos = GetTransform()->GetLocalPosition();
	PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();

	if (IsFlip == false)
	{
		WhiteSkellRender->GetTransform()->SetLocalPositiveScaleX();
		WhiteSkellRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
		TargetAreaCol->GetTransform()->SetLocalPosition({ 230.0f,-40.0f,0.f });
		SkellBodyCol->GetTransform()->SetLocalPosition({ -70.0f,-40.0f,0.f });
		AttackAreaCol->GetTransform()->SetLocalPosition({ 40.0f,-40.0f,0.f });

	}
	else
	{
		WhiteSkellRender->GetTransform()->SetLocalNegativeScaleX();
		WhiteSkellRender->GetTransform()->SetLocalPosition({ -50.0f,0.0f,0.f });
		TargetAreaCol->GetTransform()->SetLocalPosition({ -230.0f,-40.0f,0.f });
		SkellBodyCol->GetTransform()->SetLocalPosition({ 0.0f,-40.0f,0.f });
		AttackAreaCol->GetTransform()->SetLocalPosition({ -80.0f,-40.0f,0.f });

	}
	if (IsFirstRender==false)
	{
		AreaInRender->On();
		IsFirstRender = true;
	}
	if (IsFlip == false)
	{
		if (PlayerPos.x - CurPos.x> 100.0f)
		{
			GetTransform()->AddLocalPosition({ _Time * MoveSpeed, 0.0f,0.0f });

		}
		else 
		{
			ChangeState(WhiteSkellState::CHASE);
		}
	}
	else
	{
		if (CurPos.x - PlayerPos.x > 100.0f)
		{
			GetTransform()->AddLocalPosition({ -_Time * MoveSpeed, 0.0f,0.0f });

		}
		else
		{
			ChangeState(WhiteSkellState::CHASE);
		}
	}
	

}

void WhiteSkell::AttackEnd()
{
}

void WhiteSkell::DeadStart()
{
}

void WhiteSkell::DeadUpdate(float _Time)
{
}

void WhiteSkell::DeadEnd()
{
}
