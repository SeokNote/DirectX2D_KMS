#pragma once
#include <GameEngineCore/GameEngineActor.h>

// 설명 :
class TunakBullet : public GameEngineActor
{
public:
	// constrcuter destructer
	TunakBullet();
	~TunakBullet();

	// delete Function
	TunakBullet(const TunakBullet& _Other) = delete;
	TunakBullet(TunakBullet&& _Other) noexcept = delete;
	TunakBullet& operator=(const TunakBullet& _Other) = delete;
	TunakBullet& operator=(TunakBullet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
private:
	void MoveBullet(float _DeltaTime);
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletRender_0;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletRender_1;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletRender_2;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletRender_3;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletRender_4;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletRender_5;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletRender_6;
	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletRender_7;

	std::shared_ptr<class GameEngineSpriteRenderer> TunakBulletBGRender;

	//불릿변수
	float BulletSpeed = 500.0f;
	float DeadTime = 0.0f;
};

