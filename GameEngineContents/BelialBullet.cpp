#include "PrecompileHeader.h"
#include "BelialBullet.h"
#include "BelialBulletBase.h"
#include "BelialHead.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>

BelialBullet::BelialBullet()
{
}

BelialBullet::~BelialBullet()
{

}

//std::shared_ptr<BelialBullet> BelialBullet::CreateBelialBullet(GameEngineLevel* _Level, const float4& _Pos)
//{
//	//std::shared_ptr<BelialBullet> ResultSubBG = _Level->CreateActor<BelialBullet>();
//	//float X = GameEngineRandom::MainRandom.RandomFloat(_Pos.x - ResultSubBG->XValue, _Pos.x + ResultSubBG->XValue);
//	//float Y = GameEngineRandom::MainRandom.RandomFloat(_Pos.y - ResultSubBG->YValue, _Pos.y + ResultSubBG->YValue);
//	//float4 Pos = { X,Y,-730.0f };
//	//ResultSubBG->GetTransform()->SetWorldPosition(Pos);
//	//return ResultSubBG;
//}

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
	SetBullet();
	DeathTime += _DeltaTime;
	if (DeathTime >2.0f)
	{
		Death();
	}
}

void BelialBullet::SetBullet()
{
	BelialBulletRender_L->GetTransform()->AddWorldPosition({ LDir.x * 3,LDir.y * 3.0f,0.0f });
	BelialBulletRender_R->GetTransform()->AddWorldPosition({ RDir.x * 3,RDir.y * 3.0f,0.0f });
	BelialBulletRender_U->GetTransform()->AddWorldPosition({ UDir.x * 3,UDir.y * 3.0f,0.0f });
	BelialBulletRender_D->GetTransform()->AddWorldPosition({ DDir.x * 3,DDir.y * 3.0f,0.0f });
}


