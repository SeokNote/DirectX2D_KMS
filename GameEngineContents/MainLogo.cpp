#include "PrecompileHeader.h"
#include "MainLogo.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


MainLogo::MainLogo()
{
}

MainLogo::~MainLogo()
{
}

void MainLogo::Start()
{
	MainLogoRender = CreateComponent<GameEngineSpriteRenderer>();
	MainLogoRender->SetTexture("MainLogo.png");
	MainLogoRender->GetTransform()->SetLocalPosition({ 0,100,0 });
	MainLogoRender->GetTransform()->SetLocalScale(MainLogoScale);

}


void MainLogo::Update(float _DeltaTime)
{

}

