#include "PrecompileHeader.h"
#include "Trainning.h"

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
	

	TrainningNpcCol = CreateComponent<GameEngineCollision>();
	TrainningNpcCol->GetTransform()->SetLocalScale({ 1.0f,1.0f,1.0f });
	TrainningNpcCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
	TrainningNpcCol->SetOrder(3003);
}

void Trainning::Update(float _DeltaTime)
{


}

