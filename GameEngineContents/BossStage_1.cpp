#include "PrecompileHeader.h"
#include "BossStage_1.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


BossStage_1::BossStage_1()
{
}

BossStage_1::~BossStage_1()
{
}

void BossStage_1::Start()
{
	BossStage_1Render = CreateComponent<GameEngineSpriteRenderer>();
	BossStage_1Render->SetTexture("BossRoom_1.png");
	BossStage_1Render->GetTransform()->SetLocalPosition({ 12084.0f,0.0f,-10.0f });
	BossStage_1Render->GetTransform()->SetLocalScale(BossStage_1Scale);

}


void BossStage_1::Update(float _DeltaTime)
{

}

