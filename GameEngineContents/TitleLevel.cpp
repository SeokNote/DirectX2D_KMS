#include "PrecompileHeader.h"
#include "TitleLevel.h"
#include "FrontCloud.h"
#include "BackCloud.h"
#include "MidCloud.h"
#include "MainLogo.h"
#include "StartButton.h"
#include "EndButton.h"
#include "SoundButton.h"



#include <GameEngineBase\GameEngineDebug.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineBase/GameEngineDirectory.h>

TitleLevel::TitleLevel()
{
}

TitleLevel::~TitleLevel()
{
}


void TitleLevel::Start()
{


	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });
	{
		std::shared_ptr<BackCloud> BackCloudPtr = CreateActor<BackCloud>("BackCloud");
		{
			std::shared_ptr<MidCloud> MidCloudRenderPtr_1 = CreateActor<MidCloud>("MidCloud");
			MidCloudRenderPtr_1->GetTransform()->SetLocalPosition({ 500,600,0 });
			std::shared_ptr<MidCloud> MidCloudRenderPtr_2 = CreateActor<MidCloud>("MidCloud");
			MidCloudRenderPtr_2->GetTransform()->SetLocalPosition({600,-400,0 });
			std::shared_ptr<MidCloud> MidCloudRenderPtr_3 = CreateActor<MidCloud>("MidCloud");
			MidCloudRenderPtr_3->GetTransform()->SetLocalPosition({ 700,100,0 });
			std::shared_ptr<MidCloud> MidCloudRenderPtr_4 = CreateActor<MidCloud>("MidCloud");
			MidCloudRenderPtr_4->GetTransform()->SetLocalPosition({ 0,-300,0 });
		}
		std::shared_ptr<FrontCloud> FrontCloudPtr = CreateActor<FrontCloud>("FrontCloud");
		std::shared_ptr<MainLogo> MainLogoPtr = CreateActor<MainLogo>("MainLogo");
	} 
	{
		std::shared_ptr<StartButton> StartButtonPtr = CreateActor<StartButton>("StartButton");
		std::shared_ptr<SoundButton> SoundButtonPtr = CreateActor<SoundButton>("SoundButton");
		std::shared_ptr<EndButton> EndButtonPtr = CreateActor<EndButton>("EndButton");
	}




}

