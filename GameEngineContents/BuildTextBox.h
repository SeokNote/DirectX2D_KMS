#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "UIFontRender.h"
// 설명 :
class BuildTextBox : public GameEngineActor
{
public:
	// constrcuter destructer
	BuildTextBox();
	~BuildTextBox();

	// delete Function
	BuildTextBox(const BuildTextBox& _Other) = delete;
	BuildTextBox(BuildTextBox&& _Other) noexcept = delete;
	BuildTextBox& operator=(const BuildTextBox& _Other) = delete;
	BuildTextBox& operator=(BuildTextBox&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> BuildTextBoxUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> BuildTextBoxUI_S = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> BuildSelectTextUI = nullptr;
	std::shared_ptr<class GameEngineUIRenderer> BuildSelectUI = nullptr;

	std::shared_ptr<class GameEngineCollision> ButtonCol_0= nullptr;
	std::shared_ptr<class GameEngineCollision> ButtonCol_1= nullptr;
	std::shared_ptr<class GameEngineCollision> ButtonCol_2= nullptr;
	std::shared_ptr<UIFontRender> TextStrting = nullptr;
	float4 TextBoxScale = { 1280.0f,220.0f,0.0f };
	float4 SelectBoxScale = { 320.f, 210.0f,0.0f };
	float4 SelectTextBoxScale = { 202.f, 181.0f,0.0f };
	float4 SelectTextScale = { 290.f, 47.0f,0.0f };

	std::string FirstDialog = "오, 자네군. 훈련장을 건설할텐가? ";

	int IndexCount = 0;
	int count = 0;
	float DelayTime = 0;
};

