#include "PrecompileHeader.h"
#include "EndButton.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>


EndButton::EndButton()
{
}

EndButton::~EndButton()
{
}

void EndButton::Start()
{
	EndButtonRender_1 = CreateComponent<GameEngineSpriteRenderer>();
	EndButtonRender_1->SetTexture("ExitOff.png");
	EndButtonRender_1->GetTransform()->SetLocalPosition({ 0,-210,0 });
	EndButtonRender_1->GetTransform()->SetLocalScale(EndButtonScale);
	
	EndButtonRender_2 = CreateComponent<GameEngineSpriteRenderer>();
	EndButtonRender_2->SetTexture("ExitOn.png");
	EndButtonRender_2->GetTransform()->SetLocalPosition({ 0,-210,0 });
	EndButtonRender_2->GetTransform()->SetLocalScale(EndButtonScale);
	EndButtonRender_2->Off();

	EndButtonCollsion = CreateComponent<GameEngineCollision>();
	EndButtonCollsion->GetTransform()->SetLocalPosition({ 0,-210,0 });
	EndButtonCollsion->GetTransform()->SetLocalScale(EndButtonScale);
	EndButtonCollsion->SetOrder(2999);

}					


void EndButton::Update(float _DeltaTime)
{
	if (EndButtonCollsion->Collision(3000, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (GameEngineInput::IsDown("ClickMouse")) {
			int a = 0;
		}
		EndButtonRender_1->Off();
		EndButtonRender_2->On();
	}
	else {
		EndButtonRender_1->On();
		EndButtonRender_2->Off();
	}

}

