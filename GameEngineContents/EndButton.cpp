#include "PrecompileHeader.h"
#include "EndButton.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


EndButton::EndButton()
{
}

EndButton::~EndButton()
{
}

void EndButton::Start()
{
	EndButtonRender_1 = CreateComponent<GameEngineSpriteRenderer>();
	EndButtonRender_1->SetTexture("ExitOff_Kor.png");
	EndButtonRender_1->GetTransform()->SetLocalPosition({ 0,-200,0 });
	EndButtonRender_1->GetTransform()->SetLocalScale(EndButtonScale);
	
	EndButtonRender_2 = CreateComponent<GameEngineSpriteRenderer>();
	EndButtonRender_2->SetTexture("ExitOn_Kor.png");
	EndButtonRender_2->GetTransform()->SetLocalPosition({ 0,-200,0 });
	EndButtonRender_2->GetTransform()->SetLocalScale(EndButtonScale);
	EndButtonRender_2->Off();
}					


void EndButton::Update(float _DeltaTime)
{

}

