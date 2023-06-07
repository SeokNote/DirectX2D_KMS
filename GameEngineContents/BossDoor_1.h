#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class BossDoor_1 :public GameEngineActor
{
public:
	// constrcuter destructer
	BossDoor_1();
	~BossDoor_1();

	// delete Function
	BossDoor_1(const BossDoor_1& _Other) = delete;
	BossDoor_1(BossDoor_1&& _Other) noexcept = delete;
	BossDoor_1& operator=(const BossDoor_1& _Other) = delete;
	BossDoor_1& operator=(BossDoor_1&& _Other) noexcept = delete;

protected:

private:

};

