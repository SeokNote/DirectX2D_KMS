#include "PrecompileHeader.h"
#include "GameEngineShader.h"
#include "GameEngineConstantBuffer.h"

GameEngineShader::GameEngineShader()
{
}

GameEngineShader::~GameEngineShader()
{
	if (nullptr != BinaryCode)
	{
		BinaryCode->Release();
		BinaryCode = nullptr;
	}
}
//그냥 버전이 필요해서 있는 함수 쉐이더가 어떤버전으로 그릴건지 알아야함
void GameEngineShader::CreateVersion(const std::string_view& _ShaderType, UINT _VersionHigt /*= 5*/, UINT _VersionLow /*= 0*/)
{
	// vs_5_0
	Version += _ShaderType;
	Version += "_";
	Version += std::to_string(_VersionHigt);
	Version += "_";
	Version += std::to_string(_VersionLow);
}

//쉐이더 리소스 정보를 체크해주는 함수.
void GameEngineShader::ShaderResCheck()
{
	if (nullptr == BinaryCode)
	{
		MsgAssert("쉐이더가 컴파일 되지 않아서 쉐이더의 리소스를 조사할 수 없습니다.");
		return;
	}

	// Reflection : 실시간으로 정보를 알게끔 하는 다이렉트 함수
	// RTTI의 비슷한 개념으로 
	ID3D11ShaderReflection* CompileInfo = nullptr;
	//포인터 캐스팅,포인터끼리의 타입변환을 허용
	if (S_OK != D3DReflect(BinaryCode->GetBufferPointer(), BinaryCode->GetBufferSize(), IID_ID3D11ShaderReflection, reinterpret_cast<void**>(&CompileInfo)))
	{
		MsgAssert("쉐이더 리플렉션에 실패했습니다.");
		return;
	}
	//쉐이더의 정보,리소르를 담는 변수 Info
	D3D11_SHADER_DESC Info;

	//GetDesc: 셰이더의 설명,정보을 받아오는 함수
	CompileInfo->GetDesc(&Info);

	//쉐이더 리소스,정보들을 쉐이더에 바인딩기위한 구조체의 변수 ResDesc= 리소스를 뜻한다.
	D3D11_SHADER_INPUT_BIND_DESC ResDesc;

	// 내가 사용한 상수버퍼 텍스처 샘플러등의 총합입니다.
	//BoundResources : 쉐이더에 바인딩된 리소스의 수
	for (UINT i = 0; i < Info.BoundResources; i++)
	{
		// GetResourceBindingDesc를 통해 리소스 정보를 얻어오게 되고
		CompileInfo->GetResourceBindingDesc(i, &ResDesc);
		//ResDesc쉐이더리소스의 이름은?  
		std::string Name = ResDesc.Name;
		//이 쉐이더 리소스의 타입은? : 여기선 상수버퍼
		D3D_SHADER_INPUT_TYPE Type = ResDesc.Type;
		std::string UpperName = GameEngineString::ToUpper(ResDesc.Name);

		switch (Type)
		{
		case D3D_SIT_CBUFFER: //상수버퍼라면?
		{
			std::string UpperName = GameEngineString::ToUpper(ResDesc.Name);
			//ID3D11ShaderReflectionConstantBuffer : 리플렉션은 정보를 갖고오는걸 말하는거같음 상수버퍼에 대한 접근을 위한 변수
			ID3D11ShaderReflectionConstantBuffer* CBufferPtr = CompileInfo->GetConstantBufferByName(ResDesc.Name);


			//여기서부터는 일단 강의 복습하며 듣기
			D3D11_SHADER_BUFFER_DESC BufferDesc;
			CBufferPtr->GetDesc(&BufferDesc);

			std::shared_ptr<GameEngineConstantBuffer> Res = GameEngineConstantBuffer::CreateAndFind(BufferDesc.Size, UpperName, BufferDesc);



			GameEngineConstantBufferSetter Setter;

			Setter.ParentShader = this;
			Setter.Name = UpperName;
			Setter.BindPoint = ResDesc.BindPoint;
			Setter.Res = Res;

			ResHelper.CreateConstantBufferSetter(Setter);


			int a = 0;

			break;
		}
		case D3D_SIT_TEXTURE:
		{
			std::shared_ptr<GameEngineTexture> Res = GameEngineTexture::Find("EngineBaseTex.png");

			GameEngineTextureSetter Setter;
			Setter.ParentShader = this;
			Setter.Name = UpperName;
			Setter.BindPoint = ResDesc.BindPoint;
			Setter.Res = Res;

			ResHelper.CreateTextureSetter(Setter);
			break;
		}
		case D3D_SIT_SAMPLER:
		{
			std::shared_ptr<GameEngineSampler> Res = GameEngineSampler::Find(UpperName);

			GameEngineSamplerSetter Setter;
			Setter.ParentShader = this;
			Setter.Name = UpperName;
			Setter.BindPoint = ResDesc.BindPoint;
			Setter.Res = Res;

			ResHelper.CreateSamplerSetter(Setter);
			break;
		}
		default:
			break;
		}

	}

	// CompileInfo
}