#include "PrecompileHeader.h"
#include "BuilderNpc.h"
#include "Trainning.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>

BuilderNpc::BuilderNpc()
{
}

BuilderNpc::~BuilderNpc()
{
}

void BuilderNpc::Start()
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

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("BuilderIdle").GetFullPath());

		// std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });
	}

	BuilderNpcRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BuilderNpcRender->SetTexture("NPC_Builder0.png");
	BuilderNpcRender->GetTransform()->SetLocalPosition(BuilderNpcPos1);
	BuilderNpcRender->GetTransform()->SetLocalScale(BuilderNpcScale);
	BuilderNpcRender->GetTransform()->SetLocalNegativeScaleX();
	BuilderNpcRender->CreateAnimation({ .AnimationName = "BuilderNpcIdle", .SpriteName = "BuilderIdle", .ScaleToTexture = false });


	BuilderNpcRender->ChangeAnimation("BuilderNpcIdle");

	FRender = CreateComponent<GameEngineSpriteRenderer>(1);
	FRender->SetTexture("Keyboard_F.png");
	FRender->GetTransform()->SetLocalPosition(FRenderPos);
	FRender->GetTransform()->SetLocalScale(FScale);
	FRender->ColorOptionValue.MulColor.a = 0.8f;
	FRender->Off();

	BuilderNpcCol = CreateComponent<GameEngineCollision>();
	BuilderNpcCol->GetTransform()->SetLocalScale(BuilderNpcScale);
	BuilderNpcCol->GetTransform()->SetLocalPosition(BuilderNpcPos1);
	BuilderNpcCol->SetOrder(3011);
}

bool Dawhagalmunok = false;
void BuilderNpc::Update(float _DeltaTime)
{

	if (BuilderNpcCol->Collision(3333, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		FRender->On();
			if (false == Dawhagalmunok && GameEngineInput::IsDown("NpcInteraction")) {
			GetLevel()->CreateActor<Trainning>(1);
			Dawhagalmunok = true;
		}
	}
	else 
	{
		FRender->Off();
	}


}

