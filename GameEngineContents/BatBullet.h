#pragma once

// Ό³Έν :
class BatBullet
{
public:
	// constrcuter destructer
	BatBullet();
	~BatBullet();

	// delete Function
	BatBullet(const BatBullet& _Other) = delete;
	BatBullet(BatBullet&& _Other) noexcept = delete;
	BatBullet& operator=(const BatBullet& _Other) = delete;
	BatBullet& operator=(BatBullet&& _Other) noexcept = delete;

protected:

private:

};

