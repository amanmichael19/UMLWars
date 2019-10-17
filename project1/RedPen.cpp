
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

CRedPen::CRedPen(CGame* game, double xlocation, double ylocation) : CGameObject(game),
mXOrigin(xlocation), mYOrigin(ylocation)
{
	mPenImage = shared_ptr<Bitmap>(Bitmap::FromFile(L"images/images/redpen.png"));
	if (mPenImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/redpen.png");
	}
	mLoadX = mXOrigin + mXOffset;
	mLoadY = mYOrigin - mYOffset;
	SetLocation(mLoadX, mLoadY);
}

void CRedPen::SetLocation(double x, double y) {

	CGameObject::SetLocation(x, y);

	auto mGame = CGameObject::GetGame();

	mGame->HitUml(this);

}

void CRedPen::Draw(Gdiplus::Graphics* graphics)
{
	float wid = (float)mPenImage->GetWidth();
	float hit = (float)mPenImage->GetHeight();
	float x = float(GetX() - wid / 2);
	float y = float(GetY() - hit / 2);

	auto state = graphics->Save();
	graphics->TranslateTransform((float)GetX(), (float)GetY());
	if (mOnHand)
	{
		graphics->RotateTransform((float)(-mAngleOfRotation * RtoD));
		
	}
	else
	{
		graphics->RotateTransform((float)(-mAngleOnAir * RtoD));		
	}
	graphics->DrawImage(mPenImage.get(), -wid / 2, -hit / 2, wid, hit);
	graphics->Restore(state);
}

void CRedPen::FirePen(double xDirection, double yDirection)
{
	if (mOnHand)
	{
		double sqrtVecorSum = sqrt(pow(xDirection - mLoadX, 2) + pow(yDirection - mLoadY, 2));
		mXDirection = (xDirection - mLoadX)/sqrtVecorSum;
		mYDirection = (yDirection - mLoadY)/sqrtVecorSum;
		mOnHand = false;
		mAngleOnAir = mAngleOfRotation;
	}
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
		double x = elapsed * mSpeed * mXDirection + GetX();
		double y = elapsed * mSpeed * mYDirection + GetY();
		// temporary - create constants file
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
	// create a temporary variable so as to not to change mAngleOfMovement on the second if
	double angle = mAngleOfMovement;
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

void CRedPen::OnMouseMove(double angle)
{
	SetAngle(angle);
	if (mOnHand)
	{
		TrackHand();
	}
}
