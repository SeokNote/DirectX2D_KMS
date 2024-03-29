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
#include "DashBar.h"
#include "CoinBar.h"
#include "FoodBar.h"
#include "PlayerHPbar.h"
#include "WeaponSwichUI.h"
#include "ShopNpc.h"
#include "BuilderNpc.h"
#include "TempleNpc.h"
#include "DungeonIn.h"
#include "UICountBase.h"
#include "Candle.h"
#include "StandCandle.h"
#include "GreatWeapon.h"
#include "Door.h"
#include "BossDoor_0.h"
#include "BossDoor_1.h"
#include "BossDoor_2.h"
#include "BelialSpawner.h"
#include "TunakSpawner.h"
#include "SpawnStage1_1.h"
#include "SpawnStage1_2.h"
#include "Potal.h"
#include "AbilityUI.h"
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
#include "GroundBelt.h"
#include "PlatBelt.h"
#include "MyMapUI.h"
#include <GameEnginePlatform/GameEngineSound.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineTexture.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCore.h>
#include <GameEngineCore/GameEngineCoreWindow.h>
#include <GameEngineCore/GameEngineFont.h>
#include "FadeEffect.h"
#include "ContentButton.h"
#include "PointLightEffect.h"
//테스트
#include "BossSword.h"
#include "BelialHeadSubBG.h"
#include "TunakBullet.h"
#include "BelialHead.h"
#include "Tunak.h"
#include "GoblinBomb.h"
#include "Ghost.h"
#include "WhiteSkell.h"
#include "SmallBat.h"
#include "Minotaurs.h"
#include "GiantBat.h"
#include "Banshee.h"
GameEngineSoundPlayer PlayLevel::BGM;
PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}



void PlayLevel::Start()
{
	//폰트 로드
	GameEngineFont::Load("Aa카시오페아");
	GameEngineFont::Load("8-bit Operator+ SC");
	GameEngineFont::Load("8-bit Operator+");
	
	//플레이어로드
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
	//플레이어 애니메이션 
	
	GameEngineDirectory PlayerDir;
	PlayerDir.MoveParentToDirectory("ContentResources");
	PlayerDir.Move("ContentResources");
	PlayerDir.Move("Animation");
	PlayerDir.Move("MainLevelAnimation");
	PlayerDir.Move("MainPlayer");
	GameEngineSprite::LoadFolder(PlayerDir.GetPlusFileName("PlayerDead").GetFullPath());
	GameEngineSprite::LoadFolder(PlayerDir.GetPlusFileName("PlayerIdle").GetFullPath());
	GameEngineSprite::LoadFolder(PlayerDir.GetPlusFileName("PlayerJump").GetFullPath());
	GameEngineSprite::LoadFolder(PlayerDir.GetPlusFileName("PlayerRun").GetFullPath());
	GameEngineSprite::LoadFolder(PlayerDir.GetPlusFileName("PlayerJumpAni").GetFullPath());
	GameEngineSprite::LoadFolder(PlayerDir.GetPlusFileName("PlayerWalkAni").GetFullPath());
	GameEngineSprite::LoadFolder(PlayerDir.GetPlusFileName("PlayerHp").GetFullPath());
	//오브젝트 애니메이션
	GameEngineDirectory ObjectDir;
	ObjectDir.MoveParentToDirectory("ContentResources");
	ObjectDir.Move("ContentResources");
	ObjectDir.Move("Animation");
	ObjectDir.Move("MainLevelAnimation");
	ObjectDir.Move("Object");
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("CandleIdle").GetFullPath());
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("FoodAni").GetFullPath());
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("CoinIdle").GetFullPath());
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("StandCandleIdle").GetFullPath());
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("SpownAni").GetFullPath());
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("CosmosSkill").GetFullPath());
	ObjectDir.Move("SteleAni");
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("SteleClose").GetFullPath());
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("SteleIdle").GetFullPath());
	GameEngineSprite::LoadFolder(ObjectDir.GetPlusFileName("SteleOpen").GetFullPath());
	//무기 애니메이션

	GameEngineDirectory WeaponDir;
	WeaponDir.MoveParentToDirectory("ContentResources");
	WeaponDir.Move("ContentResources");
	WeaponDir.Move("Animation");
	WeaponDir.Move("MainLevelAnimation");
	WeaponDir.Move("WeaponAni");
	GameEngineSprite::LoadFolder(WeaponDir.GetPlusFileName("GreatSwordAni").GetFullPath());
	WeaponDir.Move("SpaceSword");
	GameEngineSprite::LoadFolder(WeaponDir.GetPlusFileName("SpaceSwordIdle").GetFullPath());
	GameEngineSprite::LoadFolder(WeaponDir.GetPlusFileName("SpaceSwordSwing").GetFullPath());


	//벨리알 무기 애니메이션
	GameEngineDirectory BelialSwordDir;
	BelialSwordDir.MoveParentToDirectory("ContentResources");
	BelialSwordDir.Move("ContentResources");
	BelialSwordDir.Move("Animation");
	BelialSwordDir.Move("MainLevelAnimation");
	BelialSwordDir.Move("Boss");
	GameEngineSprite::LoadFolder(BelialSwordDir.GetPlusFileName("BOSSDEAD").GetFullPath());
	BelialSwordDir.Move("Belial");
	BelialSwordDir.Move("BossSword");

	GameEngineSprite::LoadFolder(BelialSwordDir.GetPlusFileName("BossSwordAtteck").GetFullPath());
	GameEngineSprite::LoadFolder(BelialSwordDir.GetPlusFileName("BossSwordCharge").GetFullPath());
	GameEngineSprite::LoadFolder(BelialSwordDir.GetPlusFileName("BossSwordDead").GetFullPath());
	GameEngineSprite::LoadFolder(BelialSwordDir.GetPlusFileName("BossSwordFx").GetFullPath());
	GameEngineSprite::LoadFolder(BelialSwordDir.GetPlusFileName("BossSwordIdle").GetFullPath());
	//벨리알 애니메이션
	GameEngineDirectory BelialDir;
	BelialDir.MoveParentToDirectory("ContentResources");
	BelialDir.Move("ContentResources");
	BelialDir.Move("Animation");
	BelialDir.Move("MainLevelAnimation");
	BelialDir.Move("Boss");
	BelialDir.Move("Belial");
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("BelialBeforDead").GetFullPath());
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("HeadMove").GetFullPath());
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("BelialDead").GetFullPath());
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("HandIdle").GetFullPath());
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("HandLasor").GetFullPath());
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("LasorPattern").GetFullPath());
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("HeadIdle").GetFullPath());
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("BelialBullet").GetFullPath());
	BelialDir.Move("BelialBG");
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("MainBG").GetFullPath());
	GameEngineSprite::LoadFolder(BelialDir.GetPlusFileName("SubBG").GetFullPath());

	//투낙 애니메이션
	GameEngineDirectory TunakDir;
	TunakDir.MoveParentToDirectory("ContentResources");
	TunakDir.Move("ContentResources");
	TunakDir.Move("Animation");
	TunakDir.Move("MainLevelAnimation");
	TunakDir.Move("Boss");
	TunakDir.Move("Tunak");
	
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakIdle").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakJumpAttack").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakOverPower").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("GroundBomb").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("BombBG").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakDoubleAttack").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakShout").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakBombCall").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakDust").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakDust_1").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("WaveEffect").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakDead").GetFullPath());
	TunakDir.Move("Spike");
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakSpike").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakSpikeReady").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakSpikeIdle").GetFullPath());
	TunakDir.MoveParentToDirectory("Tunak");
	TunakDir.Move("Tunak");
	TunakDir.Move("TunakShoulderTackle");
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakShoulderTakleReady").GetFullPath());
	GameEngineSprite::LoadFolder(TunakDir.GetPlusFileName("TunakShoulderTakleStart").GetFullPath());
	
	//투낙 총알
	GameEngineDirectory TunakBulletDir;
	TunakBulletDir.MoveParentToDirectory("ContentResources");
	TunakBulletDir.Move("ContentResources");
	TunakBulletDir.Move("Animation");
	TunakBulletDir.Move("MainLevelAnimation");
	TunakBulletDir.Move("Boss");
	TunakBulletDir.Move("Tunak");
	TunakBulletDir.Move("TunakBullet");
	 
	GameEngineSprite::LoadFolder(TunakBulletDir.GetPlusFileName("TunakBulletIIldle").GetFullPath());
	GameEngineSprite::LoadFolder(TunakBulletDir.GetPlusFileName("TunakBulletBG").GetFullPath());
	GameEngineSprite::LoadFolder(TunakBulletDir.GetPlusFileName("TunakBulletEffect").GetFullPath());
	GameEngineSprite::LoadFolder(TunakBulletDir.GetPlusFileName("GoblinBombIdle").GetFullPath());
	GameEngineSprite::LoadFolder(TunakBulletDir.GetPlusFileName("GoblinBombEffect").GetFullPath());

	GameEngineDirectory SlimeMakeDir;
	SlimeMakeDir.MoveParentToDirectory("ContentResources");
	SlimeMakeDir.Move("ContentResources");
	SlimeMakeDir.Move("Animation");
	SlimeMakeDir.Move("MainLevelAnimation");
	SlimeMakeDir.Move("Boss");
	SlimeMakeDir.Move("SlimeMaker");
	SlimeMakeDir.Move("Belt");

	GameEngineSprite::LoadFolder(SlimeMakeDir.GetPlusFileName("PlatBelt").GetFullPath());
	GameEngineSprite::LoadFolder(SlimeMakeDir.GetPlusFileName("GroundBelt").GetFullPath());

	//몬스터 로드
	GameEngineDirectory MonsterDir;
	MonsterDir.MoveParentToDirectory("ContentResources");
	MonsterDir.Move("ContentResources");
	MonsterDir.Move("Animation");
	MonsterDir.Move("MainLevelAnimation");
	MonsterDir.Move("Monster");
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("SmallBat").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("FireBat").GetFullPath());

	MonsterDir.Move("WhiteSkell");
	//화이트스켈
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("WhiteSkellAttack").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("WhiteSkellIdle").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("WhiteSkellMove").GetFullPath());
	//미노타우르스
	MonsterDir.MoveParentToDirectory("Monster");
	MonsterDir.Move("Monster");
	MonsterDir.Move("Minotaurs");
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("MinotaursAttack").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("MinotaursIdle").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("MinotaursTakcle").GetFullPath());
	MonsterDir.MoveParentToDirectory("Monster");
	MonsterDir.Move("Monster");
	MonsterDir.Move("Ghost");
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("GhostAttack").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("GhostIdle").GetFullPath());
	MonsterDir.MoveParentToDirectory("Monster");
	MonsterDir.Move("Monster");
	MonsterDir.Move("GiantBat");
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("GiantBatAttack").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("GiantBatIdle").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("GiantBatDead").GetFullPath());
	MonsterDir.Move("BatBullet");
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("BatBulletIdle").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("BatBulletDie").GetFullPath());
	MonsterDir.MoveParentToDirectory("Monster");
	MonsterDir.Move("Monster");
	MonsterDir.Move("Banshee");
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("BansheeAttack").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("BansheeIdle").GetFullPath());
	MonsterDir.Move("BansheeBullet");
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("BansheeBulletHit").GetFullPath());
	GameEngineSprite::LoadFolder(MonsterDir.GetPlusFileName("BansheeBulletIdle").GetFullPath());

	if (false == GameEngineInput::IsKey("LeftMove"))
	{
		GameEngineInput::CreateKey("LeftMove", 'A');
		GameEngineInput::CreateKey("RightMove", 'D');
		GameEngineInput::CreateKey("UpMove", 'W');
		GameEngineInput::CreateKey("DownMove", 'S');
		GameEngineInput::CreateKey("UpMove_1", VK_SPACE);
		GameEngineInput::CreateKey("NpcInteraction", 'F');
		GameEngineInput::CreateKey("ESC", VK_ESCAPE);
		GameEngineInput::CreateKey("ATTACK", VK_LBUTTON);
		GameEngineInput::CreateKey("DEBUGMODE", 'U');
		GameEngineInput::CreateKey("DASH", VK_RBUTTON);
		GameEngineInput::CreateKey("DeBugKey", 'Q');
		GameEngineInput::CreateKey("WEAPONSWICH", VK_OEM_3);
		GameEngineInput::CreateKey("Skill", 'Q');
		GameEngineInput::CreateKey("LevelUP", VK_F1);
		GameEngineInput::CreateKey("HPSUB", VK_F2);
		GameEngineInput::CreateKey("ABS", VK_F3);
		GameEngineInput::CreateKey("MovePlayer", VK_F9);

	}
	//

	if (false == GameEngineInput::IsKey("StatUI"))
	{
		GameEngineInput::CreateKey("StatUI", 'C');
		GameEngineInput::CreateKey("Inven", 'V');
		GameEngineInput::CreateKey("MapTabUI", VK_TAB);
	}
	GetMainCamera()->SetProjectionType(CameraType::Orthogonal);
	GetMainCamera()->SetSortType(1, SortType::ZSort);
	GetMainCamera()->GetCamTarget()->DepthSettingOff();
	FEffect = GetLastTarget()->CreateEffect<FadeEffect>();

	std::shared_ptr<UICountBase> UICountBasePtr = CreateActor<UICountBase>(1);
	//	Player
	static std::shared_ptr<Player> NewPlayer = CreateActor<Player>(1);
	//NewPlayer->GetTransform()->SetLocalPosition({ 11438.0f, -480.0f, -801.0f });

	//NewPlayer->GetTransform()->SetLocalPosition({ 14504.0f,-194.0f,-801.0f });
	NewPlayer->GetTransform()->SetLocalPosition({ -2390.0f,-500.0f,-801.0f });
	//NewPlayer->GetTransform()->SetLocalPosition({ 9925.0f,-254.0f,-801.0f });

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
		//UI
		std::shared_ptr<PlayerHPbar> PlayerHPbarPtr = CreateActor<PlayerHPbar>(-10);
		PlayerHPbarPtr->GetTransform()->SetLocalPosition({ -482.0f, 318.0f,0.0f });
		std::shared_ptr<FoodBar> FoodBarPtr = CreateActor<FoodBar>(-10);
		std::shared_ptr<CoinBar> CoinBarPtr = CreateActor<CoinBar>(-10);
		std::shared_ptr<DashBar> DashBarPtr = CreateActor<DashBar>(-10);
		std::shared_ptr<WeaponSwichUI> WeaponSwichUIPtr = CreateActor<WeaponSwichUI>(-10);
		static std::shared_ptr<AbilityUI> AbilityUIPtr = CreateActor<AbilityUI>(-10);
		AbilityUIPtr->Off();
		Stat = CreateActor<PlayerStat>(-10);
		Stat->Off();
		Inventory = CreateActor<InventoryUI>(-10);
		Inventory->InventoryOff();
		MapTab = CreateActor<MapTabUI>(-10);
		MapTab->Off();
		//Cusor
		std::shared_ptr<PlayMouse> PlayMouseCusor = CreateActor<PlayMouse>(-1);

		
	}
	SetUI();
	SetMap();

	



//	보스 스포너
	static std::shared_ptr<BelialSpawner> BelialSpawnerPtr = CreateActor<BelialSpawner>(1);
	BelialSpawnerPtr->GetTransform()->SetLocalPosition({ 12050.0f,-350.0f,-760.0f });
	static std::shared_ptr<TunakSpawner> TunakSpawnerPtr = CreateActor<TunakSpawner>(1);
	TunakSpawnerPtr->GetTransform()->SetLocalPosition({ 14874.0f,-205.0f,-800.0f });
	static std::shared_ptr<SpawnStage1_1> SpawnStage1_1Ptr = CreateActor<SpawnStage1_1>(1);
	SpawnStage1_1Ptr->GetTransform()->SetLocalPosition({ 4353.0f,-468.0f,-800.0f });
	//테스트
	static std::shared_ptr<SpawnStage1_2> SpawnStage1_2Ptr = CreateActor<SpawnStage1_2>(1);
	SpawnStage1_2Ptr->GetTransform()->SetLocalPosition({ 8011.0f,254.0f,-800.0f });



	std::shared_ptr<MyMapUI> text1 = CreateActor<MyMapUI>();
	text1->SetMapText("마을");

}

void PlayLevel::SetMap()
{
	{
		//Door
		//Stage1-1
		std::shared_ptr<Door> DoorPtr = CreateActor<Door>(1);
		DoorPtr->SetDoorPos({ 3916.0f,-167.0f,0.0f });
		DoorPtr->SetNextPos({ 4120.0f, -468.0f, -801.0f });

		//Stage1-2
		std::shared_ptr<Door> DoorPtr_0 = CreateActor<Door>(1);
		DoorPtr_0->SetDoorPos({ 6372.0f,-608.0f,0.0f });
		DoorPtr_0->SetNextPos({ 8016.0f, 537.0f, -801.0f });
		DoorPtr_0->SetDoorScale({ 230.0f,50.0f,0.0f });
		//Stage1-3
		std::shared_ptr<Door> DoorPtr_1 = CreateActor<Door>(1);
		DoorPtr_1->SetDoorPos({ 6872.0f,-481.0f,0.0f });
		DoorPtr_1->SetNextPos({ 11225.0f, -254.0f, -801.0f });
		//Stage1-4
		std::shared_ptr<Door> DoorPtr_2 = CreateActor<Door>(1);
		DoorPtr_2->SetDoorPos({ 9383.0f,-252.0f,0.0f });
		DoorPtr_2->SetNextPos({ 11438.0f, -480.0f, -801.0f });
		//Stage1 Boss
		std::shared_ptr<Door> DoorPtr_3 = CreateActor<Door>(1);
		DoorPtr_3->SetDoorPos({ 12763.0f,-480.0f,0.0f });
		DoorPtr_3->SetNextPos({ 13267.0f,-132.0f, -801.0f });
		//Stage2-1
		std::shared_ptr<Door> DoorPtr_4 = CreateActor<Door>(1);
		DoorPtr_4->SetDoorPos({ 14143.0f,-132.0f,0.0f });
		DoorPtr_4->SetNextPos({ 14304.0f,-194.0f, -801.0f });
		//Stage2 Boss
		std::shared_ptr<Door> DoorPtr_5 = CreateActor<Door>(1);
		DoorPtr_5->SetDoorPos({ 15844.0f,-192.0f,0.0f });
		DoorPtr_5->SetNextPos({ 16314.0f,-178.0f, -801.0f });
		//Stage3-1
		std::shared_ptr<Door> DoorPtr_6 = CreateActor<Door>(1);
		DoorPtr_6->SetDoorPos({ 17544.0f,-178.0f,0.0f });
		DoorPtr_6->SetNextPos({ 17790.0f,-67.0f, -801.0f });
	}
	{
		//bossDoor
		std::shared_ptr<BossDoor_0> BossDoor1Ptr = CreateActor<BossDoor_0>(1);
		std::shared_ptr<BossDoor_1> BossDoor2Ptr = CreateActor<BossDoor_1>(1);
		std::shared_ptr<BossDoor_2> BossDoor3Ptr = CreateActor<BossDoor_2>(1);

	}

}
void PlayLevel::SetUI()
{
	std::shared_ptr<ShopNpc> ShopNpcPtr = CreateActor<ShopNpc>(1);
	std::shared_ptr<BuilderNpc> BuilderNpcPtr = CreateActor<BuilderNpc>(1);
	std::shared_ptr<TempleNpc> FoodNpcPtr = CreateActor<TempleNpc>(1);
	std::shared_ptr<DungeonIn> DungeonInPtr = CreateActor<DungeonIn>(1);
}

void PlayLevel::Update(float _DeltaTime)
{
	static float Time = 0.0f;

	Time += _DeltaTime;

	Frame++;
	CameraMoveSet();
	SetBGM();
	UICtr();

	if (1.0f <= Time)
	{
		UINT FRAME = static_cast<UINT>(Frame / Time);


		if (80 >= FRAME)
		{
			int a = 0;
		}

		if (70 >= FRAME)
		{
			int a = 0;
		}


		if (60 >= FRAME)
		{
			int a = 0;
		} 


		Frame = 0;
		Time = 0.0f;

	}


	if (GameEngineInput::IsDown("DEBUGMODE"))
	{
		IsDebugSwitch();
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
		if (false == Player::MainPlayer->GetData().GetBelialCtrl())
		{
			CameraColMove(11380.0f, 12788.0f, 672.0f, -672.0f);
		}
	}
	if (CurMap == MyMap::Stage2_1) {
		CameraColMove(12888.0f, 14168.0f, 360.0f, -360.0f);
	}
	if (CurMap == MyMap::Stage2_Boss) {
		if (false == Player::MainPlayer->GetData().GetTunakCtrl())
		{
			CameraColMove(14268.0f, 15868.0f, 450.0f, -450.0f);
		}
	}
	if (CurMap == MyMap::Stage3_1) {
		CameraColMove(15968.0f, 17568.0f, 360.0f, -360.0f);
	}
	if (CurMap == MyMap::Stage3_Boss) {
		CameraColMove(17668.0f, 20228.0f, 360.0f, -360.0f);
	}
}



void PlayLevel::UICtr()
{
	if (false == CheckUICtr_2 && GameEngineInput::IsDown("Inven"))
	{
		if (true == Stat->IsDeath())
		{
			Inventory = CreateActor<InventoryUI>(-10);
		}
		GameEngineSound::Play("OpenInventory.wav");
		Inventory->InventoryOn();
		CheckUICtr_2 = true;
	}
	else if (true == CheckUICtr_2 && GameEngineInput::IsDown("Inven"))
	{
		
		GameEngineSound::Play("OpenInventory.wav");
		Inventory->InventoryOff();
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
void PlayLevel::SetBGM()
{
	PrevMap = CurMap;
	CurMap = NextMap;
	NextMap = PrevMap;
	if (CurMap != NextMap)
	{

		switch (NextMap)
		{
		case MyMap::None:
			break;
		case MyMap::Town:

			BGM.SetMute(true);
			BGM = GameEngineSound::Play("0.Town.wav");
			BGM.SetLoop(-1);
			PrevMap = CurMap;
			break;
		case MyMap::Stage1_1:
			BelialText = CreateActor<MyMapUI>();
			BelialText->SetMapText("1층 : 벨리알의 관문");
			CandlePtr_0 = CreateActor<Candle>(1);
			CandlePtr_0->GetTransform()->SetLocalPosition({ 3409.f,-106.f,-200.0f });
			CandlePtr_0->SetCandleColor(float4::Red);
			CandlePtr_0->SetMyMap(MyMap::Stage1_1);
			PotalPtr0 = CreateActor<Potal>(1);
			PotalPtr0->GetPotalRender()->GetTransform()->SetLocalPosition({ -20.f,-50.0f,0.0f });
			PotalPtr0->GetPotalCol()->GetTransform()->SetLocalPosition({ -20.f,30.0f,0.0f });
			PotalPtr0->GetTransform()->SetLocalPosition({ 3916.0f,-167.0f,0.0f });
			PotalPtr0->GetTransform()->SetWorldRotation({ 0.0f,0.0f,-90.0f });
			PotalPtr0->SetPTCValue(float4::Left, float4(20.0f, 120.0f, 0.0f), 10.0f, 0.0f);
			BGM.SetMute(true);
			BGM = GameEngineSound::Play("1.JailField.wav");
			BGM.SetLoop(-1);
			PrevMap = CurMap;
			break;
		case MyMap::Stage1_2:
			PotalPtr1 = CreateActor<Potal>(1);
			PotalPtr1->GetTransform()->SetLocalPosition({ 4063.0f,-468.0f,-900.0f });
			PotalPtr1->GetPotalRender()->GetTransform()->SetLocalPosition({ 50.0f,56.0f,0.0f });
			PotalPtr1->GetPotalRender()->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-270.0f });
			PotalPtr1->GetPotalCol()->GetTransform()->SetLocalPosition({ 50.0f,56.0f,0.0f });
			PotalPtr1->GetPotalCol()->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-270.0f });
			PotalPtr1->SetPTCValue(float4::Right, float4(20.0f, 110.0f, 0.0f), 10.0f, 60.0f);
			PotalPtr2 = CreateActor<Potal>(1);
			PotalPtr2->GetTransform()->SetLocalPosition({ 6372.0f,-558.0f,-900.0f });
			PotalPtr2->GetPotalRender()->GetTransform()->SetLocalPosition({ 30.0f,0.0f,0.0f });
			PotalPtr2->GetPotalRender()->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-180.0f });
			PotalPtr2->SetPTCValue(float4::Up, float4(90.0f, 20.0f, 0.0f), -20.0f, -30.0f);
			CandlePtr_0->Death();
			PotalPtr0->Death();
			break;
		case MyMap::Stage1_3:
			PotalPtr2->Death();
			PotalPtr1->Death();
			PotalPtr3 = CreateActor<Potal>(1);
			PotalPtr3->GetTransform()->SetLocalPosition({ 8024.0f,458.0f,-900.0f });
			PotalPtr3->GetPotalRender()->GetTransform()->SetLocalPosition({ -15.0f,20.0f,0.0f });
			PotalPtr3->GetPotalRender()->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-180.0f });
			PotalPtr3->SetPTCValue(float4::Down, float4(90.0f, 20.0f, 0.0f), -20.0f, 70.0f);
			PotalPtr4 = CreateActor<Potal>(1);
			PotalPtr4->GetTransform()->SetLocalPosition({ 6872.0f,-481.0f,-900.0f });
			PotalPtr4->GetPotalRender()->GetTransform()->SetLocalPosition({ -10.0f,60.0f,0.0f });
			PotalPtr4->GetPotalRender()->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-270.0f });
			PotalPtr4->SetPTCValue(float4::Right, float4(20.0f, 90.0f, 0.0f), -20.0f, 70.0f);
			break;
		case MyMap::Stage1_4:
			PotalPtr3->Death();
			PotalPtr4->Death();
			PotalPtr5 = CreateActor<Potal>(1);
			PotalPtr5->GetTransform()->SetLocalPosition({ 11225.0f,-254.0f,0.0f });
			PotalPtr5->GetPotalRender()->GetTransform()->SetLocalPosition({ 10.0f,30.0f,0.0f });
			PotalPtr5->GetPotalRender()->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-90.0f });
			PotalPtr5->SetPTCValue(float4::Left, float4(20.0f, 70.0f, 0.0f), 20.0f, 70.0f);
			PotalPtr6 = CreateActor<Potal>(1);
			PotalPtr6->GetTransform()->SetLocalPosition({ 9383.0f,-254.0f,0.0f });
			PotalPtr6->GetPotalRender()->GetTransform()->SetLocalPosition({ 10.0f,30.0f,0.0f });
			PotalPtr6->GetPotalRender()->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-90.0f });
			PotalPtr6->SetPTCValue(float4::Right, float4(20.0f, 70.0f, 0.0f), 20.0f, 70.0f);
			S_CandlePtr0 = CreateActor<StandCandle>(1);
			S_CandlePtr0->GetTransform()->SetLocalPosition({ 9925.f,-238.f,-790.0f });
			S_CandlePtr0->SetStandCandleColor(float4(0.65f, 0.4f, 0.917f));
			S_CandlePtr0->S_SetMyMap(MyMap::Stage1_4);

			S_CandlePtr1 = CreateActor<StandCandle>(1);
			S_CandlePtr1->GetTransform()->SetLocalPosition({ 10727.f,-238.f,-790.0f });
			S_CandlePtr1->SetStandCandleColor(float4(0.65f, 0.4f, 0.917f));
			S_CandlePtr1->S_SetMyMap(MyMap::Stage1_4);
			break;
		case MyMap::Stage1_Boss:
			S_CandlePtr0->Death();
			S_CandlePtr1->Death();
			PotalPtr5->Death();
			PotalPtr6->Death();
			PotalPtr7 = CreateActor<Potal>(1);
			PotalPtr7->GetTransform()->SetLocalPosition({ 11438.0f, -480.0f,0.0f });
			PotalPtr7->GetPotalRender()->GetTransform()->SetLocalPosition({ 60.0f,-20.0f,0.0f });
			PotalPtr7->GetTransform()->SetWorldRotation({ 0.0f,0.0f,-270.0f });
			PotalPtr7->SetPTCValue(float4::Right, float4(20.0f, 110.0f, 0.0f), 0.0f, 50.0f);
			PotalPtr8 = CreateActor<Potal>(1);
			PotalPtr8->GetTransform()->SetLocalPosition({ 12763.0f, -480.0f,0.0f });
			PotalPtr8->GetPotalRender()->GetTransform()->SetLocalPosition({ -60.0f,-80.0f,0.0f });
			PotalPtr8->GetTransform()->SetWorldRotation({ 0.0f,0.0f,-90.0f });
			PotalPtr8->SetPTCValue(float4::Left, float4(20.0f, 110.0f, 0.0f), 0.0f, 50.0f);
			CandlePtr_1 = CreateActor<Candle>(1);
			CandlePtr_1->GetTransform()->SetLocalPosition({ 11730.f,-400.f,-200.0f });
			CandlePtr_1->SetCandleColor(float4(0.65f, 0.4f, 0.917f));
			CandlePtr_1->SetMyMap(MyMap::Stage1_Boss);
			CandlePtr_2 = CreateActor<Candle>(1);
			CandlePtr_2->GetTransform()->SetLocalPosition({ 12432.f,-400.f,-200.0f });
			CandlePtr_2->SetCandleColor(float4(0.65f, 0.4f, 0.917f));
			CandlePtr_2->SetMyMap(MyMap::Stage1_Boss);
			BGM.SetMute(true);
			BGM = GameEngineSound::Play("1.JailBoss.wav");
			BGM.SetLoop(-1);
			PrevMap = CurMap;
			break;
		case MyMap::Stage2_1:
			TunakText = CreateActor<MyMapUI>();
			TunakText->SetMapText("2층 : 투낙의 소굴");
			PotalPtr7->Death();
			PotalPtr8->Death();
			CandlePtr_1->Death();
			CandlePtr_2->Death();
			PotalPtr9 = CreateActor<Potal>(1);
			PotalPtr9->GetTransform()->SetLocalPosition({ 14143.0f, -132.0f,0.0f });
			PotalPtr9->GetPotalRender()->Off();
			PotalPtr9->GetPotalCol()->Off();
			PotalPtr9->SetPTCValue(float4::Left, float4(20.0f, 110.0f, 0.0f), 0.0f, 50.0f);
			BGM.SetMute(true);
			BGM = GameEngineSound::Play("3.junglefield.wav");
			BGM.SetLoop(-1);
			PrevMap = CurMap;
			break;
		case MyMap::Stage2_Boss:
			PotalPtr9->Death();
			PotalPtr10 = CreateActor<Potal>(1);
			PotalPtr10->GetTransform()->SetLocalPosition({ 14304.0f, -194.0f,0.0f });
			PotalPtr10->GetPotalRender()->GetTransform()->SetLocalPosition({ -65.0f,0.0f,0.0f });
			PotalPtr10->GetTransform()->SetWorldRotation({ 0.0f,0.0f,-90.0f });
			PotalPtr10->SetPTCValue(float4::Right, float4(20.0f, 110.0f, 0.0f), 0.0f, 50.0f);
			PotalPtr11 = CreateActor<Potal>(1);
			PotalPtr11->GetTransform()->SetLocalPosition({ 15844.0f, -194.0f,0.0f });
			PotalPtr11->GetPotalRender()->GetTransform()->SetLocalPosition({ 65.0f,0.0f,0.0f });
			PotalPtr11->GetTransform()->SetWorldRotation({ 0.0f,0.0f,-270.0f });
			PotalPtr11->SetPTCValue(float4::Left, float4(20.0f, 110.0f, 0.0f), 0.0f, 50.0f);
			BGM.SetMute(true);
			BGM = GameEngineSound::Play("3.jungleboss.wav");
			BGM.SetLoop(-1);
			PrevMap = CurMap;
			break;
		case MyMap::Stage3_1:
			break;
		case MyMap::Stage3_Boss:
			break;
		default:
			break;
		}
	}
	
}
void PlayLevel::LevelChangeStart()
{
	BGM = GameEngineSound::Play("0.Town.wav");
	BGM.SetLoop(-1);
	GameEngineLevel::LevelChangeStart();
	int a = 0;
}

void PlayLevel::LevelChangeEnd()
{
	GameEngineLevel::LevelChangeEnd();
	int a = 0;
}