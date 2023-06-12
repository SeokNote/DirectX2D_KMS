#include "PrecompileHeader.h"
#include "TempleNpc.h"
#include "FoodUI.h"
#include "FoodTextBox.h"
#include "UICountBase.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>


TempleNpc::TempleNpc()
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
		FRender->On();
		if (UICountBase::MainUICountBase->GetUICount() == 0 && GameEngineInput::IsDown("NpcInteraction"))
		{
			Player::MainPlayer->SetUICount(1);
			FoodTextBoxPtr = GetLevel()->CreateActor<FoodTextBox>();
			UICountBase::MainUICountBase->SetUICount(1);

		}
		if (UICountBase::MainUICountBase->GetUICount() == 1 && GameEngineInput::IsDown("ESC"))
		{
			FoodTextBoxPtr->Death();
			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
		}
	}
	else
	{
		FRender->Off();
	}
}

