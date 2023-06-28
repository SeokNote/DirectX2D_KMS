#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "TunakBullet.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineCore/GameEngineCollision.h>

TunakBullet::TunakBullet() 
{
}

TunakBullet::~TunakBullet() 
{
}

void TunakBullet::Start()
{
	TunakBulletRender_0  = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletRender_0->SetTexture("TunakShoutBullet00.png");
	TunakBulletRender_0->CreateAnimation({ .AnimationName = "TunakBullet_0", .SpriteName = "TunakBulletIIldle",.Loop = true , .ScaleToTexture = true });
	TunakBulletRender_0->ChangeAnimation("TunakBullet_0");
	TunakBulletRender_0->GetTransform()->SetLocalRotation({ 0.0f,0.0f,90.0f });

	TunakBulletRender_1 = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletRender_1->SetTexture("TunakShoutBullet00.png");
	TunakBulletRender_1->CreateAnimation({ .AnimationName = "TunakBullet_1", .SpriteName = "TunakBulletIIldle",.Loop = true , .ScaleToTexture = true });
	TunakBulletRender_1->ChangeAnimation("TunakBullet_1");
	TunakBulletRender_1->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-90.0f });

	TunakBulletRender_2 = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletRender_2->SetTexture("TunakShoutBullet00.png");
	TunakBulletRender_2->CreateAnimation({ .AnimationName = "TunakBullet_2", .SpriteName = "TunakBulletIIldle",.Loop = true , .ScaleToTexture = true });
	TunakBulletRender_2->ChangeAnimation("TunakBullet_2");
	TunakBulletRender_2->GetTransform()->SetLocalRotation({ 0.0f,0.0f,0.0f });

	TunakBulletRender_3 = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletRender_3->SetTexture("TunakShoutBullet00.png");
	TunakBulletRender_3->CreateAnimation({ .AnimationName = "TunakBullet_3", .SpriteName = "TunakBulletIIldle",.Loop = true , .ScaleToTexture = true });
	TunakBulletRender_3->ChangeAnimation("TunakBullet_3");
	TunakBulletRender_3->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-180.0f });

	TunakBulletRender_4 = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletRender_4->SetTexture("TunakShoutBullet00.png");
	TunakBulletRender_4->CreateAnimation({ .AnimationName = "TunakBullet_4", .SpriteName = "TunakBulletIIldle",.Loop = true , .ScaleToTexture = true });
	TunakBulletRender_4->ChangeAnimation("TunakBullet_4");
	TunakBulletRender_4->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-45.0f });

	TunakBulletRender_5 = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletRender_5->SetTexture("TunakShoutBullet00.png");
	TunakBulletRender_5->CreateAnimation({ .AnimationName = "TunakBullet_5", .SpriteName = "TunakBulletIIldle",.Loop = true , .ScaleToTexture = true });
	TunakBulletRender_5->ChangeAnimation("TunakBullet_5");
	TunakBulletRender_5->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-225.0f });

	TunakBulletRender_6 = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletRender_6->SetTexture("TunakShoutBullet00.png");
	TunakBulletRender_6->CreateAnimation({ .AnimationName = "TunakBullet_6", .SpriteName = "TunakBulletIIldle",.Loop = true , .ScaleToTexture = true });
	TunakBulletRender_6->ChangeAnimation("TunakBullet_6");
	TunakBulletRender_6->GetTransform()->SetLocalRotation({ 0.0f,0.0f,45.0f });

	TunakBulletRender_7 = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletRender_7->SetTexture("TunakShoutBullet00.png");
	TunakBulletRender_7->CreateAnimation({ .AnimationName = "TunakBullet_7", .SpriteName = "TunakBulletIIldle",.Loop = true , .ScaleToTexture = true });
	TunakBulletRender_7->ChangeAnimation("TunakBullet_7");
	TunakBulletRender_7->GetTransform()->SetLocalRotation({ 0.0f,0.0f,-135.0f });

	TunakBulletBGRender = CreateComponent<GameEngineSpriteRenderer>(1);
	TunakBulletBGRender->SetTexture("ShoutFX03.png");
	TunakBulletBGRender->CreateAnimation({ .AnimationName = "TunakBulletBG", .SpriteName = "TunakBulletBG",.Loop = false , .ScaleToTexture = true });
	TunakBulletBGRender->ChangeAnimation("TunakBulletBG");
	

	TunakBulletCol_0 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakBulletCol_0->GetTransform()->SetLocalScale(BulletScale);
	TunakBulletCol_0->SetColType(ColType::AABBBOX2D);


	TunakBulletCol_1 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakBulletCol_1->GetTransform()->SetLocalScale(BulletScale);
	TunakBulletCol_1->SetColType(ColType::AABBBOX2D);


	TunakBulletCol_2 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakBulletCol_2->GetTransform()->SetLocalScale(BulletScale);
	TunakBulletCol_2->SetColType(ColType::AABBBOX2D);


	TunakBulletCol_3 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakBulletCol_3->GetTransform()->SetLocalScale(BulletScale);
	TunakBulletCol_3->SetColType(ColType::AABBBOX2D);


	TunakBulletCol_4 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakBulletCol_4->GetTransform()->SetLocalScale(BulletScale);
	TunakBulletCol_4->SetColType(ColType::AABBBOX2D);


	TunakBulletCol_5 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakBulletCol_5->GetTransform()->SetLocalScale(BulletScale);
	TunakBulletCol_5->SetColType(ColType::AABBBOX2D);


	TunakBulletCol_6 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakBulletCol_6->GetTransform()->SetLocalScale(BulletScale);
	TunakBulletCol_6->SetColType(ColType::AABBBOX2D);

	TunakBulletCol_7 = CreateComponent<GameEngineCollision>(ColOrder::MONSTERATTACK);
	TunakBulletCol_7->GetTransform()->SetLocalScale(BulletScale);
	TunakBulletCol_7->SetColType(ColType::AABBBOX2D);
}					  

void TunakBullet::Update(float _DeltaTime)
{
	MoveBullet(_DeltaTime);
	DeadTime += _DeltaTime;
	if (DeadTime > 3.0f)
	{
		Death();
		DeadTime = 0.0f;
	}
}

void TunakBullet::MoveBullet(float _DeltaTime)
{
	float4 Pos0 = TunakBulletRender_0->GetTransform()->GetLocalPosition();
	float4 Pos1 = TunakBulletRender_1->GetTransform()->GetLocalPosition();
	float4 Pos2 = TunakBulletRender_2->GetTransform()->GetLocalPosition();
	float4 Pos3 = TunakBulletRender_3->GetTransform()->GetLocalPosition();
	float4 Pos4 = TunakBulletRender_4->GetTransform()->GetLocalPosition();
	float4 Pos5 = TunakBulletRender_5->GetTransform()->GetLocalPosition();
	float4 Pos6 = TunakBulletRender_6->GetTransform()->GetLocalPosition();
	float4 Pos7 = TunakBulletRender_7->GetTransform()->GetLocalPosition();

	TunakBulletRender_0->GetTransform()->AddLocalPosition({ 1.0f * _DeltaTime * BulletSpeed,0.0f,0.0f });
	TunakBulletRender_1->GetTransform()->AddLocalPosition({ -1.0f * _DeltaTime * BulletSpeed,0.0f,0.0f });
	TunakBulletRender_2->GetTransform()->AddLocalPosition({ 0.0f,1.0f * _DeltaTime * BulletSpeed,0.0f });
	TunakBulletRender_3->GetTransform()->AddLocalPosition({ 0.0f,-1.0f * _DeltaTime * BulletSpeed,0.0f });
	TunakBulletRender_4->GetTransform()->AddLocalPosition({ 0.75f * _DeltaTime * BulletSpeed,0.75f * _DeltaTime * BulletSpeed,0.0f });
	TunakBulletRender_5->GetTransform()->AddLocalPosition({ -0.75f * _DeltaTime * BulletSpeed,-0.75f * _DeltaTime * BulletSpeed,0.0f });
	TunakBulletRender_6->GetTransform()->AddLocalPosition({ -0.75f * _DeltaTime * BulletSpeed,0.75f * _DeltaTime * BulletSpeed,0.0f });
	TunakBulletRender_7->GetTransform()->AddLocalPosition({ 0.75f * _DeltaTime * BulletSpeed,-0.75f * _DeltaTime * BulletSpeed,0.0f });

	TunakBulletCol_0->GetTransform()->SetLocalPosition({ Pos0.x,Pos0.y,0.0f });
	TunakBulletCol_1->GetTransform()->SetLocalPosition({ Pos1.x,Pos1.y,0.0f });
	TunakBulletCol_2->GetTransform()->SetLocalPosition({ Pos2.x,Pos2.y,0.0f });
	TunakBulletCol_3->GetTransform()->SetLocalPosition({ Pos3.x,Pos3.y,0.0f });
	TunakBulletCol_4->GetTransform()->SetLocalPosition({ Pos4.x,Pos4.y,0.0f });
	TunakBulletCol_5->GetTransform()->SetLocalPosition({ Pos5.x,Pos5.y,0.0f });
	TunakBulletCol_6->GetTransform()->SetLocalPosition({ Pos6.x,Pos6.y,0.0f });
	TunakBulletCol_7->GetTransform()->SetLocalPosition({ Pos7.x,Pos7.y,0.0f });

}

