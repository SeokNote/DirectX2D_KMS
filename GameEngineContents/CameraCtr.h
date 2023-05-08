#pragma once

// Ό³Έν :
class CameraCtr
{
public:
	// constrcuter destructer
	CameraCtr();
	~CameraCtr();

	// delete Function
	CameraCtr(const CameraCtr& _Other) = delete;
	CameraCtr(CameraCtr&& _Other) noexcept = delete;
	CameraCtr& operator=(const CameraCtr& _Other) = delete;
	CameraCtr& operator=(CameraCtr&& _Other) noexcept = delete;

protected:
	void Start(std::shared_ptr<class GameEngineCamera> _MainCam);
	void Update(float _DeltaTime);
	void CameraMove(float _X, float _Y);

private:
	std::shared_ptr<class GameEngineCamera> MainCamera = nullptr;

	float4 WindowSize = float4::Zero;
	float4 WindowSizeHalf = float4::Zero;
};

