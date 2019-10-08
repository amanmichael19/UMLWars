#include "pch.h"
#include "Pen.h"
#include "GameObject.h"


using namespace Gdiplus;
using namespace std;


/// halrold filename 
//const wstring HaroldImageName = L"images/harold.png";

CPen::CPen(CGame* game) : CGameObject(game)
{
	mPenImage = unique_ptr<Gdiplus::Bitmap>(
		Bitmap::FromFile(L"images/redpen.png"));
	if (mPenImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/harold.png");
	}
}


void CPen::OnDraw(Gdiplus::Graphics* graphics)
{
	graphics->DrawImage(mPenImage.get(), 0, 0,
		mPenImage->GetWidth(), mPenImage->GetHeight());



}


