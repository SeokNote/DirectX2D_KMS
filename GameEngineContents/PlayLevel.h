#pragma once
#include <GameEngineCore\GameEngineLevel.h>
#include <GameEnginePlatform/GameEngineSound.h>
#include "ContentsEnums.h"
#include "PlayerStat.h"
#include "MapTabUI.h"
#include "InventoryUI.h"
#include "PointLightEffect.h"

// 설명 :
class PlayLevel : public GameEngineLevel
{
public:

	// constrcuter destructer
	PlayLevel();
	~PlayLevel();

	// delete Function
	PlayLevel(const PlayLevel& _Other) = delete;
	PlayLevel(PlayLevel&& _Other) noexcept = delete;
	PlayLevel& operator=(const PlayLevel& _Other) = delete;
	PlayLevel& operator=(PlayLevel&& _Other) noexcept = delete;

	std::shared_ptr<class FadeEffect> FEffect;
	void SetCandle();
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

	void LevelChangeStart() override;
	void LevelChangeEnd() override;



private:
	void SetMap();
	void SetUI();
	void SetPotal();
	void CameraColMove(float _X, float _X1, float _Y, float _Y1);
	void CameraMoveSet();
	void UICtr();
	void SetBGM();
	float4 TownScale = float4::Zero;
	MyMap CurMap = MyMap::None;
	MyMap PrevMap = MyMap::None;
	MyMap NextMap = MyMap::None;
	MyMap aaMap = MyMap::None;

	float4 WindowSizeHalf = float4::Zero;
	MyMap CandleMap = MyMap::None;

	std::shared_ptr<PlayerStat> Stat;
	std::shared_ptr<MapTabUI> MapTab;
	std::shared_ptr<InventoryUI> Inventory;
	bool CheckUICtr_0 = false;
	bool CheckUICtr_1 = false;
	bool CheckUICtr_2 = false;
	//테스트
	float FPS = 0.0f;
	int Frame = 0;
	int asd = 0;
	//양초
	std::shared_ptr<class Candle> CandlePtr_0 = nullptr;
	std::shared_ptr<class Candle> CandlePtr_1 = nullptr;
	std::shared_ptr<class Candle> CandlePtr_2 = nullptr;
	std::shared_ptr<class StandCandle> S_CandlePtr0 = nullptr;
	std::shared_ptr<class StandCandle> S_CandlePtr1 = nullptr;
	GameEngineSoundPlayer BGM;
};
