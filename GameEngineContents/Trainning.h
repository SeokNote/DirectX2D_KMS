#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineCollision.h>

// Ό³Έν :
class Trainning : public GameEngineActor
{
public:
	// constrcuter destructer
	Trainning();
	~Trainning();

	// delete Function
	Trainning(const Trainning& _Other) = delete;
	Trainning(Trainning&& _Other) noexcept = delete;
	Trainning& operator=(const Trainning& _Other) = delete;
	Trainning& operator=(Trainning&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 TrainningSchoolScale = { 1080.0f,308.0f,0.0f };
	float4 TrainNpcPos = { -1600.0f,-523.0f,0.f };
	float4 TrainNpcScale = { 92.0f,100.0f,0.f };

	std::shared_ptr<class GameEngineSpriteRenderer> TrainningSchoolRender;
	std::shared_ptr<class GameEngineSpriteRenderer> TrainningNpicRender;





	std::shared_ptr<GameEngineCollision> TrainningNpcCol;

};

