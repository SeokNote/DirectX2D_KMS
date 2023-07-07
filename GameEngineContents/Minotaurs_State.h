#pragma once

// Ό³Έν :
class Minotaurs_State
{
public:
	// constrcuter destructer
	Minotaurs_State();
	~Minotaurs_State();

	// delete Function
	Minotaurs_State(const Minotaurs_State& _Other) = delete;
	Minotaurs_State(Minotaurs_State&& _Other) noexcept = delete;
	Minotaurs_State& operator=(const Minotaurs_State& _Other) = delete;
	Minotaurs_State& operator=(Minotaurs_State&& _Other) noexcept = delete;

protected:

private:

};

