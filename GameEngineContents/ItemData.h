#pragma once
enum class WeaponDatas
{
	VACANCY,
	GreatWeapon,
	SpaceSword,
};
// Ό³Έν :
class ItemData
{
public:
	ItemData();
	~ItemData();
	void SetData(WeaponDatas _Weapon)
	{
		switch (_Weapon)
		{
		case WeaponDatas::VACANCY:
			WeaponType = WeaponDatas::VACANCY;
			ItemRender = "NULL.png";
			ItemExplaneRender = "NULL.png";
			break;
		case WeaponDatas::GreatWeapon:
			WeaponType = WeaponDatas::GreatWeapon;
			ItemRender = "GreatWeapon01.png";
			ItemExplaneRender = "GreatWeapon01.png";
			break;
		case WeaponDatas::SpaceSword:
			WeaponType = WeaponDatas::SpaceSword;
			ItemRender = "CosmosUI.png";
			ItemExplaneRender = "SpaceWeaponEx.png";
			break;
		default:
			break;
		}
	}

public:
	static ItemData* MainItemData;
	std::string ItemRender = "Null.png";
	std::string ItemExplaneRender = "Null.png";

	WeaponDatas WeaponType = WeaponDatas::VACANCY;
};