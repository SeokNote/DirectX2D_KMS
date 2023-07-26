#pragma once
#include "UIFontRender.h"
// 설명 :
class BossText :public GameEngineActor
{
public:
	// constrcuter destructer
	BossText();
	~BossText();

	// delete Function
	BossText(const BossText& _Other) = delete;
	BossText(BossText&& _Other) noexcept = delete;
	BossText& operator=(const BossText& _Other) = delete;
	BossText& operator=(BossText&& _Other) noexcept = delete;
	void SetExPlaneFont(std::string _BossName , std::string _Explane);

protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	std::shared_ptr<class UIFontRender> BossName;
	std::shared_ptr<class UIFontRender> BossName1;
	std::shared_ptr<class UIFontRender> BossName2;
	std::shared_ptr<class UIFontRender> BossName3;
	std::shared_ptr<class UIFontRender> BossName4;

	std::shared_ptr<class UIFontRender> BossExplane;
	std::shared_ptr<class UIFontRender> BossExplane1;
	std::shared_ptr<class UIFontRender> BossExplane2;
	std::shared_ptr<class UIFontRender> BossExplane3;
	std::shared_ptr<class UIFontRender> BossExplane4;
	std::string Font = "Aa카시오페아";
	float NameAlpha = 0.0f;
	float ExplaneAlpha = 0.0f;
	float Time = 0.0f;
	float Time2 = 0.0f;
	float Time3 = 0.0f;
	float Time4 = 0.0f;
	bool StartE = false;
};

