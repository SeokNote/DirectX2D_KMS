#include "PrecompileHeader.h"
#include "PlayerHPbar.h"
#include "Player.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
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


	PlayerHpBarBGUI = CreateComponent<GameEngineUIRenderer>(2);
	PlayerHpBarBGUI->SetTexture("PlayerLifeBack.png");
	PlayerHpBarBGUI->GetTransform()->SetLocalPosition(PlayerHpBarPos);
	PlayerHpBarBGUI->GetTransform()->SetLocalScale(PlayerHpBarUIScale);

	PlayerHpBarUI = CreateComponent<GameEngineUIRenderer>(2);
	PlayerHpBarUI->SetTexture("PlayerLifeBase 1.png");
	PlayerHpBarUI->GetTransform()->SetLocalPosition(PlayerHpBarPos);
	PlayerHpBarUI->GetTransform()->SetLocalScale(PlayerHpBarUIScale);

	PlayerHpBar = CreateComponent<GameEngineUIRenderer>(2);
	PlayerHpBar->SetTexture("PlayerLife.png");
	PlayerHpBar->GetTransform()->SetLocalPosition(PlayerHpPos);
	PlayerHpBar->GetTransform()->SetLocalScale(PlayerHpScale);

	PlayerHpAniRender = CreateComponent<GameEngineUIRenderer>(2);
	PlayerHpAniRender->SetTexture("LifeWave0.png");
	PlayerHpAniRender->CreateAnimation({ .AnimationName = "PlayerHp", .SpriteName = "PlayerHp",.FrameInter = 0.1f,.ScaleToTexture = true });
	PlayerHpAniRender->GetTransform()->SetLocalPosition(PlayerHpAniPos);
	PlayerHpAniRender->ChangeAnimation("PlayerHp");
	
}

void PlayerHPbar::Update(float _Delta)
{
	int CurPhp = Player::MainPlayer->GetData().GetPlayerHP();
	int Maxhp = Player::MainPlayer->GetData().GetPlayerMaxHP();
	PlayerHpBar->ImageClippingX(static_cast<float>(CurPhp) / static_cast<float>(Maxhp), ClipXDir::Left);
	float Cal = static_cast<float>(CurPhp) / static_cast<float>(Maxhp);
	float XPos = 196.0f - 196.0f * Cal ;

	if (Maxhp != CurPhp)
	{
		PlayerHpAniRender->GetTransform()->SetLocalPosition({ -342.0f - XPos, 318.0f, -100.0f });
	}

}

