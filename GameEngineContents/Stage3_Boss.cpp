#include "PrecompileHeader.h"
#include "Stage3_Boss.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage3_Boss::Stage3_Boss()
{
}

Stage3_Boss::~Stage3_Boss()
{
}

void Stage3_Boss::Start()
{
	Stage3_BossRender = CreateComponent<GameEngineSpriteRenderer>();
	Stage3_BossRender->SetTexture("Stage3_Boss.png");
	Stage3_BossRender->GetTransform()->SetLocalPosition({18948.0f,0.0f,.0f});
	Stage3_BossRender->GetTransform()->SetLocalScale(Stage3_BossScale);

}


void Stage3_Boss::Update(float _DeltaTime)
{

}

//12888+ 13528