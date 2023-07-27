#include "PrecompileHeader.h"
#include "Player.h"
#include "SpaceWeapon.h"
#include "Skill.h"
#include "SpaceSkill.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
SpaceWeapon::SpaceWeapon()
{
}

SpaceWeapon::~SpaceWeapon()
{
}

void SpaceWeapon::Start()
{


	SpaceWeaponRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SpaceWeaponRender->SetTexture("CosmosSword00.png");
	SpaceWeaponRender->GetTransform()->SetLocalPosition({ 30.0f,-20.f,-750.f });
	SpaceWeaponRender->CreateAnimation({ .AnimationName = "SpaceSwordIdle", .SpriteName = "SpaceSwordIdle",.FrameInter = 0.05f, .Loop = true, .ScaleToTexture = true });
	SpaceWeaponRender->GetTransform()->SetLocalScale(SpaceWeaponScale);
	SpaceWeaponRender->ChangeAnimation("SpaceSwordIdle");

	SpaceWeaponEffectRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SpaceWeaponEffectRender->SetTexture("GreatSwingFX00.png");
	SpaceWeaponEffectRender->CreateAnimation({ .AnimationName = "SpaceSwordSwing", .SpriteName = "SpaceSwordSwing",.FrameInter = 0.05f, .Loop = false, .ScaleToTexture = true });

	SpaceWeaponCol = CreateComponent<GameEngineCollision>(ColOrder::GreatWeapon);
	SpaceWeaponCol->GetTransform()->SetLocalScale(SpaceWeaponColScale);
	SpaceWeaponCol->SetColType(ColType::AABBBOX2D);
	SpaceWeaponCol->Off();
	SkillRender = GetLevel()->CreateActor<SpaceSkill>();
	SkillRender->GetTransform()->SetWorldPosition({ 430.0f, -307.0f , 0.0f });
}
void SpaceWeapon::Update(float _Delta)
{
	SetSpaceWeapon(_Delta);
	SetCollision();
}


void SpaceWeapon::SetSpaceWeapon(float _Delta)
{
	AttackCol += _Delta;
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();

	MousePos = WeaponBase::GetMousePos();
	EffectPos = (MousePos - PlayerPos).NormalizeReturn();
	float4 GreatSwordPos = SpaceWeaponRender->GetTransform()->GetWorldPosition();
	SpaceWeaponEffectRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() - 90.0f });

	if (DirCheck == false)
	{
		if (WeaponBase::IsFlip() == false)
		{
			SpaceWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			SpaceWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() + 20.0f });
			SpaceWeaponRender->GetTransform()->SetLocalScale({ -256.0f,256.0f,0.0f });
			SpaceWeaponRender->GetTransform()->SetLocalPosition({ 25.0f,-25.f,1.f });

		}
		else
		{
			SpaceWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			SpaceWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() - 20.0f });
			SpaceWeaponRender->GetTransform()->SetLocalScale({ -256.0f,-256.0f,0.0f });
			SpaceWeaponRender->GetTransform()->SetLocalPosition({ -25.0f,-25.f,0.f });

		}
	}
	else
	{

		if (false == WeaponBase::IsFlip())
		{
			SpaceWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			SpaceWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() + 180.0f });
			SpaceWeaponRender->GetTransform()->SetLocalScale({ -256.0f,256.0f,0.0f });
			SpaceWeaponRender->GetTransform()->SetLocalPosition({ 25.0f,-50.f,1.f });

		}
		else
		{
			SpaceWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			SpaceWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() - 180.0f });
			SpaceWeaponRender->GetTransform()->SetLocalScale({ -256.0f,-256.0f,0.0f });
			SpaceWeaponRender->GetTransform()->SetLocalPosition({ -25.0f,-50.f,0.f });

		}
	}

	if (Player::MainPlayer->GetUICount() == 0 && AttackCol>0.3f && index == 0 && GameEngineInput::IsDown("ATTACK"))
	{
		GameEngineSound::Play("swing2.wav");
		AttackCol = 0.0f;
		ShakeValue = true;
		DirCheck = true;
		index = 1;
		SpaceWeaponEffectRender->ChangeAnimation("SpaceSwordSwing");
	}
	else if (Player::MainPlayer->GetUICount() == 0 && AttackCol > 0.3f && index == 1 && GameEngineInput::IsDown("ATTACK"))
	{
		GameEngineSound::Play("swing3 #218160.wav");
		AttackCol = 0.0f;
		ShakeValue = true;
		DirCheck = false;
		index = 0;
		SpaceWeaponEffectRender->ChangeAnimation("SpaceSwordSwing");
	}
	if (SpaceSkill::MainSkillPtr->GetSkillIndex() == 1 && index == 0 && GameEngineInput::IsDown("Skill"))
	{
		GameEngineSound::Play("mace skill.wav");
		SkillPtr = GetLevel()->CreateActor<Skill>();
		SkillPtr->GetTransform()->SetLocalPosition(PlayerPos);
		ShakeValue = true;
		DirCheck = true;
		index = 1;
		SpaceWeaponEffectRender->ChangeAnimation("SpaceSwordSwing");
	}
	else if (SpaceSkill::MainSkillPtr->GetSkillIndex() == 1 && index == 1 && GameEngineInput::IsDown("Skill"))
	{
		GameEngineSound::Play("mace skill.wav");
		SkillPtr = GetLevel()->CreateActor<Skill>();
		SkillPtr->GetTransform()->SetLocalPosition(PlayerPos);
		ShakeValue = true;
		DirCheck = false;
		index = 0;
		SpaceWeaponEffectRender->ChangeAnimation("SpaceSwordSwing");
	}
	if (ShakeValue == true)
	{
		SpaceWeaponCol->On();
		ShakeTime_0 += _Delta;
		WeaponBase::CameraShake(_Delta);
		if (ShakeTime_0 > 0.2f)
		{
			SpaceWeaponCol->Off();
		}
		if (ShakeTime_0 > 0.4f)
		{
			GetLevel()->GetMainCamera()->GetTransform()->SetWorldPosition(CameraPos);
			ShakeValue = false;
			ShakeTime_0 = 0.0f;
		}

	}

}


void SpaceWeapon::SetCollision()
{
	float4 Pos = SpaceWeaponEffectRender->GetTransform()->GetWorldPosition();
	float4 Deg = SpaceWeaponEffectRender->GetTransform()->GetLocalRotation();
	SpaceWeaponCol->GetTransform()->SetLocalRotation(Deg);
	SpaceWeaponCol->GetTransform()->SetWorldPosition({ Pos.x,Pos.y,0.0f });
}