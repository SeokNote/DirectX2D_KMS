#pragma once

// Ό³Έν :
class TempleNpc
{
public:
	// constrcuter destructer
	TempleNpc();
	~TempleNpc();

	// delete Function
	TempleNpc(const TempleNpc& _Other) = delete;
	TempleNpc(TempleNpc&& _Other) noexcept = delete;
	TempleNpc& operator=(const TempleNpc& _Other) = delete;
	TempleNpc& operator=(TempleNpc&& _Other) noexcept = delete;

protected:

private:

};

