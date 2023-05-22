#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "StartButton.h"
// Ό³Έν :
class PlayStartWindow : public GameEngineActor
{
public:
	static PlayStartWindow* MainPlayStartWindow;

	// constrcuter destructer
	PlayStartWindow();
	~PlayStartWindow();

	// delete Function
	PlayStartWindow(const PlayStartWindow& _Other) = delete;
	PlayStartWindow(PlayStartWindow&& _Other) noexcept = delete;
	PlayStartWindow& operator=(const PlayStartWindow& _Other) = delete;
	PlayStartWindow& operator=(PlayStartWindow&& _Other) noexcept = delete;
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
	void CollisionSet();
private:
	float4 PlayStartWindowBGScale = { 1280.0f,720.0f,0.0f};
	float4 SlotScale = { 384.0f,572.0f,0.0f };
	float4 ButtonScale = { 88.0f,76.0f,0.0f };
	float4 SlotTextScale = { 152.0f,48.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> PlayStartWindowRender;

	std::shared_ptr<class GameEngineSpriteRenderer> PlayStartSlot_0;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayStartSlot_1;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayStartSlot_2;

	std::shared_ptr<class GameEngineSpriteRenderer> PlayStartSlotSelet_0;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayStartSlotSelet_1;
	std::shared_ptr<class GameEngineSpriteRenderer> PlayStartSlotSelet_2;

	std::shared_ptr<class GameEngineCollision> StartSlotCollsion_0;
	std::shared_ptr<class GameEngineCollision> StartSlotCollsion_1;
	std::shared_ptr<class GameEngineCollision> StartSlotCollsion_2;

	std::shared_ptr<class GameEngineSpriteRenderer> SlotExit;
	std::shared_ptr<class GameEngineSpriteRenderer> SlotExitSelet;
	std::shared_ptr<class GameEngineCollision> SlotExitCollsion;

	std::shared_ptr<class GameEngineSpriteRenderer> SlotImage_0;
	std::shared_ptr<class GameEngineSpriteRenderer> SlotImage_1;
	std::shared_ptr<class GameEngineSpriteRenderer> SlotImage_2;


	std::shared_ptr<StartButton> StartButtonPtr;

};

