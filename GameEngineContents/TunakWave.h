#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
class TunakWave :public GameEngineActor
{
public:
	// constrcuter destructer
	TunakWave();
	~TunakWave();

	// delete Function
	TunakWave(const TunakWave& _Other) = delete;
	TunakWave(TunakWave&& _Other) noexcept = delete;
	TunakWave& operator=(const TunakWave& _Other) = delete;
	TunakWave& operator=(TunakWave&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void WaveCollision();
	void SetGroundBG(float _DeltaTime);
	void CreatWave(float _DeltaTime);
	void WaveDeath(float _DeltaTime);
	std::shared_ptr<class GameEngineSpriteRenderer> TunakWaveRender;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakWaveRender_1;

	std::shared_ptr<class GameEngineCollision> TunakWaveCol;
	std::shared_ptr<class GameEngineCollision> TunakWaveCol_1;

	std::shared_ptr<class GameEngineSpriteRenderer> BGRender;

	float4 BGScale = { 200.0f,1500.0f,0.0f };
	float StartAlpha = 0.6f;
	float AlphaTime = 0.0f;
	float DeadTime = 0.0f;
	float4 WaveScale = { 220.0f,212.0f,0.f };
	float4 WaveColScale = { 220.0f,192.0f,0.f };

	//불값
	bool StartPatton = false;
	bool IsCheck = false;
	bool IsCheck_1 = false;
	bool WaveStart = false;
	//Wave
	float StartWave = 0.0f;
	float WaveSpeed = 800.0f;
	float AddSpeed = 0.0f;
	int WaveDamege = 10;
	bool FirstAttack = false;
};

