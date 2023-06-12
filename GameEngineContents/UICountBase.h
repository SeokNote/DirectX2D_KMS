#pragma once
#include <GameEngineCore/GameEngineActor.h>
// Ό³Έν :
class UICountBase :public GameEngineActor
{
public:
	// constrcuter destructer
	UICountBase();
	~UICountBase();

	// delete Function
	UICountBase(const UICountBase& _Other) = delete;
	UICountBase(UICountBase&& _Other) noexcept = delete;
	UICountBase& operator=(const UICountBase& _Other) = delete;
	UICountBase& operator=(UICountBase&& _Other) noexcept = delete;
	static UICountBase* MainUICountBase;
	void SetUICount(int _Count)
	{
		UICount = _Count;

	}
	int GetUICount()
	{
		return UICount;
	}
protected:
	void Start() override;
	void Update(float _DeltaTime) override;

private:
	
	int UICount = 0;

};

