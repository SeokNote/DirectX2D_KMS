#pragma once
#include "PlayerDataBase.h"
#include <GameEngineCore/GameEngineUIRenderer.h>
// 설명 :
class PlayerHPbar : public GameEngineActor
{
public:
	// constrcuter destructer
	PlayerHPbar();
	~PlayerHPbar();

	// delete Function
	PlayerHPbar(const PlayerHPbar& _Other) = delete;
	PlayerHPbar(PlayerHPbar&& _Other) noexcept = delete;
	PlayerHPbar& operator=(const PlayerHPbar& _Other) = delete;
	PlayerHPbar& operator=(PlayerHPbar&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	void SetLevelFont();
	void SetHpFont();
	void SetSlash();

	void UpdateText();
	std::shared_ptr<GameEngineUIRenderer> PlayerHpBarUI;
	std::shared_ptr<GameEngineUIRenderer> PlayerHpBarBGUI;
	std::shared_ptr<GameEngineUIRenderer> PlayerHpBar;
	std::shared_ptr<GameEngineUIRenderer> PlayerHpAniRender;

	std::shared_ptr<class UIFontRender> PlayerLevelFont;
	std::shared_ptr<class UIFontRender> PlayerLevelBG_0;
	std::shared_ptr<class UIFontRender> PlayerLevelBG_1;
	std::shared_ptr<class UIFontRender> PlayerLevelBG_2;
	std::shared_ptr<class UIFontRender> PlayerLevelBG_3;


	std::shared_ptr<class UIFontRender> PlayerHPFont;
	std::shared_ptr<class UIFontRender> PlayerHPFont_0;
	std::shared_ptr<class UIFontRender> PlayerHPFont_1;
	std::shared_ptr<class UIFontRender> PlayerHPFont_2;
	std::shared_ptr<class UIFontRender> PlayerHPFont_3;

	std::shared_ptr<class UIFontRender> PlayerSlashFont;
	std::shared_ptr<class UIFontRender> PlayerSlashFont_0;
	std::shared_ptr<class UIFontRender> PlayerSlashFont_1;
	std::shared_ptr<class UIFontRender> PlayerSlashFont_2;
	std::shared_ptr<class UIFontRender> PlayerSlashFont_3;

	float4 PlayerHpBarUIScale = { 296.0f,64.0f,0.0f };
	float4 PlayerHpScale = { 196.0f,40.0f,0.0f };

	float4 PlayerHpBarPos = { -482.0f, 318.0f,0.0f };
	float4 PlayerHpPos = { -444.0f, 318.0f ,0.0f };
	float4 PlayerHpAniPos = { -352.0f, 318.0f ,0.0f};


	float Xpos = 196.0f;

	std::string font = "Aa카시오페아";

};


