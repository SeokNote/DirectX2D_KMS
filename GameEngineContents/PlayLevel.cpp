#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "PlayLevel.h"
#include "Player.h"
#include "Forest.h"
#include "Mountain.h"
#include "Sky.h"
#include "Town.h"


#include "Stage_1.h"
#include "Stage_2.h"

#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>


PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}


void PlayLevel::Start()
{


	//{
	//	GameEngineDirectory NewDir;
	//	NewDir.MoveParentToDirectory("ContentResources");
	//	NewDir.Move("ContentResources");

	//	std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


	//	for (size_t i = 0; i < File.size(); i++)
	//	{
	//		GameEngineTexture::Load(File[i].GetFullPath());
	//	}

	//	int a = 0;

	//}

	if (false == GameEngineInput::IsKey("LevelChange"))
	{
		GameEngineInput::CreateKey("LevelChange", 'Z');
	
	}
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);


	//	Town
	
		std::shared_ptr<Player> NewPlayer = CreateActor<Player>(1);
		NewPlayer->GetTransform()->SetLocalPosition({ -2450,0.0f,100.0f });
	
	{
		std::shared_ptr<Sky> SkyBG = CreateActor<Sky>(-20);
	}
	{
		std::shared_ptr<Mountain> MountainBG = CreateActor<Mountain>(-19);
	}
	{
		std::shared_ptr<Forest> ForestBG = CreateActor<Forest>(-18);
	}
	{
		std::shared_ptr<Town> TownBG = CreateActor<Town>(-17);

	}

	
	std::shared_ptr<Stage_1> Stage1 = CreateActor<Stage_1>(-16);
	std::shared_ptr<Stage_2> Stage2 = CreateActor<Stage_2>(-16);

	




}


bool IsCheckM = false;
void PlayLevel::Update(float _DeltaTime)
{
	CurMap = GetMyMap(CurMap);
	//MapDataBase::MapDataPtr->SetMapName();
	//MapDataBase::MapDataPtr->GetMapName(CurMap);
	if (CurMap == MyMap::Town) {
		CameraMove(-2560.0f,2560.0f,720.0f,-720.0f);
	}
	if (CurMap == MyMap::Stage1_1) {
		CameraMove(2660.0f, 3940.0f, 360,-360);
	}
	if (CurMap == MyMap::Stage1_2) {
		CameraMove(4040.0f, 6600, 640, -640);
	}
	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}
	
}

MyMap PlayLevel::GetMyMap(MyMap _MyMap)
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	if (PlayerPos.x > -2560.0f && PlayerPos.x < 2560) {
		_MyMap = MyMap::Town;
		return _MyMap;
	}
	if (PlayerPos.x > 2560 && PlayerPos.x < 3940) {
		_MyMap = MyMap::Stage1_1;
		return _MyMap;
	}
	if (PlayerPos.x > 3940 && PlayerPos.x < 6600) {
		_MyMap = MyMap::Stage1_2;
		return _MyMap;
	}
}

void PlayLevel::CameraMove(float _X,float _X1, float _Y,float _Y1)
{
	GetMainCamera()->GetTransform()->SetWorldPosition(Player::MainPlayer->GetTransform()->GetWorldPosition());

	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 PlayerWorldPos = Player::MainPlayer->GetTransform()->GetWorldPosition();

	WindowSizeHalf = GameEngineWindow::GetScreenSize() / 2;
	float Xhalf = _X / 2;
	float Yhalf = _Y / 2;

	float LeftOutCam = _X;
	float RightOutCam = _X1;
	float UpOutCam = _Y;
	float DownOutCam = _Y1;

	float LeftOut = PlayerPos.x - WindowSizeHalf.x;
	float RightOut = PlayerPos.x + WindowSizeHalf.x;
	float UpOut = PlayerPos.y + WindowSizeHalf.y;
	float DownOut = PlayerPos.y - WindowSizeHalf.y;

	if (LeftOut < LeftOutCam)
	{
		GetMainCamera()->GetTransform()->SetWorldPosition({ LeftOutCam + WindowSizeHalf.x , GetMainCamera()->GetTransform()->GetWorldPosition().y,PlayerWorldPos.z });
	}
	if (RightOut > RightOutCam)
	{
		GetMainCamera()->GetTransform()->SetWorldPosition({ RightOutCam - WindowSizeHalf.x , GetMainCamera()->GetTransform()->GetWorldPosition().y,PlayerWorldPos.z });
	}
	
	if (DownOut < DownOutCam)
	{
		GetMainCamera()->GetTransform()->SetWorldPosition({ GetMainCamera()->GetTransform()->GetWorldPosition().x ,DownOutCam + WindowSizeHalf.y ,PlayerWorldPos.z });
	}
	if (UpOut > UpOutCam)
	{
		GetMainCamera()->GetTransform()->SetWorldPosition({ GetMainCamera()->GetTransform()->GetWorldPosition().x, UpOutCam - WindowSizeHalf.y ,PlayerWorldPos.z });
	}

}
