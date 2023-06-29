#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "Tunak.h"
#include "Player.h"
#include "GroundBomb.h"
#include "WeaponBase.h"
#include "BossDeadEffect.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>
Tunak::Tunak()
{
}

Tunak::~Tunak()
{
}
/*
������ũ(0)

�������ϸ鼭 ��ü 2�� ������ (0)
������� (�⺻������ �÷��̾��� ��ġ�� üũ�� �������� �ٲ�����(0)
�ָ� �÷��̾� ��ġ�� ���� ��������ϰ� �÷��̾� �������� �ٲ㼭 ������� ���� ��ġ���̰� 500�̻��̶�� �ٷ� ������ �����������.(0)
��� ��ź ������
�����ϸ� ��ź ������ġ�� 4�� ������ �ϰ� �ٸ��������� �Ѿ��
�����Ŭ... �ѹ������ϸ� ���� ������ �޿���޸�.

*/
void Tunak::Start()
{
	TunakRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakRender->SetTexture("TunakIdle1111.png");
	TunakRender->GetTransform()->SetLocalScale(TunakScale);
	TunakRender->CreateAnimation({ .AnimationName = "TunakIdle", .SpriteName = "TunakIdle", .Loop = true , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakSpike", .SpriteName = "TunakSpike", .Loop = false , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakSpikeReady", .SpriteName = "TunakSpikeReady", .Loop = false , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakSpikeIdle", .SpriteName = "TunakSpikeIdle",.FrameInter=0.2f, .Loop = true , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakOverPower", .SpriteName = "TunakOverPower",.FrameInter = 0.1f, .Loop = false , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakDoubleAttack", .SpriteName = "TunakDoubleAttack",.FrameInter = 0.08f, .Loop = false , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakShout", .SpriteName = "TunakShout",.FrameInter = 0.2f, .Loop = true , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakJumpAttack", .SpriteName = "TunakJumpAttack", .Loop = false , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakBombCall", .SpriteName = "TunakBombCall", .Loop = false , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakShoulderTakleReady", .SpriteName = "TunakShoulderTakleReady", .Loop = false , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakShoulderTakleStart", .SpriteName = "TunakShoulderTakleStart", .Loop = true , .ScaleToTexture = false });
	TunakRender->CreateAnimation({ .AnimationName = "TunakDead", .SpriteName = "TunakDead", .Loop = false , .ScaleToTexture = false });

	
	TunakBulletBG = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletBG->CreateAnimation({ .AnimationName = "TunakBulletEffect", .SpriteName = "TunakBulletEffect", .Loop = false , .ScaleToTexture = true });
	
	
	TunakRender->ChangeAnimation("TunakIdle");
	ChangeState(TunakState::IDLE);


	TunakCol = CreateComponent<GameEngineCollision>(ColOrder::TUNAK);
	TunakCol->GetTransform()->SetLocalScale(TunakColScale);
	TunakCol->SetColType(ColType::AABBBOX2D);

	TunakDoubleAttackCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakDoubleAttackCol->GetTransform()->SetLocalScale(DoubleAttackScale);
	TunakDoubleAttackCol->SetColType(ColType::AABBBOX2D);
	TunakDoubleAttackCol->Off();

	TunakTackleCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakTackleCol->GetTransform()->SetLocalScale(TakcleScale);
	TunakTackleCol->SetColType(ColType::AABBBOX2D);
	TunakTackleCol->Off();

	BossHpFront = CreateComponent<GameEngineUIRenderer>(1);
	BossHpFront->SetTexture("BossLifeBack.png");
	BossHpFront->GetTransform()->SetWorldPosition(HPBasePos);
	BossHpFront->GetTransform()->SetLocalScale(HPBarBaseScale);

	BossHpBase = CreateComponent<GameEngineUIRenderer>(1);
	BossHpBase->SetTexture("BossLifeBase.png");
	BossHpBase->GetTransform()->SetWorldPosition(HPBasePos);
	BossHpBase->GetTransform()->SetLocalScale(HPBarBaseScale);

	BossHpBar = CreateComponent<GameEngineUIRenderer>(1);
	BossHpBar->SetTexture("BossHpBar.png");
	BossHpBar->GetTransform()->SetWorldPosition(HPPos);
	BossHpBar->GetTransform()->SetLocalScale(HPBarScale);

	DeadBGRender = CreateComponent<GameEngineUIRenderer>(1);
	DeadBGRender->SetTexture("BossDeadBG.png");
	DeadBGRender->GetTransform()->SetWorldPosition(float4::Null);
	DeadBGRender->GetTransform()->SetLocalScale({1280.0f,720.0f,0.0f});
	DeadBGRender->Off();
}

void Tunak::Update(float _DeltaTime)
{
	UpdateState(_DeltaTime);
	TunakCollision(_DeltaTime);
	DeadEvent(_DeltaTime);
	DamegeCheck();
}

void Tunak::DamegeCheck()
{
	//�����Ŭ ������ ���
	if (TunakTackleCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(TakcleDamage);
	}
	if (TunakDoubleAttackCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(DoubleAttackDamege);
	}
}

void Tunak::DeadEvent(float _DeltaTime)
{
	float4 TunakCurPos = GetTransform()->GetLocalPosition();
	if (ShackStart == true)
	{
		ShackEnd += _DeltaTime;
		TunakCameraShack(120);
		if (TunakHP > 0 && ShackEnd > 0.5f)
		{
			x = 0.f;
			ShackStart = false;
			ShackEnd = 0.0f;
		}

	}
	if (DeadShack == true)
	{
		DeadTime += _DeltaTime;
		DeadShackTime += _DeltaTime;
		TunakCameraShack(30);
		if (DeadShackTime > 0.05f)
		{
			x = 0.f;
			DeadShackTime = 0.0f;
		}
		if (DeadTime > 5.0f)
		{
			TimeCheck_D += _DeltaTime;
			TunakRender->Off();
			IsDead = true;
			if (TimeCheck_D > 0.1f)
			{
				TunakCurPos.y -= 100.0f;
				TunakCurPos.z = -850.0f;
				BossDeadEffectPtr = GetLevel()->CreateActor<BossDeadEffect>();
				BossDeadEffectPtr->GetTransform()->SetLocalPosition(TunakCurPos);
				BossDeadEffectPtr->SetRaioPos(RatioValue);
				RatioValue += 20.0f;
				TimeCheck_D = 0.0f;
			}
		}
		if (DeadTime > 8.0f)
		{
			DeadTime = 0.0f;
			Death();
		}
	}
}

void Tunak::TunakCameraShack(int _Value)
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();

	x += 0.5;
	y = sin(x * 10.0f) * powf(0.5f, x);
	float a = x;
	float b = y;
	GetLevel()->GetMainCamera()->GetTransform()->SetWorldPosition({ CameraPos.x + (y * 10),CameraPos.y + abs(y * _Value),CameraPos.z });
}

void Tunak::CalBezierBulletTransform(const float4& _Start, const float4& _Height, const float4& _End, float _Ratio)
{
	float4 M0 = float4::LerpClamp(_Start, _Height, _Ratio);
	float4 M1 = float4::LerpClamp(_Height, _End, _Ratio);
	float4 Pos = float4::LerpClamp(M0, M1, _Ratio);


	GetTransform()->SetWorldPosition(Pos);

}
void Tunak::TunakCollision(float _DeltaTime)
{
	BossHpFront->GetTransform()->SetWorldRotation(float4::Null);
	BossHpBase->GetTransform()->SetWorldRotation(float4::Null);
	BossHpBar->GetTransform()->SetWorldRotation(float4::Null);

	float4 Pos = TunakRender->GetTransform()->GetLocalPosition();
	//�� �ø�
	if (IsFilp == false)
	{
		TunakCol->GetTransform()->SetLocalPosition({ Pos.x + 50.0f,Pos.y - 120.0f,0.0f});
		TunakTackleCol->GetTransform()->SetLocalPosition({ Pos.x + 50.0f,Pos.y - 140.0f,0.0f });
	}
	else 
	{
		TunakCol->GetTransform()->SetLocalPosition({ Pos.x - 50.0f,Pos.y - 120.0f,0.0f });
		TunakTackleCol->GetTransform()->SetLocalPosition({ Pos.x - 50.0f,Pos.y - 140.0f,0.0f });
	}
	//�浹�� �����̸� hp�ޱ�
	if (TunakCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		if (TunakHitCheck == false)
		{
			//���߿� ui�۾��� ĳ���Ͱ� �����ִ� swich�� ���⿡ ���� ��������.
			TunakHP -= WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E);
			//���⼭ hpŬ��
			BossHpBar->ImageClippingX(static_cast<float>(TunakHP) / 1500.0f, ClipXDir::Left);
			TunakRender->ColorOptionValue.MulColor.r = 1.0f;
			TunakRender->ColorOptionValue.MulColor.g = 0.1f;
			TunakRender->ColorOptionValue.MulColor.b = 0.1f;
			TunakHitCheck = true;
		}

	}
	else {
		if (TunakHitCheck == true)
		{

			Invincibilitytime += _DeltaTime;
			if (Invincibilitytime > 0.1f)
			{
				TunakRender->ColorOptionValue.MulColor.r = 1.0f;
				TunakRender->ColorOptionValue.MulColor.g = 1.0f;
				TunakRender->ColorOptionValue.MulColor.b = 1.0f;
				TunakHitCheck = false;
				Invincibilitytime = 0.0f;
			}
		}
	}


}
void Tunak::TunakFlip()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 TunakPos = GetTransform()->GetLocalPosition();

	if (TunakPos.x - PlayerPos.x < 0)
	{
		TunakRender->GetTransform()->SetLocalNegativeScaleX();
		IsFilp = true;
	}
	else
	{
		TunakRender->GetTransform()->SetLocalPositiveScaleX();
		IsFilp = false;
	}
}

