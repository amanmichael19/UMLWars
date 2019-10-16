/**
 * \file ScoreBoard.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include <string>
#include "CountDownTimer.h"


using namespace Gdiplus;
using namespace std;

CCountDownTimer::CCountDownTimer(CGame* game) : CGameObject(game)
{
}

void CCountDownTimer::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 20);
	SolidBrush heavyGreen(Color(0, 0, 0));

	char buffer[15];
	sprintf_s(buffer, "Time Left: %d", mTimeLeft);
	wstring output(&buffer[0], &buffer[14]);
	graphics->DrawString(output.c_str(), -1, &font, PointF(-600, 10), &heavyGreen);
}