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
	static GameEngineSoundPlayer BGM;
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
	void SetMap();
	void SetUI();
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
	std::shared_ptr<class Candle> CandlePtr_0;
	std::shared_ptr<class Candle> CandlePtr_1 = nullptr;
	std::shared_ptr<class Candle> CandlePtr_2 = nullptr;
	std::shared_ptr<class StandCandle> S_CandlePtr0 = nullptr;
	std::shared_ptr<class StandCandle> S_CandlePtr1 = nullptr;
	std::shared_ptr<class Potal> PotalPtr0 = nullptr;
	std::shared_ptr<class Potal> PotalPtr1 = nullptr;
	std::shared_ptr<class Potal> PotalPtr2 = nullptr;
	std::shared_ptr<class Potal> PotalPtr3 = nullptr;
	std::shared_ptr<class Potal> PotalPtr4 = nullptr;
	std::shared_ptr<class Potal> PotalPtr5 = nullptr;
	std::shared_ptr<class Potal> PotalPtr6 = nullptr;
	std::shared_ptr<class Potal> PotalPtr7 = nullptr;
	std::shared_ptr<class Potal> PotalPtr8 = nullptr;
	std::shared_ptr<class Potal> PotalPtr9 = nullptr;
	std::shared_ptr<class Potal> PotalPtr10 = nullptr;
	std::shared_ptr<class Potal> PotalPtr11 = nullptr;
	std::shared_ptr<class MyMapUI> BelialText = nullptr;
	std::shared_ptr<class MyMapUI> TunakText = nullptr;
};
