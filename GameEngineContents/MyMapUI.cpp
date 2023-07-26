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
}

void MyMapUI::Start()
{
	MapExplane = CreateComponent<UIFontRender>(999);
	MapExplane->SetFont("Aa카시오페아");
	MapExplane->SetFontFlag(FW1_CENTER);
	MapExplane->SetScale(52);
	MapExplane->SetColor(float4::White);
	MapExplane->SetText("테스트");


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
	float4 M0 = float4::LerpClamp({ 0.0f,50.0f,0.0f }, { -740.0f,50.0f,0.0f }, Time2);
	float4 M1 = float4::LerpClamp({ -740.0f,50.0f,0.0f }, { 740.0f,50.0f,0.0f }, Time2);
	float4 Pos = float4::LerpClamp(M0, M1, Time2);
	MapExplane->GetTransform()->SetWorldPosition(Pos);
}

void MyMapUI::FirstBezierPos(float _Delta)
{
	Time += _Delta;
	float4 M0 = float4::LerpClamp({-740.0f,50.0f,0.0f}, { 740.0f,50.0f,0.0f }, Time);
	float4 M1 = float4::LerpClamp({ 740.0f,50.0f,0.0f }, {0.0f,50.0f,0.0f}, Time);
	float4 Pos = float4::LerpClamp(M0, M1, Time);
	MapExplane->GetTransform()->SetWorldPosition(Pos);
	if (MapExplane->GetTransform()->GetWorldPosition() == float4(0.0f, 50.0f, 0.0f))
	{
		IsValue = true;
	}

}

