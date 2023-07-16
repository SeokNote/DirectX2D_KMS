#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum Weapon
{
	None,
	GreatWeapon_E,
};
// Ό³Έν :
class WeaponBase :public GameEngineActor
{
public:
	static WeaponBase* WeaponBasePtr;
	// constrcuter destructer
	WeaponBase();
	~WeaponBase();

	// delete Function
	WeaponBase(const WeaponBase& _Other) = delete;
	WeaponBase(WeaponBase&& _Other) noexcept = delete;
	WeaponBase& operator=(const WeaponBase& _Other) = delete;
	WeaponBase& operator=(WeaponBase&& _Other) noexcept = delete;
	int GetWeaponStrength(Weapon _MyWeapon);
	int GetWeaponIndex()
	{
		return WeaponIndex;
	}
	void SetWeaponIndex(int _Value)
	{
		WeaponIndex = _Value;
	}
protected:
	void Start();
	void Update(float _Delta) override;
	void CameraShake(float _Delta);
	bool IsFlip();
	float GetDeg();
	float4 GetMousePos();
//	float4 GetEffectDir();
private:
	int WeaponIndex = 0;
	Weapon MyWeapon = Weapon::None;
	float4 MousePos = float4::Zero;
	float4 PlayerPos = float4::Zero;
	int WeaponStrength = 0;
	float ShakeTime = 0.0f;
	float y = 0.0f;
	float x = 0.0f;
};

