#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class WeaponBase :public GameEngineActor
{
public:
	// constrcuter destructer
	WeaponBase();
	~WeaponBase();

	// delete Function
	WeaponBase(const WeaponBase& _Other) = delete;
	WeaponBase(WeaponBase&& _Other) noexcept = delete;
	WeaponBase& operator=(const WeaponBase& _Other) = delete;
	WeaponBase& operator=(WeaponBase&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
	void CameraShake(float _Delta);
	float4 GetMousePos();
	bool IsFlip();
	float GetDeg();
	float4 GetEffectDir();
private:
	float4 MousePos = float4::Zero;
	float4 PlayerPos = float4::Zero;
	float ShakeTime = 0.0f;
	float y = 0.0f;
	float x = 0.0f;
};

