/**
 * \file UMLInherited.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include "UMLInherited.h"

/**
 * CUMLInherited Constructor
 *
 * Calls CUMLPiece Constructor
 *
 * \param game The game this object is part of
 * \param x X Direction
 * \param y Y Direction
 * \param speed Speed that this object moves
 */
CUMLInherited::CUMLInherited(CGame* game, double x, double y, int speed) : CUMLPiece(game, x, y, speed)
{
}

/**
 * Draws this object by drawing the UMLDisplays associated with this object and an arrow
 * \param graphics The graphics device being drawn on
 */
void CUMLInherited::Draw(Gdiplus::Graphics* graphics)
{
	mBaseDisplay->Draw(graphics,0,0); // Draw Base
	mDerivedDisplay->Draw(graphics,0,0); // Draw Derived

	//TODO: Draw arrow
}

/**
 * Setter for mBaseDisplay
 * \param display New value of mBaseDisplay
 */
void CUMLInherited::SetBaseDisplay(std::shared_ptr<CUMLDisplay> display)
{
	mBaseDisplay = display;
}

/**
 * Setter for mDerivedDisplay
 * \param display New value of mDerivedDisplay
 */
void CUMLInherited::SetDerivedDisplay(std::shared_ptr<CUMLDisplay> display)
{
	mDerivedDisplay = display;
}

/**
 * Setter for mArrowDirection
 * \param direction The direction the arrow should be pointing when drawn
 */
void CUMLInherited::SetArrowDirection(std::wstring direction)
{
	mArrowDirection = direction;
}
