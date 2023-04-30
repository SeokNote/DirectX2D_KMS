#include "PrecompileHeader.h"
#include "Sky.h"

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

	SkyRender->GetTransform()->SetLocalScale({ 1280.0f,720.0f,0.0f });
//	SkyRender->GetTransform()->SetLocalPosition({0.0f,0.0f,0.0f});

}


void Sky::Update(float _DeltaTime)
{
	float4 sadwa = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	sadwa.z = 0;
	SkyRender->GetTransform()->SetLocalPosition(sadwa);

}

