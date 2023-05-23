#include "PrecompileHeader.h"
#include "SoundButton.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>


SoundButton::SoundButton()
{
}

SoundButton::~SoundButton()
{
}

void SoundButton::Start()
{
	SoundButtonRender_1 = CreateComponent<GameEngineSpriteRenderer>();
	SoundButtonRender_1->SetTexture("OptionOff.png");
	SoundButtonRender_1->GetTransform()->SetLocalPosition({ -2,-155,0 });
	SoundButtonRender_1->GetTransform()->SetLocalScale(SoundButtonScale);

	SoundButtonRender_2 = CreateComponent<GameEngineSpriteRenderer>();
	SoundButtonRender_2->SetTexture("OptionOn.png");
	SoundButtonRender_2->GetTransform()->SetLocalPosition({ -2,-155,0 });
	SoundButtonRender_2->GetTransform()->SetLocalScale(SoundButtonScale);
	SoundButtonRender_2->Off();

	SoundButtonCollsion = CreateComponent<GameEngineCollision>();
	SoundButtonCollsion->GetTransform()->SetLocalPosition({ -2,-155,0 });
	SoundButtonCollsion->GetTransform()->SetLocalScale(SoundButtonScale);
	SoundButtonCollsion->SetOrder(2999);

}


void SoundButton::Update(float _DeltaTime)
{
	if (SoundButtonCollsion->Collision(3000, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (GameEngineInput::IsDown("ClickMouse")) {
			int a = 0;
		}
		SoundButtonRender_1->Off();
		SoundButtonRender_2->On();
	}
	else {
		SoundButtonRender_1->On();
		SoundButtonRender_2->Off();
	}
}

