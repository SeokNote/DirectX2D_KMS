#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Player : public GameEngineActor
{
public:
	static Player* MainPlayer;

	// constrcuter destructer
	Player();
	~Player();

	// delete Function
	Player(const Player& _Other) = delete;
	Player(Player&& _Other) noexcept = delete;
	Player& operator=(const Player& _Other) = delete;
	Player& operator=(Player&& _Other) noexcept = delete;



	std::shared_ptr<class GameEngineSpriteRenderer> GetPlayerPtr()
	{
		return Render1;
	}

protected:
	void Start();
	void Update(float _Delta) override;
	void Render(float _Delta) override;

	float4 TestColor;


private:


	float Angle = 0.0f;
	std::shared_ptr<class GameEngineSpriteRenderer> Render0;
	std::shared_ptr<class GameEngineSpriteRenderer> Render1;
	std::shared_ptr<class GameEngineSpriteRenderer> Render2;
	std::shared_ptr<class GameEngineSpriteRenderer> Render3;
	std::shared_ptr<class GameEngineSpriteRenderer> Render4;

};

