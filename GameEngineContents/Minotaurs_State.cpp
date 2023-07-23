#include "PrecompileHeader.h"
#include "Minotaurs.h"
#include "TunakDust_D.h"
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
void Minotaurs::ChangeState(MinotaursState _State)
{
	MinotaursState NextState = _State;
	MinotaursState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case MinotaursState::IDLE:
		IdleStart();
		break;
	case MinotaursState::Tackle:
		MoveStart();
		break;
	case MinotaursState::DEAD:
		DeadStart();
		break;
	case MinotaursState::ATTACK:
		AttackStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case MinotaursState::IDLE:
		IdleEnd();
		break;
	case MinotaursState::Tackle:
		MoveEnd();
		break;
	case MinotaursState::DEAD:
		DeadEnd();
		break;
	case MinotaursState::ATTACK:
		AttackEnd();
		break;
	default:
		break;
	}

}

void Minotaurs::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case MinotaursState::IDLE:
		IdleUpdate(_Time);
		break;
	case MinotaursState::Tackle:
		MoveUpdate(_Time);
		break;
	case MinotaursState::DEAD:
		DeadUpdate(_Time);
		break;
	case MinotaursState::ATTACK:
		AttackUpdate(_Time);
		break;
	default:
		break;
	}
}

void Minotaurs::IdleStart()
{
	MinotaursRender->ChangeAnimation("MinotaursIdle");
}

void Minotaurs::IdleUpdate(float _Time)
{
	if (MinoHp < 0)
	{
		ChangeState(MinotaursState::DEAD);
	}
	AttackCol->Off();
	DirCheckTime += _Time;
	if (DirCheckTime > 2.0f)
	{
		if (IsFlipCheck() == true)
		{
			MinotaursRender->GetTransform()->SetLocalNegativeScaleX();
			TargetAreaCol->GetTransform()->SetLocalPosition({ -280.0f,-40.0f,0.f });
			HpBaseRender->GetTransform()->SetLocalPosition({ 35.0f,-110.0f,0.0f });
			HpRender->GetTransform()->SetLocalPosition({ 35.0f,-110.0f,0.0f });
			DirCheckTime = 0.0f;
		}
		else
		{
			MinotaursRender->GetTransform()->SetLocalPositiveScaleX();
			TargetAreaCol->GetTransform()->SetLocalPosition({ 280.0f,-40.0f,0.f });
			HpBaseRender->GetTransform()->SetLocalPosition({ -35.0f,-110.0f,0.0f });
			HpRender->GetTransform()->SetLocalPosition({ -35.0f,-110.0f,0.0f });
			DirCheckTime = 0.0f;

		}
	}
	if (IsAreaIn() == true || AreaIn==true)
	{
		NextTakcle += _Time;
		if (NextTakcle > 1.0f)
		{
			ChangeState(MinotaursState::Tackle);
			NextTakcle = false;
		}
	}
}

void Minotaurs::IdleEnd()
{
}

void Minotaurs::MoveStart()
{
	MinotaursRender->ChangeAnimation("MinotaursTakcle");
	IsFlip = IsFlipCheck();
	PrevPos = GetTransform()->GetLocalPosition();
	if (IsFlip == true)
	{
		EndPos = PrevPos;
		EndPos.x -= 500.0f;
	}
	else
	{
		EndPos = PrevPos;
		EndPos.x += 500.0f;
	}
}

void Minotaurs::MoveUpdate(float _Time)
{
	if (MinoHp < 0)
	{
		ChangeState(MinotaursState::DEAD);
	}
	float4 CurPos = GetTransform()->GetLocalPosition();
	WaitTakcle += _Time;
	if (MinotaursRender->GetCurrentFrame() == 3)
	{
		MinotaursRender->SetAnimPauseOn();
	}
	if (WaitTakcle > 1.0f)
	{
		MinotaursRender->SetAnimPauseOff();
		if (MinotaursRender->GetCurrentFrame() == 4)
		{
			MinotaursRender->SetAnimPauseOn();
			if (IsFlip == true)
			{
				if (CurPos.x > EndPos.x)
				{
					DustTime += _Time;
					if (DustTime > 0.1f)
					{
						DustRender = GetLevel()->CreateActor<TunakDust_D>();
						DustRender->GetTransform()->SetLocalPosition({ CurPos.x,CurPos.y-45.0f,CurPos.z+10.0f});
						DustTime = 0.0f;
					}
					TakcleCol->On();
					GetTransform()->AddLocalPosition({ -_Time * 700.0f,0.0f,0.0f });
			
				}
				else
				{
					MinotaursRender->SetAnimPauseOff();
					size_t frame = MinotaursRender->GetCurrentFrame();
					if (frame ==4)
					{
						ChangeState(MinotaursState::ATTACK);
					}
				}
			}
			else
			{
				if (CurPos.x < EndPos.x)
				{
					DustTime += _Time;
					if (DustTime > 0.1f)
					{
						DustRender = GetLevel()->CreateActor<TunakDust_D>();
						DustRender->GetTransform()->SetLocalNegativeScaleX();
						DustRender->GetTransform()->SetLocalPosition({ CurPos.x,CurPos.y - 45.0f,CurPos.z+10.0f });
						DustTime = 0.0f;
					}
					TakcleCol->On();
					GetTransform()->AddLocalPosition({ _Time * 700.0f,0.0f,0.0f });

				}
				else
				{
					MinotaursRender->SetAnimPauseOff();
					if (MinotaursRender->GetCurrentFrame() == 4)
					{
						ChangeState(MinotaursState::ATTACK);
					}
				}

			}
		}
	}
}

void Minotaurs::MoveEnd()
{
}

void Minotaurs::AttackStart()
{
	TakcleCol->Off();
	AttackCol->On();
	if (IsFlip == true)
	{
		MinotaursRender->GetTransform()->SetLocalPositiveScaleX();
		HpBaseRender->GetTransform()->SetLocalPosition({ -35.0f,-110.0f,0.0f });
		HpRender->GetTransform()->SetLocalPosition({ -35.0f,-110.0f,0.0f });
		TargetAreaCol->GetTransform()->SetLocalPosition({ 280.0f,-40.0f,0.f });
		AttackCol->GetTransform()->SetLocalPosition({ 70.0f,-30.0f,0.f });
	}
	else
	{
		HpBaseRender->GetTransform()->SetLocalPosition({ 35.0f,-110.0f,0.0f });
		HpRender->GetTransform()->SetLocalPosition({ 35.0f,-110.0f,0.0f });
		MinotaursRender->GetTransform()->SetLocalNegativeScaleX();
		AttackCol->GetTransform()->SetLocalPosition({ -70.0f,-30.0f,0.f });
		TargetAreaCol->GetTransform()->SetLocalPosition({ -280.0f,-40.0f,0.f });

	}	
	MinotaursRender->ChangeAnimation("MinotaursAttack");
}

void Minotaurs::AttackUpdate(float _Time)
{
	if (MinoHp < 0)
	{
		ChangeState(MinotaursState::DEAD);
	}
	if (MinotaursRender->IsAnimationEnd())
	{
		ChangeState(MinotaursState::IDLE);
	}
}

void Minotaurs::AttackEnd()
{
}

void Minotaurs::DeadStart()
{
	MinotaursRender->Off();
	DeadRender->ChangeAnimation("MinoDead");
	HpRender->Death();
	Player::MainPlayer->GetData().SubMonsterIndex(1);
	HpBaseRender->Death();
}

void Minotaurs::DeadUpdate(float _Time)
{
	if (DeadRender->IsAnimationEnd())
	{
		GoldCoin::CoinCreat(GetLevel(), GetTransform()->GetLocalPosition(), true);
		Death();
	}
}

void Minotaurs::DeadEnd()
{
}
