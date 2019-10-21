/**
 * \file UMLPiece.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include <vector>
#include <memory>
#include "UMLPiece.h"
#include "Game.h"
#include <memory>
#include "UMLStruck.h"

using namespace Gdiplus;
using namespace std;

/// The maximum Y value of the display
const double SCREEN_SIZE_Y = 1000;
/// umlpiece duration after hit
const double StuckDuration = 1.0;

/**
 * CUMLPiece Constructor
 * \param game The game this CUMLPiece object is part of
 * \param x X direction of movement
 * \param y Y direction of movement
 * \param speed How fast the piece is moving
 */
CUMLPiece::CUMLPiece(CGame* game, double x, double y, int speed) : CGameObject(game)
{
	mXDirection = x;
	mYDirection = y;
	mSpeed = speed;
	mHitUMLTimer = make_shared<CTimer>(game, StuckDuration);
	game->Add(mHitUMLTimer);
}

/**
 * Moves UMLPiece object according to its velocity
 * \param elapsed The amount of time passed since last update
 */
void CUMLPiece::Update(double elapsed)
{
	double newX = elapsed * mSpeed * mXDirection + GetX();
	double newY = elapsed * mSpeed * mYDirection + GetY();
	if (!mWasHit)
	{
		CGameObject::SetLocation(newX, newY);
	}
	else
	{
		if (mHitUMLTimer->IsTimeUp() || GetGame()->IsGameOver())
		{
			MarkForDelete(true);
			mUMLStruck->MarkForDelete(true);
		}
	}
	// Checks if object has left screen
	if (LeaveScreenCheck())
	{
		// If piece was bad signal missed
		if (mBad != L"")
		{
			GetGame()->UMLMissed();
		}

		// Queue object for deletion at end of update
		MarkForDelete(true);
	}
}

/**
 * Marks uml hit and starts timer
 * \param status hit status
 */
void CUMLPiece::MarkHit(bool status)
{
	mWasHit = status;
	mHitUMLTimer->StartTimer();
	wstring msg = mBad == L"" ? L"Unfair" : mBad;
	mUMLStruck = make_shared<CUMLStruck>(GetGame(), msg);
	mUMLStruck->SetLocation(GetX(), GetY());
	GetGame()->AddToWaitingBuffer(mUMLStruck);
}


/**
 * Checks if the UMLPiece has left the screen
 * \returns True if the UMLPiece object has left the screen
 */
bool CUMLPiece::LeaveScreenCheck()
{
	// Could be used to signal missed/correct and indicate that this object should be destroyed
	return GetY() > SCREEN_SIZE_Y;
}