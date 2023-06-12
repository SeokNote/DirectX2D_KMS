#include "PrecompileHeader.h"
#include "UICountBase.h"
UICountBase* UICountBase::MainUICountBase;

UICountBase::UICountBase()
{
	MainUICountBase = this;
}

UICountBase::~UICountBase()
{
}

void UICountBase::Start()
{
}

void UICountBase::Update(float _DeltaTime)
{
}
