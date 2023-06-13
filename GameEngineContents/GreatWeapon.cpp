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
	GreatWeaponRender->GetTransform()->SetLocalPosition({30.0f,-20.f,0.f});
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
	if (GameEngineInput::IsDown("ESC"))
	{
		int a = 0;
	}

}

