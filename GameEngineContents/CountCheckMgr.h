#pragma once

// Ό³Έν :
class CountCheckMgr
{
public:
	// constrcuter destructer
	CountCheckMgr();
	~CountCheckMgr();

	// delete Function
	CountCheckMgr(const CountCheckMgr& _Other) = delete;
	CountCheckMgr(CountCheckMgr&& _Other) noexcept = delete;
	CountCheckMgr& operator=(const CountCheckMgr& _Other) = delete;
	CountCheckMgr& operator=(CountCheckMgr&& _Other) noexcept = delete;

protected:

private:

};

