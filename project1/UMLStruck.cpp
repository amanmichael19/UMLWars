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
	//SolidBrush blackBrush(Color(0, 0, 0));
	Pen blackPen(Color(0, 0, 0));

	// Font to be used
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 13);

	graphics->DrawString(mMsg.c_str(), -1, &font, PointF(mX, mY),&yellowBrush);

}
