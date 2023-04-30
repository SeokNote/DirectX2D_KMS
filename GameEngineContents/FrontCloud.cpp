#include "PrecompileHeader.h"
#include "FrontCloud.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


FrontCloud::FrontCloud()
{
}

FrontCloud::~FrontCloud()
{
}

void FrontCloud::Start()
{
	FrontCloudRender = CreateComponent<GameEngineSpriteRenderer>();
	FrontCloudRender->SetTexture("FrontCloud.png");
	FrontCloudRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	FrontCloudRender->GetTransform()->SetLocalScale(FrontCloudScale);

}


void FrontCloud::Update(float _DeltaTime)
{

	FrontCloudRender->GetTransform()->AddLocalPosition({ -0.05f,0.f,0.f });
	//if (-640.0f>FrontCloudRender->GetTransform()->GetLocalPosition().x) {
	//	FrontCloudRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	//}
}

