#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "BelialHead.h"
#include "BelialSpawner.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
BelialSpawner* BelialSpawner::MainBelialSpawner = nullptr;
BelialSpawner::BelialSpawner() 
{
}

BelialSpawner::~BelialSpawner() 
{
}

void BelialSpawner::Start()
{
	BelialSpawnerRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialSpawnerRender->SetTexture("BossSpwner.png");
//	BelialSpawnerRender->GetTransform()->SetLocalPosition(Door2Pos);
	BelialSpawnerRender->GetTransform()->SetLocalScale(Scale);


	BelialSpawnerCol = CreateComponent<GameEngineCollision>(ColOrder::Spawner);
	BelialSpawnerCol->GetTransform()->SetLocalScale(Scale);
//	BelialSpawnerCol->GetTransform()->SetLocalPosition(Door2Pos);
	BelialSpawnerCol->SetColType(ColType::AABBBOX2D);
}

void BelialSpawner::Update(float _DeltaTime)
{
	if (BelialCreat==false && BelialSpawnerCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		static std::shared_ptr<BelialHead> BelialHeadPtr = GetLevel()->CreateActor<BelialHead>(1);
		BelialHeadPtr->GetTransform()->SetLocalPosition({ 12050.0f,-150.0f,-760.0f });
		BelialCreat = true;
	}
}

