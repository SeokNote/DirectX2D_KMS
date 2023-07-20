#include "PrecompileHeader.h"
#include "Banshee.h"
#include "Player.h"

#include "ContentsEnums.h"
#include "WeaponBase.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
Banshee::Banshee()
{
}

Banshee::~Banshee()
{
}

void Banshee::Start()
{
	Rad = GameEngineMath::PIE2 / A_Count;

	BansheeRender = CreateComponent<GameEngineSpriteRenderer>(1);
	BansheeRender->SetTexture("BigWhiteSkelIdle.png");
	BansheeRender->GetTransform()->SetLocalScale(Scale);
	BansheeRender->CreateAnimation({ .AnimationName = "BansheeAttack", .SpriteName = "BansheeAttack", .Loop = false , .ScaleToTexture = false });
	BansheeRender->CreateAnimation({ .AnimationName = "BansheeIdle", .SpriteName = "BansheeIdle", .Loop = true , .ScaleToTexture = false });
	BansheeRender->ChangeAnimation("BansheeIdle");
	ChangeState(BansheeState::IDLE);


	HpBaseRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpBaseRender->SetTexture("MonsterHpBase.png");
	HpBaseRender->GetTransform()->SetLocalScale(HpBaseScale);
	HpBaseRender->GetTransform()->SetLocalPosition({ -5.0f,-65.0f,0.f });
	HpBaseRender->Off();

	HpRender = CreateComponent<GameEngineSpriteRenderer>(1);
	HpRender->SetTexture("MonsterHpBar.png");
	HpRender->GetTransform()->SetLocalScale(HpBarScale);
	HpRender->GetTransform()->SetLocalPosition({ -5.0f,-65.0f,0.f });
	HpRender->Off();

	DeadRender = CreateComponent<GameEngineSpriteRenderer>(1);
	DeadRender->SetTexture("Die10.png");
	DeadRender->CreateAnimation({ .AnimationName = "BansheeDead", .SpriteName = "BossDead",.FrameInter = 0.07f,.Loop = false , .ScaleToTexture = true });
	DeadRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });

	AttackAreaCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	AttackAreaCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.f });
	AttackAreaCol->GetTransform()->SetLocalScale(AttackAreaScale);
	AttackAreaCol->SetColType(ColType::AABBBOX2D);

	BodyCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERBODY);
	BodyCol->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	BodyCol->GetTransform()->SetLocalScale(ColScale);
	BodyCol->SetColType(ColType::AABBBOX2D);
	SetDeg();
}

void Banshee::Update(float _DeltaTime)
{

	UpdateState(_DeltaTime);
	SetCollision(_DeltaTime);
	Flip();

}
void Banshee::SetDeg()
{
	for (int i = 0; i < A_Count; i++)
	{
		float4 Dir = { cos(Rad * i),sin(Rad * i),0.0f,0.0f };
		Degs.push_back(Dir);
	}
}
void Banshee::SetCollision(float _DeltaTime)
{
	HpRender->ImageClippingX(static_cast<float>(Hp) / static_cast<float>(MaxHp), ClipXDir::Left);
	if (AttackAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		AttackMove = true;
	}
	if (BodyCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		HpRender->On();
		HpBaseRender->On();
		if (BansheeBlink == false)
		{
			//나중에 ui작업때 캐릭터가 갖고있는 swich로 무기에 따라 정해주자.
			Hp -= WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E);
			BansheeRender->ColorOptionValue.MulColor.r = 1.0f;
			BansheeRender->ColorOptionValue.MulColor.g = 0.1f;
			BansheeRender->ColorOptionValue.MulColor.b = 0.1f;
			BansheeBlink = true;
		}

	}
	else {
		if (BansheeBlink == true)
		{

			Invincibilitytime += _DeltaTime;
			if (Invincibilitytime > 0.05f)
			{
				BansheeRender->ColorOptionValue.MulColor.r = 1.0f;
				BansheeRender->ColorOptionValue.MulColor.g = 1.0f;
				BansheeRender->ColorOptionValue.MulColor.b = 1.0f;
				BansheeBlink = false;
				Invincibilitytime = 0.0f;
			}
		}
	}
}

void Banshee::Flip()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 MyPos = GetTransform()->GetLocalPosition();
	if (PlayerPos.x - MyPos.x > 0)
	{
		BansheeRender->GetTransform()->SetLocalPositiveScaleX();
	}
	else
	{
		BansheeRender->GetTransform()->SetLocalNegativeScaleX();

	}
}

