#include "PrecompileHeader.h"
#include "GiantBat.h"
#include "Player.h"
#include "BatBullet.h"
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
void GiantBat::ChangeState(GiantBatState _State)
{
	GiantBatState NextState = _State;
	GiantBatState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case GiantBatState::IDLE:
		IdleStart();
		break;
	case GiantBatState::IDLE2:
		Idle2Start();
		break;
	case GiantBatState::DEAD:
		DeadStart();
		break;
	case GiantBatState::ATTACKREADY:
		AttackReadyStart();
		break;
	case GiantBatState::ATTACK:
		AttackStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case GiantBatState::IDLE:
		IdleEnd();
		break;
	case GiantBatState::IDLE2:
		Idle2End();
		break;
	case GiantBatState::DEAD:
		DeadEnd();
		break;
	case GiantBatState::ATTACK:
		AttackEnd();
		break;
	case GiantBatState::ATTACKREADY:
		AttackReadyEnd();
		break;
	default:
		break;
	}

}

void GiantBat::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case GiantBatState::IDLE:
		IdleUpdate(_Time);
		break;
	case GiantBatState::IDLE2:
		Idle2Update(_Time);
		break;
	case GiantBatState::DEAD:
		DeadUpdate(_Time);
		break;
	case GiantBatState::ATTACK:
		AttackUpdate(_Time);
		break;
	case GiantBatState::ATTACKREADY:
		AttackReadyUpdate(_Time);
		break;
	default:
		break;
	}
}

void GiantBat::IdleStart()
{
	if (SpownValue == false)

	{
		GiantBatRender->Off();
	}
	else
	{
		GiantBatRender->ChangeAnimation("GiantBatIdle");

	}
	SpownRender->ChangeAnimation("SpownAni");

}

void GiantBat::IdleUpdate(float _Time)
{
	if (SpownValue == false && SpownRender->IsAnimationEnd())
	{
		SpownRender->Off();
		GiantBatRender->On();
		SpownValue = true;
		ChangeState(GiantBatState::IDLE2);

	}

}

void GiantBat::IdleEnd()
{
}

void GiantBat::Idle2Start()
{
	GiantBatRender->ChangeAnimation("GiantBatIdle");

}

void GiantBat::Idle2Update(float _Time)
{
	if (Hp < 0)
	{
		ChangeState(GiantBatState::DEAD);
	}
	if (SpownValue = true && AttackMove == true)
	{
		AttackTime += _Time;
		if (AttackTime > 3.0f)
		{
			ChangeState(GiantBatState::ATTACKREADY);
			BatBullet::SetStartValue(false);
			AttackTime = 0.0f;
		}
	}
}

void GiantBat::Idle2End()
{
}

void GiantBat::AttackReadyStart()
{
	GiantBatRender->ChangeAnimation("GiantBatIdle");
	Count = 0;
}

void GiantBat::AttackReadyUpdate(float _Time)
{
	Delay += _Time;
	if (Count <18 && Delay > 0.05f)
	{
		BatBullet::CreatBatBullet(GetLevel(), 100.0f, Degs[Count],GetTransform()->GetLocalPosition());
		Delay = 0.0f;
		Count++;
	}
	if (Count > 17)
	{
		ChangeState(GiantBatState::ATTACK);
	}
}

void GiantBat::AttackReadyEnd()
{
}



void GiantBat::AttackStart()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 MyPos = GetTransform()->GetLocalPosition();
	float4 Deg = (PlayerPos - MyPos).NormalizeReturn();
	GiantBatRender->ChangeAnimation("GiantBatAttack");
	BatBullet::SetBulletDir(Deg);
	BatBullet::SetStartValue(true);
}

void GiantBat::AttackUpdate(float _Time)
{
	if (true == GiantBatRender->IsAnimationEnd())
	{
		ChangeState(GiantBatState::IDLE2);
	}
	if (Hp < 0)
	{
		ChangeState(GiantBatState::DEAD);
	}
}

void GiantBat::AttackEnd()
{
}

void GiantBat::DeadStart()
{
	GiantBatRender->ChangeAnimation("GiantBatDead");
	HpRender->Death();
	HpBaseRender->Death();
	Player::MainPlayer->GetData().SubMonsterIndex(1);
	GameEngineSound::Play("monster-sound2_bat.wav");

}

void GiantBat::DeadUpdate(float _Time)
{
	DeadTime += _Time;
	GetTransform()->AddWorldPosition({ 0.0f,-_Time * 400.0f,0.0f });
	if (DeadTime > 3)
	{
		DeadTime = 0.0f;
		GoldCoin::CoinCreat(GetLevel(), GetTransform()->GetLocalPosition(), true);
		Death();
	}
}

void GiantBat::DeadEnd()
{
}
