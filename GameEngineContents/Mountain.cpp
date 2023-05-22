#include "PrecompileHeader.h"
#include "Mountain.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>


Mountain::Mountain()
{
}

Mountain::~Mountain()
{
}

void Mountain::Start()
{
	MountainRender = CreateComponent<GameEngineSpriteRenderer>();
	MountainRender->SetTexture("MountineBG.png");
	MountainRender->GetTransform()->SetLocalPosition({ 0.0f,-300.0f,0.0f });
	MountainRender->GetTransform()-> SetLocalScale({ 5120.0f,568.0f,0.0f });
	MountainRender->Off();
}


void Mountain::Update(float _DeltaTime)
{
	PlayerPos = Player::MainPlayer->GetPlayerPtr()->GetTransform()->GetWorldPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	float XMove = (PlayerPos.x - Center.x) * (1.0f - 0.1f);
	float YMove = (CameraPos.y - Center.y) * (1.0f - 0.1f);

	//	float asda = (Center.x - PlayerPos.x) * (1.0f - 0.8f);
	//float YMove = (CameraPos.y - Center.y) * (1.0f - 0.7f);
	if (PlayerPos.x < 2560.0f && -2560 < PlayerPos.x) {
		MountainRender->On();		

		XMove += 2000.0f;
		MountainRender->GetTransform()->SetLocalPosition({ XMove,YMove + 150.0f,0.0f });

	}
	else {
		MountainRender->Off();
	}
}

