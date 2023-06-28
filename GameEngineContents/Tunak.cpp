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
스파이크(0)

샤우팅하면서 구체 2번 날리기 (0)
더블어택 (기본적으로 플레이어의 위치를 체크해 스케일을 바꿔주자(0)
멀면 플레이어 위치로 가서 더블어택하고 플레이어 방향으로 바꿔서 더블어택 만약 위치차이가 500이상이라면 바로 점프후 더블어택하자.(0)
고블린 폭탄 떨구기
손짓하면 폭탄 렌덤위치에 4개 던지기 하고 다른패턴으로 넘어가자
숄더태클... 한번시작하면 맵의 끝까지 쭈우우욱달림.

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
	//몸 충돌체 (플레이어가 때리는곳)
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

