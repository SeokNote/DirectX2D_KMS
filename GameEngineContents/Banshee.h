#pragma once

// Ό³Έν :
class Banshee
{
public:
	// constrcuter destructer
	Banshee();
	~Banshee();

	// delete Function
	Banshee(const Banshee& _Other) = delete;
	Banshee(Banshee&& _Other) noexcept = delete;
	Banshee& operator=(const Banshee& _Other) = delete;
	Banshee& operator=(Banshee&& _Other) noexcept = delete;

protected:

private:

};

