#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SpaceSkill : public GameEngineActor
{
public:
	static SpaceSkill* MainSkillPtr;
	// constrcuter destructer
	SpaceSkill();
	~SpaceSkill();

	// delete Function
	SpaceSkill(const SpaceSkill& _Other) = delete;
	SpaceSkill(SpaceSkill&& _Other) noexcept = delete;
	SpaceSkill& operator=(const SpaceSkill& _Other) = delete;
	SpaceSkill& operator=(SpaceSkill&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;
private:
	std::shared_ptr<class GameEngineUIRenderer> SkillUI;
	std::shared_ptr<class GameEngineUIRenderer> CommandUI;
	std::shared_ptr<class GameEngineUIRenderer> CulTimeUI;
	float4 SkillScale = { 76.0f,76.0f,0.0f };
	float4 CommandScale = { 26.0f,28.0f,0.0f };
	float4 CulScale = { 67.0f,68.0f,0.0f };
	bool IsValue = false;
	float CurCulltime = 0.0f;
	float MaxCulltime = 3.0f;
};

