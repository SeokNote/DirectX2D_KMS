#include "PrecompileHeader.h"
#include "BossDoor_0.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
BossDoor_0::BossDoor_0() 
{
}

BossDoor_0::~BossDoor_0() 
{
}

void BossDoor_0::Start()
{
	if (nullptr == GameEngineSprite::Find("BossDoor_0"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("Door");

		// TestAnimation.png

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("BossDoor_0").GetFullPath());

	}

	BossDoor1Render = CreateComponent<GameEngineSpriteRenderer>(1);
	BossDoor1Render->SetTexture("StageDoor1_0.png");
	BossDoor1Render->GetTransform()->SetLocalPosition(Door1Pos);
	BossDoor1Render->GetTransform()->SetLocalScale(Door1Scale);
	BossDoor1Render->CreateAnimation({ .AnimationName = "BossDoor_0Idle", .SpriteName = "BossDoor_0",.Loop = false,.ScaleToTexture = false, });


	//DungeonInRender->ChangeAnimation("DungeonInIdle");

	BossDoor1Col = CreateComponent<GameEngineCollision>();
	BossDoor1Col->GetTransform()->SetLocalScale(Door1Scale);
	BossDoor1Col->GetTransform()->SetLocalPosition(Door1Pos);
	BossDoor1Col->SetOrder(3012);
}
bool BossDoorCheck = false;
void BossDoor_0::Update(float _DeltaTime)
{
	if (BossDoorCheck == false && BossDoor1Col->Collision(3333, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Time += _DeltaTime;
		if (Time > 0.5)
		{
			BossDoor1Render->ChangeAnimation("BossDoor_0Idle");
			BossDoorCheck = true;
			Time = 0.0f;
		}
	}
}

