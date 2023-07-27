#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "BelialLasor_R.h"
#include "BelialHand_L.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
BelialLasor_R::BelialLasor_R()
{
}

BelialLasor_R::~BelialLasor_R()
{
}

void BelialLasor_R::Start()
{
	BelialLasorRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialLasorRender->SetTexture("SkellBossLeftHandIdle0.png");
	BelialLasorRender->GetTransform()->SetLocalScale(LasorScale);
	BelialLasorRender->CreateAnimation({ .AnimationName = "LasorPattern", .SpriteName = "LasorPattern", .Loop = false , .ScaleToTexture = false });
	BelialLasorRender->ChangeAnimation("LasorPattern");


	BelialLasorCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	BelialLasorCol->GetTransform()->SetLocalScale(LasorColScale);
	BelialLasorCol->SetColType(ColType::AABBBOX2D);
}
void BelialLasor_R::Update(float _DeltaTime)
{
	CollisionCheck(_DeltaTime);
	if (BelialLasorRender->IsAnimationEnd())

	{
		Death();
	}
}
void BelialLasor_R::CollisionCheck(float _DeltaTime)
{
	if (Player::MainPlayer->GetABSValue() == false && LasorOnOff_10 == false && BelialLasorCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		LasorOnOff_10 = true;
		Player::MainPlayer->GetData().SubPlayerHP(LasorDamage);
	}

}

