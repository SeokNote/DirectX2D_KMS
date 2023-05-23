#include "PrecompileHeader.h"
#include "TempleNpc.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>


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


	TempleNpcRender->ChangeAnimation("FoodNpcIdle");

}


void TempleNpc::Update(float _DeltaTime)
{
}

