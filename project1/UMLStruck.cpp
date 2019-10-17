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


void CUMLStruck::Set(int x, int y, std::wstring msg)
{
	mX = x;
	mY = y;
	mMsg = msg;
}


CUMLStruck::CUMLStruck(CGame* game) : CGameObject(game)
{

}

void CUMLStruck::Draw(Gdiplus::Graphics* graphics)
{
	// Colors to be used
	SolidBrush yellowBrush(Color(255, 0, 0));
	SolidBrush blackBrush(Color(0, 0, 0));
	Pen blackPen(Color(0, 0, 0));

	// Font to be used
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 13);

	graphics->DrawString(L"DISPLAY", -1, &font, PointF(mX, mY),&yellowBrush);

	//FontFamily font(L"Arial");
	//Gdiplus::Font fontNumber(&font, 60, FontStyleBold);
	//Gdiplus::Font fontLabel(&font, 30, FontStyleBold);
	//SolidBrush heavyGreen(Color(0, 206, 209));

	///// TODO: position can be scaled with size of window
	//graphics->DrawString(L"Correct		Missed		Unfair", -1, &fontLabel, PointF(-312.5 - 5 * 30 / 2, 20 + 60 + 15), &heavyGreen);
	////graphics->DrawString(L"Missed", -1, &fontLabel, PointF(0-5*30/2, 200 - 20), &heavyGreen);
	////graphics->DrawString(L"Unfair", -1, &fontLabel, PointF(312.5- 5 * 30 / 2, 200 - 20), &heavyGreen);
}
