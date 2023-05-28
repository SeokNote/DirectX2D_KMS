#pragma once

// Ό³Έν :
class FoodUI
{
public:
	// constrcuter destructer
	FoodUI();
	~FoodUI();

	// delete Function
	FoodUI(const FoodUI& _Other) = delete;
	FoodUI(FoodUI&& _Other) noexcept = delete;
	FoodUI& operator=(const FoodUI& _Other) = delete;
	FoodUI& operator=(FoodUI&& _Other) noexcept = delete;

protected:

private:

};

