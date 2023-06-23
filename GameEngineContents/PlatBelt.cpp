#include "PrecompileHeader.h"
#include "PlatBelt.h"
#include "BelialHand_L.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
PlatBelt::PlatBelt()
{
}

PlatBelt::~PlatBelt()
{
}

void PlatBelt::Start()
{
	PlatBeltRender = CreateComponent<GameEngineSpriteRenderer>(1);
	PlatBeltRender->SetTexture("PlatformBelt00.png");
	PlatBeltRender->CreateAnimation({ .AnimationName = "PlatBelt", .SpriteName = "PlatBelt", .Loop = true , .ScaleToTexture = true });
	PlatBeltRender->ChangeAnimation("PlatBelt");

	PlatBeltRender_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	PlatBeltRender_1->SetTexture("PlatformBelt00.png");
	PlatBeltRender_1->GetTransform()->SetLocalPosition(TwoFloor);
	PlatBeltRender_1->CreateAnimation({ .AnimationName = "PlatBelt_1", .SpriteName = "PlatBelt", .Loop = true , .ScaleToTexture = true });
	PlatBeltRender_1->ChangeAnimation("PlatBelt_1");

	//PlatBeltCol = CreateComponent<GameEngineCollision>();

}

void PlatBelt::Update(float _DeltaTime)
{
	if (true == Player::MainPlayer->IsBeltCheck())
	{
		float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
		if (PlayerPos.x > 19030)
		{
			Player::MainPlayer->GetTransform()->AddLocalPosition({ -_DeltaTime * 150.0f, 0.0f, 0.0f });
		}
	}
}

