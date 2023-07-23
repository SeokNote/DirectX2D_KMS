#include "PrecompileHeader.h"
#include "Potal.h"
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

}

void Potal::Update(float _Delta)
{
	if (Player::MainPlayer->GetData().GetMonsterIndex() == 0)
	{
		PTCSetting(_Delta);

	}
}

void Potal::PTCSetting(float _Delta)
{
	float4 MyPos = GetTransform()->GetLocalPosition();
	CreateTime0 += _Delta;
	CreateTime1 += _Delta;
	CreateTime2 += _Delta;
	if (CreateTime0 > 0.5f)
	{
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });
		CreateTime0 = 0.0f;
	}
	if (CreateTime1 > 1.0f)
	{
		CreateTime1 = 0.0f;
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });

	}
	if (CreateTime2 > 0.3f)
	{
		CreateTime2 = 0.0f;
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });
		PortalParticle::CreatePTC(GetLevel(), { MyPos.x + 10.0f,MyPos.y,MyPos.z }, { 20.0f,120.0f,0.0f }, { -1.0f,0.0f,0.0f });
	}
}


