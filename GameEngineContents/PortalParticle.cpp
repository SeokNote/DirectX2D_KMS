#include "PrecompileHeader.h"
#include "PortalParticle.h"

#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineSprite.h>
#include <GameEngineBase/GameEngineRandom.h>
#include "PortalParticle.h"

PortalParticle::PortalParticle()
{
}

PortalParticle::~PortalParticle()
{

}

std::shared_ptr<PortalParticle> PortalParticle::CreatePTC(GameEngineLevel* _Level, const float4& _Pos, const float4& _Value, const float4& _Dir)
{
	std::shared_ptr<PortalParticle> ResultSubBG = _Level->CreateActor<PortalParticle>();
	float X = GameEngineRandom::MainRandom.RandomFloat(_Pos.x - _Value.x, _Pos.x + _Value.x);
	float Y = GameEngineRandom::MainRandom.RandomFloat(_Pos.y - _Value.y, _Pos.y + _Value.y);
	float4 Pos = { X,Y,-730.0f };
	ResultSubBG->GetTransform()->SetWorldPosition(Pos);
	ResultSubBG->SetPTCDir(_Dir);
	return ResultSubBG;
}

void PortalParticle::Start()
{
	ParticleRender = CreateComponent<GameEngineSpriteRenderer>(1);
	ParticleRender->SetScaleToTexture("Particle" + std::to_string(GameEngineRandom::MainRandom.RandomInt(0, 3)) + ".png");
	ParticleRender->ColorOptionValue.MulColor.a = 0.8f;
}

void PortalParticle::Update(float _DeltaTime)
{
	Ratio += _DeltaTime;
	ParticleRender->GetTransform()->AddLocalPosition({ Dir.x * Ratio*0.5f,Dir.y * Ratio,0.0f });
	if (ParticleRender->ColorOptionValue.MulColor.a > 0)
	{
		ParticleRender->ColorOptionValue.MulColor.a -= Ratio*0.01f;
	}
	else
	{
		Ratio = 0.0f;
		Death();
	}
}
