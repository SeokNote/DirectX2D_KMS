#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class Forest : public GameEngineActor
{
public:
	// constrcuter destructer
	Forest();
	~Forest();

	// delete Function
	Forest(const Forest& _Other) = delete;
	Forest(Forest&& _Other) noexcept = delete;
	Forest& operator=(const Forest& _Other) = delete;
	Forest& operator=(Forest&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 ForestScale = { 5120.0f,380.0f,0.0f};
	std::shared_ptr<class GameEngineSpriteRenderer> ForestRender;
};

