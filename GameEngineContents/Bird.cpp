#include "PrecompileHeader.h"
#include "Bird.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>


Bird::Bird()
{
}

Bird::~Bird()
{
}

void Bird::Start()
{
	if (nullptr == GameEngineSprite::Find("BirdIdle"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("TitleAnimation");
		
		// TestAnimation.png

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("BirdIdle").GetFullPath());

		// std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });
	}

	BirdRender_1 = CreateComponent<GameEngineSpriteRenderer>();
	BirdRender_1->SetTexture("Bird0.png");
	BirdRender_1->GetTransform()->SetLocalPosition(BirdPos1);
	BirdRender_1->CreateAnimation({ .AnimationName = "IdleBird_0", .SpriteName = "BirdIdle", .ScaleToTexture = true });
	BirdRender_1->ChangeAnimation("IdleBird_0");

	BirdRender_2 = CreateComponent<GameEngineSpriteRenderer>();
	BirdRender_2->SetTexture("Bird0.png");
	BirdRender_2->GetTransform()->SetLocalPosition(BirdPos2);
	BirdRender_2->CreateAnimation({ .AnimationName = "IdleBird_0", .SpriteName = "BirdIdle", .ScaleToTexture = true });
	BirdRender_2->ChangeAnimation("IdleBird_0");

	BirdRender_3 = CreateComponent<GameEngineSpriteRenderer>();
	BirdRender_3->SetTexture("Bird0.png");
	BirdRender_3->GetTransform()->SetLocalPosition(BirdPos3);
	BirdRender_3->CreateAnimation({ .AnimationName = "IdleBird_0", .SpriteName = "BirdIdle", .ScaleToTexture = true });
	BirdRender_3->ChangeAnimation("IdleBird_0");

	BirdRender_4 = CreateComponent<GameEngineSpriteRenderer>();
	BirdRender_4->SetTexture("Bird0.png");
	BirdRender_4->GetTransform()->SetLocalPosition(BirdPos4);
	BirdRender_4->CreateAnimation({ .AnimationName = "IdleBird_0", .SpriteName = "BirdIdle", .ScaleToTexture = true });
	BirdRender_4->ChangeAnimation("IdleBird_0");

	BirdRender_5 = CreateComponent<GameEngineSpriteRenderer>();
	BirdRender_5->SetTexture("Bird0.png");
	BirdRender_5->GetTransform()->SetLocalPosition(BirdPos5);
	BirdRender_5->CreateAnimation({ .AnimationName = "IdleBird_0", .SpriteName = "BirdIdle", .ScaleToTexture = true });
	BirdRender_5->ChangeAnimation("IdleBird_0");

	BirdRender_6 = CreateComponent<GameEngineSpriteRenderer>();
	BirdRender_6->SetTexture("Bird0.png");
	BirdRender_6->GetTransform()->SetLocalPosition(BirdPos6);
	BirdRender_6->CreateAnimation({ .AnimationName = "IdleBird_0", .SpriteName = "BirdIdle", .ScaleToTexture = true });
	BirdRender_6->ChangeAnimation("IdleBird_0");

}


void Bird::Update(float _DeltaTime)
{
	BirdRender_1->GetTransform()->AddLocalPosition({ 0.1f,0.f,0.f });
	if (OverWindow < BirdRender_1->GetTransform()->GetLocalPosition().x) 
	{
		BirdRender_1->GetTransform()->SetLocalPosition(BirdPos1);
	}
	BirdRender_2->GetTransform()->AddLocalPosition({ 0.1f,0.f,0.f });
	if (OverWindow < BirdRender_2->GetTransform()->GetLocalPosition().x)
	{
		BirdRender_2->GetTransform()->SetLocalPosition(BirdPos2);
	}
	BirdRender_3->GetTransform()->AddLocalPosition({ 0.1f,0.f,0.f });
	if (OverWindow < BirdRender_3->GetTransform()->GetLocalPosition().x)
	{
		BirdRender_3->GetTransform()->SetLocalPosition(BirdPos3);
	}
	BirdRender_4->GetTransform()->AddLocalPosition({ 0.1f,0.f,0.f });
	if (OverWindow < BirdRender_4->GetTransform()->GetLocalPosition().x)
	{
		BirdRender_4->GetTransform()->SetLocalPosition(BirdPos4);
	}
	BirdRender_5->GetTransform()->AddLocalPosition({ 0.1f,0.f,0.f });
	if (OverWindow < BirdRender_5->GetTransform()->GetLocalPosition().x)
	{
		BirdRender_5->GetTransform()->SetLocalPosition(BirdPos5);
	}
	BirdRender_6->GetTransform()->AddLocalPosition({ 0.1f,0.f,0.f });
	if (OverWindow < BirdRender_6->GetTransform()->GetLocalPosition().x)
	{
		BirdRender_6->GetTransform()->SetLocalPosition(BirdPos6);
	}

}

