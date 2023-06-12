#include "PrecompileHeader.h"
#include "PlayerHPbar.h"

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

	//이다음에 빨간색 게이지
	//그 후에 글자 렌더
}

void PlayerHPbar::Update(float _Delta)
{
}

