#include "PrecompileHeader.h"
#include "GroundBelt.h"
#include "BelialHand_L.h"
#include "Player.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
GroundBelt::GroundBelt()
{
}

GroundBelt::~GroundBelt()
{
}

void GroundBelt::Start()
{
	GroundBeltRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GroundBeltRender->SetTexture("GroundBelt00.png");
	GroundBeltRender->CreateAnimation({ .AnimationName = "GroundBelt", .SpriteName = "GroundBelt", .Loop = true , .ScaleToTexture = true });
	GroundBeltRender->ChangeAnimation("GroundBelt");

	GroundBeltCol = CreateComponent<GameEngineCollision>();
	GroundBeltCol->GetTransform()->SetLocalScale({ 768.0f,32.0f,0.0f });
	GroundBeltCol->GetTransform()->SetLocalPosition({ 0.0f,10.0f,0.0f });
	GroundBeltCol->SetColType(ColType::AABBBOX2D);
	GroundBeltCol->SetOrder(3666);
}

void GroundBelt::Update(float _DeltaTime)
{
	if (GroundBeltCol->Collision(3333, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
		if (PlayerPos.x > 19030)
		{
			Player::MainPlayer->GetTransform()->AddLocalPosition({ -_DeltaTime * 120.0f, 0.0f, 0.0f });
		}
	}

}

