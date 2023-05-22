#include "PrecompileHeader.h"
#include "PlayerStat.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>

PlayerStat::PlayerStat()
{
}

PlayerStat::~PlayerStat()
{
}

void PlayerStat::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	
	PlayerStatUI = CreateComponent<GameEngineUIRenderer>();
	PlayerStatUI->SetTexture("FinalStateUI.png");
	PlayerStatUI->GetTransform()->SetLocalPosition({ -390.0f, 100.0f });
	PlayerStatUI->GetTransform()->SetLocalScale(StatUIScale);
	//PlayerStatUI->Off();
	
	FoodStatUI = CreateComponent<GameEngineUIRenderer>();
	FoodStatUI->SetTexture("FoodBase.png");
	FoodStatUI->GetTransform()->SetLocalPosition({ -390.0f, -200.0f });
	FoodStatUI->GetTransform()->SetLocalScale(FoodStatUIScale);
	//FoodStatUI->Off();

	ExitButton = CreateComponent<GameEngineUIRenderer>();
	ExitButton->SetTexture("ExitButton.png");
	ExitButton->GetTransform()->SetLocalScale(ButtonScale);
	ExitButton->GetTransform()->SetLocalPosition({ -200,305,0 });
	//ExitButton->Off();


	ExitButtonSelect = CreateComponent<GameEngineUIRenderer>();
	ExitButtonSelect->SetTexture("ExitButton_Selected.png");
	ExitButtonSelect->GetTransform()->SetLocalScale(ButtonScale);
	ExitButtonSelect->GetTransform()->SetLocalPosition({ -200,305,0 });
	//ExitButtonSelect->Off();

	ExitButtonCollsion = CreateComponent<GameEngineCollision>();
	ExitButtonCollsion->GetTransform()->SetLocalPosition({ -200,305,0 });
	ExitButtonCollsion->GetTransform()->SetLocalScale(ButtonScale);
	ExitButtonCollsion->SetOrder(2998);
	
//	

}
bool OnOff = false;
void PlayerStat::Update(float _Delta)
{

	if (ExitButtonCollsion->Collision(3001, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ExitButton->Off();
		ExitButtonSelect->On();
		if (GameEngineInput::IsDown("ClickMouse")) {
			Death();
		}
	}
	else {
		ExitButtonSelect->Off();
		ExitButton->On();
	}

}