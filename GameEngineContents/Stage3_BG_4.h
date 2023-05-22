#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Stage3_BG_4 : public GameEngineActor
{
public:
	// constrcuter destructer
	Stage3_BG_4();
	~Stage3_BG_4();

	// delete Function
	Stage3_BG_4(const Stage3_BG_4& _Other) = delete;
	Stage3_BG_4(Stage3_BG_4&& _Other) noexcept = delete;
	Stage3_BG_4& operator=(const Stage3_BG_4& _Other) = delete;
	Stage3_BG_4& operator=(Stage3_BG_4&& _Other) noexcept = delete;

protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 Stage3_BG_4Scale = { 5120.0f,512.0f,0.0f };
	std::shared_ptr<class GameEngineSpriteRenderer> Stage3_BG_4Render;
	float4 Center = { Stage3_BG_4Scale.x / 2.0f , Stage3_BG_4Scale.y / 2.0f, 0.0f };

};

