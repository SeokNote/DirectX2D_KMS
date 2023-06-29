#include "PrecompileHeader.h"
#include "BossDeadEffect.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineBase/GameEngineRandom.h>

BossDeadEffect::BossDeadEffect()
{
}

BossDeadEffect::~BossDeadEffect()
{

}


void BossDeadEffect::Start()
{
	DeadEffecr_0 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_0->SetTexture("Die10.png");
	DeadEffecr_0->CreateAnimation({ .AnimationName = "BossDeadEffect", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_0->ChangeAnimation("BossDeadEffect");

	DeadEffecr_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_1->SetTexture("Die10.png");
	DeadEffecr_1->CreateAnimation({ .AnimationName = "BossDeadEffect_1", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_1->ChangeAnimation("BossDeadEffect_1");

	DeadEffecr_2 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_2->SetTexture("Die10.png");
	DeadEffecr_2->CreateAnimation({ .AnimationName = "BossDeadEffect_2", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_2->ChangeAnimation("BossDeadEffect_2");

	DeadEffecr_3 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_3->SetTexture("Die10.png");
	DeadEffecr_3->CreateAnimation({ .AnimationName = "BossDeadEffect_3", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_3->ChangeAnimation("BossDeadEffect_3");

	DeadEffecr_4 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_4->SetTexture("Die10.png");
	DeadEffecr_4->CreateAnimation({ .AnimationName = "BossDeadEffect_4", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_4->ChangeAnimation("BossDeadEffect_4");
			   
	DeadEffecr_5 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_5->SetTexture("Die10.png");
	DeadEffecr_5->CreateAnimation({ .AnimationName = "BossDeadEffect_5", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_5->ChangeAnimation("BossDeadEffect_5");

	DeadEffecr_6 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_6->SetTexture("Die10.png");
	DeadEffecr_6->CreateAnimation({ .AnimationName = "BossDeadEffect_6", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_6->ChangeAnimation("BossDeadEffect_6");

	DeadEffecr_7 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_7->SetTexture("Die10.png");
	DeadEffecr_7->CreateAnimation({ .AnimationName = "BossDeadEffect_7", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_7->ChangeAnimation("BossDeadEffect_7");

	DeadEffecr_8 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_8->SetTexture("Die10.png");
	DeadEffecr_8->CreateAnimation({ .AnimationName = "BossDeadEffect_8", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_8->ChangeAnimation("BossDeadEffect_8");

	DeadEffecr_9 = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadEffecr_9->SetTexture("Die10.png");
	DeadEffecr_9->CreateAnimation({ .AnimationName = "BossDeadEffect_9", .SpriteName = "BossDead",.FrameInter = 0.03f,.Loop = false , .ScaleToTexture = true });
	DeadEffecr_9->ChangeAnimation("BossDeadEffect_9");



}

void BossDeadEffect::Update(float _DeltaTime)
{
	DeadEffecr_0->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 1),NextPos * sin(EffectDir * 1),0.0f });
	DeadEffecr_1->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 2),NextPos * sin(EffectDir * 2),0.0f });
	DeadEffecr_2->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 3),NextPos * sin(EffectDir * 3),0.0f });
	DeadEffecr_3->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 4),NextPos * sin(EffectDir * 4),0.0f });
	DeadEffecr_4->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 5),NextPos * sin(EffectDir * 5),0.0f });
	DeadEffecr_5->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 6),NextPos * sin(EffectDir * 6),0.0f });
	DeadEffecr_6->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 7),NextPos * sin(EffectDir * 7),0.0f });
	DeadEffecr_7->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 8),NextPos * sin(EffectDir * 8),0.0f });
	DeadEffecr_8->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 9),NextPos * sin(EffectDir * 9),0.0f });
	DeadEffecr_9->GetTransform()->SetLocalPosition({ NextPos * cos(EffectDir * 10),NextPos * sin(EffectDir * 10),0.0f });

	if (true == DeadEffecr_9->IsAnimationEnd())
	{
		Death();
	}
}

void BossDeadEffect::SetDir()
{
	
}


