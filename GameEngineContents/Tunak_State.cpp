#include "PrecompileHeader.h"
#include "Player.h"
#include "Tunak.h"
#include "GroundBomb.h"
#include "TunakAfterEffect.h"
#include "TunakBullet.h"
#include "GoblinBomb.h"
#include "TunakDust.h"
#include "TunakDust_D.h"
#include "TunakJumpEffect.h"
#include "TunakWave.h"
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
#include <GameEngineBase/GameEngineRandom.h>


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
	case TunakState::OVERPOWER:
		OverPowerStart();
		break;
	case TunakState::DOUBLEATTACK:
		DoubleAttackStart();
		break;
	case TunakState::SHOUT:
		ShoutStart();
		break;
	case TunakState::JUMPATTACK:
		JumpAttackStart();
		break;
	case TunakState::GoblimBomb:
		GoblinBombStart();
		break;
	case TunakState::TACKLE:
		TackleStart();
		break;
	case TunakState::HALFPATTON_S:
		HalfHp_SStart();
		break;
	case TunakState::HALFPATTON_E:
		HalfHp_EStart();
		break;
	case TunakState::TunakDead:
		TunakDeadStart();
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
	case TunakState::OVERPOWER:
		OverPowerEnd();
		break;
	case TunakState::DOUBLEATTACK:
		DoubleAttackEnd();
		break;
	case TunakState::SHOUT:
		ShoutEnd();
		break;
	case TunakState::JUMPATTACK:
		JumpAttackEnd();
		break;
	case TunakState::GoblimBomb:
		GoblinBombEnd();
		break;
	case TunakState::TACKLE:
		TackleEnd();
		break;
	case TunakState::HALFPATTON_S:
		HalfHp_SEnd();
		break;
	case TunakState::HALFPATTON_E:
		HalfHp_EEnd();
		break;
	case TunakState::TunakDead:
		TunakDeadEnd();
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
	case TunakState::OVERPOWER:
		OverPowerUpdate(_Time);
		break;
	case TunakState::DOUBLEATTACK:
		DoubleAttackUpdate(_Time);
		break;
	case TunakState::SHOUT:
		ShoutUpdate(_Time);
		break;
	case TunakState::JUMPATTACK:
		JumpAttackUpdate(_Time);
		break;
	case TunakState::GoblimBomb:
		GoblinBombUpdate(_Time);
		break;
	case TunakState::TACKLE:
		TackleUpdate(_Time);
		break;
	case TunakState::HALFPATTON_S:
		HalfHp_SUpdate(_Time);
		break;
	case TunakState::HALFPATTON_E:
		HalfHp_EUpdate(_Time);
		break;
	case TunakState::TunakDead:
		TunakDeadUpdate(_Time);
		break;
	default:
		break;
	}
}


void Tunak::IdleStart()
{
	TunakRender->ChangeAnimation("TunakIdle");
	RandomIndex = GameEngineRandom::MainRandom.RandomInt(0,5);

}
void Tunak::IdleUpdate(float _Time)
{
	if (TunakHP < 0)
	{
		ChangeState(TunakState::TunakDead);
	}
	float4 TunakPos = GetTransform()->GetLocalPosition();
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	//체력이 반이 되면 실행하는 패턴
	if (HalfCheck ==false && TunakHP<500)
	{
		ChangeState(TunakState::HALFPATTON_S);
		HalfCheck = true;

	}
	if (abs(PlayerPos.x - TunakPos.x) > 700 && PlayerPos.x>14300.0f)
	{
		TimeCheck += _Time;
		if (TimeCheck > 0.5)
		{
			ChangeState(TunakState::JUMPATTACK);
			TimeCheck = 0.0f;
		}
	}
	FlipTime += _Time;
	TestTime += _Time;
	if (FlipTime >0.9f)
	{
		TunakFlip();
		FlipTime = 0.0f;
	}
	if (Player::MainPlayer->SetMyMap(CurMap) == MyMap::Stage2_Boss)
	{
		if (TestTime > 1.5f)
		{
			if (RandomIndex == 0)
			{
				ChangeState(TunakState::SPIKE_R);
			
			}
			if (RandomIndex == 1)
			{
				ChangeState(TunakState::OVERPOWER);
			
			}
			if (RandomIndex == 2)
			{
				ChangeState(TunakState::DOUBLEATTACK);
			}
			if (RandomIndex == 3)
			{
				ChangeState(TunakState::SHOUT);
			}
			if (RandomIndex == 4)
			{
				ChangeState(TunakState::GoblimBomb);
			}
			if (RandomIndex == 5)
			{
				ChangeState(TunakState::TACKLE);
			}
			


			TestTime = 0.0f;
		}
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
	BombX = GameEngineRandom::MainRandom.RandomFloat(14700.0f, 14840.0f);

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
		TunakDustSPtr = GetLevel()->CreateActor<TunakDust>();
		TunakDustSPtr->GetTransform()->SetLocalPosition(TunakPos);
		//TunakDustRender
		GetTransform()->SetLocalRotation({ 0.0f,0.0f,90.0f });
		InterRatio = 0.0f;
		GroundBombPtr_0 = GetLevel()->CreateActor<GroundBomb>();
		GroundBombPtr_0->GetTransform()->SetWorldPosition({ BombX,-100.0f,-802.0f });
		GroundBombPtr_1 = GetLevel()->CreateActor<GroundBomb>();
		GroundBombPtr_1->GetTransform()->SetWorldPosition({ BombX-400.0f,-100.0f,-802.0f });
		GroundBombPtr_2 = GetLevel()->CreateActor<GroundBomb>();
		GroundBombPtr_2->GetTransform()->SetWorldPosition({ BombX+400.0f,-100.0f,-802.0f });		
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
		ShackStart = true;
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
	BombX = GameEngineRandom::MainRandom.RandomFloat(14700.0f, 14840.0f);
	TunakRender->ChangeAnimation("TunakOverPower");

	GroundBombPtr_0 = GetLevel()->CreateActor<GroundBomb>();
	GroundBombPtr_0->GetTransform()->SetWorldPosition({ BombX,-100.0f,-802.0f });
	GroundBombPtr_1 = GetLevel()->CreateActor<GroundBomb>();
	GroundBombPtr_1->GetTransform()->SetWorldPosition({ BombX - 400.0f,-100.0f,-802.0f });
	GroundBombPtr_2 = GetLevel()->CreateActor<GroundBomb>();
	GroundBombPtr_2->GetTransform()->SetWorldPosition({ BombX + 400.0f,-100.0f,-802.0f });
}

void Tunak::SPIKE_EUpdate(float _Time)
{
	size_t count = 10;
	if (count == TunakRender->GetCurrentFrame())
	{
		ShackStart = true;
	}
	if (true == TunakRender->IsAnimationEnd())
	{
		ChangeState(TunakState::IDLE);

	}
}

void Tunak::SPIKE_EEnd()
{
}

void Tunak::OverPowerStart()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	TunakRender->ChangeAnimation("TunakOverPower");
	GroundBombPtr_0 = GetLevel()->CreateActor<GroundBomb>();
	GroundBombPtr_0->GetTransform()->SetLocalPosition({ PlayerPos.x,-100.0f,-802.f });

}

void Tunak::OverPowerUpdate(float _Time)
{
	size_t count = 10;
	if (count == TunakRender->GetCurrentFrame())
	{
		ShackStart = true;
	}
	if (true == TunakRender->IsAnimationEnd())
	{
		ChangeState(TunakState::IDLE);

	}
}


void Tunak::OverPowerEnd()
{
}

void Tunak::DoubleAttackStart()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	TunakPos = GetTransform()->GetLocalPosition();
	TunakRender->ChangeAnimation("TunakDoubleAttack");
	TunakDoubleAttackCol->Off();
	DoubleTime = 0.0f;
}

void Tunak::DoubleAttackUpdate(float _Time)
{
	DoubleTime += _Time;
	if (DoubleTime > 0.1f)
	{
		TunakDoubleAttackCol->On();

	}
	float4 TunakCurPos = GetTransform()->GetLocalPosition();
	float4 Pos = TunakRender->GetTransform()->GetLocalPosition();
		if (IsFilp == false)
		{
			TunakDoubleAttackCol->GetTransform()->SetLocalPosition({ Pos.x-100.0f,Pos.y-120.0f,0.0f});
			if (TunakRender->GetCurrentFrame() < 7)
			{
				GetTransform()->AddLocalPosition({ -_Time * DoubleAttackSpeed*0.75f ,0.0f,0.0f });

			}
			if (TunakRender->GetCurrentFrame() > 8)
			{
				GetTransform()->AddLocalPosition({ -_Time * DoubleAttackSpeed * 1.25f ,0.0f,0.0f });

			}
			if (TunakCurPos.x - TunakPos.x < -120)
			{
				TunakDoubleAttackCol->Off();
				ChangeState(TunakState::IDLE);
			}
		}
		else
		{
			TunakDoubleAttackCol->GetTransform()->SetLocalPosition({ Pos.x+100.0f,Pos.y-120.0f,0.0f });
			if (TunakRender->GetCurrentFrame() < 7)
			{
				GetTransform()->AddLocalPosition({ _Time * DoubleAttackSpeed * 0.75f ,0.0f,0.0f });

			}
			if (TunakRender->GetCurrentFrame() > 8)
			{
				GetTransform()->AddLocalPosition({ _Time * DoubleAttackSpeed*1.25f ,0.0f,0.0f });

			}
			if (TunakCurPos.x - TunakPos.x > 120)
			{
				TunakDoubleAttackCol->Off();
				ChangeState(TunakState::IDLE);
			}
		}

}

void Tunak::DoubleAttackEnd()
{
}

void Tunak::ShoutStart()
{
	TunakRender->ChangeAnimation("TunakShout");

	if (IsFilp == false)
	{
		TunakBulletBG->GetTransform()->SetLocalPosition({-110.0f,-100.0f,0.0f});
	}
	else
	{
		TunakBulletBG->GetTransform()->SetLocalPosition({ 110.0f,-100.0f,0.0f });

	}
}

void Tunak::ShoutUpdate(float _Time)
{
	size_t TunakFrame = TunakRender->GetCurrentFrame();
	StartTime += _Time;
	if (TunakFrame == 3)
	{
		TunakBulletBG->ChangeAnimation("TunakBulletEffect");
	}
	float4 TunakPos = GetTransform()->GetLocalPosition();
	if (StartTime>1.0f && BulletCheck==false)
	{
		if (IsFilp == false)
		{
			TunakBulletPtr = GetLevel()->CreateActor<TunakBullet>();
			TunakBulletPtr->GetTransform()->SetLocalPosition(TunakPos + BulletPos);
			TunakBulletPtr->GetTransform()->SetLocalRotation({ 0.0f,0.0f,30.0f });
			BulletCheck = true;
			StartTime = 0.0f;
		}
		else
		{
			TunakBulletPtr = GetLevel()->CreateActor<TunakBullet>();
			TunakBulletPtr->GetTransform()->SetLocalPosition(TunakPos + FlipBulletPos);
			TunakBulletPtr->GetTransform()->SetLocalRotation({ 0.0f,0.0f,30.0f });
			BulletCheck = true;
			StartTime = 0.0f;

		}
	
	}
	if (BulletCheck == true && TunakFrame < 18)
	{
		BulletTime += _Time;
		if (BulletTime > 1.0f)
		{
			if (IsFilp == false)
			{
				TunakBulletPtr = GetLevel()->CreateActor<TunakBullet>();
				TunakBulletPtr->GetTransform()->SetLocalPosition(TunakPos + BulletPos);
				TunakBulletPtr->GetTransform()->SetLocalRotation({ 0.0f,0.0f,30.0f });
				BulletTime = 0.0f;
			}
			else
			{
				TunakBulletPtr = GetLevel()->CreateActor<TunakBullet>();
				TunakBulletPtr->GetTransform()->SetLocalPosition(TunakPos + FlipBulletPos);
				TunakBulletPtr->GetTransform()->SetLocalRotation({ 0.0f,0.0f,30.0f });
				BulletTime = 0.0f;
			}

		}
	}

	if (TunakRender->IsAnimationEnd())
	{
		ChangeState(TunakState::IDLE);
	}
}

void Tunak::ShoutEnd()
{
}

void Tunak::JumpAttackStart()
{
	TunakRender->ChangeAnimation("TunakJumpAttack");
	TunakPos = GetTransform()->GetLocalPosition();
	EndPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	EndPos.y = TunakPos.y;
	if (IsFilp == false)
	{
		Height = { (TunakPos.x + EndPos.x)/2, 400.0f, -800.0f};
		EndPos.x += 150.0f;
	}
	else
	{
		Height = { (EndPos.x + TunakPos.x)/2, 400.0f, -800.0f };
		EndPos.x -= 150.0f;

	}
}

void Tunak::JumpAttackUpdate(float _Time)
{
	JumpTime += _Time;
	CalBezierBulletTransform(TunakPos, Height, EndPos, JumpTime*0.8f);
	if (true == TunakRender->IsAnimationEnd())
	{
		JumpTime=0.0f;
		ChangeState(TunakState::DOUBLEATTACK);
	}
}

void Tunak::JumpAttackEnd()
{

}

void Tunak::GoblinBombStart()
{
	TunakRender->ChangeAnimation("TunakBombCall");
	IsGoblin = false;
	GoblinPosX = GameEngineRandom::MainRandom.RandomFloat(14700.0f, 15340.0f);
}	 


void Tunak::GoblinBombUpdate(float _Time)
{
	if (TunakRender->GetCurrentFrame() == 4 && IsGoblin ==false)
	{
		GoblinBomb_0 = GetLevel()->CreateActor<GoblinBomb>();
		GoblinBomb_0->GetTransform()->SetLocalPosition({ GoblinPosX ,-75.0f,-800.0f });
		GoblinBomb_1 = GetLevel()->CreateActor<GoblinBomb>();
		GoblinBomb_1->GetTransform()->SetLocalPosition({ GoblinPosX+ Tuom ,-75.0f,-800.0f });
		GoblinBomb_2 = GetLevel()->CreateActor<GoblinBomb>();
		GoblinBomb_2->GetTransform()->SetLocalPosition({ GoblinPosX- Tuom ,-75.0f,-800.0f });
		GoblinBomb_3 = GetLevel()->CreateActor<GoblinBomb>();
		GoblinBomb_3->GetTransform()->SetLocalPosition({ GoblinPosX+ Tuom+150.0f ,-75.0f,-800.0f });
		IsGoblin = true;
	}
	if (true == TunakRender->IsAnimationEnd())
	{
		ChangeState(TunakState::IDLE);
	}
}

void Tunak::GoblinBombEnd()
{
}

void Tunak::TackleStart()
{
	TunakRender->ChangeAnimation("TunakShoulderTakleReady");
	TackleCheck = false;
	TunakTackleCol->Off();
}

void Tunak::TackleUpdate(float _Time)
{
	float4 TunakPos = GetTransform()->GetLocalPosition();
	if (true == TunakRender->IsAnimationEnd())
	{
		PattonTime_S += _Time;
		if (PattonTime_S > 0.5f)
		{
			TunakRender->ChangeAnimation("TunakShoulderTakleStart");
			TunakTackleCol->On();
			TackleCheck = true;
			PattonTime_S = 0.0f;
		}

	}
	if (TackleCheck == true)
	{
	
		if (IsFilp == false)
		{
			DustTime += _Time;
			if (DustTime > 0.2)
			{
				TunakDustDPtr = GetLevel()->CreateActor<TunakDust_D>();
				TunakDustDPtr->GetTransform()->SetLocalPosition(TunakPos+ LeftDustPos);
				DustTime = 0.0f;
			}
			GetTransform()->AddLocalPosition({ -_Time * TackleSpeed,0.0f,0.0f });
			if (TunakPos.x < 14450)
			{
				TunakTackleCol->Off();
				ChangeState(TunakState::IDLE);
			}
		}
		else
		{
			DustTime += _Time;
			if (DustTime > 0.2)
			{
				TunakDustDPtr = GetLevel()->CreateActor<TunakDust_D>();
				TunakDustDPtr->GetTransform()->SetLocalNegativeScaleX();
				TunakDustDPtr->GetTransform()->SetLocalPosition(TunakPos+ RightDustPos);
				DustTime = 0.0f;
			}
			GetTransform()->AddLocalPosition({ _Time * TackleSpeed,0.0f,0.0f });
			if (TunakPos.x > 15700)
			{
				TunakTackleCol->Off();
				ChangeState(TunakState::IDLE);
			}
		}
	}
	bool awdas = IsFilp;
}

void Tunak::TackleEnd()
{
}

void Tunak::HalfHp_SStart()
{
	DownTime = 0.0f;
	TunakRender->ChangeAnimation("TunakJumpAttack");
	GoblinCount = 0;
}

void Tunak::HalfHp_SUpdate(float _Time)
{
	float GoblinPosX = GameEngineRandom::MainRandom.RandomFloat(14300.0f, 15740.0f);

	float4 TunakPos = GetTransform()->GetLocalPosition();
	if (TunakRender->GetCurrentFrame() > 4)
	{
		HalfAfterImage_T += _Time;
		if (HalfAfterImage_T > 0.05f)
		{
			if (IsFilp == false)
			{
				TunakJumpEffectPtr = GetLevel()->CreateActor<TunakJumpEffect>();
				TunakJumpEffectPtr->GetTransform()->SetLocalPosition(TunakPos);
				HalfAfterImage_T = 0.0f;
			}
			else
			{
				TunakJumpEffectPtr = GetLevel()->CreateActor<TunakJumpEffect>();
				TunakJumpEffectPtr->GetTransform()->SetLocalNegativeScaleX();
				TunakJumpEffectPtr->GetTransform()->SetLocalPosition(TunakPos);
				HalfAfterImage_T = 0.0f;
			}
		
		}
		if (TunakPos.y < 725.0f)
		{
			GetTransform()->AddLocalPosition({ 0.0f, HalfSpeed * _Time,0.0f });
		}
		else
		{
			GoblinTime += _Time;
			if (GoblinTime > 0.4f && GoblinCount < 15)
			{
				GoblinCount++;
				GoblinBomb_0 = GetLevel()->CreateActor<GoblinBomb>();
				GoblinBomb_0->GetTransform()->SetLocalPosition({ GoblinPosX ,-75.0f,-800.0f });
				GoblinTime = 0.0f;
			}
			if (GoblinCount > 13)
			{
				DownTime += _Time;
				if (DownTime > 3.0f)
				{
					GetTransform()->SetLocalPosition({ 15074.0f,TunakPos.y,TunakPos.z });
					ChangeState(TunakState::HALFPATTON_E);
				}
			}
		}
	}
}

void Tunak::HalfHp_SEnd()
{
}

void Tunak::HalfHp_EStart()
{
	DownTime = 0.0f;
	float4 TunakCurPos = GetTransform()->GetLocalPosition();
	TunakRender->ChangeAnimation("TunakJumpAttack");
	TunakWavePtr = GetLevel()->CreateActor<TunakWave>();
	TunakWavePtr->GetTransform()->SetLocalPosition({ TunakCurPos.x+10.f,-170.0f,-850.0f });
	//범위 뜨고 
	//애니메이션 바꾸고  
}

void Tunak::HalfHp_EUpdate(float _Time)
{
	DownTime += _Time;
	float4 TunakPos = GetTransform()->GetLocalPosition();
	if (DownTime > 1.0f)
	{
		if (TunakPos.y > -25.0f)
		{
			GetTransform()->AddLocalPosition({ 0.0f, -HalfSpeed * _Time,0.0f });

		}
		else
		{
			ShackStart = true;
			ChangeState(TunakState::IDLE);
		}
	}
	

}

void Tunak::HalfHp_EEnd()
{
}

void Tunak::TunakDeadStart()
{
	BossHpFront->Off();		
	BossHpBase->Off();
	BossHpBar->Off();
	TunakRender->ChangeAnimation("TunakDead");
	DeadBGRender->On();
}

void Tunak::TunakDeadUpdate(float _Time)
{
	float4 TunakCurPos = GetTransform()->GetLocalPosition();
	TunakCurPos.y -= 100.0f;
	if (DeadBGRender->ColorOptionValue.MulColor.a > 0.0f)
	{
		DeadBGRender->ColorOptionValue.MulColor.a -= _Time*0.5f;
	}
	else if(IsDead==false)
	{
		DeadShack = true;
		DeadEffectTime += _Time;
		if (DeadEffectTime > 0.1f)
		{
			BossDead::CreateSubBG(GetLevel(), TunakCurPos);
			DeadEffectTime = 0.0f;
		}
	}
}

void Tunak::TunakDeadEnd()
{
}
