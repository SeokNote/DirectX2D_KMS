#include "PrecompileHeader.h"
#include "SpaceSkill.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
SpaceSkill* SpaceSkill::MainSkillPtr = nullptr;
SpaceSkill::SpaceSkill() 
{
}

SpaceSkill::~SpaceSkill() 
{
}

void SpaceSkill::Start()
{
	SkillUI = CreateComponent<GameEngineUIRenderer>(90);
	SkillUI->SetTexture("CosmosSkillBG.png");
	SkillUI->GetTransform()->SetLocalPosition(float4::Zero);
	SkillUI->GetTransform()->SetLocalScale(SkillScale);

	CommandUI = CreateComponent<GameEngineUIRenderer>(92);
	CommandUI->SetTexture("Keyboard_Q.png");
	CommandUI->GetTransform()->SetLocalPosition({20.0f,-20.0f,0.0f});
	CommandUI->GetTransform()->SetLocalScale(CommandScale);
	
	CulTimeUI = CreateComponent<GameEngineUIRenderer>(91);
	CulTimeUI->SetTexture("CosmosSkillCul.png");
	CulTimeUI->GetTransform()->SetLocalPosition(float4::Zero);
	CulTimeUI->ColorOptionValue.MulColor.a = 0.8f;
	CulTimeUI->GetTransform()->SetLocalScale(CulScale);
	CulTimeUI->Off();
}

void SpaceSkill::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown("Skill"))
	{
		IsValue = true;
		CulTimeUI->On();
	}
	if (IsValue == true)
	{
		CurCulltime += _Delta;
		CulTimeUI->ImageClippingY(1-(CurCulltime/ MaxCulltime), ClipYDir::Bot);

		if (CurCulltime > 3.0f)
		{
			CurCulltime = 0.0f;
			IsValue = false;
		}
	}
}

