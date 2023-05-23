#include "PrecompileHeader.h"
#include "ShopNpc.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>


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

}


void ShopNpc::Update(float _DeltaTime)
{
}

