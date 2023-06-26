#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "BossDoor_1.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
BossDoor_1::BossDoor_1()
{
}

BossDoor_1::~BossDoor_1()
{
}

void BossDoor_1::Start()
{
	if (nullptr == GameEngineSprite::Find("BossDoor_1"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("Door");

		// TestAnimation.png

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("BossDoor_1").GetFullPath());

	}

	BossDoor2Render = CreateComponent<GameEngineSpriteRenderer>(1);
	BossDoor2Render->SetTexture("StageDoor2.png");
	BossDoor2Render->GetTransform()->SetLocalPosition(Door2Pos);
	BossDoor2Render->GetTransform()->SetLocalScale(Door2Scale);
	BossDoor2Render->CreateAnimation({ .AnimationName = "BossDoor_1Idle", .SpriteName = "BossDoor_1",.Loop = false,.ScaleToTexture = false, });


	//DungeonInRender->ChangeAnimation("DungeonInIdle");

	BossDoor2Col = CreateComponent<GameEngineCollision>();
	BossDoor2Col->GetTransform()->SetLocalScale(Door2Scale);
	BossDoor2Col->GetTransform()->SetLocalPosition(Door2Pos);
	BossDoor2Col->SetColType(ColType::AABBBOX2D);
	BossDoor2Col->SetOrder(3012);
}
bool BossDoorCheck_1 = false;
void BossDoor_1::Update(float _DeltaTime)
{
	if (BossDoorCheck_1 == false && BossDoor2Col->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Time += _DeltaTime;
		if (Time > 0.3)
		{
			BossDoor2Render->ChangeAnimation("BossDoor_1Idle");
			BossDoorCheck_1 = true;
			Time = 0.0f;
		}
	}
}

