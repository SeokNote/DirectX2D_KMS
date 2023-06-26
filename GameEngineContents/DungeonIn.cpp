#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "DungeonIn.h"
#include "Trainning.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "FadeEffect.h"

DungeonIn::DungeonIn()
{
}

DungeonIn::~DungeonIn()
{
}

void DungeonIn::Start()
{
	if (nullptr == GameEngineSprite::Find("CHAc_Ground_Run"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("Npc");

		// TestAnimation.png

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("DungeonIdle").GetFullPath());

	}
	FEffect = GetLevel()->GetLastTarget()->CreateEffect<FadeEffect>();

	DungeonInRender = CreateComponent<GameEngineSpriteRenderer>(1);
	DungeonInRender->SetTexture("DungeonEat28.png");
	DungeonInRender->GetTransform()->SetLocalPosition(DungeonInPos1);
	DungeonInRender->GetTransform()->SetLocalScale(DungeonInScale);
	DungeonInRender->CreateAnimation({ .AnimationName = "DungeonInIdle", .SpriteName = "DungeonIdle",.Loop = false,.ScaleToTexture = false, });


	//DungeonInRender->ChangeAnimation("DungeonInIdle");

	DungeonInCol = CreateComponent<GameEngineCollision>();
	DungeonInCol->GetTransform()->SetLocalScale(DungeonInColScale);
	DungeonInCol->GetTransform()->SetLocalPosition(DungeonInColPos);
	DungeonInCol->SetColType(ColType::AABBBOX2D);
	DungeonInCol->SetOrder(3011);
}

void DungeonIn::Update(float _DeltaTime)
{
	if (DungeonInCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->SetUICount(1);
		if (IndexCount == 0) 
		{
			IndexCount++;
			DungeonInRender->ChangeAnimation("DungeonInIdle");
		}
		size_t CurFrame = DungeonInRender->GetCurrentFrame();
		if (CurFrame > 6) {
			Value = true;
		}
	}
	if (Value == true)
	{
		CheckTime += _DeltaTime;
		Player::MainPlayer->Off();
		if(CheckTime>2.2f)
		{
			CheckTime = 0.0f;
			FEffect->FadeIn();
			Value = false;
			Value_1 = true;
		}
	}
	if (Value_1 == true)
	{
		CheckTime += _DeltaTime;
		if (CheckTime > 1.5f)
		{
			CheckTime = 0.0f;
			Player::MainPlayer->SetUICount(0);
			Player::MainPlayer->On();
			Player::MainPlayer->GetTransform()->SetLocalPosition({ 3046,-195.0f,-801.0f });
			FEffect->FadeOut();
			Value_1 = false;
		}
	}
}

