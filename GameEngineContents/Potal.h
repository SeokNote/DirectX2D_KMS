#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class Potal :public GameEngineActor
{
public:
	// constrcuter destructer
	Potal();
	~Potal();

	// delete Function
	Potal(const Potal& _Other) = delete;
	Potal(Potal&& _Other) noexcept = delete;
	Potal& operator=(const Potal& _Other) = delete;
	Potal& operator=(Potal&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	void PTCSetting(float _Delta);
	float4 Dir = float4::Zero;
	std::shared_ptr<class GameEngineSpriteRenderer> SteleRender = nullptr;
	float CreateTime0 = 0.0f;
	float CreateTime1 = 0.0f;
	float CreateTime2 = 0.0f;


};

