#include "PrecompileHeader.h"
#include "BossText.h"
#include "UIFontRender.h"
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
BossText::BossText() 
{
}

BossText::~BossText() 
{
}

void BossText::SetStatFont(std::string _BossName, std::string _Explane)
{
	BossName->SetText(_BossName);
	BossName1->SetText(_BossName);
	BossName2->SetText(_BossName);
	BossName3->SetText(_BossName);
	BossName4->SetText(_BossName);

	BossExplane->SetText(_Explane);

}

void BossText::Start()
{
	BossName = CreateComponent<UIFontRender>(999);
	BossName->SetFont(Font);
	BossName->SetFontFlag(FW1_CENTER);
	BossName->SetScale(52);
	BossName->SetColor({1.0f,1.0f,1.0f,NameAlpha });
	
	BossName1 = CreateComponent<UIFontRender>(998);
	BossName1->SetFont(Font);
	BossName1->SetFontFlag(FW1_CENTER);
	BossName1->SetScale(52);
	BossName1->SetColor({ 0.0f,0.0f,0.0f,NameAlpha });
	BossName1->GetTransform()->SetLocalPosition({ 0.0f,3.0f,0.0f });

	BossName2 = CreateComponent<UIFontRender>(998);
	BossName2->SetFont(Font);
	BossName2->SetFontFlag(FW1_CENTER);
	BossName2->SetScale(52);
	BossName2->SetColor({ 0.0f,0.0f,0.0f,NameAlpha });
	BossName2->GetTransform()->SetLocalPosition({ 0.0f,-3.0f,0.0f });

	BossName3 = CreateComponent<UIFontRender>(998);
	BossName3->SetFont(Font);
	BossName3->SetFontFlag(FW1_CENTER);
	BossName3->SetScale(52);
	BossName3->SetColor({ 0.0f,0.0f,0.0f,NameAlpha });
	BossName3->GetTransform()->SetLocalPosition({3.0f,0.0f,0.0f });

	BossName4 = CreateComponent<UIFontRender>(998);
	BossName4->SetFont(Font);
	BossName4->SetFontFlag(FW1_CENTER);
	BossName4->SetScale(52);
	BossName4->SetColor({ 0.0f,0.0f,0.0f,NameAlpha });
	BossName4->GetTransform()->SetLocalPosition({ -3.0f,0.0f,0.0f });

	BossExplane = CreateComponent<UIFontRender>(999);
	BossExplane->SetFont(Font);
	BossExplane->SetFontFlag(FW1_CENTER);
	BossExplane->SetScale(30);
	BossExplane->SetColor({ 1.0f,1.0f,1.0f,ExplaneAlpha });
	BossExplane->GetTransform()->SetLocalPosition({ 20.0f,30.0f,0.0f });

}

void BossText::Update(float _Delta)
{
	Time += _Delta;
	if (NameAlpha + Time >= 1)
	{
		Time2 += _Delta;
		if (ExplaneAlpha + Time2 <= 1)
		{
			BossExplane->SetColor({ 1.0f,1.0f,1.0f,ExplaneAlpha + Time2 });

		}
		else
		{
			Time4 += _Delta;
			if (Time4 > 1.0f)
			{
				StartE = true;
			}
		}
	}
	else
	{
		BossName->SetColor({ 1.0f,1.0f,1.0f,NameAlpha + Time });
		BossName1->SetColor({ 0.0f,0.0f,0.0f,NameAlpha + Time });
		BossName2->SetColor({ 0.0f,0.0f,0.0f,NameAlpha + Time });
		BossName3->SetColor({ 0.0f,0.0f,0.0f,NameAlpha + Time });
		BossName4->SetColor({ 0.0f,0.0f,0.0f,NameAlpha + Time });

	}
	if (StartE == true)
	{
		Time3 += _Delta;
		if (Time3 > 0.5f)
		{
			if (NameAlpha + Time3*0.5f >= 1)
			{
				Death();
			}
			else
			{
				BossName->SetColor({ 1.0f,1.0f,1.0f,NameAlpha - Time3 * 0.5f });
				BossName1->SetColor({ 0.0f,0.0f,0.0f,NameAlpha - Time3 * 0.5f });
				BossName2->SetColor({ 0.0f,0.0f,0.0f,NameAlpha - Time3 * 0.5f });
				BossName3->SetColor({ 0.0f,0.0f,0.0f,NameAlpha - Time3 * 0.5f });
				BossName4->SetColor({ 0.0f,0.0f,0.0f,NameAlpha - Time3 * 0.5f });
				BossExplane->SetColor({ 1.0f,1.0f,1.0f,ExplaneAlpha - Time3 * 0.5f });
			}
		
		}
	
	


	}
}