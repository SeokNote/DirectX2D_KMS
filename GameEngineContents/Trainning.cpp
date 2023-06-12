#include "PrecompileHeader.h"
#include "Trainning.h"
#include "Player.h"
#include "TrainTextBox.h"
#include "UICountBase.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>

Trainning::Trainning()
{
}

Trainning::~Trainning()
{
}

void Trainning::Start()
{
	if (nullptr == GameEngineSprite::Find("CommanderIdle"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("Npc");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("CommanderIdle").GetFullPath());
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("TranningMan").GetFullPath());

	}

	TrainningSchoolRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TrainningSchoolRender->SetTexture("TrainingSchool.png");
	TrainningSchoolRender->GetTransform()->SetLocalPosition({-1700.0f,-417.0f,-760.f});
	TrainningSchoolRender->GetTransform()->SetLocalScale(TrainningSchoolScale);


	TrainningNpicRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TrainningNpicRender->SetTexture("NPC_Builder0.png");
	TrainningNpicRender->GetTransform()->SetLocalPosition(TrainNpcPos);
	TrainningNpicRender->GetTransform()->SetLocalScale(TrainNpcScale);
	TrainningNpicRender->CreateAnimation({ .AnimationName = "TrainningNpcIdle", .SpriteName = "CommanderIdle", .ScaleToTexture = false });

	TrainningNpicRender->ChangeAnimation("TrainningNpcIdle");


	TrainningBotRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TrainningBotRender->SetTexture("NPC_Trainee0.png");
	TrainningBotRender->GetTransform()->SetLocalPosition(TrainBotPos);
	TrainningBotRender->GetTransform()->SetLocalScale(TrainBotScale);
	TrainningBotRender->GetTransform()->SetLocalNegativeScaleX();
	TrainningBotRender->CreateAnimation({ .AnimationName = "TrainningBotIdle", .SpriteName = "TranningMan", .ScaleToTexture = false });

	TrainningBotRender->ChangeAnimation("TrainningBotIdle");
	
	TrainningBotRender_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	TrainningBotRender_1->SetTexture("NPC_Trainee0.png");
	TrainningBotRender_1->GetTransform()->SetLocalPosition(TrainBotPos_1);
	TrainningBotRender_1->GetTransform()->SetLocalScale(TrainBotScale);
	TrainningBotRender_1->GetTransform()->SetLocalNegativeScaleX();
	TrainningBotRender_1->CreateAnimation({ .AnimationName = "TrainningBotIdle", .SpriteName = "TranningMan", .ScaleToTexture = false });
					  
	TrainningBotRender_1->ChangeAnimation("TrainningBotIdle");

	FRender = CreateComponent<GameEngineSpriteRenderer>(1);
	FRender->SetTexture("Keyboard_F.png");
	FRender->GetTransform()->SetLocalPosition(FRenderPos);
	FRender->GetTransform()->SetLocalScale(FScale);
	FRender->ColorOptionValue.MulColor.a = 0.8f;
	FRender->Off();

	TrainningNpcCol = CreateComponent<GameEngineCollision>();
	TrainningNpcCol->GetTransform()->SetLocalScale(TrainNpcScale);
	TrainningNpcCol->GetTransform()->SetLocalPosition(TrainNpcPos);
	TrainningNpcCol->SetOrder(3003);
}

void Trainning::Update(float _DeltaTime)
{
	if (TrainningNpcCol->Collision(3333, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		FRender->On();
		if (UICountBase::MainUICountBase->GetUICount() == 0 && GameEngineInput::IsDown("NpcInteraction")) {
			UICountBase::MainUICountBase->SetUICount(1);
			Player::MainPlayer->SetUICount(1);
			TrainTextBoxPtr = GetLevel()->CreateActor<TrainTextBox>();
			//´É·ÂÄ¡ Âï´Â ¿¢ÅÍ »ý¼º
		}
		if (UICountBase::MainUICountBase->GetUICount() == 1 && GameEngineInput::IsDown("ESC"))
		{
			UICountBase::MainUICountBase->SetUICount(0);
			Player::MainPlayer->SetUICount(0);
			TrainTextBoxPtr->Death();
		}

	}
	else
	{
		FRender->Off();
	}


}

