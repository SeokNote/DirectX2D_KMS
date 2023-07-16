#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "WeaponBase.h"
// Ό³Έν :
class SpaceWeapon : public WeaponBase
{
public:
	// constrcuter destructer
	SpaceWeapon();
	~SpaceWeapon();

	// delete Function
	SpaceWeapon(const SpaceWeapon& _Other) = delete;
	SpaceWeapon(SpaceWeapon&& _Other) noexcept = delete;
	SpaceWeapon& operator=(const SpaceWeapon& _Other) = delete;
	SpaceWeapon& operator=(SpaceWeapon&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	void SetCollision();
	void SetSpaceWeapon(float _Delta);
	std::shared_ptr<class GameEngineSpriteRenderer> SpaceWeaponRender;
	std::shared_ptr<class GameEngineSpriteRenderer> SpaceWeaponEffectRender;
	std::shared_ptr<class GameEngineCollision> SpaceWeaponCol;
	std::shared_ptr<class SpaceSkill> SkillRender;
	float4 SpaceWeaponScale = { -255.0f,255.0f,0.0f };
	float4 SpaceWeaponColScale = { 244.0f,188.0f,0.0f };
	int index = 0;
	float4 SpaceWeaponPos = float4::Zero;
	float4 MousePos = float4::Zero;
	float ShakeTime = 0.0f;
	float ShakeTime_0 = 0.0f;
	bool DirCheck = false;
	bool ShakeValue = false;
};

