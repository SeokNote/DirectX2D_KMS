#include "PrecompileHeader.h"
#include "Intro.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineCollision.h>

Intro::Intro()
{
}

Intro::~Intro()
{
}

void Intro::Start()
{
	if (nullptr == GameEngineSprite::Find("CHAc_Ground_Run"))
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentResources");
		NewDir.Move("ContentResources");
		NewDir.Move("Animation");
		NewDir.Move("IntroAnimation");

		// TestAnimation.png

		GameEngineSprite::LoadFolder(NewDir.GetPlusFileName("TeamLogo").GetFullPath());

	}
	BGRender = CreateComponent<GameEngineUIRenderer>();
	BGRender->SetTexture("IntroBG.png");
	BGRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	BGRender->GetTransform()->SetLocalScale(BGScale);


	IntroRender = CreateComponent<GameEngineUIRenderer>();
	IntroRender->SetTexture("TeamLogo0.png");
	IntroRender->GetTransform()->SetLocalPosition({ 0.0f,0.0f,0.0f });
	IntroRender->GetTransform()->SetLocalScale(IntroScale);
	IntroRender->GetTransform()->SetLocalNegativeScaleX();
	IntroRender->CreateAnimation({ .AnimationName = "TeamLogoIdle", .SpriteName = "TeamLogo",.FrameInter = 1.4f , .ScaleToTexture = false });


	IntroRender->ChangeAnimation("TeamLogoIdle");

}
void Intro::Update(float _Delta)
{


}