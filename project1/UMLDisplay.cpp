/**
 * \file UMLDisplay.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include "UMLDisplay.h"

using namespace Gdiplus;

/// The size of the font on the UML
const int FONT_SIZE = 13;

/**
 * Draws the UML on the screen
 * \param graphics The graphics device to be drawn on
 * \param x The x location at center of display
 * \param y The y location at center of display
 */
void CUMLDisplay::Draw(Gdiplus::Graphics* graphics, double x, double y)
{
	// Set dimensions if it is the first time being drawn
	if (mHeight == 0)
	{
		SetDimensions(graphics);
	}
	// Used in some size calculations
	Gdiplus::RectF size;
	Gdiplus::PointF origin(0.0f, 0.0f);
	double yOffset = y + mNameHeight;

	// Colors to be used
	SolidBrush yellowBrush(Color(255, 255, 193));
	SolidBrush blackBrush(Color(0, 0, 0));
	Pen blackPen(Color(0, 0, 0));

	// Font to be used
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, FONT_SIZE);

	auto state = graphics->Save();

	// Rectangle that contains UML
	Gdiplus::Rect rect(x, y, mWidth, mHeight);
	graphics->FillRectangle(&yellowBrush, rect);
	graphics->DrawRectangle(&blackPen, rect);

	// Draw name centered in UML
	graphics->DrawString(mName.c_str(), -1, &font, PointF(x + (mWidth - mNameWidth) / 2, y), &blackBrush);

	// Draw line between name and attributes
	graphics->DrawLine(&blackPen, PointF(x, y + mNameHeight), PointF(x + mWidth, y + mNameHeight));

	// Draw Attributes
	for (std::wstring att : mAttributes)
	{
		graphics->DrawString(att.c_str(), -1, &font, PointF(x, yOffset), &blackBrush);
		graphics->MeasureString(att.c_str(), -1, &font, origin, &size);
		yOffset += (double)size.Height;

	}

	// Draw line between attributes and operations
	graphics->DrawLine(&blackPen, PointF(x, yOffset), PointF(x + mWidth, yOffset));

	// Draw operations
	for (std::wstring op : mOperations)
	{
		graphics->DrawString(op.c_str(), -1, &font, PointF(x, yOffset), &blackBrush);
		graphics->MeasureString(op.c_str(), -1, &font, origin, &size);
		yOffset += (double)size.Height;

	}

	graphics->Restore(state);
}

/**
 * Sets the dimensions of the UMLDisplay
 * \param graphics The graphics device being drawn on
 */
void CUMLDisplay::SetDimensions(Gdiplus::Graphics* graphics)
{
	// Font to be used
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, FONT_SIZE);
	Gdiplus::RectF size;
	Gdiplus::PointF origin(0.0f, 0.0f);

	// Handle name
	graphics->MeasureString(mName.c_str(), -1, &font, origin, &size);
	mNameHeight = ((double)size.Height > 1.0f) ? (double)size.Height : 25.0f;
	mNameWidth = (double)size.Width;
	mHeight += mNameHeight;
	mWidth = (double)size.Width;

	// Handle attributes
	for (std::wstring att : mAttributes)
	{
		graphics->MeasureString(att.c_str(), -1, &font, origin, &size);
		mHeight += (double)size.Height;
		mAttributeHeight += (double)size.Height;
		
		if ((double)size.Width > mWidth)
		{
			mWidth = (double)size.Width;
		}
		
		if ((double)size.Width > mAttributeWidth)
		{
			mAttributeWidth = (double)size.Width;
		}
	}

	// Handle operations
	for (std::wstring op : mOperations)
	{
		graphics->MeasureString(op.c_str(), -1, &font, origin, &size);
		mHeight += (double)size.Height;
		mOperationHeight += (double)size.Height;

		if ((double)size.Width > mWidth)
		{
			mWidth = (double)size.Width;
		}

		if ((double)size.Width > mOperationWidth)
		{
			mOperationWidth = (double)size.Width;
		}
	}

	// Minimum height
	if (mHeight == 0.0f)
	{
		mHeight = 10.0f;
	}

	// Minimum width
	if (mWidth == mNameHeight)
	{
		mWidth += 50.0f;
	}
}
