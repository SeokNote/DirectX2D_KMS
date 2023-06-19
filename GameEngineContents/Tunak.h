#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class Tunak : public GameEngineActor
{
public:
	// constrcuter destructer
	Tunak();
	~Tunak();

	// delete Function
	Tunak(const Tunak& _Other) = delete;
	Tunak(Tunak&& _Other) noexcept = delete;
	Tunak& operator=(const Tunak& _Other) = delete;
	Tunak& operator=(Tunak&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:

//	float4 LasorScale = { 1280.0f,220.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> TunakRender;
	std::shared_ptr<class GameEngineCollision> TunakCol;

	//�׽�Ʈ
	float TestTime = 0.0f;
};

