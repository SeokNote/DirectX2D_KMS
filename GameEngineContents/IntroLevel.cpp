#include "PrecompileHeader.h"
#include "IntroLevel.h"
#include "Intro.h"


#include <GameEngineBase\GameEngineDebug.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "FadeEffect.h"

IntroLevel::IntroLevel()
{
}

IntroLevel::~IntroLevel()
{
}


void IntroLevel::Start()
{

	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("ContentResources");
	NewDir.Move("ContentResources");
	NewDir.Move("Texture");
	NewDir.Move("Intro");

	std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


	for (size_t i = 0; i < File.size(); i++)
	{
		GameEngineTexture::Load(File[i].GetFullPath());
	}
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	std::shared_ptr<Intro> IntroPtr = CreateActor<Intro>();



}

void IntroLevel::Update(float _DeltaTime)
{
	NextTime += _DeltaTime;
	if (NextTime>3.5f)
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}

}
