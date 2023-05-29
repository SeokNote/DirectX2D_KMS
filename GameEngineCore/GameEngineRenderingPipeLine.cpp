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

// 매쉬 + 머티리얼

// 선생님: 점에 대한 정보를 준비하고
//IA1에서는 버텍스 버퍼를 셋팅하고 버텍스 쉐이더 단계에 들어가기전에 필요한 정보를 셋팅해준다.ex)InputLayOut
void GameEngineRenderingPipeLine::InputAssembler1()
{
	//InputLayOut은 버텍스 쉐이더에서 첫번째 인자로 무엇이 들어오는지 쉐이더는 모르기
	// 때문에 첫번째 인자가 무엇이고 몇바이트 크기를 갖는지 알려주기위함
	// 꼭 셋팅해야함
	//
	// 랜더링을 위해서는 점으로 면을 만드는게 기본이다.
	// 그래픽카드는 점이 어떠한 구성을 가지고 있는지 알지 못한다.
	if (nullptr == InputLayOutPtr)
	{
		MsgAssert("인풋 레이아웃이 존재하지 않아서 인풋어셈블러1 과정을 실행할 수 없습니다.");
		return;
	}
	
	InputLayOutPtr->Setting();
	
	if (nullptr == VertexBufferPtr)
	{
		MsgAssert("버텍스 버퍼가 존재하지 않아서 인풋어셈블러1 과정을 실행할 수 없습니다.");
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
// 선생님: 로컬에 존재하는 점을 우리가 만든 행렬을 통해서 변환하고
// 입력한 쉐이더가(TextureShader) 파이프라인들 타고 버텍스 쉐이더 단계에 오게되면 쉐이더에서 Texture_VS를 통해  IA에서 셋팅해준 버텍스
// 버퍼를 갖고 컬러나 위치,월드행렬을 곱하여 정해진 SV_Posion과 Color를 리턴해준다.
void GameEngineRenderingPipeLine::VertexShader()
{
	if (nullptr == VertexShaderPtr)
	{
		MsgAssert("버텍스 쉐이더가 존재하지 않아서 버텍스 쉐이더 과정을 실행할 수 없습니다.");
		return;
	}

	VertexShaderPtr->Setting();
}

// 선생님: 점의 정보를 토대로 어떤 순서로 그릴지 정하고
// InputAssembler2단계에서는 각 정점들을 토대로 어떤 순서로 삼각형을 그려 출력할지 정해주는 단계이다.
// 우리의 엔진에서는 -z 즉 뒤에서 바라보기 때문에 반시계로 출력을 해야하는데 선생님이 설정에서 뒤집기를 true로 해줘서 시계방향 순서로 그린다(?)
// 카메라 변환,노말라이즈,투영행렬곱 해줌
void GameEngineRenderingPipeLine::InputAssembler2()
{	// 그리는 순서에 대한 데이터를 넣어준다.


	if (nullptr == IndexBufferPtr)
	{
		MsgAssert("인덱스 버퍼가 존재하지 않아서 인풋 어셈블러2 과정을 실행할 수 없습니다.");
		return;
	}

	// 012023
	IndexBufferPtr->Setting();

	// 012 023 <=3개씩 끊어서 면으로 만들어라는 여기서 처리가 되었다.
	GameEngineDevice::GetContext()->IASetPrimitiveTopology(TOPOLOGY);
}

// 여기서부터
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
// 여기까지는 화면과는 사실 관련 없음

// w나누기를 해줍니다. 해주는 이유 : 클리핑 영역이 바로 우리 화면에 출력되어야하는 영역인데 이 클리핑영역은 
// z = -1~0 , 0~1 ,x ,y 는 -1~1로 표현이 되는데 . 이전 단계에서 노말라이즈가 되어 각 정점들은 클리핑영역에 출력이 되는데
// 3차원 좌표를 2차원인 화면에 출력하려면 z로 나눠줘야하는데 이 z가 투영행렬연산에 의해 w 값에 저장되어 있기 때문에 w로 나눠주는것이다.
// 뷰포트도 곱해줍니다. : -1~1의 위치하면 안보이기에 현재 윈도우 크기만큼 곱해서 물체를 키우는것.
// 화면 컬링 
// 픽셀 건지기

void GameEngineRenderingPipeLine::Rasterizer()
{
	if (nullptr == RasterizerPtr)
	{
		MsgAssert("레스터라이저가 존재하지 않아서 세팅이 불가능합니다.");
		return;
	}

	RasterizerPtr->SetFILL_MODE(D3D11_FILL_MODE::D3D11_FILL_SOLID); // fill_mode란 2개의 옵션이 있는데 선으로 그릴거냐 면으로 그릴거냐를 선택함
	RasterizerPtr->Setting();

	// GameEngineDevice::GetContext()->RSSetState
}

//각 픽셀의 데이터를 생성하는 단계이다. 최종 색상과 어느 렌더타겟에 그릴지를 리턴해준다.
void GameEngineRenderingPipeLine::PixelShader()
{
	if (nullptr == PixelShaderPtr)
	{
		MsgAssert("픽셀 쉐이더가 존재하지 않아서 픽셀 쉐이더 과정을 실행할 수 없습니다.");
		return;
	}

	PixelShaderPtr->Setting();


	// GameEngineDevice::GetContext()->PSSetShader
}
void GameEngineRenderingPipeLine::OutputMerger()
{
	if (nullptr == BlendStatePtr)
	{
		MsgAssert("블랜드가 존재하지 않아 아웃풋 머저 과정을 완료할수가 없습니다.");
		return;
	}


	BlendStatePtr->Setting();

	if (nullptr == DepthStatePtr)
	{
		MsgAssert("블랜드가 존재하지 않아 아웃풋 머저 과정을 완료할수가 없습니다.");
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
		MsgAssert("존재하지 않는 버텍스 버퍼를 사용하려고 했습니다.");
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
		MsgAssert("존재하지 않는 버텍스 버퍼를 사용하려고 했습니다.");
	}
}


void GameEngineRenderingPipeLine::SetVertexShader(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	VertexShaderPtr = GameEngineVertexShader::Find(UpperName);

	if (nullptr == VertexShaderPtr)
	{
		MsgAssert("존재하지 않는 버텍스 쉐이더를 사용하려고 했습니다.");
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
		MsgAssert("존재하지 않는 픽셀 쉐이더를 사용하려고 했습니다.");
	}
}


void GameEngineRenderingPipeLine::SetBlendState(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	BlendStatePtr = GameEngineBlend::Find(UpperName);

	if (nullptr == BlendStatePtr)
	{
		MsgAssert("존재하지 않는 블랜드를 세팅하려고 했습니다.");
		return;
	}
}

void GameEngineRenderingPipeLine::SetDepthState(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	DepthStatePtr = GameEngineDepthState::Find(UpperName);

	if (nullptr == DepthStatePtr)
	{
		MsgAssert("존재하지 않는 블랜드를 세팅하려고 했습니다.");
		return;
	}
}

void GameEngineRenderingPipeLine::SetRasterizer(const std::string_view& _Value)
{
	std::string UpperName = GameEngineString::ToUpper(_Value);
	RasterizerPtr = GameEngineRasterizer::Find(UpperName);

	if (nullptr == RasterizerPtr)
	{
		MsgAssert("존재하지 않는 레스터라이저를 사용하려고 했습니다.");
	}
}
void GameEngineRenderingPipeLine::RenderingPipeLineSetting()
{
	// 랜더라고 하는 부분은 랜더링 파이프라인을 한바뀌 돌리는 것.
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


// 매쉬 + 머티리얼
void GameEngineRenderingPipeLine::Render()
{


	// GameEngineDevice::GetContext()->VSSetConstantBuffers()

	UINT IndexCount = IndexBufferPtr->GetIndexCount();
	GameEngineDevice::GetContext()->DrawIndexed(IndexCount, 0, 0);

	// 다 끝났다면

	// 메쉬 <= 외형이 어떻게 보일것인가.
	//         픽셀건져내기할 범위를 지정하는 Rasterizer
	//         w나누기를 하고 뷰포트를 곱해서

	// 머티리얼 <= 색깔이 어떻게 나올것인가?
	//             레스터라이저 + 픽셀쉐이더 + 버텍스 쉐이더
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