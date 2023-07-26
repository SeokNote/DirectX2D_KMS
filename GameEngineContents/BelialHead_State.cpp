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
#include "BossText.h"
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
	case BossHeadState::EVENT:
		EventStart();
		break;
	case BossHeadState::EVENT2:
		Event2Start();
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
	case BossHeadState::EVENT:
		EventEnd();
		break;
	case BossHeadState::EVENT2:
		Event2End();
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
	case BossHeadState::EVENT:
		EventUpdate(_Time);
		break;
	case BossHeadState::EVENT2:
		Event2Update(_Time);
		break;
	default:
		break;
	}
}


void BelialHead::IdleStart()
{
	BelialHeadRender->ChangeAnimation("HeadIdle");
}
bool EvnetStart = false;
void BelialHead::IdleUpdate(float _Time)
{
	if (EvnetStart == false)
	{
		ChangeState(BossHeadState::EVENT);
		EvnetStart = true;
	}
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
		//ChangeState(BossHeadState::DEAD);

		TimeCheck_0 = 0.0f;
		ChangeState(BossHeadState::MOVE);
	}
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
	if (BelialHp < 0)
	{
		ChangeState(BossHeadState::DEAD);
	}
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
		GameEngineSound::Play("BelialBullet.wav");
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
	if (BelialHp < 0)
	{
		ChangeState(BossHeadState::DEAD);
	}
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
	Player::MainPlayer->GetData().SubMonsterIndex(1);

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
			GameEngineSound::Play("MonsterDie.wav");
			BossDead::CreateSubBG(GetLevel(), CurPod);
			DeadEffectTime = 0.0f;
		}
	}
}
void BelialHead::DeadEnd()
{
}

void BelialHead::EventStart()
{
	BelialHeadRender->ChangeAnimation("HeadIdle");
	GameEngineSound::Play("beliallaugh_rev.wav");
	std::shared_ptr<BossText> test = GetLevel()->CreateActor<BossText>();
	test->GetTransform()->SetLocalPosition({ -500.0f,-200.f,0.0f });
	test->SetExPlaneFont("벨리알", "감옥의 수문장");
}

void BelialHead::EventUpdate(float _Time)
{
	if (BelialHeadRender->ColorOptionValue.MulColor.a < 1)
	{
		BelialHeadRender->ColorOptionValue.MulColor.a += _Time;

	}
	else
	{
		BossLayout->On();
		Player::MainPlayer->GetData().SetBelialCtrl(true);
		float4 PlayerPos = GetLevel()->GetMainCamera()->GetTransform()->GetLocalPosition();
		PlayerPos.z = -1000.0f;
		ZoomPos = GetTransform()->GetLocalPosition();
		ZoomPos.x += 50.0f;
		ZoomPos.y -= 50.f;
		ZoomPos.z = -1000.0f;
		float4 CameraPos = float4::LerpClamp(PlayerPos, ZoomPos, _Time * 1.5f);
		GetLevel()->GetMainCamera()->GetTransform()->SetWorldPosition(CameraPos);
		if (BossLayout->ColorOptionValue.MulColor.a < 1)
		{
			BossLayout->ColorOptionValue.MulColor.a += _Time;

		}
		else
		{
			PattonStart += _Time;
			if (PattonStart > 1.5f)
			{
				ChangeState(BossHeadState::EVENT2);
			}
		}
	}
}

void BelialHead::EventEnd()
{
}

void BelialHead::Event2Start()
{
	
}

void BelialHead::Event2Update(float _Time)
{
	if (BossLayout->ColorOptionValue.MulColor.a > 0.0f)
	{
		BossLayout->ColorOptionValue.MulColor.a -= _Time;

	}
	else
	{
		BossLayout->Off();
		Player::MainPlayer->GetData().SetBelialCtrl(false);
		HandStart = true;
		ChangeState(BossHeadState::IDLE);
	}
}

void BelialHead::Event2End()
{
}
