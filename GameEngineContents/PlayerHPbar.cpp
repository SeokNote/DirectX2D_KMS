#include "PrecompileHeader.h"
#include "PlayerHPbar.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include "UIFontRender.h"
PlayerHPbar::PlayerHPbar() 
{
}

PlayerHPbar::~PlayerHPbar() 
{
}

void PlayerHPbar::Start()
{

	std::shared_ptr<GameEngineCamera> Camera = GetLevel()->GetCamera(100);
	Camera->SetProjectionType(CameraType::Orthogonal);
	Camera->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });


	PlayerHpBarBGUI = CreateComponent<GameEngineUIRenderer>(90);
	PlayerHpBarBGUI->SetTexture("PlayerLifeBack.png");
	PlayerHpBarBGUI->GetTransform()->SetLocalScale(PlayerHpBarUIScale);

	PlayerHpBarUI = CreateComponent<GameEngineUIRenderer>(90);
	PlayerHpBarUI->SetTexture("PlayerLifeBase 1.png");
	//PlayerHpBarUI->GetTransform()->SetLocalPosition();
	PlayerHpBarUI->GetTransform()->SetLocalScale(PlayerHpBarUIScale);

	PlayerHpBar = CreateComponent<GameEngineUIRenderer>(90);
	PlayerHpBar->SetTexture("PlayerLife.png");
	PlayerHpBar->GetTransform()->SetLocalPosition({38.0f,0.0f,0.0f});
	PlayerHpBar->GetTransform()->SetLocalScale(PlayerHpScale);

	PlayerHpAniRender = CreateComponent<GameEngineUIRenderer>(90);
	PlayerHpAniRender->SetTexture("LifeWave0.png");
	PlayerHpAniRender->CreateAnimation({ .AnimationName = "PlayerHp", .SpriteName = "PlayerHp",.FrameInter = 0.1f,.ScaleToTexture = true });
//	PlayerHpAniRender->GetTransform()->SetLocalPosition(PlayerHpAniPos);
	PlayerHpAniRender->ChangeAnimation("PlayerHp");
	SetLevelFont();
	SetHpFont();
	SetSlash();
	
}

void PlayerHPbar::Update(float _Delta)
{
	UpdateText();
	int CurPhp = Player::MainPlayer->GetData().GetPlayerHP();
	int Maxhp = Player::MainPlayer->GetData().GetPlayerMaxHP();
	PlayerHpBar->ImageClippingX(static_cast<float>(CurPhp) / static_cast<float>(Maxhp), ClipXDir::Left);
	float Cal = static_cast<float>(CurPhp) / static_cast<float>(Maxhp);
	float XPos = 196.0f - 196.0f * Cal ;

	if (Maxhp != CurPhp)
	{
		PlayerHpAniRender->GetTransform()->SetLocalPosition({ 140.0f - XPos, 0.0f, 0.0f });
	}
	float4 Pos = PlayerLevelFont->GetTransform()->GetWorldPosition();
}

void PlayerHPbar::SetLevelFont()
{
	PlayerLevelFont = CreateComponent<UIFontRender>(100);
	PlayerLevelFont->SetFont(font);
	PlayerLevelFont->SetFontFlag(FW1_CENTER);
	PlayerLevelFont->SetScale(48);
	PlayerLevelFont->SetColor(float4::White);
	PlayerLevelFont->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelFont->GetTransform()->SetLocalPosition({-100.0f,30.0f,0.0f});

	PlayerLevelBG_0 = CreateComponent<UIFontRender>(99);
	PlayerLevelBG_0->SetFont(font);
	PlayerLevelBG_0->SetFontFlag(FW1_CENTER);
	PlayerLevelBG_0->SetScale(48);
	PlayerLevelBG_0->SetColor(float4::Black);
	PlayerLevelBG_0->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelBG_0->GetTransform()->SetLocalPosition({ -100.0f,33.0f,0.0f });

	PlayerLevelBG_3 = CreateComponent<UIFontRender>(99);
	PlayerLevelBG_3->SetFont(font);
	PlayerLevelBG_3->SetFontFlag(FW1_CENTER);
	PlayerLevelBG_3->SetScale(48);
	PlayerLevelBG_3->SetColor(float4::Black);
	PlayerLevelBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelBG_3->GetTransform()->SetLocalPosition({ -103.0f,30.0f,0.0f });

	PlayerLevelBG_1 = CreateComponent<UIFontRender>(99);
	PlayerLevelBG_1->SetFont(font);
	PlayerLevelBG_1->SetFontFlag(FW1_CENTER);
	PlayerLevelBG_1->SetScale(48);
	PlayerLevelBG_1->SetColor(float4::Black);
	PlayerLevelBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelBG_1->GetTransform()->SetLocalPosition({ -97.0f,30.0f,0.0f });

	PlayerLevelBG_2 = CreateComponent<UIFontRender>(99);
	PlayerLevelBG_2->SetFont(font);
	PlayerLevelBG_2->SetFontFlag(FW1_CENTER);
	PlayerLevelBG_2->SetScale(48);
	PlayerLevelBG_2->SetColor(float4::Black);
	PlayerLevelBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelBG_2->GetTransform()->SetLocalPosition({ -100.0f,27.0f,0.0f });
}

void PlayerHPbar::SetHpFont()
{
	
	PlayerHPFont = CreateComponent<UIFontRender>(100);
	PlayerHPFont->SetFont(font);
	PlayerHPFont->SetFontFlag(FW1_CENTER);
	PlayerHPFont->SetScale(48);
	PlayerHPFont->SetColor(float4::White);
	PlayerHPFont->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP())+ "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont->GetTransform()->SetLocalPosition({ 40.0f,30.0f,0.0f });

	PlayerHPFont_0 = CreateComponent<UIFontRender>(99);
	PlayerHPFont_0->SetFont(font);
	PlayerHPFont_0->SetFontFlag(FW1_CENTER);
	PlayerHPFont_0->SetScale(48);
	PlayerHPFont_0->SetColor(float4::Black);
	PlayerHPFont_0->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont_0->GetTransform()->SetLocalPosition({ 40.0f,33.0f,0.0f });

	PlayerHPFont_1 = CreateComponent<UIFontRender>(99);
	PlayerHPFont_1->SetFont(font);
	PlayerHPFont_1->SetFontFlag(FW1_CENTER);
	PlayerHPFont_1->SetScale(48);
	PlayerHPFont_1->SetColor(float4::Black);
	PlayerHPFont_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont_1->GetTransform()->SetLocalPosition({ 40.0f,27.0f,0.0f });

	PlayerHPFont_2 = CreateComponent<UIFontRender>(99);
	PlayerHPFont_2->SetFont(font);
	PlayerHPFont_2->SetFontFlag(FW1_CENTER);
	PlayerHPFont_2->SetScale(48);
	PlayerHPFont_2->SetColor(float4::Black);
	PlayerHPFont_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont_2->GetTransform()->SetLocalPosition({ 43.0f,30.0f,0.0f });

	PlayerHPFont_3 = CreateComponent<UIFontRender>(99);
	PlayerHPFont_3->SetFont(font);
	PlayerHPFont_3->SetFontFlag(FW1_CENTER);
	PlayerHPFont_3->SetScale(48);
	PlayerHPFont_3->SetColor(float4::Black);
	PlayerHPFont_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont_3->GetTransform()->SetLocalPosition({ 37.0f,30.0f,0.0f });
}

void PlayerHPbar::SetSlash()
{
	PlayerSlashFont = CreateComponent<UIFontRender>(100);
	PlayerSlashFont->SetFont(font);
	PlayerSlashFont->SetFontFlag(FW1_CENTER);
	PlayerSlashFont->SetScale(35);
	PlayerSlashFont->SetColor(float4::White);
	PlayerSlashFont->SetText("/");
	PlayerSlashFont->GetTransform()->SetLocalPosition({ 40.0f,22.0f,0.0f });

	PlayerSlashFont_0 = CreateComponent<UIFontRender>(99);
	PlayerSlashFont_0->SetFont(font);
	PlayerSlashFont_0->SetFontFlag(FW1_CENTER);
	PlayerSlashFont_0->SetScale(35);
	PlayerSlashFont_0->SetColor(float4::Black);
	PlayerSlashFont_0->SetText("/");
	PlayerSlashFont_0->GetTransform()->SetLocalPosition({ 40.0f,25.0f,0.0f });

	PlayerSlashFont_1 = CreateComponent<UIFontRender>(99);
	PlayerSlashFont_1->SetFont(font);
	PlayerSlashFont_1->SetFontFlag(FW1_CENTER);
	PlayerSlashFont_1->SetScale(35);
	PlayerSlashFont_1->SetColor(float4::Black);
	PlayerSlashFont_1->SetText("/");
	PlayerSlashFont_1->GetTransform()->SetLocalPosition({ 40.0f,19.0f,0.0f });

	PlayerSlashFont_2 = CreateComponent<UIFontRender>(99);
	PlayerSlashFont_2->SetFont(font);
	PlayerSlashFont_2->SetFontFlag(FW1_CENTER);
	PlayerSlashFont_2->SetScale(35);
	PlayerSlashFont_2->SetColor(float4::Black);
	PlayerSlashFont_2->SetText("/");
	PlayerSlashFont_2->GetTransform()->SetLocalPosition({ 43.0f,22.0f,0.0f });

	PlayerSlashFont_3 = CreateComponent<UIFontRender>(99);
	PlayerSlashFont_3->SetFont(font);
	PlayerSlashFont_3->SetFontFlag(FW1_CENTER);
	PlayerSlashFont_3->SetScale(35);
	PlayerSlashFont_3->SetColor(float4::Black);
	PlayerSlashFont_3->SetText("/");
	PlayerSlashFont_3->GetTransform()->SetLocalPosition({ 37.0f,22.0f,0.0f });
}

void PlayerHPbar::UpdateText()
{
	PlayerLevelFont->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelBG_0->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelBG_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelBG_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerLevelBG_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerLevel()));
	PlayerHPFont->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont_0->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont_1->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont_2->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));
	PlayerHPFont_3->SetText(std::to_string(Player::MainPlayer->GetData().GetPlayerHP()) + "   " + std::to_string(Player::MainPlayer->GetData().GetPlayerMaxHP()));

}

