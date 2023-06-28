#include"PrecompileHeader.h"
#include "ContentsEnums.h"
#include "BossSword.h"
#include "Player.h"
#include "PlayerDataBase.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
BossSword::BossSword() 
{
}

BossSword::~BossSword() 
{
}

void BossSword::Start()
{

	SwordRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordRender->SetTexture("BossSword.png");
	SwordRender->GetTransform()->SetLocalScale({ 84.0f,-260.0f,0.0f });
	SwordRender->CreateAnimation({ .AnimationName = "BossSwordIdle", .SpriteName = "BossSwordIdle", .Loop = true , .ScaleToTexture = false });

	SwordDeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordDeadRender->SetTexture("IcicleDestroyFX3.png");
	SwordDeadRender->CreateAnimation({ .AnimationName = "BossSwordDead", .SpriteName = "BossSwordDead", .Loop = false , .ScaleToTexture = true });
	//SwordDeadRender->ChangeAnimation("BossSwordDead");

	SwordEffectRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordEffectRender->SetTexture("BossSwordCharge8.png");
	SwordEffectRender->CreateAnimation({ .AnimationName = "BossSwordCharge", .SpriteName = "BossSwordCharge", .ScaleToTexture = true });

	SwordFxRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordFxRender->SetTexture("BossSwordFX.png");
	SwordRender->GetTransform()->SetLocalScale({ 84.0f,-280.0f,0.0f });
	SwordFxRender->CreateAnimation({ .AnimationName = "BossSwordAtteck", .SpriteName = "BossSwordAtteck", .Loop=false ,.ScaleToTexture = true });
	SwordFxRender->ChangeAnimation("BossSwordAtteck");
	SwordFxRender->Off();

	SwordColRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SwordColRender->SetTexture("BossSwordHitFX5.png");
	SwordColRender->CreateAnimation({ .AnimationName = "BossSwordFx", .SpriteName = "BossSwordFx", .Loop = false , .ScaleToTexture = true });
	ChangeState(BossSwordState::IDLE);

	SwordCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	SwordCol->GetTransform()->SetLocalScale({ 84.0f,-260.0f,0.0f });
	SwordCol->SetColType(ColType::AABBBOX2D);
}

void BossSword::Update(float _DeltaTime)
{
	PixelCheck();
	UpdateState(_DeltaTime);
	CollisionCheck(_DeltaTime);
}

bool BossSword::PixelCheck()
{
	float4 Pos = SwordRender->GetTransform()->GetWorldPosition();
	float4 LocalPos = SwordRender->GetTransform()->GetLocalPosition();
	float4 LocalRotation = SwordRender->GetTransform()->GetLocalRotation();
	SwordCol->GetTransform()->SetLocalPosition({LocalPos.x,LocalPos.y,0.0f});
	SwordCol->GetTransform()->SetLocalRotation(LocalRotation);
	//ÇÈ¼¿Ã¼Å©
	PixelMapResultPos = Player::MainPlayer->PixelCalculation(Pos, { 12084.0f,0.0f,0.0f }, { 704.0f,672.0f });
	Ptr = GameEngineTexture::Find("BossRoomCol_1.png");
	Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y));
	Pixel.a = 0;
	if (Pixel == GameEnginePixelColor::Black)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void BossSword::CollisionCheck(float _DeltaTime)
{
	if (InvinCheck==false && SwordCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		SwordCol->Off();
		InvinCheck = true;
		Player::MainPlayer->GetData().SubPlayerHP(SwordDamage);
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
