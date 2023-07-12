#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "FoodUI.h"
#include "TempleNpc.h"
#include "Player.h"
#include "UICountBase.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ContentButton.h"
#include "UIFontRender.h"
FoodUI::FoodUI()
{
}

FoodUI::~FoodUI()
{
}

void FoodUI::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	FoodUIRender = CreateComponent<GameEngineUIRenderer>(150);
	FoodUIRender->SetTexture("FoodUI.png");
	FoodUIRender->GetTransform()->SetLocalScale(FoodUIScale);

	ExitButtonRender = CreateComponent<GameEngineUIRenderer>(151);
	ExitButtonRender->SetTexture("ExitButton1_1.png");
	ExitButtonRender->GetTransform()->SetLocalScale(ExitButtonScale);
	ExitButtonRender->GetTransform()->SetLocalPosition(ExitButtonPos);

	ExitButtonSelectRender = CreateComponent<GameEngineUIRenderer>(151);
	ExitButtonSelectRender->SetTexture("ExitButton1_0.png");
	ExitButtonSelectRender->GetTransform()->SetLocalScale(ExitButtonScale);
	ExitButtonSelectRender->GetTransform()->SetLocalPosition(ExitButtonPos);
	ExitButtonSelectRender->Off();

	FoodUIExitCol = CreateComponent<GameEngineCollision>();
	FoodUIExitCol->GetTransform()->SetLocalPosition(ExitButtonPos);
	FoodUIExitCol->GetTransform()->SetLocalScale(ExitButtonScale);
	FoodUIExitCol->SetOrder(2998);

	FoodBGRender = CreateComponent<GameEngineUIRenderer>(151);
	FoodBGRender->SetTexture("FoodUI.png");
	FoodBGRender->CreateAnimation({ .AnimationName = "FoodAni", .SpriteName = "FoodAni",.FrameInter = 0.1f, .Loop = true, .ScaleToTexture = true });
	FoodBGRender->GetTransform()->SetLocalPosition({242.0f,0.0f,0.0f});

	FoodBGRender->ChangeAnimation("FoodAni");
	SetButton();
}
void FoodUI::Update(float _Delta)
{
	if (FoodUIExitCol->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ExitButtonRender->Off();
		ExitButtonSelectRender->On();
		if (GameEngineInput::IsDown("ClickMouse"))
		{
			Player::MainPlayer->SetUICount(0);
			UICountBase::MainUICountBase->SetUICount(0);
			Death();
		}
	}
	else {
		ExitButtonSelectRender->Off();
		ExitButtonRender->On();
	}
}

void FoodUI::SetButton()
{
	BreadButton = GetLevel()->CreateActor<ContentButton>();
	BreadButton->GetTransform()->SetParent(GetTransform());
	BreadButton->GetTransform()->SetLocalPosition({ -402.0f,143.0f,0.0f });
	BreadButton->GetRender()->SetTexture("FoodBread_01.png");
	BreadButton->GetRender()->GetTransform()->SetWorldScale({ 400.0f,200.0f,0.0f });
	BreadButton->GetExplaneRender()->SetTexture("01_Bread.png");
	BreadButton->GetExplaneRender()->GetTransform()->SetWorldPosition({ 240.0f,-20.0f,0.0f });
	BreadButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 292.0f,120.0f,1.0f });

	TomatoButton = GetLevel()->CreateActor<ContentButton>();
	TomatoButton->GetTransform()->SetParent(GetTransform());
	TomatoButton->GetTransform()->SetLocalPosition({ -402.0f,-65.0f,0.0f });
	TomatoButton->GetRender()->SetTexture("FoodTomatoSoup_01.png");
	TomatoButton->GetRender()->GetTransform()->SetWorldScale({ 400.0f,200.0f,0.0f });
	TomatoButton->GetExplaneRender()->SetTexture("04_TamatoSoup.png");
	TomatoButton->GetExplaneRender()->GetTransform()->SetWorldPosition({ 240.0f,-20.0f,0.0f });
	TomatoButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 292.0f,120.0f,1.0f });

}
