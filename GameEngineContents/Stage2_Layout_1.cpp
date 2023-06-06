#include "PrecompileHeader.h"
#include "Stage2_Layout_1.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Stage2_Layout_1::Stage2_Layout_1()
{
}

Stage2_Layout_1::~Stage2_Layout_1()
{
}

void Stage2_Layout_1::Start()
{
	Stage2_Layout_1Render = CreateComponent<GameEngineSpriteRenderer>();
	Stage2_Layout_1Render->SetTexture("BGLayer_0.png");

	Stage2_Layout_1Render->GetTransform()->SetLocalScale(Stage2_Layout_1Scale);

}


void Stage2_Layout_1::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	CameraPos.z = 0;
	if (PlayerPos.x > 12888.0f && 15868.0f > PlayerPos.x) {
		Stage2_Layout_1Render->GetTransform()->SetLocalPosition(CameraPos);
		Stage2_Layout_1Render->On();
	}
	else {
		Stage2_Layout_1Render->Off();
	}
}

