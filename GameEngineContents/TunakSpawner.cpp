#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "Tunak.h"
#include "TunakSpawner.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
TunakSpawner* TunakSpawner::MainTunakSpawner = nullptr;
TunakSpawner::TunakSpawner()
{
}

TunakSpawner::~TunakSpawner()
{
}

void TunakSpawner::Start()
{
	TunakSpawnerRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakSpawnerRender->SetTexture("BossSpwner.png");
	//	TunakSpawnerRender->GetTransform()->SetLocalPosition(Door2Pos);
	TunakSpawnerRender->GetTransform()->SetLocalScale(Scale);
	TunakSpawnerRender->CreateAnimation({ .AnimationName = "BossDoor_1Idle", .SpriteName = "BossDoor_1",.Loop = false,.ScaleToTexture = false, });


	TunakSpawnerCol = CreateComponent<GameEngineCollision>(ColOrder::Spawner);
	TunakSpawnerCol->GetTransform()->SetLocalScale(Scale);
	//	TunakSpawnerCol->GetTransform()->SetLocalPosition(Door2Pos);
	TunakSpawnerCol->SetColType(ColType::AABBBOX2D);
}

void TunakSpawner::Update(float _DeltaTime)
{
	if (TunakCreate == false && TunakSpawnerCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		static std::shared_ptr<Tunak> TunakPtr = GetLevel()->CreateActor<Tunak>(1);
		TunakPtr->GetTransform()->SetLocalPosition({ 15074.0f,-25.0f,-800.0f });
		Player::MainPlayer->GetData().PlusMonsterIndex(1);

		TunakCreate = true;
	}
}

