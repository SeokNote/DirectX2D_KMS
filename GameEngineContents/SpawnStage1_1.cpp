#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "SpawnStage1_1.h"

#include "WhiteSkell.h"
#include "SmallBat.h"
#include "Minotaurs.h"
#include "GiantBat.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
SpawnStage1_1* SpawnStage1_1::MainSpawnStage1_1 = nullptr;
SpawnStage1_1::SpawnStage1_1()
{
}

SpawnStage1_1::~SpawnStage1_1()
{
}

void SpawnStage1_1::Start()
{
	SpawnStage1_1Render = CreateComponent<GameEngineSpriteRenderer>(1);
	SpawnStage1_1Render->SetTexture("BossSpwner.png");
	//	SpawnStage1_1Render->GetTransform()->SetLocalPosition(Door2Pos);
	SpawnStage1_1Render->GetTransform()->SetLocalScale(Scale);
	SpawnStage1_1Render->CreateAnimation({ .AnimationName = "BossDoor_1Idle", .SpriteName = "BossDoor_1",.Loop = false,.ScaleToTexture = false, });


	SpawnStage1_1Col = CreateComponent<GameEngineCollision>(ColOrder::Spawner);
	SpawnStage1_1Col->GetTransform()->SetLocalScale(Scale);
	//	SpawnStage1_1Col->GetTransform()->SetLocalPosition(Door2Pos);
	SpawnStage1_1Col->SetColType(ColType::AABBBOX2D);
}

void SpawnStage1_1::Update(float _DeltaTime)
{
	if (BelialCreat == false && SpawnStage1_1Col->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		std::shared_ptr<WhiteSkell> WhiteSkellPtr = GetLevel()->CreateActor<WhiteSkell>(1);
		WhiteSkellPtr->GetTransform()->SetLocalPosition({ 4981.0f,-437.0f,-800.0f });

		std::shared_ptr<WhiteSkell> WhiteSkellPtr1 = GetLevel()->CreateActor<WhiteSkell>(1);
		WhiteSkellPtr1->GetTransform()->SetLocalPosition({ 5481.0f,-437.0f,-800.0f });

		std::shared_ptr<GiantBat> GiantBatPtr = GetLevel()->CreateActor<GiantBat>(1);
		GiantBatPtr->GetTransform()->SetLocalPosition({ 4981.0f,-148.0f,-790.0f });

		std::shared_ptr<Minotaurs> MinotaursPtr = GetLevel()->CreateActor<Minotaurs>(1);
		MinotaursPtr->GetTransform()->SetLocalPosition({ 5523.0f,258.0f,-800.0f });

		std::shared_ptr<SmallBat> SmallBatPtr = GetLevel()->CreateActor<SmallBat>(1);
		SmallBatPtr->GetTransform()->SetLocalPosition({ 4781.0f,-198.0f,-800.0f });

		std::shared_ptr<SmallBat> SmallBatPtr1 = GetLevel()->CreateActor<SmallBat>(1);
		SmallBatPtr1->GetTransform()->SetLocalPosition({ 5181.0f,-198.0f,-800.0f });

		std::shared_ptr<SmallBat> SmallBatPtr2 = GetLevel()->CreateActor<SmallBat>(1);
		SmallBatPtr2->GetTransform()->SetLocalPosition({ 4340.0f,417.0f,-800.0f });



		BelialCreat = true;
	}
}

