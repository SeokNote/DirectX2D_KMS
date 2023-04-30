#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MainLogo : public GameEngineActor
{
public:
	// constrcuter destructer
	MainLogo();
	~MainLogo();

	// delete Function
	MainLogo(const MainLogo& _Other) = delete;
	MainLogo(MainLogo&& _Other) noexcept = delete;
	MainLogo& operator=(const MainLogo& _Other) = delete;
	MainLogo& operator=(MainLogo&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 MainLogoScale = { 620.0f,300.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> MainLogoRender;
};

