#pragma once

// Ό³Έν :
class DungeonIn
{
public:
	// constrcuter destructer
	DungeonIn();
	~DungeonIn();

	// delete Function
	DungeonIn(const DungeonIn& _Other) = delete;
	DungeonIn(DungeonIn&& _Other) noexcept = delete;
	DungeonIn& operator=(const DungeonIn& _Other) = delete;
	DungeonIn& operator=(DungeonIn&& _Other) noexcept = delete;

protected:

private:

};

