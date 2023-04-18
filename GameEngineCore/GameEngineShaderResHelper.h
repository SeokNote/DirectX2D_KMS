#pragma once
#include "GameEngineConstantBuffer.h"
#include "GameEngineTexture.h"

//GameEngineShaderResHelper : 렌더러가 리소스까지 갖고있으면 너무 넘쳐나니까 도움을 주는 클래스 

// 모든 텍스처건 상수버퍼건 
class GameEngineShaderResources
{
public:
	std::string Name;
	class GameEngineShader* ParentShader;
	int BindPoint = -1; // b0 t0 같은 몇번째 슬롯에 세팅되어야 하는지에 대한 정보.
};

class GameEngineConstantBufferSetter : public GameEngineShaderResources
{
public:
	std::shared_ptr<GameEngineConstantBuffer> Res;
};

class GameEngineTextureSetter : public GameEngineShaderResources
{
public:
	std::shared_ptr<GameEngineTexture> Res;
};

class GameEngineShaderResHelper
{
private:
	std::multimap<std::string, GameEngineConstantBufferSetter> ConstantBuffer; //멀티맵을 쓴 이유 ?

public:
	void CreateConstantBufferSetter(const GameEngineConstantBufferSetter& _Buffer)
	{
		ConstantBuffer.insert(std::make_pair(_Buffer.Name, _Buffer));
	}

	void Copy(const GameEngineShaderResHelper& _ResHelper);
};
