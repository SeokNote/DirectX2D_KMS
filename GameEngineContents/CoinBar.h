#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CoinBar : public GameEngineActor
{
public:
	// constrcuter destructer
	CoinBar();
	~CoinBar();

	// delete Function
	CoinBar(const CoinBar& _Other) = delete;
	CoinBar(CoinBar&& _Other) noexcept = delete;
	CoinBar& operator=(const CoinBar& _Other) = delete;
	CoinBar& operator=(CoinBar&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> PlayerCoinBarUI;
	std::shared_ptr<class UIFontRender> CoinFontRender;
	std::shared_ptr<class UIFontRender> CoinFontRender_1;

	float4 PlayerCoinBarUIScale = { 14.0f,14.0f,0.0f };
	float4 PlayerCoinBarUIPos = { -610.0f,-290.0f,0.0f };

};

