#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

// Ό³Έν :
class TitleMouse : public GameEngineActor
{
public:
	// constrcuter destructer
	TitleMouse();
	~TitleMouse();

	// delete Function
	TitleMouse(const TitleMouse& _Other) = delete;
	TitleMouse(TitleMouse&& _Other) noexcept = delete;
	TitleMouse& operator=(const TitleMouse& _Other) = delete;
	TitleMouse& operator=(TitleMouse&& _Other) noexcept = delete;
	void SetMousePos();
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 TitleMouseScale = { 76.0f,76.0f,0.0f };
	std::shared_ptr<class GameEngineUIRenderer> TitleMouseRender;
	std::shared_ptr<class GameEngineCollision> MouseCollsion;

};

