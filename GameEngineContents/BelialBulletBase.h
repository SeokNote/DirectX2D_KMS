#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "BelialHead.h"
// 설명 :
class BelialBulletBase : public GameEngineActor
{
public:
	static BelialBulletBase* MainBelialBulletBase;

	// constrcuter destructer
	BelialBulletBase();
	~BelialBulletBase();

	// delete Function
	BelialBulletBase(const BelialBulletBase& _Other) = delete;
	BelialBulletBase(BelialBulletBase&& _Other) noexcept = delete;
	BelialBulletBase& operator=(const BelialBulletBase& _Other) = delete;
	BelialBulletBase& operator=(BelialBulletBase&& _Other) noexcept = delete;

	float4 getLDir()
	{
		return LDir_B;
	}
	float4 getRDir()
	{
		return RDir_B;
	}
	float4 getUDir()
	{
		return UDir_B;
	}
	float4 getDDir()
	{
		return DDir_B;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	float4 MainBulletPos = { 12080.0f,-250.0f,-740.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBaseRender_0;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBaseRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBaseRender_2;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialBulletBaseRender_3;

	float4 pos = BelialHead::MainBelialHead->GetTransform()->GetWorldPosition();

	float ZDir = 0.0f;
	float4 Dir = float4::Zero;

	//불릿 각도
	float4 LDir_B = float4::Zero;
	float4 RDir_B = float4::Zero;
	float4 UDir_B = float4::Zero;
	float4 DDir_B = float4::Zero;


	

};

