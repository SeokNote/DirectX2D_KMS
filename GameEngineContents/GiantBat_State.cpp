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
	GiantBatRender->ChangeAnimation("GiantBatIdle");

}

void GiantBat::IdleUpdate(float _Time)
{
	if (Hp < 0)
	{
		ChangeState(GiantBatState::DEAD);
	}
	if (AttackMove == true)
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

void GiantBat::IdleEnd()
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
		ChangeState(GiantBatState::IDLE);
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
