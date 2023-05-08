#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BackCloud : public GameEngineActor
{
public:
	// constrcuter destructer
	BackCloud();
	~BackCloud();

	// delete Function
	BackCloud(const BackCloud& _Other) = delete;
	BackCloud(BackCloud&& _Other) noexcept = delete;
	BackCloud& operator=(const BackCloud& _Other) = delete;
	BackCloud& operator=(BackCloud&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 BackCloudScale = { 2560.0f,720.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> BackCloudRender;
	std::shared_ptr<class GameEngineSpriteRenderer> BackCloudRender_1;

};

