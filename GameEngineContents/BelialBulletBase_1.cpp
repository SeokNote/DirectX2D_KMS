#include "PrecompileHeader.h"
#include "BelialBulletBase_1.h"
#include "BelialHead.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
BelialBulletBase_1* BelialBulletBase_1::MainBelialBulletBase;

BelialBulletBase_1::BelialBulletBase_1()
{
	MainBelialBulletBase = this;
}

BelialBulletBase_1::~BelialBulletBase_1()
{

}

void BelialBulletBase_1::Start()
{
	BelialBulletBase_1Render = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletBase_1Render->GetTransform()->SetLocalPosition({ 12080.0f,-250.0f,-800.0f });
	BelialBulletBase_1Render->GetTransform()->SetLocalScale({ 50.0f,50.f,0.0f });

}

void BelialBulletBase_1::Update(float _DeltaTime)
{
	BelialBulletBase_1Render->GetTransform()->AddWorldRotation({ 1.0f, 0.0f,0.f });

}

