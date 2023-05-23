#include "PrecompileHeader.h"
#include "MapTabUI.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>

MapTabUI::MapTabUI()
{
}

MapTabUI::~MapTabUI()
{
}

void MapTabUI::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	
		MapTabBaseBG = CreateComponent<GameEngineUIRenderer>();
		MapTabBaseBG->SetTexture("PlayWindowBG.png");
		MapTabBaseBG->ColorOptionValue.MulColor.a = 0.8f;
		MapTabBaseBG->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
		MapTabBaseBG->GetTransform()->SetLocalScale(MapTabUIScale);

		MapTabBase = CreateComponent<GameEngineUIRenderer>();
		MapTabBase->SetTexture("MapBase_0.png");
		MapTabBase->GetTransform()->SetLocalPosition({0.0f,0.0f,0.0f});
		MapTabBase->GetTransform()->SetLocalScale(MapTabUIScale);
		{
			Menu_Builder = CreateComponent<GameEngineUIRenderer>();
			Menu_Builder->SetTexture("Menu_Builder0.png");
			Menu_Builder->GetTransform()->SetLocalPosition(Menu_BuiderPos);
			Menu_Builder->GetTransform()->SetLocalScale(MenuIconScale);

			Menu_BuilderSelect = CreateComponent<GameEngineUIRenderer>();
			Menu_BuilderSelect->SetTexture("Menu_Builder1.png");
			Menu_BuilderSelect->GetTransform()->SetLocalPosition(Menu_BuiderPos);
			Menu_BuilderSelect->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_BuilderSelect->Off();

			Menu_Commander = CreateComponent<GameEngineUIRenderer>();
			Menu_Commander->SetTexture("Menu_Commander0.png");
			Menu_Commander->GetTransform()->SetLocalPosition(Menu_CommanderPos);
			Menu_Commander->GetTransform()->SetLocalScale(MenuIconScale);

			Menu_CommanderSelect = CreateComponent<GameEngineUIRenderer>();
			Menu_CommanderSelect->SetTexture("Menu_Commander1.png");
			Menu_CommanderSelect->GetTransform()->SetLocalPosition(Menu_CommanderPos);
			Menu_CommanderSelect->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_CommanderSelect->Off();
			
			Menu_Dungeon = CreateComponent<GameEngineUIRenderer>();
			Menu_Dungeon->SetTexture("Menu_Dungeon0.png");
			Menu_Dungeon->GetTransform()->SetLocalPosition(Menu_DungeonPos);
			Menu_Dungeon->GetTransform()->SetLocalScale(MenuIconScale);
			
			Menu_DungeonSelect = CreateComponent<GameEngineUIRenderer>();
			Menu_DungeonSelect->SetTexture("Menu_Dungeon1.png");
			Menu_DungeonSelect->GetTransform()->SetLocalPosition(Menu_DungeonPos);
			Menu_DungeonSelect->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_DungeonSelect->Off();
			
			Menu_Shop = CreateComponent<GameEngineUIRenderer>();
			Menu_Shop->SetTexture("Menu_Shop0.png");
			Menu_Shop->GetTransform()->SetLocalPosition(Menu_ShopPos);
			Menu_Shop->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_Shop->GetTransform()->SetLocalNegativeScaleX();

			Menu_ShopSelect = CreateComponent<GameEngineUIRenderer>();
			Menu_ShopSelect->SetTexture("Menu_Shop1.png");
			Menu_ShopSelect->GetTransform()->SetLocalPosition(Menu_ShopPos);
			Menu_ShopSelect->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_ShopSelect->GetTransform()->SetLocalNegativeScaleX();
			Menu_ShopSelect->Off();
			
			Menu_TemPle = CreateComponent<GameEngineUIRenderer>();
			Menu_TemPle->SetTexture("Menu_Temple0.png");
			Menu_TemPle->GetTransform()->SetLocalPosition(Menu_TemplePos);
			Menu_TemPle->GetTransform()->SetLocalScale(MenuIconScale);
			
			Menu_TemPleSelect = CreateComponent<GameEngineUIRenderer>();
			Menu_TemPleSelect->SetTexture("Menu_Temple1.png");
			Menu_TemPleSelect->GetTransform()->SetLocalPosition(Menu_TemplePos);
			Menu_TemPleSelect->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_TemPleSelect->Off();

		}
	

		{
			//collision
			Menu_BuilderCol = CreateComponent<GameEngineCollision>();
			Menu_BuilderCol->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_BuilderCol->GetTransform()->SetLocalPosition(Menu_BuiderPos);
			Menu_BuilderCol->SetOrder(3002);

			Menu_CommanderCol = CreateComponent<GameEngineCollision>();
			Menu_CommanderCol->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_CommanderCol->GetTransform()->SetLocalPosition(Menu_CommanderPos);
			Menu_CommanderCol->SetOrder(3002);

			Menu_DungeonCol = CreateComponent<GameEngineCollision>();
			Menu_DungeonCol->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_DungeonCol->GetTransform()->SetLocalPosition(Menu_DungeonPos);
			Menu_DungeonCol->SetOrder(3002);

			Menu_ShopCol = CreateComponent<GameEngineCollision>();
			Menu_ShopCol->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_ShopCol->GetTransform()->SetLocalPosition(Menu_ShopPos);
			Menu_ShopCol->SetOrder(3002);

			Menu_TemPleCol = CreateComponent<GameEngineCollision>();
			Menu_TemPleCol->GetTransform()->SetLocalScale(MenuIconScale);
			Menu_TemPleCol->GetTransform()->SetLocalPosition(Menu_TemplePos);
			Menu_TemPleCol->SetOrder(3002);
		}
	
	//	

}
void MapTabUI::Update(float _Delta)
{
	if (Menu_BuilderCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Menu_Builder->Off();
		Menu_BuilderSelect->On();
		if (GameEngineInput::IsDown("ClickMouse")) 
		{
		}
	}
	else {
		Menu_BuilderSelect->Off();
		Menu_Builder->On();
	}

	if (Menu_CommanderCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Menu_Commander->Off();
		Menu_CommanderSelect->On();
		if (GameEngineInput::IsDown("ClickMouse")) 
		{
		}
	}
	else {
		Menu_CommanderSelect->Off();
		Menu_Commander->On();
	}

	if (Menu_DungeonCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Menu_Dungeon->Off();
		Menu_DungeonSelect->On();
		if (GameEngineInput::IsDown("ClickMouse")) 
		{
		}
	}
	else {
		Menu_DungeonSelect->Off();
		Menu_Dungeon->On();
	}

	if (Menu_ShopCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Menu_Shop->Off();
		Menu_ShopSelect->On();
		if (GameEngineInput::IsDown("ClickMouse")) 
		{

		}
	}
	else {
		Menu_ShopSelect->Off();
		Menu_Shop->On();
	}

	if (Menu_TemPleCol->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Menu_TemPle->Off();
		Menu_TemPleSelect->On();
		if (GameEngineInput::IsDown("ClickMouse")) 
		{
		}
	}
	else {
		Menu_TemPleSelect->Off();
		Menu_TemPle->On();
	}

}