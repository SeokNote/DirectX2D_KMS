#include "PrecompileHeader.h"
#include "WeaponSwichUI.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

WeaponSwichUI::WeaponSwichUI()
{
}

WeaponSwichUI::~WeaponSwichUI()
{
}

void WeaponSwichUI::Start()
{

	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	PlayerWeaponSwichUIUI3 = CreateComponent<GameEngineUIRenderer>(90);
	PlayerWeaponSwichUIUI3->SetTexture("EquippedWeaponBase.png");
	PlayerWeaponSwichUIUI3->GetTransform()->SetWorldPosition(PlayerWeaponSwichUIPos);
	PlayerWeaponSwichUIUI3->GetTransform()->SetLocalScale(PlayerWeaponSwichUIScale);

	PlayerWeaponSwichUIUI2 = CreateComponent<GameEngineUIRenderer>(89);
	PlayerWeaponSwichUIUI2->SetTexture("EquippedWeaponBase.png");
	PlayerWeaponSwichUIUI2->GetTransform()->SetWorldPosition(PlayerWeaponSwichUIPos_B);
	PlayerWeaponSwichUIUI2->GetTransform()->SetLocalScale(PlayerWeaponSwichUIScale);


}

void WeaponSwichUI::Update(float _Delta)
{
	if (true == GameEngineInput::IsDown("WEAPONSWICH"))
	{
		SwichTriger = true;
		ChangePos = false;
		Ratio = 0.0f;
	}
	if (SwichTriger == true)
	{
		Ratio += _Delta;
		if (ChangePos == false)
		{
			M1 = float4::LerpClamp(PlayerWeaponSwichUIPos, EndPos, Ratio * 2.0f);
			PlayerWeaponSwichUIUI3->GetTransform()->SetWorldPosition(M1);
			M2 = float4::LerpClamp(PlayerWeaponSwichUIPos_B, EndPos, Ratio * 2.0f);
			PlayerWeaponSwichUIUI2->GetTransform()->SetWorldPosition(M2);
			if (M1 == EndPos)
			{
				ChangePos = true;
				Ratio = 0.0f;
			}
		}
		else
		{
			M1 = float4::LerpClamp(EndPos, PlayerWeaponSwichUIPos, Ratio * 2.0f);
			PlayerWeaponSwichUIUI3->GetTransform()->SetWorldPosition(M1);
			M2 = float4::LerpClamp(EndPos, PlayerWeaponSwichUIPos_B, Ratio * 2.0f);
			PlayerWeaponSwichUIUI2->GetTransform()->SetWorldPosition(M2);
			
			if (M1 == PlayerWeaponSwichUIPos)
			{
				SwichTriger = false;
			}
		}

		
	}
}

