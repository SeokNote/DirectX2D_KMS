#include "PrecompileHeader.h"
#include "WeaponBase.h"
#include "Player.h"

#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
WeaponBase* WeaponBase::WeaponBasePtr = nullptr;

WeaponBase::WeaponBase() 
{
	WeaponBasePtr = this;
}

WeaponBase::~WeaponBase() 
{
}

void WeaponBase::Start()
{
}

void WeaponBase::Update(float _Delta)
{
	GetMousePos();
	GetDeg();
}

void WeaponBase::CameraShake(float _Delta)
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();

	ShakeTime += _Delta;
	x += 0.5;
	y = sin(x * 10.0f) * powf(0.5f, x);

	GetLevel()->GetMainCamera()->GetTransform()->SetWorldPosition({ CameraPos.x,CameraPos.y + abs(y * 30),CameraPos.z });

	if (ShakeTime > 0.4f)
	{
		x = 0.f;
		ShakeTime = 0.0f;
	}

}


float4 WeaponBase::GetMousePos()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetMainCamera();
	PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();

	float4x4 ViewPort = Camera->GetViewPort();
	float4x4 projection = Camera->GetProjection();
	float4x4 View = Camera->GetView();

	MousePos = GameEngineInput::GetMousePosition();
	MousePos *= ViewPort.InverseReturn();
	MousePos *= projection.InverseReturn();
	MousePos *= View.InverseReturn();

	return MousePos;
}

bool WeaponBase::IsFlip()
{
	float FilpX = MousePos.x - PlayerPos.x;
	if (FilpX > 0.0f)
	{
		return false;
	}
	else
	{
		return true;
	}
}

float WeaponBase::GetDeg()
{
	float ZDeg = atan2(MousePos.y - PlayerPos.y, MousePos.x - PlayerPos.x) * GameEngineMath::RadToDeg;
	return ZDeg;

}

int WeaponBase::GetWeaponStrength(Weapon _MyWeapon)
{
	switch (_MyWeapon)
	{
	case None:
		return 0;
		break;
	case GreatWeapon_E:
		WeaponStrength = GameEngineRandom::MainRandom.RandomInt(20, 27);
		return WeaponStrength;
		break;
	default:
		return 0;
		break;
	}
	return 0;
}
