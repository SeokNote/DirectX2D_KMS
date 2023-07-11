#include "PrecompileHeader.h"
#include "ContentsEnums.h"
#include "Player.h"
#include "PlayerStat.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>
#include "ContentButton.h"
#include "UIFontRender.h"

PlayerStat::PlayerStat()
{
}

PlayerStat::~PlayerStat()
{
}

void PlayerStat::Start()
{
	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	
	PlayerStatUI = CreateComponent<GameEngineUIRenderer>(150);
	PlayerStatUI->SetTexture("FinalStateUI.png");
	PlayerStatUI->GetTransform()->SetLocalPosition({ -392.0f, 80.0f ,0.0f });
	PlayerStatUI->GetTransform()->SetLocalScale(StatUIScale);
	//PlayerStatUI->Off();
	
	FoodStatUI = CreateComponent<GameEngineUIRenderer>(150);
	FoodStatUI->SetTexture("FoodBase.png");
	FoodStatUI->GetTransform()->SetLocalPosition({ -392.0f, -210.0f });
	FoodStatUI->GetTransform()->SetLocalScale(FoodStatUIScale);
	//FoodStatUI->Off();

	ExitButton = CreateComponent<GameEngineUIRenderer>(150);
	ExitButton->SetTexture("ExitButton.png");
	ExitButton->GetTransform()->SetLocalScale(ButtonScale);
	ExitButton->GetTransform()->SetLocalPosition({ -200,290,0 });
	//ExitButton->Off();


	ExitButtonSelect = CreateComponent<GameEngineUIRenderer>(150);
	ExitButtonSelect->SetTexture("ExitButton_Selected.png");
	ExitButtonSelect->GetTransform()->SetLocalScale(ButtonScale);
	ExitButtonSelect->GetTransform()->SetLocalPosition({ -200,290,0 });
	//ExitButtonSelect->Off();

	ExitButtonCollsion = CreateComponent<GameEngineCollision>();
	ExitButtonCollsion->GetTransform()->SetLocalPosition({ -200,290,0 });
	ExitButtonCollsion->GetTransform()->SetLocalScale(ButtonScale);
	ExitButtonCollsion->SetOrder(2998);

	
	StatusFont = CreateComponent<UIFontRender>(150);
	StatusFont->SetFont(font);
	StatusFont->SetFontFlag(FW1_CENTER);
	StatusFont->SetScale(36);
	StatusFont->SetColor(float4::White);
	StatusFont->SetText("STATUS");
	StatusFont->GetTransform()->SetLocalPosition({ -392.0f, 235.0f ,0.0f });

	FoodFont = CreateComponent<UIFontRender>(150);
	FoodFont->SetFont(font);
	FoodFont->SetFontFlag(FW1_CENTER);
	FoodFont->SetScale(36);
	FoodFont->SetColor(float4::White);
	FoodFont->SetText("FOODS");
	FoodFont->GetTransform()->SetLocalPosition({ -392.0f, -90.0f ,0.0f });
	
	SetButton();
}
void PlayerStat::Update(float _Delta)
{

	if (ExitButtonCollsion->Collision(ColOrder::PlayMouse, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		ExitButton->Off();
		ExitButtonSelect->On();
		if (GameEngineInput::IsDown("ClickMouse")) {
			Off();
		}
	}
	else {
		ExitButtonSelect->Off();
		ExitButton->On();
	}
	UpdateStat();
}

void PlayerStat::SetButton()
{
	
	PowButton = GetLevel()->CreateActor<ContentButton>();
	PowButton->GetTransform()->SetParent(GetTransform());
	PowButton->GetTransform()->SetLocalPosition({ -589.0f,171.0f,0.0f });
	PowButton->GetRender()->SetTexture("Pow.png");
	PowButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	PowButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	PowButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	PowButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	DefButton = GetLevel()->CreateActor<ContentButton>();
	DefButton->GetTransform()->SetParent(GetTransform());
	DefButton->GetTransform()->SetLocalPosition({ -589.0f,116.0f,0.0f });
	DefButton->GetRender()->SetTexture("Def.png");
	DefButton->GetRender()->GetTransform()->SetWorldScale({42.0f,42.0f,0.0f});
	DefButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	DefButton->GetExplaneRender()->GetTransform()->SetLocalPosition({170.0f,-75.0f,0.0f});
	DefButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });


	ToughtButton = GetLevel()->CreateActor<ContentButton>();
	ToughtButton->GetTransform()->SetParent(GetTransform());
	ToughtButton->GetTransform()->SetLocalPosition({ -474.0f,116.0f,0.0f });
	ToughtButton->GetRender()->SetTexture("Tough.png");
	ToughtButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	ToughtButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	ToughtButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	ToughtButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	BlockButton = GetLevel()->CreateActor<ContentButton>();
	BlockButton->GetTransform()->SetParent(GetTransform());
	BlockButton->GetTransform()->SetLocalPosition({ -364.0f,116.0f,0.0f });
	BlockButton->GetRender()->SetTexture("Block.png");
	BlockButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	BlockButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	BlockButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	BlockButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });
	
	CritcalButton = GetLevel()->CreateActor<ContentButton>();
	CritcalButton->GetTransform()->SetParent(GetTransform());
	CritcalButton->GetTransform()->SetLocalPosition({ -589.0f,61.0f,0.0f });
	CritcalButton->GetRender()->SetTexture("CritcalIcon.png");
	CritcalButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	CritcalButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	CritcalButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	CritcalButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	CriDamageButton = GetLevel()->CreateActor<ContentButton>();
	CriDamageButton->GetTransform()->SetParent(GetTransform());
	CriDamageButton->GetTransform()->SetLocalPosition({ -474.0f,61.0f,0.0f });
	CriDamageButton->GetRender()->SetTexture("CritcalDamage #245489.png");
	CriDamageButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	CriDamageButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	CriDamageButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	CriDamageButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });
	
	EvadeButton = GetLevel()->CreateActor<ContentButton>();
	EvadeButton->GetTransform()->SetParent(GetTransform());
	EvadeButton->GetTransform()->SetLocalPosition({ -364.0f,61.0f,0.0f });
	EvadeButton->GetRender()->SetTexture("Evade.png");
	EvadeButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	EvadeButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	EvadeButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	EvadeButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });
	
	SpeedButton = GetLevel()->CreateActor<ContentButton>();
	SpeedButton->GetTransform()->SetParent(GetTransform());
	SpeedButton->GetTransform()->SetLocalPosition({ -589.0f,6.0f,0.0f });
	SpeedButton->GetRender()->SetTexture("MoveSpeed #245670.png");
	SpeedButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	SpeedButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	SpeedButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	SpeedButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	AttackSpeedButton = GetLevel()->CreateActor<ContentButton>();
	AttackSpeedButton->GetTransform()->SetParent(GetTransform());
	AttackSpeedButton->GetTransform()->SetLocalPosition({ -474.0f,6.0f,0.0f });
	AttackSpeedButton->GetRender()->SetTexture("AttackSpeed #245800.png");
	AttackSpeedButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	AttackSpeedButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	AttackSpeedButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	AttackSpeedButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	ReloadButton = GetLevel()->CreateActor<ContentButton>();
	ReloadButton->GetTransform()->SetParent(GetTransform());
	ReloadButton->GetTransform()->SetLocalPosition({ -364.0f,6.0f,0.0f });
	ReloadButton->GetRender()->SetTexture("Reload #245684.png");
	ReloadButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	ReloadButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	ReloadButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	ReloadButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	DashAttackButton = GetLevel()->CreateActor<ContentButton>();
	DashAttackButton->GetTransform()->SetParent(GetTransform());
	DashAttackButton->GetTransform()->SetLocalPosition({ -589.0f,-49.0f,0.0f });
	DashAttackButton->GetRender()->SetTexture("DashDamage #245720.png");
	DashAttackButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	DashAttackButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	DashAttackButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	DashAttackButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	TruDamageButton = GetLevel()->CreateActor<ContentButton>();
	TruDamageButton->GetTransform()->SetParent(GetTransform());
	TruDamageButton->GetTransform()->SetLocalPosition({ -474.0f,-49.0f,0.0f });
	TruDamageButton->GetRender()->SetTexture("TrueDamage.png");
	TruDamageButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	TruDamageButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	TruDamageButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	TruDamageButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	SkillCulButton = GetLevel()->CreateActor<ContentButton>();
	SkillCulButton->GetTransform()->SetParent(GetTransform());
	SkillCulButton->GetTransform()->SetLocalPosition({ -364.0f,-49.0f,0.0f });
	SkillCulButton->GetRender()->SetTexture("Cooltime #245718.png");
	SkillCulButton->GetRender()->GetTransform()->SetWorldScale({ 42.0f,42.0f,0.0f });
	SkillCulButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	SkillCulButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	SkillCulButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	BurnButton = GetLevel()->CreateActor<ContentButton>();
	BurnButton->GetTransform()->SetParent(GetTransform());
	BurnButton->GetTransform()->SetLocalPosition({ -250.0f,120.0f,0.0f });
	BurnButton->GetRender()->SetTexture("Burn_0.png");
	BurnButton->GetRender()->GetTransform()->SetWorldScale({ 34.0f,34.0f,0.0f });
	BurnButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	BurnButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	BurnButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	PoisonButton = GetLevel()->CreateActor<ContentButton>();
	PoisonButton->GetTransform()->SetParent(GetTransform());
	PoisonButton->GetTransform()->SetLocalPosition({ -250.0f,75.0f,0.0f });
	PoisonButton->GetRender()->SetTexture("Poison.png");
	PoisonButton->GetRender()->GetTransform()->SetWorldScale({ 34.0f,34.0f,0.0f });
	PoisonButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	PoisonButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	PoisonButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	ColdButton = GetLevel()->CreateActor<ContentButton>();
	ColdButton->GetTransform()->SetParent(GetTransform());
	ColdButton->GetTransform()->SetLocalPosition({ -250.0f,35.0f,0.0f });
	ColdButton->GetRender()->SetTexture("Cold.png");
	ColdButton->GetRender()->GetTransform()->SetWorldScale({ 34.0f,34.0f,0.0f });
	ColdButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	ColdButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	ColdButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	ShockButton = GetLevel()->CreateActor<ContentButton>();
	ShockButton->GetTransform()->SetParent(GetTransform());
	ShockButton->GetTransform()->SetLocalPosition({ -250.0f,-10.0f,0.0f });
	ShockButton->GetRender()->SetTexture("Shock_0.png");
	ShockButton->GetRender()->GetTransform()->SetWorldScale({ 34.0f,34.0f,0.0f });
	ShockButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	ShockButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	ShockButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

	StunButton = GetLevel()->CreateActor<ContentButton>();
	StunButton->GetTransform()->SetParent(GetTransform());
	StunButton->GetTransform()->SetLocalPosition({ -250.0f,-55.0f,0.0f });
	StunButton->GetRender()->SetTexture("Stun.png");
	StunButton->GetRender()->GetTransform()->SetWorldScale({ 34.0f,34.0f,0.0f });
	StunButton->GetExplaneRender()->SetTexture("ExplaneBG.png");
	StunButton->GetExplaneRender()->GetTransform()->SetLocalPosition({ 170.0f,-75.0f,0.0f });
	StunButton->GetExplaneRender()->GetTransform()->SetWorldScale({ 390.0f,140.0f,1.0f });

}

void PlayerStat::UpdateStat()
{
	PowButton->SetStatFont({ .Name = "������ݷ�(����)",.ExplaneName = "������ ������ݷ��� ������� �߰�",.TwoExplaneName = "���ط��� ������ �ݴϴ�.",
	.Value = "�ӽ� ~ �ӽ�",.Index = 1});

	DefButton->SetStatFont({ .Name = "����",.ExplaneName = "�޴� ���ظ� �氨�����ݴϴ�.",
	.Value = SubString(std::to_string(Player::MainPlayer->GetData().GetDefense()),1) });

	ToughtButton->SetStatFont({.Name = "������",.ExplaneName = "������ ��ġ�� ���� �������� ",.TwoExplaneName="���ظ� ���ҽ�Ų��.",
	.Value = std::to_string(Player::MainPlayer->GetData().GetToughness()),.Index = 1});

	BlockButton->SetStatFont({ .Name = "����",.ExplaneName = "���� ������ ���� �� �ִ� ",.TwoExplaneName = "Ȯ���� ������Ų��.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetBlock()) + "%"),.Index = 1 });

	CritcalButton->SetStatFont({ .Name = "ũ��Ƽ��",.ExplaneName = "������ ġ������ ���ظ� ���� �� �ִ�",.TwoExplaneName = "��ȸ�� �þ�ϴ�.",
	.Value = std::to_string(Player::MainPlayer->GetData().GetCriticalChance()),.Index = 1 });

	CriDamageButton->SetStatFont({ .Name = "ũ��Ƽ�� ������",.ExplaneName = "ũ��Ƽ�� �߰� ���ط��� ��Ÿ���ϴ�.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetCriticalDamage())+"%")});

	EvadeButton->SetStatFont({ .Name = "ȸ��",.ExplaneName = "���� ������ ȸ���� �� �ִ� Ȯ����",.TwoExplaneName = "������Ų��.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetEvasion()) + "%"),.Index = 1 });

	SpeedButton->SetStatFont({ .Name = "�̵� �ӵ�",.ExplaneName = "�� ������ �����̰� ���ݴϴ�",
	.Value = SubString(std::to_string(Player::MainPlayer->GetData().GetMoveSpeed()/100.0f),1)});

	AttackSpeedButton->SetStatFont({ .Name = "���� �ӵ�",.ExplaneName = "1�ʿ� ������ �� �ִ� Ƚ���� ��Ÿ���ϴ�",
	.Value = SubString(std::to_string(Player::MainPlayer->GetData().GetAttackSpeed()),1) });

	ReloadButton->SetStatFont({ .Name = "������ �ӵ�",.ExplaneName = "�������� �ɸ��� �ð��� ��Ÿ���ϴ�.",
	.Value = "-"});

	DashAttackButton->SetStatFont({ .Name = "�뽬 ���ݷ�",.ExplaneName = "�뽬 ���ݷ��� ������ݷ��� %��",.TwoExplaneName = "���˴ϴ�.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetDashPower()) + "%"),.Index = 1 });

	TruDamageButton->SetStatFont({ .Name = "���� �����",.ExplaneName = "���� ���µ��� �����ϰ� ������ ���ظ�",.TwoExplaneName = "�����ϴ�.",
	.Value = std::to_string(Player::MainPlayer->GetData().GetTrueDamage()),.Index = 1 });

	SkillCulButton->SetStatFont({ .Name = "��ų ��Ÿ��",.ExplaneName = "��ų�� �� ������ ����� �� �ְ��մϴ�.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetSkillcul()) + "%") });

	BurnButton->SetStatFont({ .Name = "ȭ��",.ExplaneName = "���� ���¿� ª�� �ð����� �������",.TwoExplaneName = "�ݴϴ�.",
	.Value = "0",.Index = 1});

	PoisonButton->SetStatFont({ .Name = "�ߵ�",.ExplaneName = "���� �ߵ����� �� �ð����� �������.",.TwoExplaneName = "�ݴϴ�.",
	.Value = "0",.Index = 1 });

	ColdButton->SetStatFont({ .Name = "����",.ExplaneName = "���� ������ ����ϴ�",
	.Value = "0%"});

	ShockButton->SetStatFont({ .Name = "����",.ExplaneName = "ª�� �ð����� ������� �ְ� ���� ��",.TwoExplaneName = "�߰� ���ظ� �����ϴ�.",
	.Value = "0%",.Index = 1});

	StunButton->SetStatFont({ .Name = "����",.ExplaneName = "���� �Ͻ������� �ൿ�Ұ� ���·� ����ϴ�.",
	.Value = "0%"});
}

std::string PlayerStat::SubString(std::string num, int pos)
{
		return num.substr(0, num.find('.') + pos + 1);
}
