#include "PrecompileHeader.h"
#include "BelialHeadSubBG.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineBase/GameEngineRandom.h>

BelialHeadSubBG::BelialHeadSubBG() 
{
}

BelialHeadSubBG::~BelialHeadSubBG() 
{

}

std::shared_ptr<BelialHeadSubBG> BelialHeadSubBG::CreateSubBG(GameEngineLevel* _Level, const float4& _Pos)
{
	std::shared_ptr<BelialHeadSubBG> ResultSubBG = _Level->CreateActor<BelialHeadSubBG>();
	float X = GameEngineRandom::MainRandom.RandomFloat(_Pos.x- ResultSubBG->XValue, _Pos.x+ ResultSubBG->XValue);
	float Y = GameEngineRandom::MainRandom.RandomFloat(_Pos.y - ResultSubBG->YValue, _Pos.y + ResultSubBG->YValue);
	float4 Pos = { X,Y,-730.0f };
	ResultSubBG->GetTransform()->SetWorldPosition(Pos);
	return ResultSubBG;
}

void BelialHeadSubBG::Start()
{
	BelialSubBGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialSubBGRender->SetTexture("SkellBossParticle0.png");
	BelialSubBGRender->CreateAnimation({ .AnimationName = "BelialSubBG", .SpriteName = "SubBG",.FrameInter = 0.07f,.Loop = false , .ScaleToTexture = true });
	BelialSubBGRender->SetAnimationStartEvent("BelialSubBG", 8, [this]()
		{
			Death();
		});
	BelialSubBGRender->ChangeAnimation("BelialSubBG");
}


