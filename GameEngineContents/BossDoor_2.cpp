#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "BossDoor_2.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
BossDoor_2::BossDoor_2()
{
}

BossDoor_2::~BossDoor_2()
{
}

void BossDoor_2::Start()
{
	if (nullptr == GameEngineSprite::Find("BossDoor"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("Door");

		// TestAnimation.png

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("BossDoor_2").GetFullPath());

	}

	BossDoor3Render = CreateComponent<GameEngineSpriteRenderer>(1);
	BossDoor3Render->SetTexture("StageDoor_0.png");
	BossDoor3Render->GetTransform()->SetLocalPosition(Door3Pos);
	BossDoor3Render->GetTransform()->SetLocalScale(Door3Scale);
	BossDoor3Render->CreateAnimation({ .AnimationName = "BossDoor2_Idle", .SpriteName = "BossDoor_2",.Loop = false,.ScaleToTexture = false, });


	BossDoor3Col = CreateComponent<GameEngineCollision>();
	BossDoor3Col->GetTransform()->SetLocalScale(Door3Scale);
	BossDoor3Col->GetTransform()->SetLocalPosition(Door3Pos);
	BossDoor3Col->SetColType(ColType::AABBBOX2D);
	BossDoor3Col->SetOrder(3012);
}
bool BossDoorCheck_2 = false;
void BossDoor_2::Update(float _DeltaTime)
{
	if (BossDoorCheck_2 == false && BossDoor3Col->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Time += _DeltaTime;
		if (Time > 0.4)
		{
			BossDoor3Render->ChangeAnimation("BossDoor2_Idle");
			BossDoorCheck_2 = true;
			Time = 0.0f;
		}
	}
}

