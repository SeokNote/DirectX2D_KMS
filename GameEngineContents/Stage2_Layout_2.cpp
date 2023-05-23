#include "PrecompileHeader.h"
#include "Stage2_Layout_2.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage2_Layout_2::Stage2_Layout_2()
{
}

Stage2_Layout_2::~Stage2_Layout_2()
{
}

void Stage2_Layout_2::Start()
{
	Stage2_Layout_2Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage2_Layout_2Render->SetTexture("BGLayer_1x3.png");
	Stage2_Layout_2Render->GetTransform()->SetLocalPosition({ 13939.0f,0.0f,0.0f });

	Stage2_Layout_2Render->GetTransform()->SetLocalScale(Stage2_Layout_2Scale);
	Stage2_Layout_2Render->Off();

}


void Stage2_Layout_2::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos= GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	float XMove = (CameraPos.x - Center.x) * (1.0f - 0.1f);
	float YMove = (CameraPos.y - Center.y) * (1.0f - 0.2f);
	XMove += 2250.0f;
	Stage2_Layout_2Render->GetTransform()->SetLocalPosition({ XMove,YMove+500.0f,0.0f });
	if (PlayerPos.x > 12888.0f && 15868.0f > PlayerPos.x)
	{
		Stage2_Layout_2Render->On();

	}
	else {
		Stage2_Layout_2Render->Off();
	}
	
}

