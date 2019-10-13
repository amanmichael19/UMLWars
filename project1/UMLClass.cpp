/**
 * \file UMLClass.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include "UMLClass.h"

/**
 * CUMLClass Constructor
 *
 * Calls CUMLPiece Constructor
 *
 * \param game The game this object is part of
 * \param x X Direction
 * \param y Y Direction
 * \param speed Speed that this object moves
 */
CUMLClass::CUMLClass(CGame* game, double x, double y, int speed) : CUMLPiece(game, x, y, speed)
{
}

/**
 * Draws this object by drawing the UMLDisplay associated with the class
 * \param graphics The graphics device being drawn on
 */
void CUMLClass::Draw(Gdiplus::Graphics* graphics)
{
	mClassDisplay->Draw(graphics,GetX(),GetY());
}

/**
 * Add a CUMLDisplay object to this object
 * \param display The display being added to this object 
 */
void CUMLClass::SetDisplay(std::shared_ptr<CUMLDisplay> display)
{
	mClassDisplay = display;
}

/**
 * Determines if a set of coordinates have hit this object
 *
 * Used mainly for Pen collision detection
 * \param x X location of hit
 * \param y Y location of hit
 * \returns True if the given arguments result in a hit
 */
bool CUMLClass::HitTest(int x, int y)
{
	// Get dimensions of CUMLDisplay member
	double height = mClassDisplay->GetHeight();
	double width = mClassDisplay->GetWidth();

	// Determine acceptable X values
	double minX = GetX();
	double maxX = minX + width;

	// Determine acceptable Y values
	double minY = GetY();
	double maxY = minY + height;

	// Determine if given x and y are valid
	bool validX = (x >= minX) && (x <= maxX);
	bool validY = (y >= minY) && (y <= maxY);

	// Return true if both x and y are hits
	return (validX && validY);
}
