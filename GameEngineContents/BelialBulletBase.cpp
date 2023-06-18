#include "PrecompileHeader.h"
#include "BelialBulletBase.h"
#include "BelialHead.h"
#include "BelialBulletBase_1.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>

BelialBulletBase::BelialBulletBase()
{
}

BelialBulletBase::~BelialBulletBase()
{

}

void BelialBulletBase::Start()
{
	BelialBulletBaseRender_0 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletBaseRender_0->GetTransform()->SetLocalPosition({ 12150.0f,-150.0f,-760.0f });
	BelialBulletBaseRender_0->GetTransform()->SetLocalScale({ 50.0f,50.f,0.0f });
	BelialBulletBaseRender_0->GetTransform()->SetParent(GetTransform());

	BelialBulletBaseRender_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletBaseRender_1->GetTransform()->SetLocalPosition({ 11950.0f,-150.0f,-760.0f });
	BelialBulletBaseRender_1->GetTransform()->SetLocalScale({ 50.0f,50.f,0.0f });
	BelialBulletBaseRender_1->GetTransform()->SetParent(GetTransform());

	BelialBulletBaseRender_2 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletBaseRender_2->GetTransform()->SetLocalPosition({ 12050.0f,-50.0f,-760.0f });
	BelialBulletBaseRender_2->GetTransform()->SetLocalScale({ 50.0f,50.f,0.0f });
	BelialBulletBaseRender_2->GetTransform()->SetParent(GetTransform());

	BelialBulletBaseRender_3 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialBulletBaseRender_3->GetTransform()->SetLocalPosition({ 12050.0f,-250.0f,-760.0f });
	BelialBulletBaseRender_3->GetTransform()->SetLocalScale({ 50.0f,50.f,0.0f });
	BelialBulletBaseRender_3->GetTransform()->SetParent(GetTransform());

}


void BelialBulletBase::Update(float _DeltaTime)
{
	GetTransform()->AddLocalRotation({ 0.0f,0.0f,0.01f });
}

