#pragma once

// Ό³Έν :
class CommanderNpc
{
public:
	// constrcuter destructer
	CommanderNpc();
	~CommanderNpc();

	// delete Function
	CommanderNpc(const CommanderNpc& _Other) = delete;
	CommanderNpc(CommanderNpc&& _Other) noexcept = delete;
	CommanderNpc& operator=(const CommanderNpc& _Other) = delete;
	CommanderNpc& operator=(CommanderNpc&& _Other) noexcept = delete;

protected:

private:

};

