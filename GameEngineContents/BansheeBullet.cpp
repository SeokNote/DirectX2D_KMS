#include "PrecompileHeader.h"
#include "BansheeBullet.h"
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
bool BansheeBullet::MoveStart = false;
BansheeBullet::BansheeBullet()
{
}

BansheeBullet::~BansheeBullet()
{
}

void BansheeBullet::CreatBansheeBullet(GameEngineLevel* _Level, float _Range, float4 _Deg, float4 _Pos)
{
	std::shared_ptr<BansheeBullet> BansheeBulletPtr = _Level->CreateActor<BansheeBullet>();
	BansheeBulletPtr->GetTransform()->SetLocalPosition({ _Pos.x + _Deg.x * _Range,_Pos.y + _Deg.y * _Range,-800.0f });
	BansheeBulletPtr->SetBulletDir(_Deg);
}
void BansheeBullet::MoveBullet(float _Delta, float4 Deg)
{
	GetTransform()->AddLocalPosition({ _Delta * 250.0f * Deg.x ,_Delta * 250.0f * Deg.y ,0.0f });
}

// 움직이는 함수.
//gettransform 
void BansheeBullet::Start()
{
	BulletRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BulletRender->SetTexture("RangeBallBullet0.png");
	BulletRender->CreateAnimation({ .AnimationName = "BansheeBulletIdle", .SpriteName = "BansheeBulletIdle", .Loop = true , .ScaleToTexture = true });
	BulletRender->CreateAnimation({ .AnimationName = "BansheeBulletHit", .SpriteName = "BansheeBulletHit", .Loop = false , .ScaleToTexture = true });
	BulletRender->ChangeAnimation("BansheeBulletIdle");

	AttackCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	AttackCol->GetTransform()->SetLocalScale(Scale);
	AttackCol->SetColType(ColType::AABBBOX2D);
	
}

void BansheeBullet::Update(float _DeltaTime)
{
	DeadTime += _DeltaTime;
	SetCollison();

	MoveBullet(_DeltaTime, Dir);
	if (DeadTime > 5.0f)
	{
		Death();
		DeadTime = 0.0f;
	}

}
void BansheeBullet::SetCollison()
{
	if (AttackCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(Damege);
		Death();
	}
}