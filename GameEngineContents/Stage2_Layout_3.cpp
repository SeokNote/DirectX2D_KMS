#include "PrecompileHeader.h"
#include "Stage2_Layout_3.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage2_Layout_3::Stage2_Layout_3()
{
}

Stage2_Layout_3::~Stage2_Layout_3()
{
}

void Stage2_Layout_3::Start()
{
	Stage2_Layout_3Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage2_Layout_3Render->SetTexture("BGLayer_2.png");
	Stage2_Layout_3Render->GetTransform()->SetLocalPosition({ 13939.0f,0.0f,0.0f });

	Stage2_Layout_3Render->GetTransform()->SetLocalScale(Stage2_Layout_3Scale);
	Stage2_Layout_3Render->Off();

}


void Stage2_Layout_3::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	float XMove = (CameraPos.x - Center.x) * (1.0f - 0.4f);
	float YMove = (CameraPos.y - Center.y) * (1.0f - 0.5f);

	XMove += 6750.0f;
	Stage2_Layout_3Render->GetTransform()->SetLocalPosition({ XMove,YMove + 370.0f,0.0f });
	if (PlayerPos.x > 11380.0f && 15868.0f > PlayerPos.x)
	{
		Stage2_Layout_3Render->On();

	}
	else {
		Stage2_Layout_3Render->Off();
	}

}

