#pragma once

// Ό³Έν :
class TunakBulletBase
{
public:
	// constrcuter destructer
	TunakBulletBase();
	~TunakBulletBase();

	// delete Function
	TunakBulletBase(const TunakBulletBase& _Other) = delete;
	TunakBulletBase(TunakBulletBase&& _Other) noexcept = delete;
	TunakBulletBase& operator=(const TunakBulletBase& _Other) = delete;
	TunakBulletBase& operator=(TunakBulletBase&& _Other) noexcept = delete;

protected:

private:

};

