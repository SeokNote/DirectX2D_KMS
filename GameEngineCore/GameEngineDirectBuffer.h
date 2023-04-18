#pragma once
#include "GameEngineResource.h"

// 설명 :
class GameEngineDirectBuffer
{
public:
	// constrcuter destructer
	GameEngineDirectBuffer();
	~GameEngineDirectBuffer();

	// delete Function
	GameEngineDirectBuffer(const GameEngineDirectBuffer& _Other) = delete;
	GameEngineDirectBuffer(GameEngineDirectBuffer&& _Other) noexcept = delete;
	GameEngineDirectBuffer& operator=(const GameEngineDirectBuffer& _Other) = delete;
	GameEngineDirectBuffer& operator=(GameEngineDirectBuffer&& _Other) noexcept = delete;

public:
	//BufferInfo즉 버퍼의 정보중 버퍼의 사이즈를 알려고 만듬
	UINT GetBufferSize()
	{
		return BufferInfo.ByteWidth;
	}

protected:
	D3D11_BUFFER_DESC BufferInfo = { 0, };
	ID3D11Buffer* Buffer = nullptr;

private:
};

