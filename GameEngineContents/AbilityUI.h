#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
// 설명 :
class AbilityUI : public GameEngineActor
{
public:
	static AbilityUI* AbilityUIPtr;
	// constrcuter destructer
	AbilityUI();
	~AbilityUI();

	// delete Function
	AbilityUI(const AbilityUI& _Other) = delete;
	AbilityUI(AbilityUI&& _Other) noexcept = delete;
	AbilityUI& operator=(const AbilityUI& _Other) = delete;
	AbilityUI& operator=(AbilityUI&& _Other) noexcept = delete;
	void SetPoint(int _Value)
	{
		Point = _Value;
	}
	void PlusStat();
protected:
	void Start();
	void Update(float _Delta) override;

private:
	void SetCollision();
	void FontCreate();
	void SetFont();
	void StatCalCulation();
	void ButtonCreate();
	std::string SubString(std::string num, int pos);

	float4 AbilityUIScale = { 1280.0f,720.0f,0.0f };
	float4 ExitButtonScale = { 96.0f,96.0f,0.0f };

	float4 Button_RedPos = { -494.0f,-225.0f,0.0f };
	float4 Button_GreenPos= { -233.0f,-225.0f,0.0f };
	float4 Button_WhitePos= { 20.0f,-225.0f,0.0f };
	float4 Button_BluePos = { 269.0f,-225.0f,0.0f };
	float4 Button_YellowPos = {522.0f,-225.0f,0.0f};

	float4 Button_Scale = { 72.0f,72.0f,0.0f };

	std::shared_ptr<GameEngineUIRenderer> AbilityBase;
	std::shared_ptr<GameEngineUIRenderer> AbilityBaseBG;

	std::shared_ptr<GameEngineUIRenderer> Button_RedRender;
	std::shared_ptr<GameEngineUIRenderer> Button_GreenRender;
	std::shared_ptr<GameEngineUIRenderer> Button_WhiteRender;
	std::shared_ptr<GameEngineUIRenderer> Button_BlueRender;
	std::shared_ptr<GameEngineUIRenderer> Button_YellowRender;

	std::shared_ptr<class GameEngineCollision> Button_RedCol;
	std::shared_ptr<class GameEngineCollision> Button_GreenCol;
	std::shared_ptr<class GameEngineCollision> Button_WhiteCol;
	std::shared_ptr<class GameEngineCollision> Button_BlueCol;
	std::shared_ptr<class GameEngineCollision> Button_YellowCol;

	std::shared_ptr<class UIFontRender> AngerFont;
	std::shared_ptr<class UIFontRender> AngerFontBG_0;
	std::shared_ptr<class UIFontRender> AngerFontBG_1;
	std::shared_ptr<class UIFontRender> AngerFontBG_2;
	std::shared_ptr<class UIFontRender> AngerFontBG_3;

	std::shared_ptr<class UIFontRender> FastFont;
	std::shared_ptr<class UIFontRender> FastFontBG_0;
	std::shared_ptr<class UIFontRender> FastFontBG_1;
	std::shared_ptr<class UIFontRender> FastFontBG_2;
	std::shared_ptr<class UIFontRender> FastFontBG_3;

	std::shared_ptr<class UIFontRender> PatienceFont;
	std::shared_ptr<class UIFontRender> PatienceFontBG_0;
	std::shared_ptr<class UIFontRender> PatienceFontBG_1;
	std::shared_ptr<class UIFontRender> PatienceFontBG_2;
	std::shared_ptr<class UIFontRender> PatienceFontBG_3;

	std::shared_ptr<class UIFontRender> MysteryFont;
	std::shared_ptr<class UIFontRender> MysteryFontBG_0;
	std::shared_ptr<class UIFontRender> MysteryFontBG_1;
	std::shared_ptr<class UIFontRender> MysteryFontBG_2;
	std::shared_ptr<class UIFontRender> MysteryFontBG_3;

	std::shared_ptr<class UIFontRender> AvariceFont;
	std::shared_ptr<class UIFontRender> AvariceFontBG_0;
	std::shared_ptr<class UIFontRender> AvariceFontBG_1;
	std::shared_ptr<class UIFontRender> AvariceFontBG_2;
	std::shared_ptr<class UIFontRender> AvariceFontBG_3;

	std::shared_ptr<class UIFontRender> AngerValue;
	std::shared_ptr<class UIFontRender> FastValue;
	std::shared_ptr<class UIFontRender> FastValue1;
	std::shared_ptr<class UIFontRender> PatienceValue;
	std::shared_ptr<class UIFontRender> MysteryValue;
	std::shared_ptr<class UIFontRender> MysteryValue1;
	std::shared_ptr<class UIFontRender> AvariceValue;
	std::shared_ptr<class UIFontRender> ResetFont;
	std::shared_ptr<class UIFontRender> PointFont;

	std::shared_ptr<class ContentButton> ResetButton;
	bool IsValue = false;
	bool ResetValue = false;
	int Anger = 0;
	int Fast = 0;
	int Patience = 0;
	int Mystery = 0;
	int Avarice = 0;

	int A_Power = 0;
	float A_Speed = 0.0f;
	float A_AttackSpeed = 0.0f;
	float A_Aamor = 0.0f;
	float A_Evasion = 0.0f;
	float A_Cri = 0.0f;
	int A_MaxHP = 0;

	float4 AngerColor = { 0.8f,0.486f,0.419f };
	float4 FastColor = { 0.674f,0.85f,0.768f };
	float4 PatienceColor = { 0.662f,0.686f,0.729f };
	float4 MysteryColor = { 0.596f,0.66f,0.792f };
	float4 AvariceColor = { 0.917f,0.717f,0.3f };
	std::string font = "8-bit Operator+";
	std::string font1 = "Aa카시오페아";

	int Point = 10;
};

