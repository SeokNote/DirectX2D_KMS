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
			ItemSwichRender = "Null.png";
			break;
		case WeaponDatas::GreatWeapon:
			WeaponType = WeaponDatas::GreatWeapon;
			ItemRender = "ShortSwordUI.png";
			ItemExplaneRender = "ShortWeaponEx.png";
			ItemSwichRender = "ShortSword.png";
			break;
		case WeaponDatas::SpaceSword:
			WeaponType = WeaponDatas::SpaceSword;
			ItemRender = "CosmosUI.png";
			ItemExplaneRender = "SpaceWeaponEx.png";
			ItemSwichRender = "CosmosWeapon.png";
			break;
		default:
			break;
		}
	}

public:
	static ItemData* MainItemData;
	std::string ItemRender = "Null.png";
	std::string ItemExplaneRender = "Null.png";
	std::string ItemSwichRender = "Null.png";

	WeaponDatas WeaponType = WeaponDatas::VACANCY;
};