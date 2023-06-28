#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "Tunak.h"
#include "Player.h"
#include "GroundBomb.h"
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

	
	TunakBulletBG = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletBG->CreateAnimation({ .AnimationName = "TunakBulletEffect", .SpriteName = "TunakBulletEffect", .Loop = false , .ScaleToTexture = true });
	
	
	TunakRender->ChangeAnimation("TunakIdle");
	ChangeState(TunakState::IDLE);


	TunakCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
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

	
}

void Tunak::Update(float _DeltaTime)
{
	TunakCol->Off();
	UpdateState(_DeltaTime);
	TunakColision();
}

void Tunak::CalBezierBulletTransform(const float4& _Start, const float4& _Height, const float4& _End, float _Ratio)
{
	float4 M0 = float4::LerpClamp(_Start, _Height, _Ratio);
	float4 M1 = float4::LerpClamp(_Height, _End, _Ratio);
	float4 Pos = float4::LerpClamp(M0, M1, _Ratio);


	GetTransform()->SetWorldPosition(Pos);
	//std::shared_ptr<TunakBullet> TunakBulletPtr = CreateActor<TunakBullet>(1);
	//TunakBulletPtr->GetTransform()->SetLocalPosition({ 15074.0f,-100.0f,-800.0f });
	//TunakBulletPtr->GetTransform()->SetLocalRotation({ 0.0f,0.0f,15.0f });
}
void Tunak::TunakColision()
{
	float4 Pos = TunakRender->GetTransform()->GetLocalPosition();
	//�� �浹ü (�÷��̾ �����°�)
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

