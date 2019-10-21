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
<<<<<<< HEAD
		MakeAPen();
=======
		
		mGame = game;
		mTimer = make_shared<CTimer>(mGame);
		mGame->Add(mTimer);

		GetAPen();

>>>>>>> 8f87c7502a50a239d96fd3bd0dea7f049a83d859
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
<<<<<<< HEAD
	mPenTimer->SetIsUpdate(true);
=======
	mTimer->SetUp(1);
	mTimer->Start();
>>>>>>> 8f87c7502a50a239d96fd3bd0dea7f049a83d859
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

<<<<<<< HEAD
void CPlayer::MakeAPen() 
{
	auto game = GetGame();
	mPenOnHand = make_shared<CRedPen>(game, GetX(), GetY());
	game->Add(mPenOnHand);
	mPenOnHand->OnMouseMove(mAngle);
=======
void CPlayer::GetAPen() {
	auto pen = make_shared<CRedPen>(mGame, GetX(), GetY());
	mGame->Add(pen);
	mPenOnHand = pen;
	
>>>>>>> 8f87c7502a50a239d96fd3bd0dea7f049a83d859
	mIsPenOnHand = true;

	mPenTimer = make_shared<CTimer>(game);
	game->Add(mPenTimer);
	mPenTimer->SetIsUpdate(false);
	mPenTimer->SetTotalTime(1);	
}

<<<<<<< HEAD
void CPlayer::DestroyPen()
{
	mPenOnHand->MarkForDelete(true);
}
=======
bool CPlayer::IfGetPen() {return !mIsPenOnHand && mTimer->IsTimeUp();}
>>>>>>> 8f87c7502a50a239d96fd3bd0dea7f049a83d859


