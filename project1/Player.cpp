/**
 * \file Player.h
 *
 * \author Funakoshi Silva
 *
 *
 */


#include "pch.h"
#include "Player.h"

using namespace Gdiplus;
using namespace std;


/// halrold filename 
//const wstring HaroldImageName = L"images/harold.png";

CPlayer::CPlayer(CGame* game) : CGameObject(game)
{
	mPlayerImage = unique_ptr<Gdiplus::Bitmap>(
		Bitmap::FromFile(L"images/harold.png"));
	if (mPlayerImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/harold.png");
	}
}


void CPlayer::OnDraw(Gdiplus::Graphics* graphics)
{
	graphics->DrawImage(mPlayerImage.get(), 0, 0,
		mPlayerImage->GetWidth(), mPlayerImage->GetHeight());

	

}

