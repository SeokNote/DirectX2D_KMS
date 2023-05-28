#include "PrecompileHeader.h"
#include "TempleNpc.h"
#include "FoodUI.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>


TempleNpc::TempleNpc()
	:IndexCount(0)
{
}

TempleNpc::~TempleNpc()
{
}

void TempleNpc::Start()
{
	if (nullptr == GameEngineSprite::Find("Fooddle"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("Npc");

		// TestAnimation.png

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("Fooddle").GetFullPath());

		// std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });
	}

	TempleNpcRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TempleNpcRender->SetTexture("NPC_Inn0.png");
	TempleNpcRender->GetTransform()->SetLocalPosition(TempleNpcPos1);
	TempleNpcRender->GetTransform()->SetLocalScale(TempleNpcScale);
	TempleNpcRender->CreateAnimation({ .AnimationName = "FoodNpcIdle", .SpriteName = "Fooddle", .ScaleToTexture = false });


	FRender = CreateComponent<GameEngineSpriteRenderer>(1);
	FRender->SetTexture("Keyboard_F.png");
	FRender->GetTransform()->SetLocalPosition(FRenderPos);
	FRender->GetTransform()->SetLocalScale(FScale);
	FRender->ColorOptionValue.MulColor.a = 0.8f;
	FRender->Off();

	TempleNpcRender->ChangeAnimation("FoodNpcIdle");

	TempleNpcCol = CreateComponent<GameEngineCollision>();
	TempleNpcCol->GetTransform()->SetLocalScale(TempleNpcScale);
	TempleNpcCol->GetTransform()->SetLocalPosition(TempleNpcPos1);
	TempleNpcCol->SetOrder(3011);
}


void TempleNpc::Update(float _DeltaTime)
{
	if (TempleNpcCol->Collision(3333, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		int asd = IndexCount;
		FRender->On();
		if (IndexCount < 1 && GameEngineInput::IsDown("NpcInteraction"))
		{
			IndexCount++;
			FoodUIPtr = GetLevel()->CreateActor<FoodUI>();
			FoodUIPtr->SetNpc(DynamicThis<TempleNpc>());
		}
		if (IndexCount == 1 && GameEngineInput::IsDown("ESC"))
		{
			IndexCount--;
			FoodUIPtr->Death();
		}
	}
	else
	{
		FRender->Off();
	}
}

