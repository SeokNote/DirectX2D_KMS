#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "MapDataBase.h"

// Ό³Έν :
class Town : public GameEngineActor
{
public:
	// constrcuter destructer
	Town();
	~Town();

	// delete Function
	Town(const Town& _Other) = delete;
	Town(Town&& _Other) noexcept = delete;
	Town& operator=(const Town& _Other) = delete;
	Town& operator=(Town&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 TownScale = { 5120.0f,1440.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> TownRender;
};

