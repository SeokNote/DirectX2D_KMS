#include "PrecompileHeader.h"
#include "BossDead.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineBase/GameEngineRandom.h>

BossDead::BossDead()
{
}

BossDead::~BossDead()
{

}

std::shared_ptr<BossDead> BossDead::CreateSubBG(GameEngineLevel* _Level, const float4& _Pos)
{
	std::shared_ptr<BossDead> ResultSubBG = _Level->CreateActor<BossDead>();
	float X = GameEngineRandom::MainRandom.RandomFloat(_Pos.x - ResultSubBG->XValue, _Pos.x + ResultSubBG->XValue);
	float Y = GameEngineRandom::MainRandom.RandomFloat(_Pos.y - ResultSubBG->YValue, _Pos.y + ResultSubBG->YValue);
	float4 Pos = { X,Y,-850.0f };
	ResultSubBG->GetTransform()->SetWorldPosition(Pos);
	return ResultSubBG;
}

void BossDead::Start()
{
	BelialSubBGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialSubBGRender->SetTexture("Die10.png");
	BelialSubBGRender->CreateAnimation({ .AnimationName = "BOSSDEAD", .SpriteName = "BOSSDEAD",.FrameInter = 0.05f,.Loop = false , .ScaleToTexture = true });
	BelialSubBGRender->SetAnimationStartEvent("BOSSDEAD", 10, [this]()
		{
			Death();
		});
	BelialSubBGRender->ChangeAnimation("BOSSDEAD");
}


