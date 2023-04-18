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
	//BindFlags : ������ ���������ο� ���ε� �Ǵ� ����� ���� ���⼭�� ������۷� �����
	BufferInfo.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	//ByteWidth : ������ ũ�⸦ ��Ÿ��
	BufferInfo.ByteWidth = _BufferDesc.Size;

	//CPUAccessFlags : CPU�� �����ϴ� ������ �����ش� ������۴� D3D11_CPU_ACCESS_WRITE : �� ������ ������ ������ �����Ҽ� �ִ�. 0�̸� �׼����� �ʿ����� ��������̴�.
	BufferInfo.CPUAccessFlags = D3D11_CPU_ACCESS_FLAG::D3D11_CPU_ACCESS_WRITE;
	if (0 == BufferInfo.CPUAccessFlags)
	{
		BufferInfo.Usage = D3D11_USAGE_DEFAULT; // D3D11_USAGE_DEFAULT : �б� �� ���� �������� �ʿ���
	}
	else {
		BufferInfo.Usage = D3D11_USAGE_DYNAMIC; //D3D11_USAGE_DYNAMIC: �б� �Ǵ� ���� �� �����Ѱ�.
	}

	if (S_OK != GameEngineDevice::GetDevice()->CreateBuffer(&BufferInfo, nullptr, &Buffer)) //CreateBuffer: �����쿡�� �����ϴ� ����ũ��������
	{
		MsgAssert("���ؽ� ���� ������ �����߽��ϴ�.");
	}
}