#pragma once

// Ό³Έν :
class BossBase
{
public:
	// constrcuter destructer
	BossBase();
	~BossBase();

	// delete Function
	BossBase(const BossBase& _Other) = delete;
	BossBase(BossBase&& _Other) noexcept = delete;
	BossBase& operator=(const BossBase& _Other) = delete;
	BossBase& operator=(BossBase&& _Other) noexcept = delete;

protected:

private:

};

