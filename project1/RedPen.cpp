
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
/// angle of hand from center of player
const double INITIAL_ANGLE = -1.078;
/// radius of hand from center of player
const double RADIUS = 61.3;

CRedPen::CRedPen(CGame* game, shared_ptr<Gdiplus::Bitmap> penImage, double xlocation, double ylocation) : CGameObject(game), mPenImage(penImage),
mXOrigin(xlocation), mYOrigin(ylocation)
{
	mLoadX = mXOrigin + mXOffset;
	mLoadY = mYOrigin - mYOffset;
	SetLocation(mLoadX, mLoadY);
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

void CRedPen::Fire(double xDirection, double yDirection)
{
	mXDirection = xDirection - mLoadX; 
	mYDirection = yDirection - mLoadY; 
	mOnHand = false;
}

void CRedPen::ReLoad()
{
	mOnHand = true;
	TrackHand();
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
			ReLoad();
		}
		else
		{
			SetLocation(x, y);
		}
		
	}
}

void CRedPen::TrackHand()
{
	double angle = mAngle + PI/2;
	if (mOnHand)
	{
		/// rotating away from the x=0 line
		if (angle > -PI / 2)
		{
			angle = -angle;
		}
		double x = mXOrigin + RADIUS * cos(INITIAL_ANGLE + angle);
		double y = mYOrigin + RADIUS * sin(INITIAL_ANGLE + angle);
		SetLocation(x, y);
	}
}
