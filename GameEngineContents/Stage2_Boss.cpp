#include "PrecompileHeader.h"
#include "Stage2_Boss.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage2_Boss::Stage2_Boss()
{
}

Stage2_Boss::~Stage2_Boss()
{
}

void Stage2_Boss::Start()
{
	Stage2_BossRender = CreateComponent<GameEngineSpriteRenderer>();
	Stage2_BossRender->SetTexture("TunakFinal_1.png");
	Stage2_BossRender->GetTransform()->SetLocalPosition({ 15068.0f,0.0f,0.0f });
	Stage2_BossRender->GetTransform()->SetLocalScale(Stage2_BossScale);

}


void Stage2_Boss::Update(float _DeltaTime)
{

}

//14268 + 800