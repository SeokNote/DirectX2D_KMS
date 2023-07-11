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
	PowButton->SetStatFont({ .Name = "무기공격력(위력)",.ExplaneName = "위력은 무기공격력을 기반으로 추가",.TwoExplaneName = "피해량에 영향을 줍니다.",
	.Value = "임시 ~ 임시",.Index = 1});

	DefButton->SetStatFont({ .Name = "방어력",.ExplaneName = "받는 피해를 경감시켜줍니다.",
	.Value = SubString(std::to_string(Player::MainPlayer->GetData().GetDefense()),1) });

	ToughtButton->SetStatFont({.Name = "강인함",.ExplaneName = "강인함 수치에 따라 고정값의 ",.TwoExplaneName="피해를 감소시킨다.",
	.Value = std::to_string(Player::MainPlayer->GetData().GetToughness()),.Index = 1});

	BlockButton->SetStatFont({ .Name = "막기",.ExplaneName = "적의 공격을 막을 수 있는 ",.TwoExplaneName = "확률을 증가시킨다.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetBlock()) + "%"),.Index = 1 });

	CritcalButton->SetStatFont({ .Name = "크리티컬",.ExplaneName = "적에게 치명적인 피해를 입힐 수 있는",.TwoExplaneName = "기회가 늘어납니다.",
	.Value = std::to_string(Player::MainPlayer->GetData().GetCriticalChance()),.Index = 1 });

	CriDamageButton->SetStatFont({ .Name = "크리티컬 데미지",.ExplaneName = "크리티컬 추가 피해량을 나타냅니다.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetCriticalDamage())+"%")});

	EvadeButton->SetStatFont({ .Name = "회피",.ExplaneName = "적의 공격을 회피할 수 있는 확률을",.TwoExplaneName = "증가시킨다.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetEvasion()) + "%"),.Index = 1 });

	SpeedButton->SetStatFont({ .Name = "이동 속도",.ExplaneName = "더 빠르게 움직이게 해줍니다",
	.Value = SubString(std::to_string(Player::MainPlayer->GetData().GetMoveSpeed()/100.0f),1)});

	AttackSpeedButton->SetStatFont({ .Name = "공격 속도",.ExplaneName = "1초에 공격할 수 있는 횟수를 나타냅니다",
	.Value = SubString(std::to_string(Player::MainPlayer->GetData().GetAttackSpeed()),1) });

	ReloadButton->SetStatFont({ .Name = "재장전 속도",.ExplaneName = "재장전시 걸리는 시간을 나타냅니다.",
	.Value = "-"});

	DashAttackButton->SetStatFont({ .Name = "대쉬 공격력",.ExplaneName = "대쉬 공격력은 무기공격력의 %로",.TwoExplaneName = "계산됩니다.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetDashPower()) + "%"),.Index = 1 });

	TruDamageButton->SetStatFont({ .Name = "고정 대미지",.ExplaneName = "적의 방어력등을 무시하고 고정된 피해를",.TwoExplaneName = "입힙니다.",
	.Value = std::to_string(Player::MainPlayer->GetData().GetTrueDamage()),.Index = 1 });

	SkillCulButton->SetStatFont({ .Name = "스킬 쿨타임",.ExplaneName = "스킬을 더 빠르게 사용할 수 있게합니다.",
	.Value = (std::to_string(Player::MainPlayer->GetData().GetSkillcul()) + "%") });

	BurnButton->SetStatFont({ .Name = "화상",.ExplaneName = "적을 불태워 짧은 시간동안 대미지를",.TwoExplaneName = "줍니다.",
	.Value = "0",.Index = 1});

	PoisonButton->SetStatFont({ .Name = "중독",.ExplaneName = "적을 중독시켜 긴 시간동안 대미지를.",.TwoExplaneName = "줍니다.",
	.Value = "0",.Index = 1 });

	ColdButton->SetStatFont({ .Name = "추위",.ExplaneName = "적을 느리게 만듭니다",
	.Value = "0%"});

	ShockButton->SetStatFont({ .Name = "감전",.ExplaneName = "짧은 시간동안 대미지를 주고 공격 시",.TwoExplaneName = "추가 피해를 입힙니다.",
	.Value = "0%",.Index = 1});

	StunButton->SetStatFont({ .Name = "기절",.ExplaneName = "적을 일시적으로 행동불가 상태로 만듭니다.",
	.Value = "0%"});
}

std::string PlayerStat::SubString(std::string num, int pos)
{
		return num.substr(0, num.find('.') + pos + 1);
}
