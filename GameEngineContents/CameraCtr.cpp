#include"PrecompileHeader.h"
#include "CameraCtr.h"
#include "Player.h"
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineActor.h>
CameraCtr::CameraCtr() 
{
}

CameraCtr::~CameraCtr() 
{
}
void CameraCtr::Start(std::shared_ptr<class GameEngineCamera> _MainCam)
{

	MainCamera = _MainCam;
	MainCamera->SetProjectionType(CameraType::Orthogonal);
	WindowSize = GameEngineWindow::GetScreenSize();
	WindowSizeHalf = WindowSize.half();

}
void CameraCtr::Update(float _DeltaTime)
{


}
// 5120 1440
void CameraCtr::CameraMove(float _X, float _Y)
{
	float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	WindowSizeHalf = GameEngineWindow::GetScreenSize() / 2;
	float Xhalf = _X / 2;
	float Yhalf = _Y / 2;

	float LeftOutCam = -Xhalf;
	float RightOutCam = Xhalf;
	float UpOutCam = Yhalf;
	float DownOutCam = -Yhalf;

	float LeftOut = PlayerPos.x - WindowSizeHalf.x;
	float RightOut = PlayerPos.x + WindowSizeHalf.x;
	float UpOut = PlayerPos.x + WindowSizeHalf.y;
	float DownOut = PlayerPos.x - WindowSizeHalf.y;
	
	if (LeftOut < LeftOutCam)
	{
		MainCamera->GetTransform()->SetWorldPosition({ LeftOutCam + WindowSizeHalf.x , PlayerPos.y,PlayerPos.z });
	}
	if (RightOut > RightOutCam)
	{
		MainCamera->GetTransform()->SetWorldPosition({ RightOutCam - WindowSizeHalf.x , PlayerPos.y,PlayerPos.z });
	}

	if (UpOut < UpOutCam)
	{
		MainCamera->GetTransform()->SetWorldPosition({ PlayerPos.x ,DownOutCam + WindowSizeHalf.y ,PlayerPos.z });
	}
	if (DownOut > UpOutCam)
	{
		MainCamera->GetTransform()->SetWorldPosition({ PlayerPos.x, UpOutCam - WindowSizeHalf.y ,PlayerPos.z });
	}
}
