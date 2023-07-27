#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEnginePlatform/GameEngineSound.h>
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
	void SetButton();
	void MoveFood(float _Delta);
	void SetSatieyFont();
	void FontUpdate();
	std::shared_ptr<class UIFontRender> FontCreate();
	float4 FoodUIScale = { 1280.f,720.0f,0.0f };
	float4 ExitButtonScale = { 88.0f,76.0f,0.0f };

	std::shared_ptr<class GameEngineUIRenderer> FoodUIRender;
	std::shared_ptr<class GameEngineUIRenderer> ExitButtonRender;
	std::shared_ptr<class GameEngineUIRenderer> ExitButtonSelectRender;
	std::shared_ptr<class GameEngineUIRenderer> FoodBGRender;
	std::shared_ptr<class GameEngineUIRenderer> SatietyBGRender;
	std::shared_ptr<class GameEngineUIRenderer> HPBaseRender;
	std::shared_ptr<class GameEngineUIRenderer> HPRender;

	std::shared_ptr<class GameEngineCollision> FoodUIExitCol;
	float4 ExitButtonPos = { 590.0f, 315.0f, 0.0f };
	std::shared_ptr<class TempleNpc> TempleNpcPtr;
	GameEngineSoundPlayer FoodBGM;


	std::shared_ptr<class ContentButton> BreadButton;
	std::shared_ptr<class ContentButton> TomatoButton;

	//UI폰트.
	std::shared_ptr<class UIFontRender> PlayerFoodFont;
	std::shared_ptr<class UIFontRender> PlayerFoodBG_0;
	std::shared_ptr<class UIFontRender> PlayerFoodBG_1;
	std::shared_ptr<class UIFontRender> PlayerFoodBG_2;
	std::shared_ptr<class UIFontRender> PlayerFoodBG_3;


	std::shared_ptr<class UIFontRender> PlayerMaxFood;
	std::shared_ptr<class UIFontRender> PlayerMaxFood_0;
	std::shared_ptr<class UIFontRender> PlayerMaxFood_1;
	std::shared_ptr<class UIFontRender> PlayerMaxFood_2;
	std::shared_ptr<class UIFontRender> PlayerMaxFood_3;

	std::shared_ptr<class UIFontRender> SlashFont;
	std::shared_ptr<class UIFontRender> SlashFont_0;
	std::shared_ptr<class UIFontRender> SlashFont_1;
	std::shared_ptr<class UIFontRender> SlashFont_2;
	std::shared_ptr<class UIFontRender> SlashFont_3;

	std::shared_ptr<class UIFontRender> PlayerHPFont;
	std::shared_ptr<class UIFontRender> PlayerHPBG_0;
	std::shared_ptr<class UIFontRender> PlayerHPBG_1;
	std::shared_ptr<class UIFontRender> PlayerHPBG_2;
	std::shared_ptr<class UIFontRender> PlayerHPBG_3;


	std::shared_ptr<class UIFontRender> PlayerMaxHP;
	std::shared_ptr<class UIFontRender> PlayerMaxHP_0;
	std::shared_ptr<class UIFontRender> PlayerMaxHP_1;
	std::shared_ptr<class UIFontRender> PlayerMaxHP_2;
	std::shared_ptr<class UIFontRender> PlayerMaxHP_3;

	std::shared_ptr<class UIFontRender> SlashFontHP;
	std::shared_ptr<class UIFontRender> SlashFontHP_0;
	std::shared_ptr<class UIFontRender> SlashFontHP_1;
	std::shared_ptr<class UIFontRender> SlashFontHP_2;
	std::shared_ptr<class UIFontRender> SlashFontHP_3;

	std::shared_ptr<class UIFontRender> CoinRender;

	bool MoveBread = false;
	bool MoveTomato = false;
	std::string font = "Aa카시오페아";

};
