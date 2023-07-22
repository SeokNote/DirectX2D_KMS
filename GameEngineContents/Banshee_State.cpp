#include "PrecompileHeader.h"
#include "Banshee.h"
#include "Player.h"
#include "BansheeBullet.h"
#include "TextUI.h"
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
void Banshee::ChangeState(BansheeState _State)
{
	BansheeState NextState = _State;
	BansheeState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case BansheeState::IDLE:
		IdleStart();
		break;
	case BansheeState::DEAD:
		DeadStart();
		break;
	case BansheeState::ATTACKREADY:
		AttackReadyStart();
		break;
	case BansheeState::ATTACK:
		AttackStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case BansheeState::IDLE:
		IdleEnd();
		break;
	case BansheeState::DEAD:
		DeadEnd();
		break;
	case BansheeState::ATTACK:
		AttackEnd();
		break;
	case BansheeState::ATTACKREADY:
		AttackReadyEnd();
		break;
	default:
		break;
	}

}

void Banshee::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case BansheeState::IDLE:
		IdleUpdate(_Time);
		break;
	case BansheeState::DEAD:
		DeadUpdate(_Time);
		break;
	case BansheeState::ATTACK:
		AttackUpdate(_Time);
		break;
	case BansheeState::ATTACKREADY:
		AttackReadyUpdate(_Time);
		break;
	default:
		break;
	}
}

void Banshee::IdleStart()
{
	if (SpownValue == false)
	{
		BansheeRender->Off();

	}
	else
	{
		BansheeRender->ChangeAnimation("BansheeIdle");

	}
	SpownRender->ChangeAnimation("SpownAni");


}

void Banshee::IdleUpdate(float _Time)
{
	if (SpownValue == false && SpownRender->IsAnimationEnd())
	{
		BansheeRender->ChangeAnimation("BansheeIdle");
		SpownRender->Off();
		BansheeRender->On();
		SpownValue = true;
	}
	if (Hp < 0)
	{
		ChangeState(BansheeState::DEAD);
	}
	if (AttackMove == true)
	{
		AttackTime += _Time;
		if (AttackTime > 3.0f)
		{
			ChangeState(BansheeState::ATTACKREADY);
			AttackTime = 0.0f;
		}
	}
}

void Banshee::IdleEnd()
{
}

void Banshee::AttackReadyStart()
{
	BansheeRender->ChangeAnimation("BansheeAttack");
	Count = 0;
}

void Banshee::AttackReadyUpdate(float _Time)
{
	if (Count <14)
	{
		BansheeBullet::CreatBansheeBullet(GetLevel(), 10.0f, Degs[Count], GetTransform()->GetLocalPosition());

	}
	if (Count == 15)
	{
		ChangeState(BansheeState::ATTACK);
	}
	Count++;

}

void Banshee::AttackReadyEnd()
{
}



void Banshee::AttackStart()
{
	BansheeBullet::SetStartValue(true);
	BansheeRender->ChangeAnimation("BansheeIdle");
}

void Banshee::AttackUpdate(float _Time)
{
	NextTime += _Time;
	if (NextTime > 3.f)
	{
		ChangeState(BansheeState::IDLE);
	}

	if (Hp < 0)
	{
		ChangeState(BansheeState::DEAD);
	}
}

void Banshee::AttackEnd()
{
}

void Banshee::DeadStart()
{
	BansheeRender->Off();
	DeadRender->ChangeAnimation("BansheeDead");
	HpRender->Death();
	HpBaseRender->Death();
	BodyCol->Off();
	HpRender->Death();
	HpBaseRender->Death();

}

void Banshee::DeadUpdate(float _Time)
{
	if (DeadRender->IsAnimationEnd())
	{
		GoldCoin::CoinCreat(GetLevel(), GetTransform()->GetLocalPosition(), true);
		Death();
	}
}

void Banshee::DeadEnd()
{
}
