#include "PrecompileHeader.h"
#include "Stage2_Layout_4.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage2_Layout_4::Stage2_Layout_4()
{
}

Stage2_Layout_4::~Stage2_Layout_4()
{
}

void Stage2_Layout_4::Start()
{
	Stage2_Layout_4Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage2_Layout_4Render->SetTexture("BGLayer_3.png");
	Stage2_Layout_4Render->GetTransform()->SetLocalPosition({ 13939.0f,0.0f,0.0f });

	Stage2_Layout_4Render->GetTransform()->SetLocalScale(Stage2_Layout_4Scale);
	Stage2_Layout_4Render->Off();

}


void Stage2_Layout_4::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	float XMove = (CameraPos.x - Center.x) * (1.0f - 0.7f);
	float YMove = (CameraPos.y - Center.y) * (1.0f - 0.7f);

	XMove += 10250.0f;
	Stage2_Layout_4Render->GetTransform()->SetLocalPosition({ XMove,YMove + 350.0f,0.0f });
	if (PlayerPos.x > 12888.0f && 15868.0f > PlayerPos.x)
	{
		Stage2_Layout_4Render->On();

	}
	else {
		Stage2_Layout_4Render->Off();
	}

}

