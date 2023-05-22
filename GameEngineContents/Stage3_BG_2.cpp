#include "PrecompileHeader.h"
#include "Stage3_BG_2.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage3_BG_2::Stage3_BG_2()
{
}

Stage3_BG_2::~Stage3_BG_2()
{
}

void Stage3_BG_2::Start()
{
	Stage3_BG_2Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage3_BG_2Render->SetTexture("StageBGLayer3_2.png");
	Stage3_BG_2Render->GetTransform()->SetLocalScale(Stage3_BG_2Scale);
	Stage3_BG_2Render->Off();
}


void Stage3_BG_2::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	if (PlayerPos.x > 15968.0f && 20228 > PlayerPos.x) {
		Stage3_BG_2Render->On();
	}
	else {
		Stage3_BG_2Render->Off();
	}
	float PosSet = (CameraPos.x - Center.x) * (1.0f - 0.1f);
	PosSet += 4050.0f;
	Stage3_BG_2Render->GetTransform()->SetLocalPosition({ PosSet,-200.0f,0.0f });

}

//12888+ 13528