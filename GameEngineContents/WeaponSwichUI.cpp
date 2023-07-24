#include "PrecompileHeader.h"
#include "WeaponSwichUI.h"
#include "InventoryUI.h"
#include "InventoryButton.h"
#include "SpaceSkill.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include "GreatWeapon.h"
#include "SpaceWeapon.h"
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

	PlayerWeaponRender = CreateComponent<GameEngineUIRenderer>(91);
	PlayerWeaponRender->GetTransform()->SetWorldPosition(PlayerWeaponSwichUIPos);
	PlayerWeaponRender->GetTransform()->SetWorldScale({76.0f,28.0f,0.f});
	GreatWeaponPtr =GetLevel()->CreateActor<GreatWeapon>(1);
	GreatWeaponPtr->GetTransform()->SetParent(Player::MainPlayer->GetTransform());
	GreatWeaponPtr->Off();
	SpaceWeaponPtr = GetLevel()->CreateActor<SpaceWeapon>(1);
	SpaceWeaponPtr->GetTransform()->SetParent(Player::MainPlayer->GetTransform());
	SpaceWeaponPtr->Off();
}
// 스왑을 누를수 있는 시간을 정해주자.
// 내가 보유하고 있는 무기에 따른 렌더러를 띄우고 둘이 겹치는 순간 렌더러를 바꿔줌.
void WeaponSwichUI::Update(float _Delta)
{
	GreatWeaponPtr->GetTransform()->SetWorldPosition(Player::MainPlayer->GetTransform()->GetWorldPosition());
	SpaceWeaponPtr->GetTransform()->SetWorldPosition(Player::MainPlayer->GetTransform()->GetWorldPosition());
	MyWeapon0 = InventoryUI::InventoryUIPtr->GetWeaponInven0()->GetData().WeaponType;
	MyWeapon1 = InventoryUI::InventoryUIPtr->GetWeaponInven1()->GetData().WeaponType;
	if (SwichValue == false && true == GameEngineInput::IsDown("WEAPONSWICH"))
	{
		GameEngineSound::Play("etc-sound0033_swap.wav");
		SwichValue = true;
		SwichTriger = true;
		ChangePos = false;
		Ratio = 0.0f;
		Count++;
	}
	if (SwichTriger == true)
	{
		Ratio += _Delta;
		if (ChangePos == false)
		{

			M1 = float4::LerpClamp(PlayerWeaponSwichUIPos, EndPos, Ratio * 3.0f);
			PlayerWeaponSwichUIUI3->GetTransform()->SetWorldPosition(M1);
			PlayerWeaponRender->GetTransform()->SetWorldPosition(M1);
			M2 = float4::LerpClamp(PlayerWeaponSwichUIPos_B, EndPos, Ratio * 3.0f);
			PlayerWeaponSwichUIUI2->GetTransform()->SetWorldPosition(M2);

			if (M1 == EndPos)
			{
				if (Count % 2 == 0)
				{
					CurWeaponIndex = 0;
				}
				else
				{
					CurWeaponIndex = 1;
				}
				ChangePos = true;
				Ratio = 0.0f;
			}
		}
		else
		{
			M1 = float4::LerpClamp(EndPos, PlayerWeaponSwichUIPos, Ratio * 3.0f);
			PlayerWeaponSwichUIUI3->GetTransform()->SetWorldPosition(M1);
			PlayerWeaponRender->GetTransform()->SetWorldPosition(M1);

			M2 = float4::LerpClamp(EndPos, PlayerWeaponSwichUIPos_B, Ratio * 3.0f);
			PlayerWeaponSwichUIUI2->GetTransform()->SetWorldPosition(M2);

			
			if (M1 == PlayerWeaponSwichUIPos)
			{
				SwichTriger = false;
				SwichValue = false;
			}
		}

		
	}
	if (CurWeaponIndex == 0)
	{
		PlayerWeaponRender->SetTexture(InventoryUI::InventoryUIPtr->GetWeaponInven0()->GetData().ItemSwichRender);
		switch (MyWeapon0)
		{
		case WeaponDatas::VACANCY:
			SpaceWeaponPtr->Off();
			GreatWeaponPtr->Off();
			SpaceSkill::MainSkillPtr->Off();
			break;
		case WeaponDatas::GreatWeapon:
			SpaceWeaponPtr->Off();
			GreatWeaponPtr->On();
			SpaceSkill::MainSkillPtr->Off();
			break;
		case WeaponDatas::SpaceSword:
			SpaceWeaponPtr->On();
			GreatWeaponPtr->Off();
			SpaceSkill::MainSkillPtr->On();
			break;
		default:
			break;
		}
	}
	else
	{
		PlayerWeaponRender->SetTexture(InventoryUI::InventoryUIPtr->GetWeaponInven1()->GetData().ItemSwichRender);
		switch (MyWeapon1)
		{
		case WeaponDatas::VACANCY:
			SpaceWeaponPtr->Off();
			GreatWeaponPtr->Off();
			SpaceSkill::MainSkillPtr->Off();
			break;
		case WeaponDatas::GreatWeapon:
			SpaceWeaponPtr->Off();
			GreatWeaponPtr->On();
			SpaceSkill::MainSkillPtr->Off();
			break;
		case WeaponDatas::SpaceSword:
			SpaceWeaponPtr->On();
			GreatWeaponPtr->Off();
			SpaceSkill::MainSkillPtr->On();
			break;
		default:
			break;
		}
	}
}

//무기
