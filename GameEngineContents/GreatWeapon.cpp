#include "PrecompileHeader.h"
#include "Player.h"
#include "GreatWeapon.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
GreatWeapon::GreatWeapon() 
{
}

GreatWeapon::~GreatWeapon() 
{
}

void GreatWeapon::Start()
{
	if (nullptr == GameEngineSprite::Find("GreatSwordAni"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("MainLevelAnimation");
		NewDir.Move("WeaponAni");
		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("GreatSwordAni").GetFullPath());

	}

	GreatWeaponRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GreatWeaponRender->SetTexture("GreatSword0.png");
	GreatWeaponRender->GetTransform()->SetLocalPosition({30.0f,-20.f,-750.f});
	GreatWeaponRender->GetTransform()->SetLocalScale(GreatWeaponScale);

	GreatWeaponEffectRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GreatWeaponEffectRender->SetTexture("GreatSwingFX00.png");
	GreatWeaponEffectRender->CreateAnimation({ .AnimationName = "GreatSwordAniIdle", .SpriteName = "GreatSwordAni",.FrameInter=0.05f, .Loop=false, .ScaleToTexture = true });

	GreatWeaponCol = CreateComponent<GameEngineCollision>(ColOrder::GreatWeapon);
	GreatWeaponCol->GetTransform()->SetLocalScale(GreatWeaponColScale);
	GreatWeaponCol->SetColType(ColType::AABBBOX2D);
	GreatWeaponCol->Off();
}
bool DirCheck = false;
void GreatWeapon::Update(float _Delta)
{
	SetGreatWeapon(_Delta);
	SetCollision();
}


void GreatWeapon::SetGreatWeapon(float _Delta)
{
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();

	MousePos = WeaponBase::GetMousePos();
	float4 EffectPos = (MousePos - PlayerPos).NormalizeReturn();
	float4 GreatSwordPos = GreatWeaponRender->GetTransform()->GetWorldPosition();
	GreatWeaponEffectRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() - 90.0f });

	if (DirCheck == false)
	{
		if (WeaponBase::IsFlip()==false)
		{
			GreatWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() + 20.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale(GreatWeaponScale);
			GreatWeaponRender->GetTransform()->SetLocalPosition({ 10.0f,-25.f,1.f });

		}
		else
		{
			GreatWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() - 20.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale({ -256.0f,-256.0f,0.0f });
			GreatWeaponRender->GetTransform()->SetLocalPosition({ -10.0f,-25.f,0.f });

		}
	}
	else
	{

		if (false == WeaponBase::IsFlip())
		{
			GreatWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() + 180.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale({ -256.0f,256.0f,0.0f });
			GreatWeaponRender->GetTransform()->SetLocalPosition({ 20.0f,-50.f,1.f });

		}
		else
		{
			GreatWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,WeaponBase::GetDeg() - 180.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale({ -256.0f,-256.0f,0.0f });
			GreatWeaponRender->GetTransform()->SetLocalPosition({ -20.0f,-50.f,0.f });

		}
	}

	if (index == 0 && GameEngineInput::IsDown("ATTACK"))
	{
		ShakeValue = true;
		DirCheck = true;
		index = 1;
		GreatWeaponEffectRender->ChangeAnimation("GreatSwordAniIdle");
	}
	else if (index == 1 && GameEngineInput::IsDown("ATTACK"))
	{
		ShakeValue = true;
		DirCheck = false;
		index = 0;
		GreatWeaponEffectRender->ChangeAnimation("GreatSwordAniIdle");
	}
	if (ShakeValue == true)
	{
		GreatWeaponCol->On();
		ShakeTime_0 += _Delta;
		WeaponBase::CameraShake(_Delta);
		if (ShakeTime_0 > 0.2f)
		{
			GreatWeaponCol->Off();
		}
		if (ShakeTime_0 > 0.4f)
		{
			GetLevel()->GetMainCamera()->GetTransform()->SetWorldPosition(CameraPos);
			ShakeValue = false;
			ShakeTime_0 = 0.0f;
		}

	}

}


void GreatWeapon::SetCollision()
{
	float4 Pos = GreatWeaponEffectRender->GetTransform()->GetWorldPosition();
	float4 Deg = GreatWeaponEffectRender->GetTransform()->GetLocalRotation();
	GreatWeaponCol->GetTransform()->SetLocalRotation(Deg);
	GreatWeaponCol->GetTransform()->SetWorldPosition({ Pos.x,Pos.y,0.0f });
}