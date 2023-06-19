#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BelialLasor : public GameEngineActor
{
public:
	// constrcuter destructer
	BelialLasor();
	~BelialLasor();

	// delete Function
	BelialLasor(const BelialLasor& _Other) = delete;
	BelialLasor(BelialLasor&& _Other) noexcept = delete;
	BelialLasor& operator=(const BelialLasor& _Other) = delete;
	BelialLasor& operator=(BelialLasor&& _Other) noexcept = delete;
	
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:

	float4 LasorScale = { 1280.0f,220.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> BelialLasorRender;
	std::shared_ptr<class GameEngineCollision> BelialLasorCol;

};

