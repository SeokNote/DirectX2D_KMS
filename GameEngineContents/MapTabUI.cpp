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
		MapTabBase->SetTexture("MapBase.png");
		MapTabBase->GetTransform()->SetLocalPosition({0.0f,0.0f,0.0f});
		MapTabBase->GetTransform()->SetLocalScale(MapTabUIScale);
		
	
	//	

}
bool OnOff_1 = false;
void MapTabUI::Update(float _Delta)
{
}