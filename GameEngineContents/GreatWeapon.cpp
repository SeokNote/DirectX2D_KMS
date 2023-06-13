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
//	GreatWeaponRender->GetTransform()->SetLocalNegativeScaleX();
	GreatWeaponRender->GetTransform()->SetLocalPosition({30.0f,-20.f,-750.f});
	GreatWeaponRender->GetTransform()->SetLocalScale(GreatWeaponScale);

	GreatWeaponEffectRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GreatWeaponEffectRender->SetTexture("GreatSwingFX00.png");
	GreatWeaponEffectRender->CreateAnimation({ .AnimationName = "GreatSwordAniIdle", .SpriteName = "GreatSwordAni",.FrameInter=0.05f, .Loop=false, .ScaleToTexture = true });
	//GreatWeaponEffectRender->GetTransform()->SetLocalPosition({ 30.0f,-20.f,-750.f });
//	GreatWeaponEffectRender->GetTransform()->SetLocalScale(GreatWeaponScale);

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
	float4 EffectPos = (MousePos - PlayerPos).NormalizeReturn();
	float4 GreatSwordPos = GreatWeaponRender->GetTransform()->GetWorldPosition();
	GreatWeaponEffectRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg-90.0f });
	
	if (awda == false)
	{
		if (FilpX > 0)
		{
			GreatWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y+EffectPos.y * 100.0f,-802.0f });
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg + 20.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale(GreatWeaponScale);
			GreatWeaponRender->GetTransform()->SetLocalPosition({ 10.0f,-25.f,-750.f });

		}
		else
		{
			GreatWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg - 20.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale({ -256.0f,-256.0f,0.0f });
			GreatWeaponRender->GetTransform()->SetLocalPosition({ -10.0f,-25.f,-750.f });

		}
	}
	else
	{

		if (FilpX > 0)
		{
			GreatWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
			GreatWeaponRender->GetTransform()->SetLocalRotation({ 0.0f,0.0f,ZDeg + 180.0f });
			GreatWeaponRender->GetTransform()->SetLocalScale({ -256.0f,256.0f,0.0f });
			GreatWeaponRender->GetTransform()->SetLocalPosition({ 20.0f,-50.f,-750.f });

		}
		else
		{
			GreatWeaponEffectRender->GetTransform()->SetWorldPosition({ PlayerPos.x + EffectPos.x * 100.0f ,PlayerPos.y + EffectPos.y * 100.0f,-802.0f });
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
		GreatWeaponEffectRender->ChangeAnimation("GreatSwordAniIdle");
	}
	else if (index==1 && GameEngineInput::IsDown("ATTACK"))
	{
		//	GreatWeaponRender->GetTransform()->SetLocalPosition({ -20.0f,-50.f,-750.f });
			//GreatWeaponRender->GetTransform()->AddWorldRotation({ 0.0f,0.0f,160.0f });
		awda = false;
		index = 0;
		GreatWeaponEffectRender->ChangeAnimation("GreatSwordAniIdle");
	}
}

