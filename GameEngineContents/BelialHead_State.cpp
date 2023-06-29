#include "PrecompileHeader.h"
#include "BelialHead.h"
#include "BelialBullet.h"
#include "Player.h"
#include "BossDead.h"
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
	case BossHeadState::SWORD:
		SwordStart();
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
	case BossHeadState::SWORD:
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
	case BossHeadState::SWORD:
		SwordUpdate(_Time);
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
	if (BelialHp < 0)
	{
		ChangeState(BossHeadState::DEAD);
	}
	BelialCol->GetTransform()->SetLocalScale(BelialColScale);
	BulletPatton = false;
	TimeCheck_0 += _Time;
	if (TimeCheck_0 > 10.0f)
	{
		TimeCheck_0 = 0.0f;
		ChangeState(BossHeadState::MOVE);
	}
	//if (TimeCheck_0 > 2.0f)
	//{
	//
	//
	//}
}
void BelialHead::IdleEnd()
{
}

void BelialHead::MoveStart()
{
	BelialCol->GetTransform()->SetLocalScale({ 200.0f,400.0f,0.0f });
	BelialHeadRender->ChangeAnimation("HeadMove");
	IsBullet = true;
}
void BelialHead::MoveUpdate(float _Time)
{
	BulletPatton = true;
	BulletTime += _Time;
	TimeCheck_1 += _Time;
	if (TimeCheck_1 > 5.0f)
	{
		ChangeState(BossHeadState::SWORD);
		TimeCheck_1 = 0.0f;
		IsBullet = false;
	}
	if (IsBullet == true && BulletTime > 0.15f)
	{
		BelialBulletRender = GetLevel()->CreateActor<BelialBullet>();
		BulletTime = 0.0f;
	}
}
void BelialHead::MoveEnd()
{
}
void BelialHead::SwordStart()
{
	BelialHeadRender->ChangeAnimation("HeadIdle");
	SwordIndex = 0;
	StartX = 11800.0f;
	YInvers = -100.0f;
}
void BelialHead::SwordUpdate(float _Time)
{
	BelialSwordPlay(_Time);
	TimeCheck_2 += _Time;
	if (TimeCheck_2 > 5.0f)
	{
		ChangeState(BossHeadState::IDLE);
		TimeCheck_2 = 0.0f;
	}
}
void BelialHead::SwordEnd()
{
}
void BelialHead::DeadStart()
{
	BossHpFront->Off();
	BossHpBase->Off();
	BossHpBar->Off();
	BelialHeadRender->ChangeAnimation("BelialBeforDead");
	DeadBGRender->On();
	IsDeath = true;
	HandleStop = true;
}
void BelialHead::DeadUpdate(float _Time)
{

	float4 CurPod = BelialHeadRender->GetTransform()->GetWorldPosition();
	if (DeadBGRender->ColorOptionValue.MulColor.a > 0.0f)
	{
		DeadBGRender->ColorOptionValue.MulColor.a -= _Time * 0.5f;
	}

	else if (IsDead == false)
	{
		DeathShack = true;
		DeadEffectTime += _Time;
		if (DeadEffectTime > 0.1f)
		{
			BossDead::CreateSubBG(GetLevel(), CurPod);
			DeadEffectTime = 0.0f;
		}
	}
}
void BelialHead::DeadEnd()
{
}
