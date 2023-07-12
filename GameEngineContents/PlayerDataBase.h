#pragma once
// 설명 :
#include <cmath>
class PlayerDataBase 
{
public:
	PlayerDataBase();
	~PlayerDataBase();

protected:


public:
	int GetPlayerLevel()
	{
		return PlayerLevel;
	}
	void SubPlayerLevel(int _Value)
	{
		PlayerLevel -= _Value;
	}
	void PlusPlayerLevel(int _Value)
	{
		PlayerLevel += _Value;
	}
	int GetPlayerHP()
	{
		return PlayerHP;
	}
	void SubPlayerHP(int _Value)
	{
		PlayerHP -= _Value;
	}
	void PlusPlayerHP(int _Value)
	{
		PlayerHP += _Value;
	}
	int GetCoin()
	{
		return Coin;
	}
	void SubCoin(int _Value)
	{
		Coin -= _Value;
	}
	void PlusCoin(int _Value)
	{
		Coin += _Value;
	}
	int GetDashCunt()
	{
		return DashCunt;
	}
	void SubDashCunt(int _Value)
	{
		DashCunt -= _Value;
	}
	void PlusDashCunt(int _Value)
	{
		DashCunt += _Value;
	}
	int GetSatiety()
	{
		return Satiety;
	}
	void SubSatiety(int _Value)
	{
		Satiety -= _Value;
	}
	void PlusSatiety(int _Value)
	{
		Satiety += _Value;
	}
	int GetPower()
	{
		return Power;
	}
	void SubPower(int _Value)
	{
		Power -= _Value;
	}
	void PlusPower(int _Value)
	{
		Power += _Value;
	}
	float GetDefense()
	{
		return round(Defense * 100) / 100;
	}
	float GetAttackSpeed()
	{
		return AttackSpeed;
	}
	void SubAttackSpeed(float _Value)
	{
		AttackSpeed -= _Value;
	}
	void PlusAttackSpeed(float _Value)
	{
		AttackSpeed += _Value;
	}
	
	float GetMoveSpeed()
	{
		return MoveSpeed;
	}
	void SubMoveSpeed(float _Value)
	{
		MoveSpeed -= _Value;
	}
	void PlusMoveSpeed(float _Value)
	{
		MoveSpeed += _Value;
	}

	int GetEvasion()
	{
		return Evasion;
	}
	int GetBlock()
	{
		return Block;
	}

	int GetToughness()
	{
		return Toughness;
	}

	int GetTrueDamage()
	{
		return TrueDamage;
	}

	float GetCriticalChance()
	{
		return CriticalChance;
	}
	int GetCriticalDamage()
	{
		return CriticalDamage;
	}
	int GetDashPower()
	{
		return DashPower;
	}
	int GetPlayerMaxHP()
	{
		PlayerMaxHP += (PlayerLevel - 1) * 2;
		return PlayerMaxHP;
	}
	bool GetBelialCtrl()
	{
		return BelialCamera;
	}
	void SetBelialCtrl(bool _Value)
	{
		BelialCamera = _Value;
	}
	bool GetTunakCtrl()
	{
		return TunakCamera;
	}
	void SetTunakCtrl(bool _Value)
	{
		TunakCamera = _Value;
	}
	bool GetSkillcul()
	{
		return Skillcul;
	}
	void SetSkillcul(bool _Value)
	{
		Skillcul = _Value;
	}
	void PlusDefense(float _Value)
	{
		Defense += _Value;
	}
	void PlusCriticalChance(float _Value)
	{
		CriticalChance += _Value;
	}
	int GetMaxSatiety()
	{
		return MaxSatiety;
	}
private:
	int PlayerLevel = 1;				//플레이어 레벨	
	int PlayerMaxHP = 60;
	int PlayerHP = 60;					//플레이어 체력
	int Coin = 0;						//돈
	int DashCunt = 3;					//대쉬카운터
	int Satiety = 0;					//포만감
	int MaxSatiety = 100;
	int Power = 100;					//위력
	float Defense = 1.5f;					//방어력
	float AttackSpeed = 1.0f;			//공격속도
	float MoveSpeed = 350.0f;			//이동속도
	int Evasion = 0;					//회피
	int Block = 0;						//막기
	int Toughness = 0;					//강인함
	int TrueDamage = 0;					//고정 데미지
	float CriticalChance = 0;				//크리티컬
	int CriticalDamage = 100;				//크리티컬 데미지
	int DashPower = 50;					// 대쉬 공격력
	int Skillcul = 0;
	//보스 스폰카메라 컨트롤
	bool BelialCamera = false;
	bool TunakCamera = false;
};

