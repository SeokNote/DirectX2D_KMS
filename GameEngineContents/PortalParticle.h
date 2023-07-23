#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class PortalParticle : public GameEngineActor
{
public:
	// constrcuter destructer
	PortalParticle();
	~PortalParticle();

	// delete Function
	PortalParticle(const PortalParticle& _Other) = delete;
	PortalParticle(PortalParticle&& _Other) noexcept = delete;
	PortalParticle& operator=(const PortalParticle& _Other) = delete;
	PortalParticle& operator=(PortalParticle&& _Other) noexcept = delete;

	static std::shared_ptr<PortalParticle> CreatePTC(GameEngineLevel* _Level, const float4& _Pos , const float4& _Value,const float4& _Dir);
	void SetPTCDir(float4 _Dir)
	{
		Dir = _Dir;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	std::shared_ptr<class GameEngineSpriteRenderer> ParticleRender = nullptr;
	int RandomValue = 0;
	float Ratio = 0.0f;
	float4 Dir = float4::Zero;
};

