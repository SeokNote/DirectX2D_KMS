#pragma once

// Ό³Έν :
class ShopNpc
{
public:
	// constrcuter destructer
	ShopNpc();
	~ShopNpc();

	// delete Function
	ShopNpc(const ShopNpc& _Other) = delete;
	ShopNpc(ShopNpc&& _Other) noexcept = delete;
	ShopNpc& operator=(const ShopNpc& _Other) = delete;
	ShopNpc& operator=(ShopNpc&& _Other) noexcept = delete;

protected:

private:

};

