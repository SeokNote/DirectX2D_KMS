#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

// 설명 :
class PlayerStat : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerStat();
	~PlayerStat();

	// delete Function
	PlayerStat(const PlayerStat& _Other) = delete;
	PlayerStat(PlayerStat&& _Other) noexcept = delete;
	PlayerStat& operator=(const PlayerStat& _Other) = delete;
	PlayerStat& operator=(PlayerStat&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;

private:
	void SetButton();
	void UpdateStat();
	std::string SubString(std::string num, int pos);
	float4 StatUIScale = { 470.0f,330.0f,0.0f };
	float4 FoodStatUIScale = { 470.0f,250.0f,0.0f };
	float4 ButtonScale = { 88.0f,76.0f,0.0f };
	bool OnOff = false;

	std::shared_ptr<GameEngineUIRenderer> PlayerStatUI;
	std::shared_ptr<GameEngineUIRenderer> FoodStatUI;
	std::shared_ptr<GameEngineUIRenderer> ExitButton;
	std::shared_ptr<GameEngineUIRenderer> ExitButtonSelect;

	std::shared_ptr<class GameEngineCollision> ExitButtonCollsion;
	//UI 배경
	std::shared_ptr<class UIFontRender> StatusFont;
	std::shared_ptr<class UIFontRender> FoodFont;
	//스탯아이콘
	std::shared_ptr<class ContentButton> PowButton;
	std::shared_ptr<class ContentButton> DefButton;
	std::shared_ptr<class ContentButton> ToughtButton;
	std::shared_ptr<class ContentButton> BlockButton;
	std::shared_ptr<class ContentButton> CritcalButton;
	std::shared_ptr<class ContentButton> CriDamageButton;
	std::shared_ptr<class ContentButton> EvadeButton;
	std::shared_ptr<class ContentButton> SpeedButton;
	std::shared_ptr<class ContentButton> AttackSpeedButton;
	std::shared_ptr<class ContentButton> ReloadButton;
	std::shared_ptr<class ContentButton> DashAttackButton;
	std::shared_ptr<class ContentButton> TruDamageButton;
	std::shared_ptr<class ContentButton> SkillCulButton;
	//상태이상 아이콘
	std::shared_ptr<class ContentButton> BurnButton;
	std::shared_ptr<class ContentButton> PoisonButton;
	std::shared_ptr<class ContentButton> ColdButton;
	std::shared_ptr<class ContentButton> ShockButton;
	std::shared_ptr<class ContentButton> StunButton;

	std::string font = "Aa카시오페아";

};
