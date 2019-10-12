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
	CGameObject::SetLocation(100, 100);
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
