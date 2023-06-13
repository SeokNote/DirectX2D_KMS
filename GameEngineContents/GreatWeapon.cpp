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


	GreatWeaponRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GreatWeaponRender->SetTexture("GreatSword0.png");
//	GreatWeaponRender->GetTransform()->SetLocalNegativeScaleX();
	GreatWeaponRender->GetTransform()->SetLocalPosition({30.0f,-20.f,-750.f});
	GreatWeaponRender->GetTransform()->SetLocalScale(GreatWeaponScale);
}
bool awda = false;
void GreatWeapon::Update(float _Delta)
{

	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetMainCamera();
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();

	float4x4 ViewPort = Camera->GetViewPort();
	float4x4 projection = Camera->GetProjection();
	float4x4 View = Camera->GetView();

	float4 MousePos = GameEngineInput::GetMousePosition();
	MousePos *= ViewPort.InverseReturn();
	MousePos *= projection.InverseReturn();
	MousePos *= View.InverseReturn();
	float ZDeg = atan2(MousePos.y - PlayerPos.y, MousePos.x - PlayerPos.x) * GameEngineMath::RadToDeg;
	float FilpX = MousePos.x - PlayerPos.x;
	if (awda == false)
	{
		if (FilpX > 0)
		{
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg + 20.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale(GreatWeaponScale);
			GreatWeaponRender->GetTransform()->SetLocalPosition({ 10.0f,-25.f,-750.f });

		}
		else
		{
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg - 20.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale({ -256.0f,-256.0f,0.0f });
			GreatWeaponRender->GetTransform()->SetLocalPosition({ -10.0f,-25.f,-750.f });

		}
	}
	else
	{
		if (FilpX > 0)
		{
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg + 180.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale({ -256.0f,256.0f,0.0f });
			GreatWeaponRender->GetTransform()->SetLocalPosition({ 20.0f,-50.f,-750.f });

		}
		else
		{
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg - 180.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale({ -256.0f,-256.0f,0.0f });
			GreatWeaponRender->GetTransform()->SetLocalPosition({ -20.0f,-50.f,-750.f });

		}
	}

	if (index==0&&GameEngineInput::IsDown("ATTACK"))
	{
	//	GreatWeaponRender->GetTransform()->SetLocalPosition({ -20.0f,-50.f,-750.f });
		//GreatWeaponRender->GetTransform()->AddWorldRotation({ 0.0f,0.0f,160.0f });
		awda = true;
		index = 1;
	}
	else if (index==1 && GameEngineInput::IsDown("ATTACK"))
	{
		//	GreatWeaponRender->GetTransform()->SetLocalPosition({ -20.0f,-50.f,-750.f });
			//GreatWeaponRender->GetTransform()->AddWorldRotation({ 0.0f,0.0f,160.0f });
		awda = false;
		index = 0;
	}
}

