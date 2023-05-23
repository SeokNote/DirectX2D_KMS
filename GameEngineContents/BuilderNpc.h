#pragma once

// Ό³Έν :
class BuilderNpc
{
public:
	// constrcuter destructer
	BuilderNpc();
	~BuilderNpc();

	// delete Function
	BuilderNpc(const BuilderNpc& _Other) = delete;
	BuilderNpc(BuilderNpc&& _Other) noexcept = delete;
	BuilderNpc& operator=(const BuilderNpc& _Other) = delete;
	BuilderNpc& operator=(BuilderNpc&& _Other) noexcept = delete;

protected:

private:

};

