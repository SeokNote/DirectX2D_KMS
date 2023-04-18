#include "PrecompileHeader.h"
#include "GameEngineConstantBuffer.h"

std::map<int, std::map<std::string, std::shared_ptr<GameEngineConstantBuffer>>> GameEngineConstantBuffer::ConstantBufferRes;

void GameEngineConstantBuffer::ResourcesClear()
{
	GameEngineResource<GameEngineConstantBuffer>::ResourcesClear();

	ConstantBufferRes.clear();
}

GameEngineConstantBuffer::GameEngineConstantBuffer()
{
}

GameEngineConstantBuffer::~GameEngineConstantBuffer()
{
}

void GameEngineConstantBuffer::ResCreate(const D3D11_SHADER_BUFFER_DESC& _BufferDesc)
{
	//BindFlags : 렌더링 파이프라인에 바인딩 되는 방식을 말함 여기서는 상수버퍼로 적용됨
	BufferInfo.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	//ByteWidth : 버퍼의 크기를 나타냄
	BufferInfo.ByteWidth = _BufferDesc.Size;

	//CPUAccessFlags : CPU에 접근하는 유형을 정해준다 상수버퍼는 D3D11_CPU_ACCESS_WRITE : 즉 변경이 가능한 내용을 매핑할수 있다. 0이면 액세스가 필요하지 않을경우이다.
	BufferInfo.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;
	if (0 == BufferInfo.CPUAccessFlags)
	{
		BufferInfo.Usage = D3D11_USAGE_DEFAULT; // D3D11_USAGE_DEFAULT : 읽기 및 쓰기 엑세스가 필요함
	}
	else {
		BufferInfo.Usage = D3D11_USAGE_DYNAMIC; //D3D11_USAGE_DYNAMIC: 읽기 또는 쓰기 다 가능한것.
	}

	if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&BufferInfo, nullptr, &Buffer)) //CreateBuffer: 윈도우에서 제공하는 버퍼크리에이터
	{
		MsgAssert("버텍스 버퍼 생성에 실패했습니다.");
	}
}