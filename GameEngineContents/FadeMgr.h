#pragma once

// Ό³Έν :
class FadeMgr
{
public:
	// constrcuter destructer
	FadeMgr();
	~FadeMgr();

	// delete Function
	FadeMgr(const FadeMgr& _Other) = delete;
	FadeMgr(FadeMgr&& _Other) noexcept = delete;
	FadeMgr& operator=(const FadeMgr& _Other) = delete;
	FadeMgr& operator=(FadeMgr&& _Other) noexcept = delete;

protected:

private:

};

