#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>

// ���� :
class MapTabUI : public GameEngineActor
{
public:
	// constrcuter destructer
	MapTabUI();
	~MapTabUI();

	// delete Function
	MapTabUI(const MapTabUI& _Other) = delete;
	MapTabUI(MapTabUI&& _Other) noexcept = delete;
	MapTabUI& operator=(const MapTabUI& _Other) = delete;
	MapTabUI& operator=(MapTabUI&& _Other) noexcept = delete;

protected:
	void Start();
	void Update(float _Delta) override;

private:

	float4 MapTabUIScale = { 1280.0f,720.0f,0.0f };

	std::shared_ptr<GameEngineUIRenderer> MapTabBase;
	std::shared_ptr<GameEngineUIRenderer> MapTabBaseBG;
};

//�ܰ� �κ��丮 �������� Ʋ�� �����