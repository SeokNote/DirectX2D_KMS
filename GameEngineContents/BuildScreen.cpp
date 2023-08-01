#include "PrecompileHeader.h"
#include "BuildScreen.h"
#include "ContentButton.h"
#include "Trainning.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
BuildScreen::BuildScreen() 
{
}

BuildScreen::~BuildScreen() 
{
}

void BuildScreen::Start()
{
	Player::MainPlayer->SetUICount(1);
	BuildBaseBG = CreateComponent<GameEngineUIRenderer>(149);
	BuildBaseBG->SetTexture("PlayWindowBG.png");
	BuildBaseBG->ColorOptionValue.MulColor.a = 0.8f;
	BuildBaseBG->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	BuildBaseBG->GetTransform()->SetLocalScale({1280.0f,720.0f,0.0f});

	BuildBase = CreateComponent<GameEngineUIRenderer>(150);
	BuildBase->SetTexture("BuildBase.png");
	BuildBase->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	BuildBase->GetTransform()->SetLocalScale({ 1280.0f,720.0f,0.0f });

	BuildTextUI = CreateComponent<GameEngineUIRenderer>(151);
	BuildTextUI->SetScaleToTexture("BuildText.png");
	BuildTextUI->GetTransform()->SetLocalPosition({ 0.0f,-50.0f,0.0f });	
	BuildTextUI->Off();

	BuildButton = GetLevel()->CreateActor<ContentButton>();
	BuildButton->GetTransform()->SetParent(GetTransform());
	BuildButton->GetTransform()->SetLocalPosition({ 0.0f,100.0f,0.0f });
	BuildButton->GetRender()->SetScaleToTexture("TranBuild.png");
	BuildButton->GetRender_Select()->SetScaleToTexture("TranBuildSelet.png");
	BuildButton->SetEvent([this]()
		{
			GetLevel()->CreateActor<Trainning>();
			BuildTextUI->On();
			BuildButton->Death();

		});
	ExitButton = GetLevel()->CreateActor<ContentButton>();
	ExitButton->GetTransform()->SetParent(GetTransform());
	ExitButton->GetTransform()->SetLocalPosition({ 580.0f,295.0f,0.0f });
	ExitButton->GetRender()->SetScaleToTexture("ExitButton1_1.png");
	ExitButton->GetRender_Select()->SetScaleToTexture("ExitButton1_0.png");
	ExitButton->SetEvent([this]()
		{
			Player::MainPlayer->SetUICount(0);
			Death();
		});
	
}

void BuildScreen::Update(float _DeltaTime)
{

}

