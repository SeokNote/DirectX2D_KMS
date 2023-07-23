#pragma once

// Ό³Έν :
class Potal_State
{
public:
	// constrcuter destructer
	Potal_State();
	~Potal_State();

	// delete Function
	Potal_State(const Potal_State& _Other) = delete;
	Potal_State(Potal_State&& _Other) noexcept = delete;
	Potal_State& operator=(const Potal_State& _Other) = delete;
	Potal_State& operator=(Potal_State&& _Other) noexcept = delete;

protected:

private:

};

