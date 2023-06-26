#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "WeaponBase.h"
// Ό³Έν :
class GreatWeapon : public WeaponBase
{
public:
	// constrcuter destructer
	GreatWeapon();
	~GreatWeapon();

	// delete Function
	GreatWeapon(const GreatWeapon& _Other) = delete;
	GreatWeapon(GreatWeapon&& _Other) noexcept = delete;
	GreatWeapon& operator=(const GreatWeapon& _Other) = delete;
	GreatWeapon& operator=(GreatWeapon&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	void SetCollision();
	void SetGreatWeapon(float _Delta);
	std::shared_ptr<class GameEngineSpriteRenderer> GreatWeaponRender;
	std::shared_ptr<class GameEngineSpriteRenderer> GreatWeaponEffectRender;
	std::shared_ptr<class GameEngineCollision> GreatWeaponCol;
	float4 GreatWeaponScale = { -256.0f,256.0f,0.0f };
	float4 GreatWeaponColScale = { 244.0f,188.0f,0.0f };
	int index = 0;
	float4 GreatWeaponPos = float4::Zero;
	float4 MousePos = float4::Zero;
	float ShakeTime = 0.0f;
	float ShakeTime_0 = 0.0f;
	bool ShakeValue = false;
};

