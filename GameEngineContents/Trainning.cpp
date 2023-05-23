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

	}

	TrainningSchoolRender = CreateComponent<GameEngineSpriteRenderer>();
	TrainningSchoolRender->SetTexture("TrainingSchool.png");
	TrainningSchoolRender->GetTransform()->SetLocalPosition({-1700.0f,-417.0f,0.f});
	TrainningSchoolRender->GetTransform()->SetLocalScale(TrainningSchoolScale);


	TrainningNpicRender = CreateComponent<GameEngineSpriteRenderer>();
	TrainningNpicRender->SetTexture("NPC_Builder0.png");
	TrainningNpicRender->GetTransform()->SetLocalPosition(TrainNpcPos);
	TrainningNpicRender->GetTransform()->SetLocalScale(TrainNpcScale);
	TrainningNpicRender->CreateAnimation({ .AnimationName = "TrainningNpcIdle", .SpriteName = "CommanderIdle", .ScaleToTexture = false });

	TrainningNpicRender->ChangeAnimation("TrainningNpcIdle");


	TrainningNpcCol = CreateComponent<GameEngineCollision>();
	TrainningNpcCol->GetTransform()->SetLocalScale({ 1.0f,1.0f,1.0f });
	TrainningNpcCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
	TrainningNpcCol->SetOrder(3003);
}

void Trainning::Update(float _DeltaTime)
{



}

