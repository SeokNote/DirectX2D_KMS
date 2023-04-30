#include "PrecompileHeader.h"
#include "MidCloud.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


MidCloud::MidCloud()
{
}

MidCloud::~MidCloud()
{
}

void MidCloud::Start()
{
	MidCloudRender = CreateComponent<GameEngineSpriteRenderer>();
	MidCloudRender->SetTexture("MidCloud0.png");
	MidCloudRender->GetTransform()->SetLocalPosition({ 0,100,0 });
	MidCloudRender->GetTransform()->SetLocalScale(MidCloudScale);

}


void MidCloud::Update(float _DeltaTime)
{
	MidCloudRender->GetTransform()->AddLocalPosition({ -0.01f,0.f,0.f });

}

