#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include "ContentsEnums.h"
#include "PlayerStat.h"
#include "MapTabUI.h"
#include "InventoryUI.h"
// Ό³Έν :
class PlayLevel : public GameEngineLevel
{
public:
	static PlayLevel* MainPlayLevel;

	// constrcuter destructer
	PlayLevel();
	~PlayLevel();

	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;

	std::shared_ptr<class FadeEffect> FEffect;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;



private:
	
	void CameraColMove(float _X, float _X1, float _Y, float _Y1);
	void CameraMoveSet();
	
	void UICtr();
	
	float4 TownScale = float4::Zero;
	MyMap CurMap = MyMap::None;
	float4 WindowSizeHalf = float4::Zero;

	std::shared_ptr<PlayerStat> Stat;
	std::shared_ptr<MapTabUI> MapTab;
	std::shared_ptr<InventoryUI> Inventory;

};
