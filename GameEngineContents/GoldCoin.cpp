#include "PrecompileHeader.h"
#include "GoldCoin.h"
#include "Player.h"
#include "TextUI.h"
#include <GameEngineCore/GameEngineSpriteRenderer.h>
#include <GameEnginePlatform/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineCamera.h>
GoldCoin::GoldCoin()
{
}

GoldCoin::~GoldCoin()
{
}

void GoldCoin::CoinSetting(float4 _Pos, bool _MoveValue)
{
	Value = _MoveValue;
	Pos = _Pos;
}
void GoldCoin::CoinCreat(GameEngineLevel* _Level, float4 _Pos, bool _MoveValue)
{
	std::shared_ptr<GoldCoin> TextPtr = _Level->CreateActor<GoldCoin>();
	TextPtr->CoinSetting(_Pos,_MoveValue);

}

void GoldCoin::Start()
{
	GoldCoinRender = CreateComponent<GameEngineSpriteRenderer>(1);
	GoldCoinRender->CreateAnimation({ .AnimationName = "CoinIdle", .SpriteName = "CoinIdle", .Loop = true, .ScaleToTexture = true });
	GoldCoinRender->ChangeAnimation("CoinIdle");

	BodyCol = CreateComponent<GameEngineCollision>(ColOrder::COIN);
	BodyCol->GetTransform()->SetLocalScale(ColScale);
	BodyCol->SetColType(ColType::AABBBOX2D);
}

void GoldCoin::Update(float _Delta)
{
	CurMap = Player::MainPlayer->SetMyMap(CurMap);
	MoveCoin(_Delta);
	if (GroundCheck==false && IsCheck == true)
	{
		if (false == Player::MainPlayer->GroundCheck(GoldCoinRender->GetTransform()->GetWorldPosition()))
		{
			GoldCoinRender->GetTransform()->AddWorldPosition({ 0.0f,-_Delta * 200.0f,0.0f });
			if (true == MiddleCheck(GoldCoinRender->GetTransform()->GetWorldPosition()))
			{
				GroundCheck = true;
			}
		}
	}
	SetCollision();
}

void GoldCoin::SetCollision()
{
	BodyCol->GetTransform()->SetWorldPosition(GoldCoinRender->GetTransform()->GetWorldPosition());
	float4 CurPos = BodyCol->GetTransform()->GetWorldPosition();

	if (BodyCol->Collision(ColOrder::PlayerBody, ColType::AABBBOX2D, ColType::AABBBOX2D))
	{
		TextUI::TextCreat(GetLevel(), { CurPos.x,CurPos.y+50.0f,-802.f }, {1.f, 0.5840f, 0.235f}, "100G", false,32);
		Player::MainPlayer->GetData().PlusCoin(100);
		Death();
	}
}

void GoldCoin::MoveCoin(float _Delta)
{
	if (IsCheck ==false && Value == true)
	{
		Ratio += _Delta;
		float4 EndPos = { Pos.x,Pos.y - 10.0f,Pos.z };
		float4 M0 = float4::LerpClamp(Pos, { Pos.x ,Pos.y + 100.0f,Pos.z }, Ratio);
		float4 M1 = float4::LerpClamp({ Pos.x ,Pos.y + 100.0f,Pos.z }, EndPos, Ratio);
		float4 Pos2 = float4::LerpClamp(M0, M1, Ratio);
		GoldCoinRender->GetTransform()->SetWorldPosition(Pos2);
		if (GoldCoinRender->GetTransform()->GetWorldPosition() == EndPos)
		{
			IsCheck = true;
		}
		

	}
}

bool GoldCoin::MiddleCheck(float4 _Pos)
{
	float4 BottomPos = _Pos;
	switch (CurMap)
	{
	case MyMap::None:
		return false;
		break;
	case MyMap::Town:
		PixelMapResultPos = Player::MainPlayer->PixelCalculation(BottomPos, { 0.0f,0.0f,0.0f }, { 2560.f,720.0f });
		Ptr = GameEngineTexture::Find("TownCol_1.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y + 80.0f));
		if (Pixel == MiddleGround)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage1_1:
		PixelMapResultPos = Player::MainPlayer->PixelCalculation(BottomPos, { 3300.0f,0.0f,0.0f }, { 640.0f,360 });
		Ptr = GameEngineTexture::Find("StageCol_1.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y));
		if (Pixel == MiddleGround)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage1_2:
		PixelMapResultPos = Player::MainPlayer->PixelCalculation(BottomPos, { 5320.0f,0.0f,0.0f }, { 1280.0f,720.0f });
		Ptr = GameEngineTexture::Find("StageCol_2.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y + 60.0f));
		if (Pixel == MiddleGround)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage1_3:
		PixelMapResultPos = Player::MainPlayer->PixelCalculation(BottomPos, { 7980.0f,0.0f,0.0f }, { 1280.f,640.0f });
		Ptr = GameEngineTexture::Find("StageCol_3.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y + 80.0f));
		if (Pixel == MiddleGround)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage1_4:
		PixelMapResultPos = Player::MainPlayer->PixelCalculation(BottomPos, { 10320.0f,0.0f,0.0f }, { 960.f,360.0f });
		Ptr = GameEngineTexture::Find("StageCol_4.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y + 80.0f));
		if (Pixel == MiddleGround)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage1_Boss:
		PixelMapResultPos = Player::MainPlayer->PixelCalculation(BottomPos, { 12084.0f,0.0f,0.0f }, { 704.0f,672.0f });
		Ptr = GameEngineTexture::Find("BossRoomCol_1.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y + 80.0f));
		if (Pixel == MiddleGround)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	case MyMap::Stage2_1:
		return false;
		break;
	case MyMap::Stage2_Boss:
		return false;
		break;
	case MyMap::Stage3_1:
		return false;
		break;
	case MyMap::Stage3_Boss:
		PixelMapResultPos = Player::MainPlayer->PixelCalculation(BottomPos, { 18948.0f,0.0f,0.0f }, { 1280.0f,360.0f });
		Ptr = GameEngineTexture::Find("Stage3Col_Boss11.png");
		Pixel = Ptr->GetPixel(static_cast<int>(PixelMapResultPos.x), static_cast<int>(PixelMapResultPos.y + 80.0f));
		if (Pixel == MiddleGround)
		{
			return true;
		}
		else
		{
			return false;
		}
		break;
	default:
		return false;
		break;
	}
}