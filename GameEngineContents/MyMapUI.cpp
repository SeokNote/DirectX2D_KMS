#include "PrecompileHeader.h"
#include "MyMapUI.h"
#include "UIFontRender.h"
#include <GameEngineCore/GameEngineFontRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
MyMapUI::MyMapUI() 
{
}

MyMapUI::~MyMapUI() 
{
}

void MyMapUI::SetMapText(std::string _Name)
{
	MapExplane->SetText(_Name);
	MapExplane1->SetText(_Name);
	MapExplane2->SetText(_Name);
	MapExplane3->SetText(_Name);
	MapExplane4->SetText(_Name);

}

void MyMapUI::Start()
{
	MapExplane = CreateComponent<UIFontRender>(999);
	MapExplane->SetFont("Aa카시오페아");
	MapExplane->SetFontFlag(FW1_CENTER);
	MapExplane->SetScale(52);
	MapExplane->SetColor(float4::White);
	MapExplane->SetText("테스트");
	MapExplane->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });

	MapExplane1 = CreateComponent<UIFontRender>(998);
	MapExplane1->SetFont("Aa카시오페아");
	MapExplane1->SetFontFlag(FW1_CENTER);
	MapExplane1->SetScale(52);
	MapExplane1->SetColor(float4::Black);
	MapExplane1->GetTransform()->SetLocalPosition({0.0f,5.0f,0.0f});

	MapExplane2 = CreateComponent<UIFontRender>(998);
	MapExplane2->SetFont("Aa카시오페아");
	MapExplane2->SetFontFlag(FW1_CENTER);
	MapExplane2->SetScale(52);
	MapExplane2->SetColor(float4::Black);
	MapExplane2->GetTransform()->SetLocalPosition({ 0.0f,-5.0f,0.0f });

	MapExplane3 = CreateComponent<UIFontRender>(998);
	MapExplane3->SetFont("Aa카시오페아");
	MapExplane3->SetFontFlag(FW1_CENTER);
	MapExplane3->SetScale(52);
	MapExplane3->SetColor(float4::Black);
	MapExplane3->GetTransform()->SetLocalPosition({ 5.0f,0.0f,0.0f });

	MapExplane4 = CreateComponent<UIFontRender>(998);
	MapExplane4->SetFont("Aa카시오페아");
	MapExplane4->SetFontFlag(FW1_CENTER);
	MapExplane4->SetScale(52);
	MapExplane4->SetColor(float4::Black);
	MapExplane4->GetTransform()->SetLocalPosition({ -5.0f,0.0f,0.0f });

}

void MyMapUI::Update(float _Delta)
{
	FirstBezierPos(_Delta);
	if (IsValue == true)
	{
		Time1 += _Delta;
		if (Time1 > 1.0f)
		{
			SecoundBezierPos(_Delta);
		}
	}
}

void MyMapUI::SecoundBezierPos(float _Delta)
{
	Time2 += _Delta;
	float4 M0 = float4::LerpClamp({ 0.0f,150.0f,0.0f }, { -840.0f,150.0f,0.0f }, Time2);
	float4 M1 = float4::LerpClamp({ -840.0f,150.0f,0.0f }, { 840.0f,150.0f,0.0f }, Time2);
	float4 Pos = float4::LerpClamp(M0, M1, Time2);
	MapExplane->GetTransform()->SetWorldPosition(Pos);
	MapExplane1->GetTransform()->SetWorldPosition({ Pos.x-3.0f,Pos.y,Pos.z});
	MapExplane2->GetTransform()->SetWorldPosition({ Pos.x+3.0f,Pos.y,Pos.z });
	MapExplane3->GetTransform()->SetWorldPosition({ Pos.x,Pos.y+3.0f,Pos.z });
	MapExplane4->GetTransform()->SetWorldPosition({ Pos.x,Pos.y-3.0f,Pos.z });

	if (MapExplane->GetTransform()->GetWorldPosition() == float4(840.0f, 150.0f, 0.0f))
	{
		Death();
	}
}

void MyMapUI::FirstBezierPos(float _Delta)
{
	Time += _Delta;
	float4 M0 = float4::LerpClamp({-840.0f,150.0f,0.0f}, { 840.0f,150.0f,0.0f }, Time);
	float4 M1 = float4::LerpClamp({ 840.0f,150.0f,0.0f }, {0.0f,150.0f,0.0f}, Time);
	float4 Pos = float4::LerpClamp(M0, M1, Time);
	MapExplane->GetTransform()->SetWorldPosition(Pos);
	MapExplane1->GetTransform()->SetWorldPosition({ Pos.x-3.0f,Pos.y,Pos.z});
	MapExplane2->GetTransform()->SetWorldPosition({ Pos.x + 3.0f,Pos.y,Pos.z });
	MapExplane3->GetTransform()->SetWorldPosition({ Pos.x,Pos.y + 3.0f,Pos.z });
	MapExplane4->GetTransform()->SetWorldPosition({ Pos.x,Pos.y - 3.0f,Pos.z });

	if (MapExplane->GetTransform()->GetWorldPosition() == float4(0.0f,150.0f, 0.0f))
	{
		IsValue = true;
	}

}

