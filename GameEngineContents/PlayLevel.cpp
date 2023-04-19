#include "PrecompileHeader.h"
#include "PlayLevel.h"
#include "Player.h"
#include <GameEngineCore/GameEngineCamera.h>

PlayLevel::PlayLevel()
{
}

PlayLevel::~PlayLevel()
{
}


void PlayLevel::Start()
{
	//카메라 타입을 정해주는것. 원근투영이냐 직교투영이냐
	GetMainCamera()->SetProjectionType(CameraType::Perspective);

	GetMainCamera()->GetTransform()->SetLocalPosition({ 0, 0, -1000.0f });

	std::shared_ptr<Player> NewPlayer = CreateActor<Player>("Player");


}