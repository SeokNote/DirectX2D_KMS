#include "PrecompileHeader.h"
#include "Door.h"
#include "Player.h"
#include "FadeEffect.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>

Door::Door() 
{
}

Door::~Door() 
{
}

void Door::Start()
{
	FEffect = GetLevel()->GetLastTarget()->CreateEffect<FadeEffect>();

	DoorCol = CreateComponent<GameEngineCollision>();
	DoorCol->GetTransform()->SetLocalScale(DoorScale);
	DoorCol->GetTransform()->SetLocalPosition(DoorPos);
	DoorCol->SetOrder(3012);
}

void Door::Update(float _DeltaTime)
{
	DoorCol->GetTransform()->SetLocalScale(DoorScale);
	DoorCol->GetTransform()->SetLocalPosition(DoorPos);
	DoorCol->SetColType(ColType::AABBBOX2D);
	float4 Pos = DoorCol->GetTransform()->GetLocalPosition();

	if (DoorCol->Collision(3333, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->SetUICount(1);
		MapMove(_DeltaTime, NextPos);

	}
}


void Door::MapMove(float _DeltaTime, float4 _Pos)
{

	CheckTime_0 += _DeltaTime;

	if (Value_1 == false)
	{
		FEffect->FadeIn();
		Value_1 = true;
	}

	if (CheckTime_0 > 1.0f && Value_1 == true)
	{
		Player::MainPlayer->Off();
		Player::MainPlayer->GetTransform()->SetLocalPosition(_Pos);
		Value_0 = true;
	}
	if (Value_0 == true)
	{
		Player::MainPlayer->On();
		FEffect->FadeOut();
		Player::MainPlayer->SetUICount(0);
		Value_0 = false;
		Value_1 = false;
		CheckTime_0 = 0.0f;
	}
	
}
