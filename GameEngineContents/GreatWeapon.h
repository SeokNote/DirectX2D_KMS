#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GreatWeapon : public GameEngineActor
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
	std::shared_ptr<class GameEngineSpriteRenderer> GreatWeaponRender;


	float4 GreatWeaponScale = { -256.0f,256.0f,0.0f };
	float4 GreatWeaponPos = float4::Zero;
	int index = 0;
};

