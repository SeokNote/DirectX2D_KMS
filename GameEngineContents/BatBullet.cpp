#include "PrecompileHeader.h"
#include "BatBullet.h"
#include "ContentsEnums.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
bool BatBullet::MoveStart = false;
float4 BatBullet::Dir = float4::Zero;
BatBullet::BatBullet() 
{
}

BatBullet::~BatBullet() 
{
}

void BatBullet::CreatBatBullet(GameEngineLevel* _Level, float _Range, float4 _Deg , float4 _Pos)
{
	std::shared_ptr<BatBullet> BatBulletPtr = _Level->CreateActor<BatBullet>();
	BatBulletPtr->GetTransform()->SetLocalPosition({ _Pos.x+ _Deg.x * _Range,_Pos.y+ _Deg.y * _Range,-800.0f });
}
void BatBullet::MoveBullet( float _Delta, float4 Deg)
{
	if (ColCheck == false && MiddleCheck==false)
	{
		GetTransform()->AddLocalPosition({ _Delta * 250.0f * Deg.x ,_Delta * 250.0f * Deg.y ,0.0f });
	}
}

// 움직이는 함수.
//gettransform 
void BatBullet::Start()
{
	BulletRender= CreateComponent<GameEngineSpriteRenderer>(1);
	BulletRender->SetTexture("RangeBallBullet0.png");
	BulletRender->CreateAnimation({ .AnimationName = "BatBulletIdle", .SpriteName = "BatBulletIdle", .Loop = true , .ScaleToTexture = true });
	BulletRender->CreateAnimation({ .AnimationName = "BatBulletDie", .SpriteName = "BatBulletDie", .Loop = false , .ScaleToTexture = true });
	BulletRender->ChangeAnimation("BatBulletIdle");

	AttackCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	AttackCol->GetTransform()->SetLocalScale(Scale);
	AttackCol->SetColType(ColType::AABBBOX2D);
}

void BatBullet::Update(float _DeltaTime)
{
	SetCollison();
	PixelCollision();
	MidPixelCollision();
	if(MoveStart ==true)
	{
		DeadTime1 += _DeltaTime;
		MoveBullet(_DeltaTime, Dir);
	}
	if (ColCheck == true || MiddleCheck == true|| DeadTime1>3.0f)
	{
		
		DeadTime += _DeltaTime;
		if (Value == false)
		{
			BulletRender->ChangeAnimation("BatBulletDie");
			AttackCol->Off();
			Value = true;
		}
		if (DeadTime > 1.0f)
		{
			Death();
			DeadTime = 0.0f;
			DeadTime1 = 0.0f;
		}
	}
}
void BatBullet::SetCollison()
{
	if (Player::MainPlayer->GetABSValue() == false && AttackCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(Damege);
		Death();
	}
}
void BatBullet::PixelCollision()
{
	PixelMapResultPos = PixelCalculation(GetTransform()->GetLocalPosition(), { 5320.0f,0.0f,0.0f }, { 1280.0f,720.0f });
	Ptr = GameEngineTexture::Find("TownCol_3.png");
	Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y+60.0f));

	Pixel.a = 0;
	if (Pixel == GameEnginePixelColor::Black)
	{
		ColCheck = true;
	}


}
void BatBullet::MidPixelCollision()
{
	PixelMapResultPos = PixelCalculation(GetTransform()->GetLocalPosition(), { 5320.0f,0.0f,0.0f }, { 1280.0f,720.0f });
	Ptr = GameEngineTexture::Find("StageCol_2.png");
	Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y+60.0f));
	if (Pixel == MiddleGround)
	{
		MiddleCheck = true;
	}
}
float4 BatBullet::PixelCalculation(float4 _TargetPos, float4 _MapCenterPos, float4 _TransColPos)
{
	TargetPos = _TargetPos;
	PixelMapResultPos.x = _TargetPos.x + _TransColPos.x - _MapCenterPos.x;
	PixelMapResultPos.y = _TransColPos.y - _TargetPos.y;
	return PixelMapResultPos;
}
