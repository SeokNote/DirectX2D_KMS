#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossDoor_2 :public GameEngineActor
{
public:
	// constrcuter destructer
	BossDoor_2();
	~BossDoor_2();

	// delete Function
	BossDoor_2(const BossDoor_2& _Other) = delete;
	BossDoor_2(BossDoor_2&& _Other) noexcept = delete;
	BossDoor_2& operator=(const BossDoor_2& _Other) = delete;
	BossDoor_2& operator=(BossDoor_2&& _Other) noexcept = delete;

protected:

private:

};

