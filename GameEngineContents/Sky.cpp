#include "PrecompileHeader.h"
#include "Sky.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Sky::Sky()
{
}

Sky::~Sky()
{
}

void Sky::Start()
{
	SkyRender = CreateComponent<GameEngineSpriteRenderer>();
	SkyRender->SetTexture("Sky_Day.png");

	SkyRender->GetTransform()->SetLocalScale({ 1280.0f,720.0f,-1.0f });
//	SkyRender->GetTransform()->SetLocalPosition({0.0f,0.0f,0.0f});
	SkyRender->Off();
}


void Sky::Update(float _DeltaTime)
{
	float4 PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 XMove = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	XMove.z = -1;
	if (PlayerPos.x < 2560.0f && -2560 < PlayerPos.x) {
		SkyRender->GetTransform()->SetLocalPosition(XMove);
		SkyRender->On();
	}
	else {
		SkyRender->Off();
	}
}

