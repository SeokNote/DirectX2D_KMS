#include "PrecompileHeader.h"
#include "ContentsCore.h"
#include <GameEngineBase/GameEngineDirectory.h>
#include <GameEngineCore/GameEngineVertexShader.h>
#include <GameEngineCore/GameEnginePixelShader.h>
#include <GameEngineCore/GameEngineRenderingPipeLine.h>
#include <GameEnginePlatform/GameEngineSound.h>
void ContentsCore::ContentsResourcesCreate()
{
	// 텍스처 로드만 각 레벨별로 하고 정리하는 습관을 들이세요.
	//사운드 로드
	GameEngineDirectory SoundDir;
	SoundDir.MoveParentToDirectory("ContentResources");
	SoundDir.Move("ContentResources");
	SoundDir.Move("Sound");
	std::vector<GameEngineFile> SoundFile = SoundDir.GetAllFile({ ".wav", });
	for (size_t i = 0; i < SoundFile.size(); i++)
	{
		GameEngineSound::Load(SoundFile[i].GetFullPath());
	}
	{
		GameEngineDirectory NewDir;
		NewDir.MoveParentToDirectory("ContentsShader");
		NewDir.Move("ContentsShader");

		std::vector<GameEngineFile> Files = NewDir.GetAllFile({ ".hlsl", ".fx" });

		for (size_t i = 0; i < Files.size(); i++)
		{
			GameEngineShader::AutoCompile(Files[i]);
		}

		//GameEngineVertexShader::Load(Files[0].GetFullPath(), "MyShader_VS");
		//GameEnginePixelShader::Load(Files[0].GetFullPath(), "MyShader_PS");
	}
	{
		std::shared_ptr<GameEngineRenderingPipeLine> Pipe = GameEngineRenderingPipeLine::Create("My2DTexture");

		//Pipe->SetVertexBuffer("Rect");
		//Pipe->SetIndexBuffer("Rect");
		Pipe->SetVertexShader("MyShader.fx");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("MyShader.fx");
		Pipe->SetBlendState("AlphaBlend");
		Pipe->SetDepthState("EngineDepth");
	}


	{
		std::shared_ptr<GameEngineRenderingPipeLine> Pipe = GameEngineRenderingPipeLine::Create("Fade");

		//Pipe->SetVertexBuffer("FullRect");
		//Pipe->SetIndexBuffer("FullRect");
		Pipe->SetVertexShader("FadeShader.hlsl");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("FadeShader.hlsl");
		Pipe->SetBlendState("AlphaBlend");
		Pipe->SetDepthState("EngineDepth");
	}

	{
		std::shared_ptr<GameEngineRenderingPipeLine> Pipe = GameEngineRenderingPipeLine::Create("DebugRect");
		//Pipe->SetVertexBuffer("Rect");
		//Pipe->SetIndexBuffer("Rect");
		Pipe->SetVertexShader("DebugMeshRender.hlsl");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("DebugMeshRender.hlsl");
		Pipe->SetBlendState("AlphaBlend");
		Pipe->SetDepthState("EngineDepth");
	}
	{
		std::shared_ptr<GameEngineRenderingPipeLine> Pipe = GameEngineRenderingPipeLine::Create("PointLight");

		Pipe->SetVertexShader("PointLightShader.hlsl");
		Pipe->SetRasterizer("Engine2DBase");
		Pipe->SetPixelShader("PointLightShader.hlsl");
		Pipe->SetBlendState("MergeBlend");
		Pipe->SetDepthState("EngineDepth");
	}
	//{
	//	std::shared_ptr<GameEngineRenderingPipeLine> Pipe = GameEngineRenderingPipeLine::Create("DebugSphere");
	//	Pipe->SetVertexBuffer("Sphere");
	//	Pipe->SetIndexBuffer("Sphere");
	//	Pipe->SetVertexShader("CollisionDebugShader.hlsl");
	//	Pipe->SetRasterizer("Engine2DBase");
	//	Pipe->SetPixelShader("CollisionDebugShader.hlsl");
	//	Pipe->SetBlendState("AlphaBlend");
	//	Pipe->SetDepthState("EngineDepth");
	//}



}