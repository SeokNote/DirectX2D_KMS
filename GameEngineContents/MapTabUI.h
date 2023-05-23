#pragma once
#include <GameEngineCore/GameEngineActor.h>
#include <GameEngineCore/GameEngineUIRenderer.h>
#include <GameEngineCore/GameEngineCollision.h>
// 설명 :
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
	float4 MenuIconScale = { 96.0f,96.0f,0.0f };

	float4 Menu_BuiderPos = { 0.0f,-218.0f,0.0f };
	float4 Menu_CommanderPos = { -300.0f,-218.0f,0.0f };
	float4 Menu_DungeonPos = { 250.0f,-206.0f,0.0f };
	float4 Menu_ShopPos = { 350.0f,20.0f,0.0f };
	float4 Menu_TemplePos = { -350.0f,18.0f,0.0f };


	std::shared_ptr<GameEngineUIRenderer> MapTabBase;
	std::shared_ptr<GameEngineUIRenderer> MapTabBaseBG;

	std::shared_ptr<GameEngineUIRenderer> Menu_Builder;
	std::shared_ptr<GameEngineUIRenderer> Menu_BuilderSelect;
	std::shared_ptr<GameEngineUIRenderer> Menu_Commander;
	std::shared_ptr<GameEngineUIRenderer> Menu_CommanderSelect;
	std::shared_ptr<GameEngineUIRenderer> Menu_Dungeon;
	std::shared_ptr<GameEngineUIRenderer> Menu_DungeonSelect;
	std::shared_ptr<GameEngineUIRenderer> Menu_Shop;
	std::shared_ptr<GameEngineUIRenderer> Menu_ShopSelect;
	std::shared_ptr<GameEngineUIRenderer> Menu_TemPle;
	std::shared_ptr<GameEngineUIRenderer> Menu_TemPleSelect;


	std::shared_ptr<GameEngineCollision> Menu_BuilderCol;
	std::shared_ptr<GameEngineCollision> Menu_CommanderCol;
	std::shared_ptr<GameEngineCollision> Menu_DungeonCol;
	std::shared_ptr<GameEngineCollision> Menu_ShopCol;
	std::shared_ptr<GameEngineCollision> Menu_TemPleCol;
};

//텝과 인벤토리 기초적인 틀만 만들기