/**
 * \file Player.h
 *
 * \author Funakoshi Silva
 *
 *
 */


#include "pch.h"
#include "Player.h"
#include "RedPen.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

CPlayer::CPlayer(CGame* game) : CGameObject(game)
{
	mPlayerImage = unique_ptr<Gdiplus::Bitmap>(
		//Bitmap::FromFile(L"M:/project1/images/images/harold.png"));
		Bitmap::FromFile(L"images/images/harold.png"));
	if (mPlayerImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/harold.png");
	}
	else
	{
		SetLocation(0, double(double(CGame::GetHeight()) - mPlayerImage->GetHeight()/2.0f));
		
		mGame = game;
		mTimer = make_shared<CTimer>(mGame);
		mGame->Add(mTimer);

		GetAPen();

	}
}

void CPlayer::OnMouseMove(double mouseX, double mouseY)
{
	if (mouseY < GetY()) 
	{
		/// Did mouseX - GetX() instead of the other way around is to
		/// make the player rotate to the direction of mouse movement
		mAngle = atan2(GetY() - mouseY, mouseX - GetX()) - PI / 2;

		if (mAngle > PI / 2)
			mAngle = PI / 2;
		else if (mAngle < -PI / 2)
			mAngle = -PI / 2;
		mPenOnHand->OnMouseMove(mAngle);
	}
}

void CPlayer::OnLeftClick(double mouseX, double mouseY)
{
	mPenOnHand->FirePen(mouseX, mouseY);
	mTimer->SetUp(1);
	mTimer->Start();
	mIsPenOnHand = false;
}

void CPlayer::Draw(Gdiplus::Graphics* graphics)
{
	float wid = (float)mPlayerImage->GetWidth();
	float hit = (float)mPlayerImage->GetHeight();

	auto state = graphics->Save();
	graphics->TranslateTransform((float)GetX(), (float)GetY());
	graphics->RotateTransform((float)(-mAngle * RtoD));
	graphics->DrawImage(mPlayerImage.get(), -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);
}

void CPlayer::GetAPen() {
	auto pen = make_shared<CRedPen>(mGame, GetX(), GetY());
	mGame->Add(pen);
	mPenOnHand = pen;
	
	mIsPenOnHand = true;

	mPenOnHand->OnMouseMove(mAngle);
}

bool CPlayer::IfGetPen() {return !mIsPenOnHand && mTimer->IsTimeUp();}

