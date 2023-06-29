#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class BelialHeadPice :public GameEngineActor
{
public:
	// constrcuter destructer
	BelialHeadPice();
	~BelialHeadPice();

	// delete Function
	BelialHeadPice(const BelialHeadPice& _Other) = delete;
	BelialHeadPice(BelialHeadPice&& _Other) noexcept = delete;
	BelialHeadPice& operator=(const BelialHeadPice& _Other) = delete;
	BelialHeadPice& operator=(BelialHeadPice&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void DownHead(float _DeltaTime);
	std::shared_ptr<class GameEngineSpriteRenderer> BelialHeadPice_0;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialHeadPice_1;
	std::shared_ptr<class GameEngineSpriteRenderer> BelialHeadPice_2;
	float4 HeadScale = { 280.0f,512.0f,0.0f };
	float4 Pos_0 = float4::Zero;
	float4 Pos_1 = float4::Zero;
};

