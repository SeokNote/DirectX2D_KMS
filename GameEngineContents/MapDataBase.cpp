#include "PrecompileHeader.h"
#include "MapDataBase.h"
#include "Player.h"



std::shared_ptr<MapDataBase> MapDataBase::MapDataPtr = nullptr;

MapDataBase::MapDataBase() 
{
}

MapDataBase::~MapDataBase() 
{

}



//void MapDataBase::Start()
//{
//	MapDataPtr = Shared_This_dynamic_pointer<MapDataBase>();
//	SetMapName();
//
//}
//
//void MapDataBase::Update(float _Delta)
//
//
//{
//
//
//}
//
//
//
//
//
//void MapDataBase::SetMapName()
//{
//	float4 PlayerCurPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
//	if (PlayerCurPos.x < 2560.0f && PlayerCurPos.x >-2560.0f) {
//		MapName = MyMap::Town;
//	}
//}
//
//
//
//void MapDataBase::Render(float _Delta)
//{
//
//
//}
