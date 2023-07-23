#pragma once
#include <GameEngineCore/GameEngineActor.h>
enum class PotalState
{
	IDLE,
	IDLE2,
	OPEN,
	CLOSE,
};
// Ό³Έν :
class Potal :public GameEngineActor
{
public:
	// constrcuter destructer
	Potal();
	~Potal();

	// delete Function
	Potal(const Potal& _Other) = delete;
	Potal(Potal&& _Other) noexcept = delete;
	Potal& operator=(const Potal& _Other) = delete;
	Potal& operator=(Potal&& _Other) noexcept = delete;
	std::shared_ptr<class GameEngineSpriteRenderer>  GetPotalRender()
	{
		return SteleRender;
	}
	void SetPTCValue(float4 _Dir , float4 _Pos,float _PivotX,float _PivotY)
	{
		Dir = _Dir;
		Pos = _Pos;
		PivotX = _PivotX;
		PivotY = _PivotY;

	}
protected:
	void Start();
	void Update(float _Delta) override;
private:
	void PTCSetting(float _Delta);
	void ChangeState(PotalState _State);
	void UpdateState(float _Time);
	PotalState StateValue = PotalState::IDLE;
	void IdleStart();
	void IdleUpdate(float _Time);
	void IdleEnd();

	void Idle2Start();
	void Idle2Update(float _Time);
	void Idle2End();

	void OpenStart();
	void OpenUpdate(float _Time);
	void OpenEnd();

	void CloseStart();
	void CloseUpdate(float _Time);
	void CloseEnd();
	float4 Scale = { 264.0f,80.0f,0.0f };
	float4 Dir = float4::Zero;
	float4 Pos = float4::Zero;
	float PivotX = 0.0f;
	float PivotY = 0.0f;

	std::shared_ptr<class GameEngineSpriteRenderer> SteleRender = nullptr;
	float CreateTime0 = 0.0f;
	float CreateTime1 = 0.0f;
	float CreateTime2 = 0.0f;
	float Deg = 0.0f;

};

