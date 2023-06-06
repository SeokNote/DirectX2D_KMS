#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "PlayLevel.h"
#include "Player.h"
#include "PlayerStat.h"
#include "MapTabUI.h"
#include "PlayMouse.h"
#include "Forest.h"
#include "Mountain.h"
#include "Sky.h"
#include "Town.h"

#include "ShopNpc.h"
#include "BuilderNpc.h"
#include "TempleNpc.h"
#include "DungeonIn.h"
#include "Stage_1.h"
#include "Stage_2.h"
#include "Stage_3.h"
#include "Stage_4.h"
#include "BossStage_1.h"

#include "Stage2_Layout_1.h"
#include "Stage2_Layout_2.h"
#include "Stage2_Layout_3.h"
#include "Stage2_Layout_4.h"


#include "Stage2_1.h"
#include "Stage2_Boss.h"

#include "Stage3_BG_1.h"
#include "Stage3_BG_2.h"
#include "Stage3_BG_3.h"
#include "Stage3_BG_4.h"
#include "Stage3_1.h"
#include "Stage3_Boss.h"


#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include "FadeEffect.h"

//Å×½ºÆ®
PlayLevel* PlayLevel::MainPlayLevel = nullptr;

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}

void PlayLevel::Start()
{
	GameEngineDirectory NewDir;
	NewDir.MoveParentToDirectory("ContentResources");
	NewDir.Move("ContentResources");
	NewDir.Move("Texture");
	NewDir.Move("Play");

	std::vector<GameEngineFile> File = NewDir.GetAllFile({ ".Png", });


	for (size_t i = 0; i < File.size(); i++)
	{
		GameEngineTexture::Load(File[i].GetFullPath());
	}
	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("UpMove", 'W');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove_1", VK_SPACE);
		GameEngineInput::CreateKey("NpcInteraction", 'F');
		GameEngineInput::CreateKey("ESC", VK_ESCAPE);

	}
	


	if (false == GameEngineInput::IsKey("StatUI"))
	{
		GameEngineInput::CreateKey("StatUI", 'C');
		GameEngineInput::CreateKey("Inven", 'V');
		GameEngineInput::CreateKey("MapTabUI", VK_TAB);
	}
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(1, SortType::ZSort);
	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();



	{	//Town
		std::shared_ptr<Sky> SkyBG = CreateActor<Sky>(1);
		std::shared_ptr<Mountain> MountainBG = CreateActor<Mountain>(1);
		std::shared_ptr<Forest> ForestBG = CreateActor<Forest>(1);
		std::shared_ptr<Town> TownBG = CreateActor<Town>(1);
	}
	{	//	Stage_1
		std::shared_ptr<Stage_1> Stage1 = CreateActor<Stage_1>(-16);
		std::shared_ptr<Stage_2> Stage2 = CreateActor<Stage_2>(-16);
		std::shared_ptr<Stage_3> Stage3 = CreateActor<Stage_3>(-16);
		std::shared_ptr<Stage_4> Stage4 = CreateActor<Stage_4>(-16);
		std::shared_ptr<BossStage_1> Stage1_Boss = CreateActor<BossStage_1>(-16);
	}
	{	//	Stage_2
		std::shared_ptr<Stage2_Layout_1> Stage2_BG0 = CreateActor<Stage2_Layout_1>(-25);
		std::shared_ptr<Stage2_Layout_2> Stage2_BG1= CreateActor<Stage2_Layout_2>(-22);
		std::shared_ptr<Stage2_Layout_3> Stage2_BG2 = CreateActor<Stage2_Layout_3>(-21);
		std::shared_ptr<Stage2_Layout_4> Stage2_BG3 = CreateActor<Stage2_Layout_4>(-20);

		std::shared_ptr<Stage2_1> Stage1 = CreateActor<Stage2_1>(-16);
		std::shared_ptr<Stage2_Boss> BossStage_2 = CreateActor<Stage2_Boss>(-16);
	}
	{
		//	Stage_3
		std::shared_ptr<Stage3_BG_1> Stage3_BG1 = CreateActor<Stage3_BG_1>(-21);
		std::shared_ptr<Stage3_BG_2> Stage3_BG2 = CreateActor<Stage3_BG_2>(-20);
		std::shared_ptr<Stage3_BG_3> Stage3_BG3 = CreateActor<Stage3_BG_3>(-19);
		std::shared_ptr<Stage3_BG_4> Stage3_BG4 = CreateActor<Stage3_BG_4>(-18);

		std::shared_ptr<Stage3_1> Stage1= CreateActor<Stage3_1>(-16);
		std::shared_ptr<Stage3_Boss> BossStage_3 = CreateActor<Stage3_Boss>(-16);
	}
	{
		//UI
		Stat = CreateActor<PlayerStat>(-10);
		Stat->Off();
		Inventory = CreateActor<InventoryUI>(-10);
		Inventory->Off();
		MapTab = CreateActor<MapTabUI>(-10);
		MapTab->Off();
		//Cusor
		std::shared_ptr<PlayMouse> PlayMouseCusor = CreateActor<PlayMouse>(-1);

		
	}
	{
		//NPC
		std::shared_ptr<ShopNpc> ShopNpcPtr = CreateActor<ShopNpc>(1);
		std::shared_ptr<BuilderNpc> BuilderNpcPtr = CreateActor<BuilderNpc>(1);
		std::shared_ptr<TempleNpc> FoodNpcPtr = CreateActor<TempleNpc>(1);
		std::shared_ptr<DungeonIn> DungeonInPtr = CreateActor<DungeonIn>(1);


	}
	
	//	Player
	static std::shared_ptr<Player> NewPlayer = CreateActor<Player>(1);
	//NewPlayer->GetTransform()->SetLocalPosition({ 13150.0f,-39.0f,0.0f });
	NewPlayer->GetTransform()->SetLocalPosition({ -2390.0f,-500.0f,-801.0f });
	//NewPlayer->GetTransform()->SetLocalPosition({ 18948.0f,0.0f,-801.0f });

}


void PlayLevel::Update(float _DeltaTime)
{
	CameraMoveSet();	
	UICtr();
	if (GameEngineInput::IsDown("LevelChange"))
	{
		GameEngineCore::ChangeLevel("TitleLevel");
	}


}



void PlayLevel::CameraColMove(float _X,float _X1, float _Y,float _Y1)
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	GetMainCamera()->GetTransform()->SetWorldPosition({ PlayerPos.x, PlayerPos.y,-1000.0f });

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

void PlayLevel::CameraMoveSet()
{
	CurMap = Player::MainPlayer->SetMyMap(CurMap);
	if (CurMap == MyMap::Town) {
		CameraColMove(-2560.0f, 2560.0f, 720.0f, -720.0f);
	}
	if (CurMap == MyMap::Stage1_1) {
		CameraColMove(2660.0f, 3940.0f, 360.0f, -360.0f);
	}
	if (CurMap == MyMap::Stage1_2) {
		CameraColMove(4040.0f, 6600, 640, -640);
	}
	if (CurMap == MyMap::Stage1_3) {
		CameraColMove(6700.0f, 9260.0f, 640, -640);
	}
	if (CurMap == MyMap::Stage1_4) {
		CameraColMove(9360.0f, 11280, 360, -360);
	}
	if (CurMap == MyMap::Stage1_Boss) {
		CameraColMove(11380.0f, 12788.0f, 672.0f, -672.0f);
	}
	if (CurMap == MyMap::Stage2_1) {
		CameraColMove(12888.0f, 14168.0f, 360.0f, -360.0f);
	}
	if (CurMap == MyMap::Stage2_Boss) {
		CameraColMove(14268.0f, 15868.0f, 450.0f, -450.0f);
	}
	if (CurMap == MyMap::Stage3_1) {
		CameraColMove(15968.0f, 17568.0f, 360.0f, -360.0f);
	}
	if (CurMap == MyMap::Stage3_Boss) {
		CameraColMove(17668.0f, 20228.0f, 360.0f, -360.0f);
	}
}

bool CheckUICtr_0 = false;
bool CheckUICtr_1 = false;
bool CheckUICtr_2 = false;

void PlayLevel::UICtr()
{
	if (false == CheckUICtr_2 && GameEngineInput::IsDown("Inven"))
	{
		if (true == Stat->IsDeath())
		{
			Inventory = CreateActor<InventoryUI>(-10);
		}
		Inventory->On();
		CheckUICtr_2 = true;
	}
	else if (true == CheckUICtr_2 && GameEngineInput::IsDown("Inven"))
	{
		Inventory->Off();
		CheckUICtr_2 = false;
	}

	if (false == CheckUICtr_0 && GameEngineInput::IsDown("StatUI"))
	{
		if (true == Stat->IsDeath())
		{
			Stat = CreateActor<PlayerStat>(-10);
		}
		Stat->On();
		CheckUICtr_0 = true;
	}
	else if (true == CheckUICtr_0 && GameEngineInput::IsDown("StatUI"))
	{
		Stat->Off();
		CheckUICtr_0 = false;
	}
	if (CurMap == MyMap::Town) {
		if (false == CheckUICtr_1 && GameEngineInput::IsDown("MapTabUI"))
		{
			if (true == MapTab->IsDeath())
			{
				MapTab = CreateActor<MapTabUI>(-10);
				CheckUICtr_1 = true;
			}
			else 
			{
				MapTab->On();
				CheckUICtr_1 = true;
			}
		}
		else if (true == CheckUICtr_1 && GameEngineInput::IsDown("MapTabUI"))
		{
			MapTab->Off();
			CheckUICtr_1 = false;
		}
	}
}
void PlayLevel::LevelChangeStart()
{
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}

void PlayLevel::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}