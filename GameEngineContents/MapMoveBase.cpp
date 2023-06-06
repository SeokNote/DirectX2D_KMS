#include "PrecompileHeader.h"
#include "MapMoveBase.h"
#include "Player.h"
#include "FadeEffect.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>

MapMoveBase::MapMoveBase() 
{
}

MapMoveBase::~MapMoveBase() 
{
}



void MapMoveBase::Start()
{
	FEffect = GetLevel()->GetLastTarget()->CreateEffect<FadeEffect>();

}

void MapMoveBase::Update(float _DeltaTime)
{
	MapMove(_DeltaTime, Pos);
}

void MapMoveBase::MapMove(float _DeltaTime, float4 _Pos)
{
	if (Value_1 == false)
	{
		CheckTime_0 += _DeltaTime;
		FEffect->FadeIn();

		if (CheckTime_0 > 1.5f)
		{
			Player::MainPlayer->Off();
			CheckTime_0 = 0.0f;
			Player::MainPlayer->GetTransform()->SetLocalPosition(_Pos);
			Value_0 = true;
		}
		if (Value_0 == true)
		{
			Player::MainPlayer->On();
			FEffect->FadeOut();
			Value_0 = false;
			Value_1 = true;
		}
	}

}
