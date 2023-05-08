#include "PrecompileHeader.h"
#include "Logo.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Logo::Logo()
{
}

Logo::~Logo()
{
}

void Logo::Start()
{
	LogoRender = CreateComponent<GameEngineSpriteRenderer>();
	LogoRender->SetTexture("Copyright.png");
	LogoRender->GetTransform()->SetLocalPosition({ 0,-300,0 });
	LogoRender->GetTransform()->SetLocalScale(LogoScale);

}


void Logo::Update(float _DeltaTime)
{

}

