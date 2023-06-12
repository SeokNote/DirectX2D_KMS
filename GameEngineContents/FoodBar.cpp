#include "PrecompileHeader.h"
#include "FoodBar.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

FoodBar::FoodBar() 
{
}

FoodBar::~FoodBar() 
{
}

void FoodBar::Start()
{

	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	PlayerFoodUI = CreateComponent<GameEngineUIRenderer>(2);
	PlayerFoodUI->SetTexture("PlayerFoodUI.png");
	PlayerFoodUI->GetTransform()->SetLocalPosition(PlayerFoodUIPos);
	PlayerFoodUI->GetTransform()->SetLocalScale(PlayerFoodUIScale);

}

void FoodBar::Update(float _Delta)
{
}

