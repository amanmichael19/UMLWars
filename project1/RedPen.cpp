
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
	if (mOnHand)
	{
		graphics->TranslateTransform((float)GetX(), (float)GetY());
		graphics->RotateTransform((float)(-mAngle * RtoD));
		graphics->DrawImage(mPenImage.get(), -wid / 2, -hit / 2, wid, hit);
		graphics->Restore(state);
	}
	else
	{
		graphics->DrawImage(mPenImage.get(), x, y, wid, hit);
	}
}

void CRedPen::Update(double elapsed)
{
	if (!mOnHand)
	{
		//temporary
		double x = elapsed * mSpeed * mXDirection + GetX();
		double y = elapsed * mSpeed * mYDirection + GetY();
		if (x < -1250 / 2 || x > 1250 / 2 || y > 1000 || y < 0)
		{
			mOnHand = true;
			SetLocation(0, 925);
		}
		else
		{
			SetLocation(x, y);
		}
		
	}
}
