#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

// Ό³Έν :
class Intro : public GameEngineActor
{
public:
	// constrcuter destructer
	Intro();
	~Intro();

	// delete Function
	Intro(const Intro& _Other) = delete;
	Intro(Intro&& _Other) noexcept = delete;
	Intro& operator=(const Intro& _Other) = delete;
	Intro& operator=(Intro&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;

private:
	float4 BGScale = { 1280.0f,720.0f,0.0f };
	float4 IntroScale = { 236.0f,256.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> IntroRender;
	std::shared_ptr<class GameEngineSpriteRenderer> BGRender;

};
