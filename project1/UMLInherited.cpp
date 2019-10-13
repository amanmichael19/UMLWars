/**
 * \file UMLInherited.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include "UMLInherited.h"

using Gdiplus::PointF;

/// Number of pixels between base and derived class in Y direction
const double Y_OFFSET = 50;

/// How many pixels away from tip/tail arrow ends are in Y direction
const double ARROW_Y_OFFSET = 15;

/// How many pixels away from tip/tail arrow ends are in X direction
const double ARROW_X_OFFSET = 20;

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
	// Set the dimensions of both UMLDisplays, as they will be needed to correctly display the final result
	if (mFirstDraw)
	{
		mBaseDisplay->SetDimensions(graphics);
		mDerivedDisplay->SetDimensions(graphics);
		mFirstDraw = false;
	}
	
	double derivedY = GetY() + mBaseDisplay->GetHeight() + Y_OFFSET;
	double derivedX = GetX() + (mBaseDisplay->GetWidth() - mDerivedDisplay->GetWidth()) / 2;

	// Center and Space Base and Derived
	mBaseDisplay->Draw(graphics,GetX(),GetY()); // Draw Base
	mDerivedDisplay->Draw(graphics,derivedX,derivedY); // Draw Derived

	// Pen used to draw arrow
	Gdiplus::Pen blackPen(Gdiplus::Color(0, 0, 0));

	// Pen used to clean up leftover arrow
	Gdiplus::Pen eraser(Gdiplus::Color(255, 255, 255));

	// Draw shaft of arrow
	PointF topPoint(derivedX + (mDerivedDisplay->GetWidth() / 2), derivedY - Y_OFFSET);
	PointF tailPoint(derivedX + (mDerivedDisplay->GetWidth() / 2), derivedY);
	graphics->DrawLine(&blackPen, topPoint, tailPoint);

	// Draw up arrow tip
	if (mArrowDirection == L"up")
	{
		// Points needed to draw up arrow
		PointF leftTop(topPoint.X - ARROW_X_OFFSET, topPoint.Y + ARROW_Y_OFFSET);
		PointF rightTop(topPoint.X + ARROW_X_OFFSET, topPoint.Y + ARROW_Y_OFFSET);
		PointF topBase(topPoint.X,topPoint.Y + ARROW_Y_OFFSET);

		// Draws up arrow
		graphics->DrawLine(&blackPen, topPoint, leftTop);
		graphics->DrawLine(&blackPen, topPoint, rightTop);
		graphics->DrawLine(&blackPen, leftTop, rightTop);
		graphics->DrawLine(&eraser, topPoint, topBase);
	}

	// Draw down arrow tip
	else
	{
		// Points needed to draw down arrow
		PointF leftBottom(tailPoint.X - ARROW_X_OFFSET, tailPoint.Y - ARROW_Y_OFFSET);
		PointF rightBottom(tailPoint.X + ARROW_X_OFFSET, tailPoint.Y - ARROW_Y_OFFSET);
		PointF bottomBase(tailPoint.X, tailPoint.Y - ARROW_Y_OFFSET);

		// Draws down arrow
		graphics->DrawLine(&blackPen, tailPoint, leftBottom);
		graphics->DrawLine(&blackPen, tailPoint, rightBottom);
		graphics->DrawLine(&blackPen, leftBottom, rightBottom);
		graphics->DrawLine(&eraser, tailPoint, bottomBase);
	}
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
