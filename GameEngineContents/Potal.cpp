#include "PrecompileHeader.h"
#include "Potal.h"
#include "ContentsEnums.h"
#include "Player.h"
#include "PortalParticle.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
Potal::Potal() 
{
}

Potal::~Potal() 
{
}

void Potal::Start()
{
	SteleRender = CreateComponent<GameEngineSpriteRenderer>(1);
	SteleRender->GetTransform()->SetLocalScale(Scale);
	SteleRender->SetTexture("SteleOpen00.png");
	
	SteleRender->CreateAnimation({ .AnimationName = "SteleClose", .SpriteName = "SteleClose", .Loop = false , .ScaleToTexture = false });
	SteleRender->CreateAnimation({ .AnimationName = "SteleOpen", .SpriteName = "SteleOpen", .Loop = false , .ScaleToTexture = false });
	SteleRender->CreateAnimation({ .AnimationName = "SteleIdle", .SpriteName = "SteleIdle", .Loop = true , .ScaleToTexture = false });
	
	SteleCol = CreateComponent<GameEngineCollision>(ColOrder::POTAL);
	SteleCol->GetTransform()->SetLocalScale(Scale);
	SteleCol->SetColType(ColType::OBBBOX2D);
	SteleCol->Off();
	ChangeState(PotalState::IDLE);

}

void Potal::Update(float _Delta)
{
	float4 MyPos = GetTransform()->GetWorldPosition();

	UpdateState(_Delta);
	if (Player::MainPlayer->GetData().GetMonsterIndex() == 0)
	{
		PTCSetting(_Delta);

	}
	SteleCol->GetTransform()->SetWorldPosition(SteleRender->GetTransform()->GetWorldPosition());
}

void Potal::PTCSetting(float _Delta)
{
	//외부에서 범위와 dir을 입력해준다,.
	float4 MyPos = GetTransform()->GetLocalPosition();
	CreateTime0 += _Delta;
	CreateTime1 += _Delta;
	CreateTime2 += _Delta;
	if (CreateTime0 > 0.5f)
	{
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y+ PivotY,MyPos.z }, Pos,Dir);
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y+ PivotY,MyPos.z }, Pos,Dir);
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y+ PivotY,MyPos.z }, Pos,Dir);
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y+ PivotY,MyPos.z }, Pos,Dir);
		CreateTime0 = 0.0f;							
	}												
	if (CreateTime1 > 1.0f)							
	{												
		CreateTime1 = 0.0f;							
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y + PivotY,MyPos.z }, Pos, Dir);
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y + PivotY,MyPos.z },Pos, Dir);
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y + PivotY,MyPos.z },Pos, Dir);
														
	}													
	if (CreateTime2 > 0.3f)								
	{													
		CreateTime2 = 0.0f;								
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y + PivotY,MyPos.z }, Pos, Dir);
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + PivotX,MyPos.y + PivotY,MyPos.z }, Pos, Dir);
	}
}


