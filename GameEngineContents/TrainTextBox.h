#pragma once

// Ό³Έν :
class TrainTextBox
{
public:
	// constrcuter destructer
	TrainTextBox();
	~TrainTextBox();

	// delete Function
	TrainTextBox(const TrainTextBox& _Other) = delete;
	TrainTextBox(TrainTextBox&& _Other) noexcept = delete;
	TrainTextBox& operator=(const TrainTextBox& _Other) = delete;
	TrainTextBox& operator=(TrainTextBox&& _Other) noexcept = delete;

protected:

private:

};

