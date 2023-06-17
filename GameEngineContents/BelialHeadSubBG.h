#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BelialHeadSubBG : public GameEngineActor
{
public:
	// constrcuter destructer
	BelialHeadSubBG();
	~BelialHeadSubBG();

	// delete Function
	BelialHeadSubBG(const BelialHeadSubBG& _Other) = delete;
	BelialHeadSubBG(BelialHeadSubBG&& _Other) noexcept = delete;
	BelialHeadSubBG& operator=(const BelialHeadSubBG& _Other) = delete;
	BelialHeadSubBG& operator=(BelialHeadSubBG&& _Other) noexcept = delete;

	static std::shared_ptr<BelialHeadSubBG> CreateSubBG(GameEngineLevel* _Level, const float4& _Pos);

protected:
	void Start() override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> BelialSubBGRender;

	float XValue = 120.0f;
	float YValue = 120.0f;
};

