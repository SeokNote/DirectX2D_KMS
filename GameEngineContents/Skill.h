#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class Skill :public GameEngineActor
{
public:
	// constrcuter destructer
	Skill();
	~Skill();

	// delete Function
	Skill(const Skill& _Other) = delete;
	Skill(Skill&& _Other) noexcept = delete;
	Skill& operator=(const Skill& _Other) = delete;
	Skill& operator=(Skill&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	void Move(float _Delta);
	std::shared_ptr<class GameEngineSpriteRenderer> SkillRender;
	std::shared_ptr<class GameEngineCollision> SkillCol;

	float4 Scale = { 236.0f,132.0f,0.0f };
	float4 MousePos = float4::Zero;;
	float4 EffectPos = float4::Zero;;
	float Time = 0.0f;
};

