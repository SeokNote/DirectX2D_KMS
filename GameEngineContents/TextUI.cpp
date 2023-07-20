#include "PrecompileHeader.h"
#include "TextUI.h"

#include <GameEngineCore/GameEngineFontRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
TextUI::TextUI() 
{
}

TextUI::~TextUI() 
{
}

void TextUI::TextSetting(float4 _Pos, float4 _FontColor,std::string _Text , bool _MoveValue)
{
	Value = _MoveValue;
	Pos = _Pos;
	Color = _FontColor;
	FontRender->SetFont(font);
	FontRender->SetText(_Text);
	FontRender->SetFontFlag(FW1_CENTER);
	FontRender->SetScale(32);
	FontRender->SetColor(Color);
	FontRender->GetTransform()->SetWorldPosition(_Pos);

	int a = 0;

}
void TextUI::TextCreat(GameEngineLevel* _Level, float4 _Pos, float4 _FontColor,std::string _Text,bool _MoveValue)
{
	std::shared_ptr<TextUI> TextPtr = _Level->CreateActor<TextUI>();
	TextPtr->TextSetting(_Pos, _FontColor , _Text , _MoveValue);

}

void TextUI::Start()
{
	FontRender = CreateComponent<GameEngineFontRenderer>(1);

}

void TextUI::Update(float _Delta)
{
	MoveFont(_Delta);
}

void TextUI::MoveFont(float _Delta)
{
	if (Value == true)
	{
		Ratio += _Delta;
		float4 M0 = float4::LerpClamp(Pos, {Pos.x+50.0f,Pos.y+80.0f,Pos.z}, Ratio);
		float4 M1 = float4::LerpClamp({ Pos.x + 50.0f,Pos.y + 80.0f,Pos.z }, { Pos.x + 70.0f,Pos.y + 50.0f,Pos.z }, Ratio);
		float4 Pos2 = float4::LerpClamp(M0, M1, Ratio);
		FontRender->GetTransform()->SetWorldPosition(Pos2);
		FontRender->SetColor({ Color.r,Color.g,Color.b,Color.a - Ratio*0.5f });

		if (Color.a - Ratio * 0.5f < 0)
		{
			Ratio = 0.0f;
			Death();
		}
	}
	else
	{
		Ratio += _Delta;
		FontRender->GetTransform()->AddWorldPosition({ 0.0f,Ratio * 5.0f,0.0f });
		FontRender->SetColor({ Color.r,Color.g,Color.b,Color.a - Ratio * 0.5f });

		if (Color.a - Ratio * 0.5f < 0)
		{
			Ratio = 0.0f;
			Death();
		}
	}
}

