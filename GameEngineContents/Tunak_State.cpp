#include "PrecompileHeader.h"
#include "Player.h"
#include "Tunak.h"
#include "GroundBomb.h"
#include "TunakAfterEffect.h"
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
void Tunak::ChangeState(TunakState _State)
{
	TunakState NextState = _State;
	TunakState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case TunakState::IDLE:
		IdleStart();
		break;
	case TunakState::SPIKE_R:
		SPIKE_RStart();
		break;
	case TunakState::SPIKE_S:
		SPIKE_SStart();
		break;
	case TunakState::SPIKE_U:
		SPIKE_UStart();
		break;
	case TunakState::SPIKE_E:
		SPIKE_EStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case TunakState::IDLE:
		IdleEnd();
		break;
	case TunakState::SPIKE_R:
		SPIKE_REnd();
		break;
	case TunakState::SPIKE_S:
		SPIKE_SEnd();
		break;
	case TunakState::SPIKE_U:
		SPIKE_UEnd();
		break;
	case TunakState::SPIKE_E:
		SPIKE_EEnd();
		break;
	default:
		break;
	}
}

void Tunak::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case TunakState::IDLE:
		IdleUpdate(_Time);
		break;
	case TunakState::SPIKE_R:
		SPIKE_RUpdate(_Time);
		break;
	case TunakState::SPIKE_S:
		SPIKE_SUpdate(_Time);
		break;
	case TunakState::SPIKE_U:
		SPIKE_UUpdate(_Time);
		break;
	case TunakState::SPIKE_E:
		SPIKE_EUpdate(_Time);
		break;
	default:
		break;
	}
}


void Tunak::IdleStart()
{
	TunakRender->ChangeAnimation("TunakIdle");

}
void Tunak::IdleUpdate(float _Time)
{
	TestTime += _Time;
	if (TestTime > 5.0f)
	{
		ChangeState(TunakState::SPIKE_R);
		TestTime = 0.0f;
	}

}
void Tunak::IdleEnd()
{
}

void Tunak::SPIKE_RStart()
{
	TunakRender->ChangeAnimation("TunakSpikeReady");
	CurPos = GetTransform()->GetLocalPosition();
	SpikeHeight = { CurPos.x + 100.0f,CurPos.y + 100.0f,-800.0f };
}
void Tunak::SPIKE_RUpdate(float _Time)
{
	float4 TunakPos = GetTransform()->GetLocalPosition();
	//잔상 생성 및 목표지점으로 러프시켜보자
	
	//러프시킨후 일단 임의로
	TestTime_0 += _Time;
	if (TestTime_0 > 1.f)
	{
		AfterImageTime += _Time;
		if (AfterImageTime > 0.05f)
		{
			TunakAfter_E = GetLevel()->CreateActor<TunakAfterEffect>();
			TunakAfter_E->GetTransform()->SetLocalPosition(TunakPos);
			AfterImageTime = 0.0f;
		}
		InterRatio += _Time;
		TunakRender->GetTransform()->SetLocalScale(TunakScale);
		float4 AfterimagePos = TunakPos;
		CalBezierBulletTransform(CurPos, SpikeHeight, SpikeEndPos, InterRatio * 5.0f);

	}
	if (TunakPos == SpikeEndPos)
	{
		GetTransform()->SetLocalRotation({ 0.0f,0.0f,90.0f });
		InterRatio = 0.0f;
		GetLevel()->CreateActor<GroundBomb>();
		ChangeState(TunakState::SPIKE_S);
	}
}
void Tunak::SPIKE_REnd()
{
}
void Tunak::SPIKE_SStart()
{
	TunakRender->ChangeAnimation("TunakSpikeIdle");


}
void Tunak::SPIKE_SUpdate(float _Time)
{
	TestTime_1 += _Time;
	//2초동안 메달린후에 찍어버리는 스테이트로 이동
	if (TestTime_1 > 1.0f)
	{
		GetTransform()->SetLocalRotation({ 0.0f,0.0f,0.0f });
		GetTransform()->SetLocalPosition({ 15520.0f,-25.0f,-800.0f });
		ChangeState(TunakState::SPIKE_U);
		TestTime_1 = 0.0f;
	}
}
void Tunak::SPIKE_SEnd()
{
}

void Tunak::SPIKE_UStart()
{
	TunakRender->ChangeAnimation("TunakSpike");

}

void Tunak::SPIKE_UUpdate(float _Time)
{
	//내려찍기가 끝나면 기모아서 땅찍기 실행
	if (true == TunakRender->IsAnimationEnd())
	{
		ChangeState(TunakState::SPIKE_E);

	}
}

void Tunak::SPIKE_UEnd()
{
}

void Tunak::SPIKE_EStart()
{
	TunakRender->ChangeAnimation("TunakOverPower");
	GetLevel()->CreateActor<GroundBomb>();

}

void Tunak::SPIKE_EUpdate(float _Time)
{
	if (true == TunakRender->IsAnimationEnd())
	{
		ChangeState(TunakState::IDLE);

	}
}

void Tunak::SPIKE_EEnd()
{
}
