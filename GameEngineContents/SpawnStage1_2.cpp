#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "SpawnStage1_2.h"

#include "WhiteSkell.h"
#include "Ghost.h"
#include "Minotaurs.h"
#include "Banshee.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
SpawnStage1_2* SpawnStage1_2::MainSpawnStage1_2 = nullptr;
SpawnStage1_2::SpawnStage1_2()
{
}

SpawnStage1_2::~SpawnStage1_2()
{
}

void SpawnStage1_2::Start()
{
	SpawnStage1_2Render = CreateComponent<GameEngineSpriteRenderer>(1);
	SpawnStage1_2Render->SetTexture("BossSpwner.png");
	//	SpawnStage1_2Render->GetTransform()->SetLocalPosition(Door2Pos);
	SpawnStage1_2Render->GetTransform()->SetLocalScale(Scale);


	SpawnStage1_2Col = CreateComponent<GameEngineCollision>(ColOrder::Spawner);
	SpawnStage1_2Col->GetTransform()->SetLocalScale(Scale);
	//	SpawnStage1_2Col->GetTransform()->SetLocalPosition(Door2Pos);
	SpawnStage1_2Col->SetColType(ColType::AABBBOX2D);
}

void SpawnStage1_2::Update(float _DeltaTime)
{
	if (MonsterCreat == false && SpawnStage1_2Col->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		std::shared_ptr<Banshee> BansheePtr = GetLevel()->CreateActor<Banshee>(1);
		BansheePtr->GetTransform()->SetLocalPosition({ 8011.0f,207.0f,-800.0f });
		std::shared_ptr<WhiteSkell> WhiteSkellPtr1 = GetLevel()->CreateActor<WhiteSkell>(1);
		WhiteSkellPtr1->GetTransform()->SetLocalPosition({ 7951.0f,-445.0f,-800.0f });
		std::shared_ptr<WhiteSkell> WhiteSkellPtr2 = GetLevel()->CreateActor<WhiteSkell>(1);
		WhiteSkellPtr2->GetTransform()->SetLocalPosition({ 8211.0f,-445.0f,-800.0f });

		std::shared_ptr<Minotaurs> MinotaursPtr = GetLevel()->CreateActor<Minotaurs>(1);
		MinotaursPtr->GetTransform()->SetLocalPosition({ 8011.0f,-445.0f,-800.0f });

		std::shared_ptr<Ghost> GhostPtr = GetLevel()->CreateActor<Ghost>(1);
		GhostPtr->GetTransform()->SetLocalPosition({ 8211.0f,300.0f,-800.0f });

		std::shared_ptr<Ghost> GhostPtr1 = GetLevel()->CreateActor<Ghost>(1);
		GhostPtr1->GetTransform()->SetLocalPosition({ 7811.0f,154.0f,-800.0f });

		std::shared_ptr<Ghost> GhostPtr2 = GetLevel()->CreateActor<Ghost>(1);
		GhostPtr2->GetTransform()->SetLocalPosition({ 8211.0f,154.0f,-800.0f });

		std::shared_ptr<Ghost> GhostPtr3 = GetLevel()->CreateActor<Ghost>(1);
		GhostPtr3->GetTransform()->SetLocalPosition({ 7811.0f,300.0f,-800.0f });



		MonsterCreat = true;
	}
}

