#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

// Ό³Έν :
class PlayMouse : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayMouse();
	~PlayMouse();

	// delete Function
	PlayMouse(const PlayMouse& _Other) = delete;
	PlayMouse(PlayMouse&& _Other) noexcept = delete;
	PlayMouse& operator=(const PlayMouse& _Other) = delete;
	PlayMouse& operator=(PlayMouse&& _Other) noexcept = delete;
	static PlayMouse* MainPlayMouse;
	std::shared_ptr<class GameEngineUIRenderer> GetMouseRender()
	{
		return PlayMouseRender;
	}
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 PlayMouseScale = { 76.0f,76.0f,0.0f };
	std::shared_ptr<class GameEngineUIRenderer> PlayMouseRender;
	std::shared_ptr<class GameEngineCollision> PlayMouseCollsion;

};

