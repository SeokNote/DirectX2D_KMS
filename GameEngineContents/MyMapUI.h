#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class MyMapUI : public GameEngineActor
{
public:
	// constrcuter destructer
	MyMapUI();
	~MyMapUI();

	// delete Function
	MyMapUI(const MyMapUI& _Other) = delete;
	MyMapUI(MyMapUI&& _Other) noexcept = delete;
	MyMapUI& operator=(const MyMapUI& _Other) = delete;
	MyMapUI& operator=(MyMapUI&& _Other) noexcept = delete;
	void SetMapText(std::string _Name);
protected:
	void Start() override;
	void Update(float _Delta) override;
private:
	void FirstBezierPos(float _Delta);
	void SecoundBezierPos(float _Delta);
	std::shared_ptr<class UIFontRender> MapExplane;
	float Time = 0.0f;
	float Time1 = 0.0f;
	float Time2 = 0.0f;

	bool IsValue = false;
};

