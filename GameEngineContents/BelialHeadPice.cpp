#include "PrecompileHeader.h"
#include "BelialHeadPice.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
BelialHeadPice::BelialHeadPice() 
{
}

BelialHeadPice::~BelialHeadPice() 
{
}

void BelialHeadPice::Start()
{
	BelialHeadPice_0 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialHeadPice_0->SetTexture("BelialHeadOne.png");
	BelialHeadPice_0->GetTransform()->SetLocalPosition({ 0.0f,-80.0f,-100.0f });
	BelialHeadPice_0->GetTransform()->SetLocalScale(HeadScale);

	BelialHeadPice_2 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialHeadPice_2->GetTransform()->SetLocalPosition({ 0.0f,40.0f,-80.0f });
	BelialHeadPice_2->SetTexture("BelialHeadThree.png");
	BelialHeadPice_2->GetTransform()->SetLocalScale(HeadScale);

	BelialHeadPice_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	BelialHeadPice_1->GetTransform()->SetLocalPosition({ 0.0f,10.0f,-90.0f });
	BelialHeadPice_1->SetTexture("BelialHeadTwo.png");
	BelialHeadPice_1->GetTransform()->SetLocalScale(HeadScale);
	Pos_0 = BelialHeadPice_0->GetTransform()->GetWorldPosition();
	Pos_1 = Pos_0;
	Pos_1.y = -363.0f;

}

void BelialHeadPice::Update(float _DeltaTime)
{
	DownHead(_DeltaTime);
}

void BelialHeadPice::DownHead(float _DeltaTime)
{
	float4 EndPos_0 = BelialHeadPice_0->GetTransform()->GetWorldPosition();
	float4 EndPos_1 = BelialHeadPice_1->GetTransform()->GetWorldPosition();
	float4 EndPos_2 = BelialHeadPice_2->GetTransform()->GetWorldPosition();

	if (EndPos_0.y > -363.0f)
	{
		BelialHeadPice_0->GetTransform()->AddLocalPosition({ 0.0f,-_DeltaTime * 100.0f,0.0f });

	}
	if (EndPos_1.y > -270.0f)
	{
		BelialHeadPice_1->GetTransform()->AddLocalPosition({ 0.0f,-_DeltaTime * 100.0f,0.0f });

	}
	if (EndPos_2.y > -170.0f)
	{
		BelialHeadPice_2->GetTransform()->AddLocalPosition({ 0.0f,-_DeltaTime * 100.0f,0.0f });

	}
}
