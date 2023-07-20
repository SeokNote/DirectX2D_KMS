#pragma once
enum class MyMap
{
	None,
	Town,
	Stage1_1,
	Stage1_2,
	Stage1_3,
	Stage1_4,
	Stage1_Boss,

	Stage2_1,
	Stage2_Boss,

	Stage3_1,
	Stage3_Boss,

};

enum class ColOrder
{
	//몬스터 인지 범위
	ATTACKAREA,
	//몬스터 공격
	MONSTERATTACK,
	MONSTERBODY,
	//보스
	BELIALHEAD,
	TUNAK,
	//무기
	GreatWeapon,
	//스포너
	Spawner,
	//플레이어
	PlayerBody,
	//마우스
	PlayMouse,
};

