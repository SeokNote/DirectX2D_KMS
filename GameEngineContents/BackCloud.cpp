#include "PrecompileHeader.h"
#include "BackCloud.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


BackCloud::BackCloud()
{
}

BackCloud::~BackCloud()
{
}

void BackCloud::Start()
{
	BackCloudRender = CreateComponent<GameEngineSpriteRenderer>();
	BackCloudRender->SetTexture("BackCloud.png");
	BackCloudRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	BackCloudRender->GetTransform()->SetLocalScale(BackCloudScale);

	BackCloudRender_1 = CreateComponent<GameEngineSpriteRenderer>();
	BackCloudRender_1->SetTexture("BackCloud.png");
	BackCloudRender_1->GetTransform()->SetLocalPosition({ 2560.0f,0.0f,0.0f });
	BackCloudRender_1->GetTransform()->SetLocalScale(BackCloudScale);


}


void BackCloud::Update(float _DeltaTime)
{

	BackCloudRender->GetTransform()->AddLocalPosition({ -0.01f,0.f,0.f });
	if (-2560.0f >= BackCloudRender->GetTransform()->GetLocalPosition().x) {
		BackCloudRender->GetTransform()->SetLocalPosition({ 2560.0f, 0.0f, 0.0f });
	}
	BackCloudRender_1->GetTransform()->AddLocalPosition({ -0.01f,0.f,0.f });
	if (-2560.0f >= BackCloudRender_1->GetTransform()->GetLocalPosition().x) {
		BackCloudRender_1->GetTransform()->SetLocalPosition({ 2560.0f, 0.0f, 0.0f });
	}
}

