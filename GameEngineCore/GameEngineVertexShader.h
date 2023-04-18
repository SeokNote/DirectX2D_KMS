#pragma once
#include "GameEngineResource.h"
#include "GameEngineShader.h"

// 설명 :GameEngineVertexShader는 모든 쉐이더가 필요한 공통의 요소를 갖는 GameEngineShader를 상속받고
// 쉐이더리소스중 하나이기 때문에 GameEngineResource<GameEngineVertexShader>를 상속받는다.

class GameEngineVertexShader : public GameEngineResource<GameEngineVertexShader>, public GameEngineShader
{
	friend class GameEngineInputLayOut; //InputLayOut을 버텍스 단계에서 셋팅해줘야해서 friend처리함

public:
	// constrcuter destructer
	GameEngineVertexShader();
	~GameEngineVertexShader();

	// delete Function
	GameEngineVertexShader(const GameEngineVertexShader& _Other) = delete;
	GameEngineVertexShader(GameEngineVertexShader&& _Other) noexcept = delete;
	GameEngineVertexShader& operator=(const GameEngineVertexShader& _Other) = delete;
	GameEngineVertexShader& operator=(GameEngineVertexShader&& _Other) noexcept = delete;

	static std::shared_ptr<GameEngineVertexShader> Load(const std::string_view& _Path, const std::string_view& _EntryPoint, UINT _VersionHigh = 5, UINT _VersionLow = 0)
	{
		GameEnginePath Path = GameEnginePath(std::string(_Path.data()));

		return Load(_Path, Path.GetFileName(), _EntryPoint, _VersionHigh, _VersionLow);
	}

	static std::shared_ptr<GameEngineVertexShader> Load(const std::string_view& _Path, const std::string_view& _Name, const std::string_view& _EntryPoint, UINT _VersionHigh = 5, UINT _VersionLow = 0)
	{
		std::shared_ptr<GameEngineVertexShader> Res = GameEngineVertexShader::Create(_Name);
		Res->ShaderLoad(_Path, _EntryPoint, _VersionHigh, _VersionLow);
		return Res;
	}

	void Setting() override;

protected:

private:
	ID3D11VertexShader* ShaderPtr = nullptr;

	void ShaderLoad(const std::string_view& _Path, const std::string_view& _EntryPoint, UINT _VersionHigh = 5, UINT _VersionLow = 0);

};

