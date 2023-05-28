#include "PrecompileHeader.h"
#include "ShopNpc.h"
#include "ShopUI.h"
#include "InventoryUI.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>


ShopNpc::ShopNpc()
{
}

ShopNpc::~ShopNpc()
{
}

void ShopNpc::Start()
{
	if (nullptr == GameEngineSprite::Find("CHAc_Ground_Run"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("Npc");

		// TestAnimation.png

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("ShopIdle").GetFullPath());

		// std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });
	}

	ShopNpcRender = CreateComponent<GameEngineSpriteRenderer>(1);
	ShopNpcRender->SetTexture("NPC_Merchant0.png");
	ShopNpcRender->GetTransform()->SetLocalPosition(ShopNpcPos1);
	ShopNpcRender->GetTransform()->SetLocalScale(ShopNpcScale);
	ShopNpcRender->GetTransform()->SetLocalNegativeScaleX();
	ShopNpcRender->CreateAnimation({ .AnimationName = "ShopNpcIdle", .SpriteName = "ShopIdle", .ScaleToTexture = false });


	ShopNpcRender->ChangeAnimation("ShopNpcIdle");

	FRender = CreateComponent<GameEngineSpriteRenderer>(1);
	FRender->SetTexture("Keyboard_F.png");
	FRender->GetTransform()->SetLocalPosition(FRenderPos);
	FRender->GetTransform()->SetLocalScale(FScale);
	FRender->ColorOptionValue.MulColor.a = 0.8f;
	FRender->Off();


	ShopNpcCol = CreateComponent<GameEngineCollision>();
	ShopNpcCol->GetTransform()->SetLocalScale(ShopNpcScale);
	ShopNpcCol->GetTransform()->SetLocalPosition(ShopNpcPos1);
	ShopNpcCol->SetOrder(3011);
}


void ShopNpc::Update(float _DeltaTime)
{
	if (ShopNpcCol->Collision(3333, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		FRender->On();
		if (IndexCount < 1 && GameEngineInput::IsDown("NpcInteraction")) {
			IndexCount++;
			ShopUIPtr = GetLevel()->CreateActor<ShopUI>(1);
			InventoryUIPtr = GetLevel()->CreateActor<InventoryUI>(1);

		}
		if (IndexCount == 1 && GameEngineInput::IsDown("ESC"))
		{
			IndexCount--;
			ShopUIPtr->Death();
			InventoryUIPtr->Death();
		}

	
	}
	else
	{
		FRender->Off();
	}

}

