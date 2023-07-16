#pragma once

// Ό³Έν :
class ItemData
{
public:
	ItemData();
	~ItemData();
public:
	static ItemData* MainItemData;
	void SetWeaponRender(std::string _string)
	{
		ItemRender = _string;
	}
	void SetExplaneRender(std::string _string)
	{
		ItemExplaneRender = _string;
	}
	void SetItemNumber(int _Value)
	{
		ItemNumber = _Value;
	}
	std::string GetWeaponRender()
	{
		return ItemRender;
	}
	std::string GetExplaneRender()
	{
		return ItemExplaneRender;
	}
	int SetItemNumber()
	{
		return ItemNumber;
	}
	std::string ItemRender = "Null.png";
	std::string ItemExplaneRender = "Null.png";
	int ItemNumber = 0;

};