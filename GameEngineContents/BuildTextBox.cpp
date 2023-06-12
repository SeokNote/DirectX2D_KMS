#include "PrecompileHeader.h"
#include "BuildTextBox.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

BuildTextBox::BuildTextBox() 
{
}

BuildTextBox::~BuildTextBox() 
{
}

void BuildTextBox::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	BuildTextBoxUI = CreateComponent<GameEngineUIRenderer>(2);
	BuildTextBoxUI->SetTexture("BuildTextBoxBase.png");
	BuildTextBoxUI->GetTransform()->SetLocalPosition({ 0.0f, -250.0f , -100.0f });
	BuildTextBoxUI->GetTransform()->SetLocalScale(TextBoxScale);

	BuildTextBoxUI_S = CreateComponent<GameEngineUIRenderer>(2);
	BuildTextBoxUI_S->SetTexture("SeletTextBoxBase_1.png");
	BuildTextBoxUI_S->GetTransform()->SetLocalPosition({ 480.0f, -30.0f , -100.0f });
	BuildTextBoxUI_S->GetTransform()->SetLocalScale(SelectBoxScale);

	////////////////////// 충돌디버그 뜨면 그때 위치값 셋팅해주기////////////////
	ButtonCol_0 = CreateComponent<GameEngineCollision>();
	ButtonCol_0->GetTransform()->SetLocalScale(ButtonColScale);
	ButtonCol_0->GetTransform()->SetLocalPosition(ButtonPos_0);
	ButtonCol_0->SetOrder(3011);

	ButtonCol_1 = CreateComponent<GameEngineCollision>();
	ButtonCol_1->GetTransform()->SetLocalScale(ButtonColScale);
	ButtonCol_1->GetTransform()->SetLocalPosition(ButtonPos_1);
	ButtonCol_1->SetOrder(3011);

	ButtonCol_2 = CreateComponent<GameEngineCollision>();
	ButtonCol_2->GetTransform()->SetLocalScale(ButtonColScale);
	ButtonCol_2->GetTransform()->SetLocalPosition(ButtonPos_2);
	ButtonCol_2->SetOrder(3011);
}

void BuildTextBox::Update(float _Delta)
{

}

