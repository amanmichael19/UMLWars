/**
 * \file UMLPiece.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include <vector>
#include <memory>
#include "UMLPiece.h"

using namespace Gdiplus;

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

/**
 * Moves UMLPiece object according to its velocity
 * \param elapsed The amount of time passed since last update
 */
void CUMLPiece::Update(double elapsed)
{
	double newX = elapsed * mSpeed * mXDirection + GetX();
	double newY = elapsed * mSpeed * mYDirection + GetY();

	CGameObject::SetLocation(newX, newY);

	LeaveScreenCheck();
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

	// Colors to be used
	SolidBrush yellowBrush(Color(255, 255, 193));
	SolidBrush blackBrush(Color(0, 0, 0));
	Pen blackPen(Color(0, 0, 0));

	// Font to be used
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 13);

}
