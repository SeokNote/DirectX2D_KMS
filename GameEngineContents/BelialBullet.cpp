#include "PrecompileHeader.h"
#include "BelialBullet.h"
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
	BelialBulletRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletRender->SetTexture("SkellBossBullet_0.png");
	BelialBulletRender->CreateAnimation({ .AnimationName = "BelialBullet", .SpriteName = "BelialBullet",.FrameInter = 0.07f,.Loop = true , .ScaleToTexture = true });
	BelialBulletRender->ChangeAnimation("BelialBullet");
	BelialBulletRender->GetTransform()->SetLocalPosition({ 12080.0f,-250.0f,-740.0f });
	BelialBulletRender->GetTransform()->SetParent(BelialHead::MainBelialHead->GetTransform());
	awdsd = BelialHead::MainBelialHead->GetBGPtr()->GetTransform()->GetWorldRightVector();
}

void BelialBullet::Update(float _DeltaTime)
{
	float4 gesfda = BelialBulletRender-> GetTransform()->GetLocalPosition();
	float4 gesfdawda = BelialBulletRender->GetTransform()->GetWorldPosition();
	BelialBulletRender->GetTransform()->AddLocalPosition({ awdsd.x+1,awdsd.y+1});
}


