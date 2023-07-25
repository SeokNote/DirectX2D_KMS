#include "PrecompileHeader.h"
#include "Potal.h"
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
#include <GameEnginePlatform/GameEngineSound.h>
void Potal::ChangeState(PotalState _State)
{
	PotalState NextState = _State;
	PotalState PrevState = StateValue;

	StateValue = NextState;

	switch (NextState)
	{
	case PotalState::IDLE:
		IdleStart();
		break;
	case PotalState::IDLE2:
		Idle2Start();
		break;
	case PotalState::OPEN:
		OpenStart();
		break;
	case PotalState::CLOSE:
		CloseStart();
		break;
	default:
		break;
	}

	switch (PrevState)
	{
	case PotalState::IDLE:
		IdleEnd();
		break;
	case PotalState::IDLE2:
		Idle2End();
		break;
	case PotalState::OPEN:
		OpenEnd();
		break;
	case PotalState::CLOSE:
		CloseEnd();
		break;
	default:
		break;
	}

}

void Potal::UpdateState(float _Time)
{
	switch (StateValue)
	{
	case PotalState::IDLE:
		IdleUpdate(_Time);
		break;
	case PotalState::IDLE2:
		Idle2Update(_Time);
		break;
	case PotalState::OPEN:
		OpenUpdate(_Time);
		break;
	case PotalState::CLOSE:
		CloseUpdate(_Time);
		break;

	default:
		break;
	}
}

void Potal::IdleStart()
{

}

void Potal::IdleUpdate(float _Time)
{
	if (Player::MainPlayer->GetData().GetMonsterIndex() != 0)
	{
		ChangeState(PotalState::CLOSE);
	}
}

void Potal::IdleEnd()
{
}

void Potal::Idle2Start()
{
	SteleRender->ChangeAnimation("SteleIdle");
}

void Potal::Idle2Update(float _Time)
{
	if (Player::MainPlayer->GetData().GetMonsterIndex() == 0)
	{
		SteleCol->Off();
		ChangeState(PotalState::OPEN);
	}
}

void Potal::Idle2End()
{
}

void Potal::OpenStart()
{
	
	SteleRender->ChangeAnimation("SteleOpen");
	if (true == SteleSound.IsValid())
	{
		bool IsPlayValue = false;
		SteleSound.isPlaying(&IsPlayValue);
		if (IsPlayValue == true)
		{
			return;
		}
		

	}
	SteleSound = GameEngineSound::Play("stoneDoor.wav");
}

void Potal::OpenUpdate(float _Time)
{
	if (Player::MainPlayer->GetData().GetMonsterIndex() != 0)
	{
		ChangeState(PotalState::CLOSE);
	}
}

void Potal::OpenEnd()
{
}

void Potal::CloseStart()
{
	SteleRender->ChangeAnimation("SteleClose");
	if (true == SteleSound.IsValid())
	{
		bool IsPlayValue = false;
		SteleSound.isPlaying(&IsPlayValue);
		if (IsPlayValue == true)
		{
			return;
		}


	}
	SteleSound = GameEngineSound::Play("stoneDoor.wav");
}

void Potal::CloseUpdate(float _Time)
{
	if (true == SteleRender->IsAnimationEnd())
	{
		SteleCol->On();
		ChangeState(PotalState::IDLE2);
	}
}

void Potal::CloseEnd()
{
}
