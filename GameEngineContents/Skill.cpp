#include "PrecompileHeader.h"
#include "Skill.h"
#include "Player.h"
#include "WeaponBase.h"
#include "ContentsEnums.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
Skill::Skill() 
{
}

Skill::~Skill() 
{
}

void Skill::Start()
{
	SkillRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SkillRender->SetTexture("Skill_CosmosSwordAuror.png");
	SkillRender->GetTransform()->SetLocalPosition({ 0.0f,0.f,1.f });
	SkillRender->GetTransform()->SetLocalScale(Scale);

	SkillCol = CreateComponent<GameEngineCollision>(ColOrder::GreatWeapon);
	SkillCol->GetTransform()->SetLocalScale(Scale);
	SkillCol->SetColType(ColType::AABBBOX2D);
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	MousePos = WeaponBase::WeaponBasePtr->GetMousePos();
	EffectPos = (MousePos - PlayerPos).NormalizeReturn();
	float Deg = WeaponBase::WeaponBasePtr->GetDeg();
	SkillRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,Deg });
}

void Skill::Update(float _Delta)
{
	Move(_Delta);
}

void Skill::Move(float _Delta)
{
	Time += _Delta;

	SkillRender->GetTransform()->AddLocalPosition({ EffectPos.x * Time*10.0f,EffectPos.y * Time * 10.0f,0.0f });
	SkillCol->GetTransform()->SetLocalPosition(SkillRender->GetTransform()->GetLocalPosition());
	if (Time > 2.0f)
	{
		Death();
		Time = 0.0f;
	}

}


