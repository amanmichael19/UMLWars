/**
 * \file Player.h
 *
 * \author Funakoshi Silva
 *
 *
 */


#include "pch.h"
#include "Player.h"
#include "Game.h"

using namespace Gdiplus;
using namespace std;

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;
/// pi constant
const double PI = 3.141592653;

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
		mPenHandler = make_shared<CPenHandler>(game, GetX(), GetY());
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
		mPenHandler->OnMouseMove(mAngle);
	}
}

void CPlayer::OnLeftClick(double mouseX, double mouseY)
{
	if (mPenHandler->OnHand())
	{
		mPenHandler->FirePen(mouseX, mouseY);
	}
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

