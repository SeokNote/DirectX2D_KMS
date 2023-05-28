#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BuilderNpc : public GameEngineActor
{
public:
	// constrcuter destructer
	BuilderNpc();
	~BuilderNpc();

	// delete Function
	BuilderNpc(const BuilderNpc& _Other) = delete;
	BuilderNpc(BuilderNpc&& _Other) noexcept = delete;
	BuilderNpc& operator=(const BuilderNpc& _Other) = delete;
	BuilderNpc& operator=(BuilderNpc&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 BuilderNpcScale = { 56.0f,92.0f,0.0f };
	float4 FScale = { 52.0f,56.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> BuilderNpcRender;
	std::shared_ptr<class GameEngineSpriteRenderer> FRender;


	//Position
	float4 BuilderNpcPos1 = { -3.0f,-528.0f,-750.f };
	float4 FRenderPos = { -3.0f,-448.0f,-750.f };

	std::shared_ptr<class GameEngineCollision> BuilderNpcCol;

};

