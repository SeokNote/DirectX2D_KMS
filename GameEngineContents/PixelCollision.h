#pragma once
#include "ContentsEnums.h"
// º≥∏Ì :
class GameEnginePixelColor;
class PixelCollision
{
public:
	// constrcuter destructer
	PixelCollision();
	~PixelCollision();

	// delete Function
	PixelCollision(const PixelCollision& _Other) = delete;
	PixelCollision(PixelCollision&& _Other) noexcept = delete;
	PixelCollision& operator=(const PixelCollision& _Other) = delete;
	PixelCollision& operator=(PixelCollision&& _Other) noexcept = delete;

	//∏ ≈∏¿‘ , ∏ ¿Ã∏ß , ≤¿¡˛¡° , ∏ Ω∫ƒ…¿œ
	//GameEnginePixelColor MapPixelColSetting(MyMap _CurMap);
//	GameEnginePixelColor GetMapPixel(const std::string_view& _FileName, float4 _Center, float4 _Scale);

	
protected:

private:
	MyMap CurMap = MyMap::None;
//	std::string_view& FileName;
	float4 Center = float4::Null;
	float4 Scale = float4::Null;
};

