
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

/// Constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

CRedPen::CRedPen(CGame* game, shared_ptr<Gdiplus::Bitmap> penImage) : CGameObject(game), mPenImage(penImage)
{
}

void CRedPen::Draw(Gdiplus::Graphics* graphics)
{
	float wid = (float)mPenImage->GetWidth();
	float hit = (float)mPenImage->GetHeight();
	float x = float(GetX() - wid / 2);
	float y = float(GetY() - hit / 2);

	auto state = graphics->Save();
	//mRotate = false;
	if (mRotate)
	{
		graphics->TranslateTransform((float)x, (float)y);
		graphics->RotateTransform((float)(-mAngle * RtoD));
		graphics->DrawImage(mPenImage.get(), -wid / 2, -hit / 2, wid, hit);
		graphics->Restore(state);
	}
	else
	{
		graphics->DrawImage(mPenImage.get(), x, y, wid, hit);
	}
}
