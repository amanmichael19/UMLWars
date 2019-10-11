
/**
 * \file Player.h
 *
 * \author Funakoshi Silva
 *
 *
 */


#include "pch.h"
#include "RedPen.h"


using namespace Gdiplus;
using namespace std;


/// halrold filename 
//const wstring HaroldImageName = L"images/harold.png";

CRedPen::CRedPen(CGame* game) : CGameObject(game)
{
	mPenImage = unique_ptr<Gdiplus::Bitmap>(
		Bitmap::FromFile(L"images/redpen.png"));
	if (mPenImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/redpen.png");
	}
}

void CRedPen::OnDraw(Gdiplus::Graphics* graphics)
{
	graphics->DrawImage(mPenImage.get(), 0, 0,
		mPenImage->GetWidth(), mPenImage->GetHeight());



}

