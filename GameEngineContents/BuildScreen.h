#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class BuildScreen : public GameEngineActor
{
public:
	// constrcuter destructer
	BuildScreen();
	~BuildScreen();

	// delete Function
	BuildScreen(const BuildScreen& _Other) = delete;
	BuildScreen(BuildScreen&& _Other) noexcept = delete;
	BuildScreen& operator=(const BuildScreen& _Other) = delete;
	BuildScreen& operator=(BuildScreen&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> BuildBase = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> BuildTextUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> BuildBaseBG = nullptr;
	std::shared_ptr<class ContentButton> BuildButton = nullptr;
	std::shared_ptr<class ContentButton> ExitButton = nullptr;

};

