#include "PrecompileHeader.h"
#include "Stage3_BG_4.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage3_BG_4::Stage3_BG_4()
{
}

Stage3_BG_4::~Stage3_BG_4()
{
}

void Stage3_BG_4::Start()
{
	Stage3_BG_4Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage3_BG_4Render->SetTexture("StageBGLayer3_4.png");
	Stage3_BG_4Render->GetTransform()->SetLocalScale(Stage3_BG_4Scale);
	Stage3_BG_4Render->Off();
}


void Stage3_BG_4::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	if (PlayerPos.x > 15968.0f && 20228 > PlayerPos.x) {
		Stage3_BG_4Render->On();
	}
	else {
		Stage3_BG_4Render->Off();
	}
	float PosSet = (CameraPos.x - Center.x) * (1.0f - 0.6f);
	PosSet += 11350.0f;
	Stage3_BG_4Render->GetTransform()->SetLocalPosition({ PosSet,-240.0f,0.0f });

}

