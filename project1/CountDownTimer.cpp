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

	/// TODO: position can be scaled with size of window
	graphics->DrawString(L"Time Left:", -1, &font, PointF(-620, 10), &heavyGreen);

	graphics->DrawString(to_wstring(mTimeLeft).c_str(), -1, &font, PointF(-620+130, 10), &heavyGreen);
}