#include "PrecompileHeader.h"
#include "PlayLevel.h"
#include "Player.h"
#include "Forest.h"
#include "Mountain.h"
#include "Sky.h"
#include "Town.h"

#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}


void PlayLevel::Start()
{
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");

		std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


		for (size_t i = 0; i < File.size(); i++)
		{
			GameEngineTexture::Load(File[i].GetFullPath());
		}

		int a = 0;

	}


	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	float4 CamPos = GetMainCamera()->GetTransform()->GetWorldPosition();
	float4 CamSize = GameEngineWindow::GetScreenSize();


	//CreateActor<Forest>();

	{
		std::shared_ptr<Sky> SkyBG = CreateActor<Sky>("Sky");
	}
	{
		std::shared_ptr<Mountain> MountainBG = CreateActor<Mountain>("Mountain");
	}
	{
		std::shared_ptr<Forest> ForestBG = CreateActor<Forest>("Forest");
	}
	{
		std::shared_ptr<Town> TownBG = CreateActor<Town>("Town");

	}
	{
		std::shared_ptr<Player> NewPlayer = CreateActor<Player>("Player");
	}

}



void PlayLevel::Update(float _DeltaTime)
{

}
