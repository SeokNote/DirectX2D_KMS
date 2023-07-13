#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class WeaponSwichUI : public GameEngineActor
{
public:
	// constrcuter destructer
	WeaponSwichUI();
	~WeaponSwichUI();

	// delete Function
	WeaponSwichUI(const WeaponSwichUI& _Other) = delete;
	WeaponSwichUI(WeaponSwichUI&& _Other) noexcept = delete;
	WeaponSwichUI& operator=(const WeaponSwichUI& _Other) = delete;
	WeaponSwichUI& operator=(WeaponSwichUI&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> PlayerWeaponSwichUIUI3;
	std::shared_ptr<class GameEngineUIRenderer> PlayerWeaponSwichUIUI2;
	std::shared_ptr<class GameEngineUIRenderer> PlayerWeaponSwichUIUI1;
	std::shared_ptr<class GameEngineUIRenderer> PlayerWeaponSwichUIUI0;
	float4 PlayerWeaponSwichUIScale = { 136.0f,96.0f,0.0f };
	float4 PlayerWeaponSwichUIPos = { 547.0f, -296.0f , 0.0f };
	float4 PlayerWeaponSwichUIPos_B = { 565.0f, -276.0f , 0.0f };
	float4 EndPos= { 556.0f, -286.0f , 0.0f };

	bool SwichTriger = false;
	bool ChangePos = false;
	float Ratio = 0.0f;
	float4 M1 = float4::Zero;
	float4 M2 = float4::Zero;
};

