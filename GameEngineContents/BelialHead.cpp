#include "PrecompileHeader.h"
#include "BelialHead.h"
#include "BelialHeadSubBG.h"
#include "BossSword.h"
#include "Player.h"
#include "BelialBullet.h"
#include "BelialBulletBase.h"
#include "BelialBulletBase_1.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
BelialHead* BelialHead::MainBelialHead = nullptr;

BelialHead::BelialHead()
{
	MainBelialHead = this;
}

BelialHead::~BelialHead()
{
}

void BelialHead::Start()
{

	BelialHeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialHeadRender->SetTexture("SkellBossIdle0.png");
	BelialHeadRender->CreateAnimation({ .AnimationName = "HeadIdle", .SpriteName = "HeadIdle", .Loop = true , .ScaleToTexture = true });
	BelialHeadRender->CreateAnimation({ .AnimationName = "HeadMove", .SpriteName = "HeadMove", .Loop = false , .ScaleToTexture = true });

	BelialBGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBGRender->SetTexture("BossSword.png");
	BelialBGRender->GetTransform()->SetWorldPosition(MainBGPos);
	BelialBGRender->GetTransform()->SetLocalScale({ 150.0f,150.0f,0.0f });
	BelialBGRender->CreateAnimation({ .AnimationName = "BelialMainBG", .SpriteName = "MainBG", .Loop = true , .ScaleToTexture = true });
	BelialBGRender->ChangeAnimation("BelialMainBG");
	ChangeState(BossHeadState::IDLE);
	//GetLevel()->CreateActor<BelialBulletBase_1>();
	GetLevel()->CreateActor<BelialBulletBase>();

}

void BelialHead::Update(float _DeltaTime)
{
	SubBGTime += _DeltaTime;
	if (SubBGTime > 0.1f)
	{
		BelialHeadSubBG::CreateSubBG(GetLevel(), MainBGPos);

		SubBGTime = 0.0f;
	}
	UpdateState(_DeltaTime);
	BelialSwordPlay(_DeltaTime);
	if (GameEngineInput::IsDown("DeBugKey"))
	{
		//BelialBulletPtr =GetLevel()->CreateActor<BelialBullet>();
		SwordIndex = 0;
		StartX = 11800.0f;
		YInvers = -100.0f;
	}
}

void BelialHead::BelialSwordPlay(float _Time)
{
	SwordTime += _Time;

	if (SwordTime > 0.3f)
	{
		SwordIndex++;
		if (SwordIndex < 6)
		{

			BossSwordPtr_0 = GetLevel()->CreateActor<BossSword>();
			BossSwordPtr_0->GetTransform()->SetWorldPosition({ StartX - YInvers ,50.0f,-801.0f });
			YInvers -= 100.0f;
		}
		SwordTime = 0.0f;
	}
}
