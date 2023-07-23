#include "PrecompileHeader.h"
#include "Candle.h"
#include "Player.h"
#include "ContentsEnums.h"
#include "PointLightEffect.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineWindow.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineBase/GameEngineRandom.h>
Candle::Candle() 
{
}

Candle::~Candle() 
{
}



void Candle::Start()
{
	CandleRender = CreateComponent<GameEngineSpriteRenderer>(1);
	CandleRender->CreateAnimation({ .AnimationName = "CandleIdle", .SpriteName = "CandleIdle", .Loop = true , .ScaleToTexture = true });
	CandleRender->ChangeAnimation("CandleIdle");
	LightEffect = GetLevel()->GetMainCamera()->GetCamTarget()->CreateEffect<PointLightEffect>();
	LightEffect->SetState(PointLightType::Circle);
	LightEffect->LightBuffer.LightOption.x = 1.0f;
}

void Candle::Update(float _Delta)
{
	if (Player::MainPlayer->SetMyMap(Value) == Stage1_M)
	{
		if (nullptr != LightEffect)
		{
			Time += _Delta;
			float RandomY = GameEngineRandom::MainRandom.RandomFloat(130.0f, 150.0f);
			std::shared_ptr<GameEngineCamera> MainCam = GetLevel()->GetMainCamera();
			float4 Result = GetTransform()->GetWorldPosition();
			Result *= MainCam->GetView();
			Result *= MainCam->GetProjection();
			Result *= MainCam->GetViewPort();
			LightEffect->LightBuffer.LightColor = Color;
			if (Time > 0.1f)
			{
				LightEffect->LightBuffer.LightOption.y = RandomY;
				Time = 0.0f;
			}
			LightEffect->LightBuffer.LightPos = Result;
			LightEffect->LightBuffer.LightOption.x = 1.0f;

		}
	}
	else
	{
		LightEffect->LightBuffer.LightOption.x = 0.0f;
		LightEffect->LightBuffer.LightOption.y = 0.0f;

	}
	
}

