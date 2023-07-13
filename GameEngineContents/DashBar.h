#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class DashBar : public GameEngineActor
{
public:
	// constrcuter destructer
	DashBar();
	~DashBar();

	// delete Function
	DashBar(const DashBar& _Other) = delete;
	DashBar(DashBar&& _Other) noexcept = delete;
	DashBar& operator=(const DashBar& _Other) = delete;
	DashBar& operator=(DashBar&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> PlayerDashBarUI3;
	std::shared_ptr<class GameEngineUIRenderer> PlayerDashBarUI2;
	std::shared_ptr<class GameEngineUIRenderer> PlayerDashBarUI1;
	std::shared_ptr<class GameEngineUIRenderer> PlayerDashBarUI0;
	float4 PlayerDashBarUIScale = { 132.0f,32.0f,0.0f };
	float4 PlayerDashBarUIPos = { -562.0f, 266.0f , 0.0f };
};

