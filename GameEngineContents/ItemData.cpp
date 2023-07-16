#include "PrecompileHeader.h"
#include "ItemData.h"
ItemData* ItemData::MainItemData = nullptr;
ItemData::ItemData() 
{
	MainItemData = this;
}

ItemData::~ItemData() 
{
}

