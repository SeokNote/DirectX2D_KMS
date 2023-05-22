#include"PrecompileHeader.h"
#include "PixelCollision.h"
#include "Player.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>

#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>

PixelCollision::PixelCollision()
{
}

PixelCollision::~PixelCollision() 
{
}

//GameEnginePixelColor PixelCollision::MapPixelColSetting(MyMap _CurMap) {
//	std::string Name = "";
//	CurMap = _CurMap;
//	switch (CurMap)
//	{
//	case MyMap::None:
//	
//		break;
//	case MyMap::Town:
//		Name = "Stage_1";
//		return GetMapPixel(Name.c_str(), { 0,0,0 }, { 2560,720,0 });
//		break;
//	//case MyMap::Stage1_1:
//	//	//GetMapPixel();
//	//	break;
//	//case MyMap::Stage1_2:
//	//	//GetMapPixel();
//	//	break;
//	//case MyMap::Stage1_3:
//	//	//GetMapPixel();
//	//	break;
//	//case MyMap::Stage1_4:
//	//	//GetMapPixel();
//	//	break;
//	//case MyMap::Stage1_Boss:
//	//	//GetMapPixel();
//	//	break;
//	//case MyMap::Stage2_1:
//	//	//GetMapPixel();
//	//	break;
//	//case MyMap::Stage2_Boss:
//	//	//GetMapPixel();
//	//	break;
//	//case MyMap::Stage3_1:
//	//	//GetMapPixel();
//	//	break;
//	//case MyMap::Stage3_Boss:
//	//	//GetMapPixel();
//	//	break;
//	default:
//		return GameEnginePixelColor::Black;
//		break;
//	}
	/*
	
	CurMap =SetMyMap(CurMap);
	int Speed = 300.0f;

	float4 PlayerPos = GetTransform()->GetLocalPosition();
	float4 MapCenter = { 0.0f,0.0f,0.0f };
	float4 TransColPos = { 2560.0f,720 };
	float4 ColPlayerPos = MapCenter + TransColPos - PlayerPos;
	std::shared_ptr<GameEngineTexture> Ptr = GameEngineTexture::Find("TownCol_1.png");

	GameEnginePixelColor Pixel = Ptr->GetPixel(ColPlayerPos.x, ColPlayerPos.y+65);
	Pixel.a = 0;
	//if (Pixel == GameEnginePixelColor::Black) {
	//	GetTransform()->AddLocalPosition(-float4::Down * Speed * _DeltaTime);
	//}

		MyMap CurMap = MyMap::None;
	std::string_view& FileName;
	float4 Center = float4::Null;
	float4 Scale = float4::Null;
	*/


//GameEnginePixelColor PixelCollision::GetMapPixel(const std::string_view& _FileName, float4 _Center, float4 _Scale)
//{

	//float4 PlayerPos = Player::MainPlayer->GetTransform()->GetLocalPosition();
	//FileName = _FileName;
	//Center = _Center;
	//Scale = _Scale;
	//float4 ColPlayerPos = Center + Scale/2 - PlayerPos;
	//std::shared_ptr<GameEngineTexture> Ptr = GameEngineTexture::Find(FileName);

	//GameEnginePixelColor Pixel = Ptr->GetPixel(ColPlayerPos.x, ColPlayerPos.y + 65);
	//Pixel.a = 0;
	//return Pixel;
//}

