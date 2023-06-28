#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "BelialLasor.h"
#include "BelialHand_L.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
BelialLasor::BelialLasor() 
{
}

BelialLasor::~BelialLasor() 
{
}

void BelialLasor::Start()
{
	BelialLasorRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialLasorRender->SetTexture("SkellBossLeftHandIdle0.png");
	BelialLasorRender->GetTransform()->SetLocalScale(LasorScale);
	BelialLasorRender->CreateAnimation({ .AnimationName = "LasorPattern", .SpriteName = "LasorPattern", .Loop = false , .ScaleToTexture = false });
	BelialLasorRender->ChangeAnimation("LasorPattern");

	
	BelialLasorCol_L = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	BelialLasorCol_L->GetTransform()->SetLocalScale(LasorColScale);
	BelialLasorCol_L->SetColType(ColType::AABBBOX2D);
}

void BelialLasor::Update(float _DeltaTime)
{
	CollisionCheck(_DeltaTime);
	if (BelialLasorRender->IsAnimationEnd())

	{
		Death();
	}
}

void BelialLasor::CollisionCheck(float _DeltaTime)
{
	if (InvinCheck == false && BelialLasorCol_L->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		InvinCheck = true;
		//Player::MainPlayer->GetData().SubPlayerHP(LasorDamage);
	}

	//if (InvinCheck == true)
	//{
	//	InvinTime += _DeltaTime;
	//	Player::MainPlayer->Invincible(_DeltaTime);
	//	if (InvinTime > 1.1f)
	//	{
	//		InvinCheck = false;
	//		Player::MainPlayer->SetBlinkTime(0.0f);
	//		InvinTime = 0.0f;
	//	}
	//}
}
