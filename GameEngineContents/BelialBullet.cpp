#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "BelialBullet.h"
#include "BelialBulletBase.h"
#include "BelialHead.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>

BelialBullet::BelialBullet()
{
}

BelialBullet::~BelialBullet()
{

}


void BelialBullet::Start()
{
	BelialBulletRender_L = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletRender_L->SetTexture("SkellBossBullet_0.png");
	BelialBulletRender_L->CreateAnimation({ .AnimationName = "BelialBullet", .SpriteName = "BelialBullet",.FrameInter = 0.07f,.Loop = true , .ScaleToTexture = true });
	BelialBulletRender_L->ChangeAnimation("BelialBullet");
	BelialBulletRender_L->GetTransform()->SetLocalPosition(PivotPos);

	BelialBulletRender_R = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletRender_R->SetTexture("SkellBossBullet_0.png");
	BelialBulletRender_R->CreateAnimation({ .AnimationName = "BelialBullet", .SpriteName = "BelialBullet",.FrameInter = 0.07f,.Loop = true , .ScaleToTexture = true });
	BelialBulletRender_R->ChangeAnimation("BelialBullet");
	BelialBulletRender_R->GetTransform()->SetLocalPosition(PivotPos);

	BelialBulletRender_U = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletRender_U->SetTexture("SkellBossBullet_0.png");
	BelialBulletRender_U->CreateAnimation({ .AnimationName = "BelialBullet", .SpriteName = "BelialBullet",.FrameInter = 0.07f,.Loop = true , .ScaleToTexture = true });
	BelialBulletRender_U->ChangeAnimation("BelialBullet");
	BelialBulletRender_U->GetTransform()->SetLocalPosition(PivotPos);

	BelialBulletRender_D = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletRender_D->SetTexture("SkellBossBullet_0.png");
	BelialBulletRender_D->CreateAnimation({ .AnimationName = "BelialBullet", .SpriteName = "BelialBullet",.FrameInter = 0.07f,.Loop = true , .ScaleToTexture = true });
	BelialBulletRender_D->ChangeAnimation("BelialBullet");
	BelialBulletRender_D->GetTransform()->SetLocalPosition(PivotPos);

	BelialBulletCol_0 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	BelialBulletCol_0->GetTransform()->SetLocalScale(BulletColScale);
	BelialBulletCol_0->SetColType(ColType::AABBBOX2D);

	BelialBulletCol_1 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	BelialBulletCol_1->GetTransform()->SetLocalScale(BulletColScale);
	BelialBulletCol_1->SetColType(ColType::AABBBOX2D);

	BelialBulletCol_2 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	BelialBulletCol_2->GetTransform()->SetLocalScale(BulletColScale);
	BelialBulletCol_2->SetColType(ColType::AABBBOX2D);

	BelialBulletCol_3 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	BelialBulletCol_3->GetTransform()->SetLocalScale(BulletColScale);
	BelialBulletCol_3->SetColType(ColType::AABBBOX2D);

	LDir_t = BelialBulletBase::MainBelialBulletBase->getLDir();
	RDir_t = BelialBulletBase::MainBelialBulletBase->getRDir();
	UDir_t = BelialBulletBase::MainBelialBulletBase->getUDir();
	DDir_t = BelialBulletBase::MainBelialBulletBase->getDDir();
	LDir = (LDir_t - PivotPos).NormalizeReturn();
	RDir = (RDir_t - PivotPos).NormalizeReturn();
	UDir = (UDir_t - PivotPos).NormalizeReturn();
	DDir = (DDir_t - PivotPos).NormalizeReturn();
}
void BelialBullet::Update(float _DeltaTime)
{
	SetBullet(_DeltaTime);
	DeathTime += _DeltaTime;
	if (DeathTime >3.0f)
	{
		Death();
		DeathTime = 0.0f;
	}
}

void BelialBullet::SetBullet(float _DeltaTime)
{

	BelialBulletRender_L->GetTransform()->AddWorldPosition({ LDir.x *BulletSpeed* _DeltaTime,LDir.y * BulletSpeed * _DeltaTime,0.0f });
	BelialBulletRender_R->GetTransform()->AddWorldPosition({ RDir.x *BulletSpeed * _DeltaTime,RDir.y *  BulletSpeed * _DeltaTime,0.0f });
	BelialBulletRender_U->GetTransform()->AddWorldPosition({ UDir.x *BulletSpeed * _DeltaTime,UDir.y * BulletSpeed * _DeltaTime,0.0f });
	BelialBulletRender_D->GetTransform()->AddWorldPosition({ DDir.x *BulletSpeed * _DeltaTime,DDir.y * BulletSpeed * _DeltaTime,0.0f });

	BelialBulletCol_0->GetTransform()->SetLocalPosition(BelialBulletRender_L->GetTransform()->GetLocalPosition());
	BelialBulletCol_1->GetTransform()->SetLocalPosition(BelialBulletRender_R->GetTransform()->GetLocalPosition());
	BelialBulletCol_2->GetTransform()->SetLocalPosition(BelialBulletRender_U->GetTransform()->GetLocalPosition());
	BelialBulletCol_3->GetTransform()->SetLocalPosition(BelialBulletRender_D->GetTransform()->GetLocalPosition());

	if (BelialBulletCol_0->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(BulletDamage);
		int ads = Player::MainPlayer->GetData().GetPlayerHP();

	}
	if (BelialBulletCol_1->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(BulletDamage);
	}
	if (BelialBulletCol_2->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(BulletDamage);
	}
	if (BelialBulletCol_3->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(BulletDamage);
	}
}


