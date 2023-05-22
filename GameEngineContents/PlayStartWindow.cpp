#include "PrecompileHeader.h"
#include "PlayStartWindow.h"
#include "StartButton.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineCore.h>
PlayStartWindow* PlayStartWindow::MainPlayStartWindow = nullptr;
PlayStartWindow::PlayStartWindow()
{
	MainPlayStartWindow = this;
}

PlayStartWindow::~PlayStartWindow()
{
}

void PlayStartWindow::Start()
{
	PlayStartWindowRender = CreateComponent<GameEngineSpriteRenderer>();
	PlayStartWindowRender->SetTexture("PlayWindowBG.png");
	PlayStartWindowRender->GetTransform()->SetLocalScale(PlayStartWindowBGScale);
	PlayStartWindowRender->ColorOptionValue.MulColor.a = 0.9f;


	PlayStartSlot_0 = CreateComponent<GameEngineSpriteRenderer>();
	PlayStartSlot_0->SetTexture("SlotBase.png");
	PlayStartSlot_0->GetTransform()->SetLocalScale(SlotScale);
	PlayStartSlot_0->GetTransform()->SetLocalPosition({ -400,-30,0 });

	PlayStartSlot_1 = CreateComponent<GameEngineSpriteRenderer>();
	PlayStartSlot_1->SetTexture("SlotBase.png");
	PlayStartSlot_1->GetTransform()->SetLocalScale(SlotScale);
	PlayStartSlot_1->GetTransform()->SetLocalPosition({ 0,-30,0 });

	PlayStartSlot_2 = CreateComponent<GameEngineSpriteRenderer>();
	PlayStartSlot_2->SetTexture("SlotBase.png");
	PlayStartSlot_2->GetTransform()->SetLocalScale(SlotScale);
	PlayStartSlot_2->GetTransform()->SetLocalPosition({ 400,-30,0 });


	PlayStartSlotSelet_0 = CreateComponent<GameEngineSpriteRenderer>();
	PlayStartSlotSelet_0->SetTexture("SlotBase_Selected.png");
	PlayStartSlotSelet_0->GetTransform()->SetLocalScale(SlotScale);
	PlayStartSlotSelet_0->GetTransform()->SetLocalPosition({ -400,-30,0 });
	PlayStartSlotSelet_0->Off();

	PlayStartSlotSelet_1 = CreateComponent<GameEngineSpriteRenderer>();
	PlayStartSlotSelet_1->SetTexture("SlotBase_Selected.png");
	PlayStartSlotSelet_1->GetTransform()->SetLocalScale(SlotScale);
	PlayStartSlotSelet_1->GetTransform()->SetLocalPosition({ 0,-30,0 });
	PlayStartSlotSelet_1->Off();

	PlayStartSlotSelet_2 = CreateComponent<GameEngineSpriteRenderer>();
	PlayStartSlotSelet_2->SetTexture("SlotBase_Selected.png");
	PlayStartSlotSelet_2->GetTransform()->SetLocalScale(SlotScale);
	PlayStartSlotSelet_2->GetTransform()->SetLocalPosition({ 400,-30,0 });
	PlayStartSlotSelet_2->Off();

	StartSlotCollsion_0 = CreateComponent<GameEngineCollision>();
	StartSlotCollsion_0->GetTransform()->SetLocalPosition({ -400,-30,0 });
	StartSlotCollsion_0->GetTransform()->SetLocalScale(SlotScale);
	StartSlotCollsion_0->SetOrder(2998);

	StartSlotCollsion_1 = CreateComponent<GameEngineCollision>();
	StartSlotCollsion_1->GetTransform()->SetLocalPosition({ 0,-30,0 });
	StartSlotCollsion_1->GetTransform()->SetLocalScale(SlotScale);
	StartSlotCollsion_1->SetOrder(2998);

	StartSlotCollsion_2 = CreateComponent<GameEngineCollision>();
	StartSlotCollsion_2->GetTransform()->SetLocalPosition({ 400,-30,0 });
	StartSlotCollsion_2->GetTransform()->SetLocalScale(SlotScale);
	StartSlotCollsion_2->SetOrder(2998);

	SlotExit = CreateComponent<GameEngineSpriteRenderer>();
	SlotExit->SetTexture("ExitButton.png");
	SlotExit->GetTransform()->SetLocalScale(ButtonScale);
	SlotExit->GetTransform()->SetLocalPosition({ 590,315,0 });

	SlotExitSelet = CreateComponent<GameEngineSpriteRenderer>();
	SlotExitSelet->SetTexture("ExitButton_Selected.png");
	SlotExitSelet->GetTransform()->SetLocalScale(ButtonScale);
	SlotExitSelet->GetTransform()->SetLocalPosition({ 590,315,0 });
	SlotExitSelet->Off();

	SlotExitCollsion = CreateComponent<GameEngineCollision>();
	SlotExitCollsion->GetTransform()->SetLocalPosition({ 590,315,0 });
	SlotExitCollsion->GetTransform()->SetLocalScale(ButtonScale);
	SlotExitCollsion->SetOrder(2998);

	SlotImage_0 = CreateComponent<GameEngineSpriteRenderer>();
	SlotImage_0->SetTexture("SlotText1.EN.png");
	SlotImage_0->GetTransform()->SetLocalScale(SlotTextScale);
	SlotImage_0->GetTransform()->SetLocalPosition({ -400,185,0 });

	SlotImage_1 = CreateComponent<GameEngineSpriteRenderer>();
	SlotImage_1->SetTexture("SlotText2.EN.png");
	SlotImage_1->GetTransform()->SetLocalScale(SlotTextScale);
	SlotImage_1->GetTransform()->SetLocalPosition({ 0,185,0 });

	SlotImage_2 = CreateComponent<GameEngineSpriteRenderer>();
	SlotImage_2->SetTexture("SlotText3.EN.png");
	SlotImage_2->GetTransform()->SetLocalScale(SlotTextScale);
	SlotImage_2->GetTransform()->SetLocalPosition({ 400,185,0 });
}

float CheckTime = 0.0f;
void PlayStartWindow::Update(float _DeltaTime)
{
	CheckTime += _DeltaTime;
	if (CheckTime > 0.5f)
	{
		CollisionSet();
	}
}

void PlayStartWindow::CollisionSet()
{
	if (StartSlotCollsion_0->Collision(3000, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (GameEngineInput::IsDown("ClickMouse")) {
			GameEngineCore::ChangeLevel("PlayLevel");
		}
		PlayStartSlot_0->Off();
		PlayStartSlotSelet_0->On();
	}
	else {
		PlayStartSlot_0->On();
		PlayStartSlotSelet_0->Off();
	}
	if (StartSlotCollsion_1->Collision(3000, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (GameEngineInput::IsDown("ClickMouse")) {
			GameEngineCore::ChangeLevel("PlayLevel");
		}
		PlayStartSlot_1->Off();
		PlayStartSlotSelet_1->On();
	}
	else {
		PlayStartSlot_1->On();
		PlayStartSlotSelet_1->Off();
	}
	if (StartSlotCollsion_2->Collision(3000, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (GameEngineInput::IsDown("ClickMouse")) {
			GameEngineCore::ChangeLevel("PlayLevel");
		}
		PlayStartSlot_2->Off();
		PlayStartSlotSelet_2->On();
	}
	else {
		PlayStartSlot_2->On();
		PlayStartSlotSelet_2->Off();
	}
	if (SlotExitCollsion->Collision(3000, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (GameEngineInput::IsDown("ClickMouse")) {
			Death();
			CheckTime = 0.0f;
		}
		SlotExit->Off();
		SlotExitSelet->On();
	}
	else {
		SlotExit->On();
		SlotExitSelet->Off();
	}
}

