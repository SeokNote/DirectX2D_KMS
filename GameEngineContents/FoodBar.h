#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
class FoodBar : public GameEngineActor
{
public:
	// constrcuter destructer
	FoodBar();
	~FoodBar();

	// delete Function
	FoodBar(const FoodBar& _Other) = delete;
	FoodBar(FoodBar&& _Other) noexcept = delete;
	FoodBar& operator=(const FoodBar& _Other) = delete;
	FoodBar& operator=(FoodBar&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	void FontSet();
	std::shared_ptr<class GameEngineUIRenderer> PlayerFoodUI;

	float4 PlayerFoodUIScale = { 34.0f,28.0f,0.0f };
	float4 PlayerFoodUIPos = { -610.0f,-320.0f,0.0f };

	std::shared_ptr<class UIFontRender> CurSatityRender;
	std::shared_ptr<class UIFontRender> SlashRender;
	std::shared_ptr<class UIFontRender> MaxSatityRender;
	std::string font = "Aa카시오페아";


};

