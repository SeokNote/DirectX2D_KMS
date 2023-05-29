#include "PrecompileHeader.h"
#include "GameEngineRenderingPipeLine.h"
#include <GameEngineCore/GameEngineDevice.h>
#include "GameEngineVertexBuffer.h"
#include "GameEngineIndexBuffer.h"
#include "GameEngineVertexShader.h"
#include "GameEngineRasterizer.h"
#include "GameEnginePixelShader.h"
#include "GameEngineBlend.h"
#include "GameEngineInputLayOut.h"
#include "GameEngineDepthState.h"

GameEngineRenderingPipeLine::GameEngineRenderingPipeLine()
{
	InputLayOutPtr = std::make_shared<GameEngineInputLayOut>();
}

GameEngineRenderingPipeLine::~GameEngineRenderingPipeLine()
{
}

// �Ž� + ��Ƽ����

// ������: ���� ���� ������ �غ��ϰ�
//IA1������ ���ؽ� ���۸� �����ϰ� ���ؽ� ���̴� �ܰ迡 �������� �ʿ��� ������ �������ش�.ex)InputLayOut
void GameEngineRenderingPipeLine::InputAssembler1()
{
	//InputLayOut�� ���ؽ� ���̴����� ù��° ���ڷ� ������ �������� ���̴��� �𸣱�
	// ������ ù��° ���ڰ� �����̰� �����Ʈ ũ�⸦ ������ �˷��ֱ�����
	// �� �����ؾ���
	//
	// �������� ���ؼ��� ������ ���� ����°� �⺻�̴�.
	// �׷���ī��� ���� ��� ������ ������ �ִ��� ���� ���Ѵ�.
	if (nullptr == InputLayOutPtr)
	{
		MsgAssert("��ǲ ���̾ƿ��� �������� �ʾƼ� ��ǲ�����1 ������ ������ �� �����ϴ�.");
		return;
	}
	
	InputLayOutPtr->Setting();
	
	if (nullptr == VertexBufferPtr)
	{
		MsgAssert("���ؽ� ���۰� �������� �ʾƼ� ��ǲ�����1 ������ ������ �� �����ϴ�.");
		return;
	}

	// D3D11 ERROR: ID3D11DeviceContext::DrawIndexed: The Vertex Shader expects 
	// application provided input data (which is to say data other than hardware 
	// auto-generated values such as VertexID or InstanceID). Therefore an Input 
	// Assembler object is expected, but none is bound. 
	// [ EXECUTION ERROR #349: DEVICE_DRAW_INPUTLAYOUT_NOT_SET]

	VertexBufferPtr->Setting();
	// GameEngineDevice::GetContext()->IASetVertexBuffers()
}
// ������: ���ÿ� �����ϴ� ���� �츮�� ���� ����� ���ؼ� ��ȯ�ϰ�
// �Է��� ���̴���(TextureShader) ���������ε� Ÿ�� ���ؽ� ���̴� �ܰ迡 ���ԵǸ� ���̴����� Texture_VS�� ����  IA���� �������� ���ؽ�
// ���۸� ���� �÷��� ��ġ,��������� ���Ͽ� ������ SV_Posion�� Color�� �������ش�.
void GameEngineRenderingPipeLine::VertexShader()
{
	if (nullptr == VertexShaderPtr)
	{
		MsgAssert("���ؽ� ���̴��� �������� �ʾƼ� ���ؽ� ���̴� ������ ������ �� �����ϴ�.");
		return;
	}

	VertexShaderPtr->Setting();
}

// ������: ���� ������ ���� � ������ �׸��� ���ϰ�
// InputAssembler2�ܰ迡���� �� �������� ���� � ������ �ﰢ���� �׷� ������� �����ִ� �ܰ��̴�.
// �츮�� ���������� -z �� �ڿ��� �ٶ󺸱� ������ �ݽð�� ����� �ؾ��ϴµ� �������� �������� �����⸦ true�� ���༭ �ð���� ������ �׸���(?)
// ī�޶� ��ȯ,�븻������,������İ� ����
void GameEngineRenderingPipeLine::InputAssembler2()
{	// �׸��� ������ ���� �����͸� �־��ش�.


	if (nullptr == IndexBufferPtr)
	{
		MsgAssert("�ε��� ���۰� �������� �ʾƼ� ��ǲ �����2 ������ ������ �� �����ϴ�.");
		return;
	}

	// 012023
	IndexBufferPtr->Setting();

	// 012 023 <=3���� ��� ������ ������� ���⼭ ó���� �Ǿ���.
	GameEngineDevice::GetContext()->IASetPrimitiveTopology(TOPOLOGY);
}

// ���⼭����
void GameEngineRenderingPipeLine::HullShader()
{

}
void GameEngineRenderingPipeLine::Tessellator()
{

}
void GameEngineRenderingPipeLine::DomainShader()
{

}
void GameEngineRenderingPipeLine::GeometryShaeder()
{

}
// ��������� ȭ����� ��� ���� ����

// w�����⸦ ���ݴϴ�. ���ִ� ���� : Ŭ���� ������ �ٷ� �츮 ȭ�鿡 ��µǾ���ϴ� �����ε� �� Ŭ���ο����� 
// z = -1~0 , 0~1 ,x ,y �� -1~1�� ǥ���� �Ǵµ� . ���� �ܰ迡�� �븻����� �Ǿ� �� �������� Ŭ���ο����� ����� �Ǵµ�
// 3���� ��ǥ�� 2������ ȭ�鿡 ����Ϸ��� z�� ��������ϴµ� �� z�� ������Ŀ��꿡 ���� w ���� ����Ǿ� �ֱ� ������ w�� �����ִ°��̴�.
// ����Ʈ�� �����ݴϴ�. : -1~1�� ��ġ�ϸ� �Ⱥ��̱⿡ ���� ������ ũ�⸸ŭ ���ؼ� ��ü�� Ű��°�.
// ȭ�� �ø� 
// �ȼ� ������

void GameEngineRenderingPipeLine::Rasterizer()
{
	if (nullptr == RasterizerPtr)
	{
		MsgAssert("�����Ͷ������� �������� �ʾƼ� ������ �Ұ����մϴ�.");
		return;
	}

	RasterizerPtr->SetFILL_MODE(D3D11_FILL_MODE::D3D11_FILL_SOLID); // fill_mode�� 2���� �ɼ��� �ִµ� ������ �׸��ų� ������ �׸��ųĸ� ������
	RasterizerPtr->Setting();

	// GameEngineDevice::GetContext()->RSSetState
}

//�� �ȼ��� �����͸� �����ϴ� �ܰ��̴�. ���� ����� ��� ����Ÿ�ٿ� �׸����� �������ش�.
void GameEngineRenderingPipeLine::PixelShader()
{
	if (nullptr == PixelShaderPtr)
	{
		MsgAssert("�ȼ� ���̴��� �������� �ʾƼ� �ȼ� ���̴� ������ ������ �� �����ϴ�.");
		return;
	}

	PixelShaderPtr->Setting();


	// GameEngineDevice::GetContext()->PSSetShader
}
void GameEngineRenderingPipeLine::OutputMerger()
{
	if (nullptr == BlendStatePtr)
	{
		MsgAssert("���尡 �������� �ʾ� �ƿ�ǲ ���� ������ �Ϸ��Ҽ��� �����ϴ�.");
		return;
	}


	BlendStatePtr->Setting();

	if (nullptr == DepthStatePtr)
	{
		MsgAssert("���尡 �������� �ʾ� �ƿ�ǲ ���� ������ �Ϸ��Ҽ��� �����ϴ�.");
		return;
	}
	DepthStatePtr->Setting();
	// GameEngineDevice::GetContext()->OMSetRenderTargets
}


void GameEngineRenderingPipeLine::SetVertexBuffer(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	VertexBufferPtr = GameEngineVertexBuffer::Find(UpperName);

	if (nullptr == VertexBufferPtr)
	{
		MsgAssert("�������� �ʴ� ���ؽ� ���۸� ����Ϸ��� �߽��ϴ�.");
	}

	if (nullptr == VertexShaderPtr)
	{
		return;
	}

	InputLayOutPtr->ResCreate(VertexBufferPtr, VertexShaderPtr);
}


void GameEngineRenderingPipeLine::SetIndexBuffer(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	IndexBufferPtr = GameEngineIndexBuffer::Find(UpperName);

	if (nullptr == IndexBufferPtr)
	{
		MsgAssert("�������� �ʴ� ���ؽ� ���۸� ����Ϸ��� �߽��ϴ�.");
	}
}


void GameEngineRenderingPipeLine::SetVertexShader(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	VertexShaderPtr = GameEngineVertexShader::Find(UpperName);

	if (nullptr == VertexShaderPtr)
	{
		MsgAssert("�������� �ʴ� ���ؽ� ���̴��� ����Ϸ��� �߽��ϴ�.");
	}

	if (nullptr == VertexBufferPtr)
	{
		return;
	}

	InputLayOutPtr->ResCreate(VertexBufferPtr, VertexShaderPtr);
}


void GameEngineRenderingPipeLine::SetPixelShader(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	PixelShaderPtr = GameEnginePixelShader::Find(UpperName);

	if (nullptr == PixelShaderPtr)
	{
		MsgAssert("�������� �ʴ� �ȼ� ���̴��� ����Ϸ��� �߽��ϴ�.");
	}
}


void GameEngineRenderingPipeLine::SetBlendState(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	BlendStatePtr = GameEngineBlend::Find(UpperName);

	if (nullptr == BlendStatePtr)
	{
		MsgAssert("�������� �ʴ� ���带 �����Ϸ��� �߽��ϴ�.");
		return;
	}
}

void GameEngineRenderingPipeLine::SetDepthState(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	DepthStatePtr = GameEngineDepthState::Find(UpperName);

	if (nullptr == DepthStatePtr)
	{
		MsgAssert("�������� �ʴ� ���带 �����Ϸ��� �߽��ϴ�.");
		return;
	}
}

void GameEngineRenderingPipeLine::SetRasterizer(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	RasterizerPtr = GameEngineRasterizer::Find(UpperName);

	if (nullptr == RasterizerPtr)
	{
		MsgAssert("�������� �ʴ� �����Ͷ������� ����Ϸ��� �߽��ϴ�.");
	}
}
void GameEngineRenderingPipeLine::RenderingPipeLineSetting()
{
	// ������� �ϴ� �κ��� ������ ������������ �ѹٲ� ������ ��.
	InputAssembler1();
	VertexShader();
	InputAssembler2();
	HullShader();
	Tessellator();
	DomainShader();
	GeometryShaeder();
	Rasterizer();
	PixelShader();
	OutputMerger();
}


// �Ž� + ��Ƽ����
void GameEngineRenderingPipeLine::Render()
{


	// GameEngineDevice::GetContext()->VSSetConstantBuffers()

	UINT IndexCount = IndexBufferPtr->GetIndexCount();
	GameEngineDevice::GetContext()->DrawIndexed(IndexCount, 0, 0);

	// �� �����ٸ�

	// �޽� <= ������ ��� ���ϰ��ΰ�.
	//         �ȼ����������� ������ �����ϴ� Rasterizer
	//         w�����⸦ �ϰ� ����Ʈ�� ���ؼ�

	// ��Ƽ���� <= ������ ��� ���ð��ΰ�?
	//             �����Ͷ����� + �ȼ����̴� + ���ؽ� ���̴�
}
std::shared_ptr<GameEngineRenderingPipeLine> GameEngineRenderingPipeLine::Clone()
{
	std::shared_ptr<GameEngineRenderingPipeLine> ClonePipe = std::make_shared<GameEngineRenderingPipeLine>();

	ClonePipe->InputLayOutPtr = InputLayOutPtr;
	ClonePipe->VertexBufferPtr = VertexBufferPtr;
	ClonePipe->IndexBufferPtr = IndexBufferPtr;
	ClonePipe->VertexShaderPtr = VertexShaderPtr;
	ClonePipe->RasterizerPtr = RasterizerPtr;
	ClonePipe->PixelShaderPtr = PixelShaderPtr;
	ClonePipe->BlendStatePtr = BlendStatePtr;
	ClonePipe->DepthStatePtr = DepthStatePtr;
	ClonePipe->IsCloneValue = true;

	return ClonePipe;
}