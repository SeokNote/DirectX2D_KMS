#include "PrecompileHeader.h"
#include "WhiteSkell.h"
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
WhiteSkell::WhiteSkell() 
{
}

WhiteSkell::~WhiteSkell() 
{
}

void WhiteSkell::Start()
{
	WhiteSkellRender = CreateComponent<GameEngineSpriteRenderer>(1);
	WhiteSkellRender->SetTexture("BigWhiteSkelIdle.png");
	WhiteSkellRender->GetTransform()->SetLocalScale(Scale);
	WhiteSkellRender->CreateAnimation({ .AnimationName = "WhiteSkellMove", .SpriteName = "WhiteSkellMove", .Loop = true , .ScaleToTexture = false });
	WhiteSkellRender->CreateAnimation({ .AnimationName = "WhiteSkellIdle", .SpriteName = "WhiteSkellIdle", .Loop = true , .ScaleToTexture = false });
	WhiteSkellRender->CreateAnimation({ .AnimationName = "WhiteSkellAttack", .SpriteName = "WhiteSkellAttack", .Loop = false , .ScaleToTexture = false });
	WhiteSkellRender->ChangeAnimation("WhiteSkellIdle");
	ChangeState(WhiteSkellState::IDLE);

	TargetAreaCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	TargetAreaCol->GetTransform()->SetLocalPosition({ 230.0f,-40.0f,0.f });
	TargetAreaCol->GetTransform()->SetLocalScale(AreaPos);
	TargetAreaCol->SetColType(ColType::AABBBOX2D);

	SkellBodyCol = CreateComponent<GameEngineCollision>(ColOrder::ATTACKAREA);
	SkellBodyCol->GetTransform()->SetLocalPosition({ -70.0f,-40.0f,0.f });
	SkellBodyCol->GetTransform()->SetLocalScale(ColScale);
	SkellBodyCol->SetColType(ColType::AABBBOX2D);

	AttackAreaCol = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	AttackAreaCol->GetTransform()->SetLocalScale(AttackColScale);
	AttackAreaCol->SetColType(ColType::AABBBOX2D);
	AttackAreaCol->Off();
	AreaInRender = CreateComponent<GameEngineSpriteRenderer>(1);
	AreaInRender->SetTexture("ExMark03.png");
	AreaInRender->GetTransform()->SetLocalScale(InScale);
	AreaInRender->GetTransform()->SetLocalPosition({ 10.0f,70.0f,0.0f });
	AreaInRender->Off();
}

void WhiteSkell::Update(float _DeltaTime)
{
	UpdateState(_DeltaTime);
	SetCollision(_DeltaTime);
	FlipCheck();
}
bool SkellBlink = false;
void WhiteSkell::SetCollision(float _DeltaTime)
{
	if (AttackAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		Player::MainPlayer->GetData().SubPlayerHP(Damege);
	}
	if (TargetAreaCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		InArea = true;
	}
	else
	{
		//InArea = false;

	}
	if (SkellBodyCol->Collision(ColOrder::GreatWeapon, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		InArea = true;
		if (SkellBlink == false)
		{
			//나중에 ui작업때 캐릭터가 갖고있는 swich로 무기에 따라 정해주자.
			SkellHP -= WeaponBase::WeaponBasePtr->GetWeaponStrength(Weapon::GreatWeapon_E);
			//여기서 hp클립
			//BossHpBar->ImageClippingX(static_cast<float>(BelialHp) / 1000.0f, ClipXDir::Left);
			WhiteSkellRender->ColorOptionValue.MulColor.r = 1.0f;
			WhiteSkellRender->ColorOptionValue.MulColor.g = 0.1f;
			WhiteSkellRender->ColorOptionValue.MulColor.b = 0.1f;
			SkellBlink = true;
		}

	}
	else {
		if (SkellBlink == true)
		{

			Invincibilitytime += _DeltaTime;
			if (Invincibilitytime > 0.1f)
			{
				WhiteSkellRender->ColorOptionValue.MulColor.r = 1.0f;
				WhiteSkellRender->ColorOptionValue.MulColor.g = 1.0f;
				WhiteSkellRender->ColorOptionValue.MulColor.b = 1.0f;
				SkellBlink = false;
				Invincibilitytime = 0.0f;
			}
		}
	}
}

bool WhiteSkell::GroundCheck()
{
	float4 MonsterPos = GetTransform()->GetLocalPosition();
	PixelMapResultPos = PixelCalculation(MonsterPos, { 5320.0f,0.0f,0.0f }, { 1280.0f,720.0f });
	Ptr = GameEngineTexture::Find("StageCol_2.png");
	Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y + 167.0f));
	Pixel.a = 0;
	if (Pixel == GameEnginePixelColor::Black)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void WhiteSkell::FlipCheck()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 MyPos = GetTransform()->GetLocalPosition();
	if (PlayerPos.x - MyPos.x < 0)
	{
		IsFlip = true;
	}
	else 
	{
		IsFlip = false;
	}
}
float4 WhiteSkell::PixelCalculation(float4 _TargetPos, float4 _MapCenterPos, float4 _TransColPos)
{
	TargetPos = _TargetPos;
	PixelMapResultPos.x = _TargetPos.x + _TransColPos.x - _MapCenterPos.x;
	PixelMapResultPos.y = _TransColPos.y - _TargetPos.y;
	return PixelMapResultPos;
}