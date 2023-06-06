#include "PrecompileHeader.h"
#include "Stage3_BG_1.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage3_BG_1::Stage3_BG_1()
{
}

Stage3_BG_1::~Stage3_BG_1()
{
}

void Stage3_BG_1::Start()
{
	Stage3_BG_1Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage3_BG_1Render->SetTexture("StageBGLayer3_1.png");
	Stage3_BG_1Render->GetTransform()->SetLocalScale(Stage3_BG_1Scale);
	Stage3_BG_1Render->Off();
}


void Stage3_BG_1::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	CameraPos.z = 0.0f;
	if (PlayerPos.x > 15968.0f && 20228 > PlayerPos.x) {
		Stage3_BG_1Render->On();
		Stage3_BG_1Render->GetTransform()->SetLocalPosition(CameraPos);
	}
	else {
		Stage3_BG_1Render->Off();
	}
}

//12888+ 13528