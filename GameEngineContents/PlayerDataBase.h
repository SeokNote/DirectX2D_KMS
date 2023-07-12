#pragma once
// ���� :
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
	int PlayerLevel = 1;				//�÷��̾� ����	
	int PlayerMaxHP = 60;
	int PlayerHP = 60;					//�÷��̾� ü��
	int Coin = 0;						//��
	int DashCunt = 3;					//�뽬ī����
	int Satiety = 0;					//������
	int MaxSatiety = 100;
	int Power = 100;					//����
	float Defense = 1.5f;					//����
	float AttackSpeed = 1.0f;			//���ݼӵ�
	float MoveSpeed = 350.0f;			//�̵��ӵ�
	int Evasion = 0;					//ȸ��
	int Block = 0;						//����
	int Toughness = 0;					//������
	int TrueDamage = 0;					//���� ������
	float CriticalChance = 0;				//ũ��Ƽ��
	int CriticalDamage = 100;				//ũ��Ƽ�� ������
	int DashPower = 50;					// �뽬 ���ݷ�
	int Skillcul = 0;
	//���� ����ī�޶� ��Ʈ��
	bool BelialCamera = false;
	bool TunakCamera = false;
};

