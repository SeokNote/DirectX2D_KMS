#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include "ContentsEnums.h"
// Ό³Έν :
enum class MyMap
{
	None,
	Town,
	Stage1_1,
	Stage1_2

};


class MapDataBase 

{
public:
	// constrcuter destructer
	MapDataBase();
	~MapDataBase();

	// delete Function
	MapDataBase(const MapDataBase& _Other) = delete;
	MapDataBase(MapDataBase&& _Other) noexcept = delete;
	MapDataBase& operator=(const MapDataBase& _Other) = delete;
	MapDataBase& operator=(MapDataBase&& _Other) noexcept = delete;


	//static MapDataBase GetMapName(MyMap _Value)
	//{
	//	MapName = _Value;
	//	return MapName;
	//}

	static std::shared_ptr<MapDataBase> MapDataPtr;

protected:

private:

	MyMap MapName = MyMap::None;
	float Height = 0.0f;
	float Width = 0.0f;

	

};

