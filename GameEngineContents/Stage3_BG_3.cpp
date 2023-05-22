#include "PrecompileHeader.h"
#include "Stage3_BG_3.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage3_BG_3::Stage3_BG_3()
{
}

Stage3_BG_3::~Stage3_BG_3()
{
}

void Stage3_BG_3::Start()
{
	Stage3_BG_3Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage3_BG_3Render->SetTexture("StageBGLayer3_3.png");
	Stage3_BG_3Render->GetTransform()->SetLocalScale(Stage3_BG_3Scale);
	Stage3_BG_3Render->Off();
}


void Stage3_BG_3::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	if (PlayerPos.x > 15968.0f && 20228 > PlayerPos.x) {
		Stage3_BG_3Render->On();
	}
	else {
		Stage3_BG_3Render->Off();
	}
	float PosSet = (CameraPos.x - Center.x) * (1.0f - 0.4f);
	PosSet += 7350.0f;
	Stage3_BG_3Render->GetTransform()->SetLocalPosition({ PosSet,-280.0f,0.0f });

}

//12888+ 13528