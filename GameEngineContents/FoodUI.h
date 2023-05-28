#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include"TempleNpc.h"
// 설명 :
class FoodUI : public GameEngineActor
{
public:
	// constrcuter destructer
	FoodUI();
	~FoodUI();

	// delete Function
	FoodUI(const FoodUI& _Other) = delete;
	FoodUI(FoodUI&& _Other) noexcept = delete;
	FoodUI& operator=(const FoodUI& _Other) = delete;
	FoodUI& operator=(FoodUI&& _Other) noexcept = delete;
	void SetNpc(std::shared_ptr<class TempleNpc> _Npc) {
		TempleNpcPtr = _Npc;
	}
protected:
	void Start();
	void Update(float _Delta) override;

private:

	float4 FoodUIScale = { 1280.f,720.0f,0.0f };
	float4 ExitButtonScale = { 88.0f,76.0f,0.0f };

	std::shared_ptr<class GameEngineUIRenderer> FoodUIRender;
	std::shared_ptr<class GameEngineUIRenderer> ExitButtonRender;
	std::shared_ptr<class GameEngineUIRenderer> ExitButtonSelectRender;

	std::shared_ptr<class GameEngineCollision> FoodUIExitCol;
	float4 ExitButtonPos = { 590, 315, 0 };

	std::shared_ptr<class TempleNpc> TempleNpcPtr;
};

//텝과 인벤토리 기초적인 틀만 만들기