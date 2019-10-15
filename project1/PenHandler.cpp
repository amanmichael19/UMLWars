/**
 * \file PenHandler.cpp
 *
 * \author Amanuel
 */

#include "pch.h"
#include "PenHandler.h"
#include "RedPen.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;

/// angle of hand from center of player
const double INITIAL_ANGLE = -1.078;
/// radius of hand from center of player
const double RADIUS = 61.3;
CPenHandler::CPenHandler(CGame* game, double xlocation, double ylocation) : mGame(game), mXOrigin(xlocation), mYOrigin(ylocation)
{
	mPenImage = shared_ptr<Bitmap>(Bitmap::FromFile(L"images/images/redpen.png"));
	if (mPenImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/redpen.png");
	}
	mPen = make_shared<CRedPen>(game, mPenImage);
	mLoadX = xlocation + mXOffset;
	mLoadY = ylocation - mYOffset;
	mPen->SetLocation(mLoadX, mLoadY);
	game->Add(mPen);
}

void CPenHandler::FirePen(double mouseX, double mouseY)
{
	mPen->Fire(mouseX - mLoadX, mouseY - mLoadY);
	mOnHand = false;
}

void CPenHandler::OnMouseMove(double angle)
{
	mPen->SetAngle(angle);
	if (mOnHand)
	{
		/// rotating away from the x=0 line
		if (angle > -PI / 2)
		{
			angle = -angle;
		}
		double x = mXOrigin + RADIUS * cos(INITIAL_ANGLE + angle);
		double y = mYOrigin + RADIUS * sin(INITIAL_ANGLE + angle);
		mPen->SetLocation(x, y);
	}
}
