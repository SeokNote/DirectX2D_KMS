#include "PrecompileHeader.h"
#include "TitleLevel.h"
#include "FrontCloud.h"
#include "BackCloud.h"
#include "MidCloud.h"
#include "MainLogo.h"
#include "StartButton.h"
#include "SoundButton.h"
#include "EndButton.h"
#include "Logo.h"

#include "Bird.h"
#include "TitleMouse.h"
#include "PlayStartWindow.h"
#include "ContentsEnums.h"


#include <GameEngineBase\GameEngineDebug.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "FadeEffect.h"

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}


void TitleLevel::Start()
{
	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("ContentResources");
	NewDir.Move("ContentResources");
	NewDir.Move("Texture");
	NewDir.Move("Title");

	std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


	for (size_t i = 0; i < File.size(); i++)
	{
		GameEngineTexture::Load(File[i].GetFullPath());
	}

	if (false == GameEngineInput::IsKey("ClickMouse"))
	{
		GameEngineInput::CreateKey("ClickMouse", VK_LBUTTON);

	}

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'Z');

	}
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });
	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();

	{
		std::shared_ptr<BackCloud> BackCloudPtr = CreateActorToName<BackCloud>("BackCloud");
		{
			std::shared_ptr<MidCloud> MidCloudRenderPtr_1 = CreateActorToName<MidCloud>("MidCloud");
			MidCloudRenderPtr_1->GetTransform()->SetLocalPosition({ 500,600,0 });
			std::shared_ptr<MidCloud> MidCloudRenderPtr_2 = CreateActorToName<MidCloud>("MidCloud");
			MidCloudRenderPtr_2->GetTransform()->SetLocalPosition({600,-400,0 });
			std::shared_ptr<MidCloud> MidCloudRenderPtr_3 = CreateActorToName<MidCloud>("MidCloud");
			MidCloudRenderPtr_3->GetTransform()->SetLocalPosition({ 700,100,0 });
			std::shared_ptr<MidCloud> MidCloudRenderPtr_4 = CreateActorToName<MidCloud>("MidCloud");
			MidCloudRenderPtr_4->GetTransform()->SetLocalPosition({ 0,-300,0 });
		}
		std::shared_ptr<Bird> BirdPtr = CreateActorToName<Bird>("Bird");
		std::shared_ptr<FrontCloud> FrontCloudPtr = CreateActorToName<FrontCloud>("FrontCloud");
		std::shared_ptr<MainLogo> MainLogoPtr = CreateActorToName<MainLogo>("MainLogo");
	} 
	{
		std::shared_ptr<StartButton> StartButtonPtr = CreateActorToName<StartButton>("StartButton");
		std::shared_ptr<SoundButton> SoundButtonPtr = CreateActorToName<SoundButton>("SoundButton");
		std::shared_ptr<EndButton> EndButtonPtr = CreateActorToName<EndButton>("EndButton");
	}
	{
		std::shared_ptr<Logo> LogoPtr = CreateActorToName<Logo>("Logo");

	}
	
		std::shared_ptr<TitleMouse> TitleMousePtr = CreateActor<TitleMouse>(ColOrder::PlayMouse);


}

void TitleLevel::Update(float _DeltaTime)
{

	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::ChangeLevel("PlayLevel");
	}


}

void TitleLevel::LevelChangeStart()
{
	FEffect->FadeOut();
	GameEngineLevel::LevelChangeStart();
}

void TitleLevel::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
}