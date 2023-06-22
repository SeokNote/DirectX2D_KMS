#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TunakDust : public GameEngineActor
{
public:
	// constrcuter destructer
	TunakDust();
	~TunakDust();

	// delete Function
	TunakDust(const TunakDust& _Other) = delete;
	TunakDust(TunakDust&& _Other) noexcept = delete;
	TunakDust& operator=(const TunakDust& _Other) = delete;
	TunakDust& operator=(TunakDust&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	std::shared_ptr<class GameEngineSpriteRenderer> TunakDustRender;

};

