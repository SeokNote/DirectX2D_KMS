#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class TextUI : public GameEngineActor
{
public:
	// constrcuter destructer
	TextUI();
	~TextUI();

	// delete Function
	TextUI(const TextUI& _Other) = delete;
	TextUI(TextUI&& _Other) noexcept = delete;
	TextUI& operator=(const TextUI& _Other) = delete;
	TextUI& operator=(TextUI&& _Other) noexcept = delete;
	void TextSetting(float4 _Pos, float4 _FontColor, std::string _Text, bool _MoveValue, int _FontSize);
	static void TextCreat(GameEngineLevel* _Level, float4 _Pos, float4 _FontColor, std::string _Text, bool _MoveValue, int _FontSize);
protected:
	void Start();
	void Update(float _Delta) override;
private:
	void MoveFont(float _Delta);
	std::shared_ptr<class GameEngineFontRenderer> FontRender;
	std::string font = "8-bit Operator+";
	bool Value = false;
	float4 Pos = float4::Zero;
	float4 Color = float4::Zero;
	float4 FontColor = float4::Black;
	float Ratio = 0.0f;
};

