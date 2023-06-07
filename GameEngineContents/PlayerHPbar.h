#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
// Ό³Έν :
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
	std::shared_ptr<GameEngineUIRenderer> PlayerHpBarUI;
	std::shared_ptr<GameEngineUIRenderer> PlayerHpBarBGUI;

	float4 PlayerHpBarUIScale = { 296.0f,64.0f,0.0f };

	float4 PlayerHpBarPos = { -482.0f, 318.0f };
};


