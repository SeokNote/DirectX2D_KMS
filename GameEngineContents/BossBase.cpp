#include "BossBase.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineBase/GameEngineRandom.h>
BossBase::BossBase() 
{
}

BossBase::~BossBase() 
{
}

void BossBase::Start()
{
}

void BossBase::Update(float _DeltaTime)
{
}

void BossBase::MonsterCameraShack()
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	float4 CameraPos = GetLevel()->GetMainCamera()->GetTransform()->GetWorldPosition();

	x += 0.5;
	y = sin(x * 10.0f) * powf(0.5f, x);
	float a = x;
	float b = y;
	GetLevel()->GetMainCamera()->GetTransform()->SetWorldPosition({ CameraPos.x + (y * 50),CameraPos.y + abs(y * 50),CameraPos.z });

}

