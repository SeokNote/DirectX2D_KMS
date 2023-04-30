#include "PrecompileHeader.h"
#include "SoundButton.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


SoundButton::SoundButton()
{
}

SoundButton::~SoundButton()
{
}

void SoundButton::Start()
{
	SoundButtonRender_1 = CreateComponent<GameEngineSpriteRenderer>();
	SoundButtonRender_1->SetTexture("OptionOff_Kor.png");
	SoundButtonRender_1->GetTransform()->SetLocalPosition({ 0,-150,0 });
	SoundButtonRender_1->GetTransform()->SetLocalScale(SoundButtonScale);

	SoundButtonRender_2 = CreateComponent<GameEngineSpriteRenderer>();
	SoundButtonRender_2->SetTexture("OptionOn_Kor.png");
	SoundButtonRender_2->GetTransform()->SetLocalPosition({ 0,-150,0 });
	SoundButtonRender_2->GetTransform()->SetLocalScale(SoundButtonScale);
	SoundButtonRender_2->Off();
}


void SoundButton::Update(float _DeltaTime)
{

}

