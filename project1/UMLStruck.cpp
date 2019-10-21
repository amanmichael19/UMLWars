/**
 * \file UMLStruck.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include <memory>
#include "UMLStruck.h"

using namespace Gdiplus;
using namespace std;


void CUMLStruck::Draw(Gdiplus::Graphics* graphics)
{
	// Colors to be used
	SolidBrush redwBrush(Color(255, 0, 0));
	SolidBrush greenBrush(Color(34, 139, 34));

	// Font to be used
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 20);
	if (mMsg == L"Unfair") {
		graphics->DrawString(mMsg.c_str(), -1, &font, PointF(GetX(), GetY()), &redwBrush);
	}
	else {
		graphics->DrawString(mMsg.c_str(), -1, &font, PointF(GetX(), GetY()), &greenBrush);
	}
	
}
