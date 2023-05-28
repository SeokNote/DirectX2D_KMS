#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class TempleNpc : public GameEngineActor
{
public:
	// constrcuter destructer
	TempleNpc();
	~TempleNpc();

	// delete Function
	TempleNpc(const TempleNpc& _Other) = delete;
	TempleNpc(TempleNpc&& _Other) noexcept = delete;
	TempleNpc& operator=(const TempleNpc& _Other) = delete;
	TempleNpc& operator=(TempleNpc&& _Other) noexcept = delete;

	int SetIndexCount(int _Value) {
		IndexCount = _Value;
		return IndexCount;
	}
protected:

	void Start() override;
	void Update(float _DeltaTime) override;
private:
	float4 TempleNpcScale = { 60.0f,92.0f,0.0f };
	float4 FScale = { 52.0f,56.0f,0.0f };

	std::shared_ptr<class GameEngineSpriteRenderer> TempleNpcRender;
	std::shared_ptr<class GameEngineSpriteRenderer> FRender;

	std::shared_ptr<class FoodUI> FoodUIPtr;




	//Position
	float4 TempleNpcPos1 = { -1815.0f,45.0f,-750.f };
	float4 FRenderPos = { -1815.0f,135.0f,-750.f };

	std::shared_ptr<class GameEngineCollision> TempleNpcCol;

	int IndexCount = 0;
};

