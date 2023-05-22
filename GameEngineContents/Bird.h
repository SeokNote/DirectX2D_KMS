#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Bird : public GameEngineActor
{
public:
	// constrcuter destructer
	Bird();
	~Bird();

	// delete Function
	Bird(const Bird& _Other) = delete;
	Bird(Bird&& _Other) noexcept = delete;
	Bird& operator=(const Bird& _Other) = delete;
	Bird& operator=(Bird&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 BirdScale = { 84.0f,48.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> BirdRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> BirdRender_2;
	std::shared_ptr<class GameEngineSpriteRenderer> BirdRender_3;
	std::shared_ptr<class GameEngineSpriteRenderer> BirdRender_4;
	std::shared_ptr<class GameEngineSpriteRenderer> BirdRender_5;
	std::shared_ptr<class GameEngineSpriteRenderer> BirdRender_6;

	float OverWindow = 800.0f;



	//Position
	float4 BirdPos1 = { -700.0f,-200.0f,0.f };
	float4 BirdPos2 = { -800.0f,170.0f,0.f };
	float4 BirdPos3 = { -1550.0f,115.0f,0.f };
	float4 BirdPos4 = { -1500.0f,140.0f,0.f };
	float4 BirdPos5 = { -1550.0f,165.0f,0.f };
	float4 BirdPos6 = { -650.0f,300.0f,0.f };


};

