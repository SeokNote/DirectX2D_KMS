#include "PrecompileHeader.h"
#include "Forest.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "MapDataBase.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Forest::Forest() 
{
}

Forest::~Forest() 
{
}

void Forest::Start()
{
	ForestRender = CreateComponent<GameEngineSpriteRenderer>();
	ForestRender->SetTexture("BG3.png");
	ForestRender->GetTransform()->SetLocalPosition({ 0.0f,-400.0f,0.0f });
	ForestRender->GetTransform()->SetLocalScale({ 5120.0f,380.0f,0.0f });
	ForestRender->Off();

}


void Forest::Update(float _DeltaTime)
{
	PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	float XMove = (CameraPos.x - Center.x) * (1.0f - 0.7f);
	float YMove = (CameraPos.y-Center.y) * (1.0f - 0.7f);

	XMove -= 400.0f;
	if (PlayerPos.x <2560.0f && -2560<PlayerPos.x) {

		ForestRender->GetTransform()->SetLocalPosition({ XMove,YMove-300.0f,0 });

		ForestRender->On();
	}
	else {
		ForestRender->Off();

	}


}

