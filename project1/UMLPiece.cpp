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

using namespace Gdiplus;
using namespace std;

/// The maximum Y value of the display
const double SCREEN_SIZE_Y = 1000;

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
}

void CUMLPiece::Draw(Gdiplus::Graphics* graphics)
{

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 40);
	SolidBrush red(Color(255, 0, 0));

	/// TODO: clean all other objects and display inthe center, wii finish this when the time of score is done.


	graphics->DrawString(mBad.c_str(), -1, &font, PointF(-130, 350), &red);


}

/**
 * Moves UMLPiece object according to its velocity
 * \param elapsed The amount of time passed since last update
 */
void CUMLPiece::Update(double elapsed)
{
	double newX = elapsed * mSpeed * mXDirection + GetX();
	double newY = elapsed * mSpeed * mYDirection + GetY();

	CGameObject::SetLocation(newX, newY);

	// Checks if object has left screen
	if (LeaveScreenCheck())
	{
		// If piece was bad signal missed
		if (mBad != L"")
		{
			GetGame()->UMLMissed();
		}

		// Queue object for deletion at end of update
		GetGame()->QueueFree(this);
	}
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

void CUMLPiece::DisplayHitMessage()
{

	if (mBad == L"")
	{

		

		mBad = L"This was good UML.";

	}
	//GetGame()->QueueFree(this);
	mSpeed = 0;
}