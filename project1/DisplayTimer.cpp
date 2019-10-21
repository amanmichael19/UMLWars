/**
 * \file ScoreBoard.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include <string>
#include <sstream>
#include <iomanip>
#include "DisplayTimer.h"


using namespace Gdiplus;
using namespace std;

CDisplayTimer::CDisplayTimer(CGame* game, double duration) : CTimer(game, duration)
{
	Start();
}


void CDisplayTimer::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 20);
	SolidBrush heavyGreen(Color(0, 0, 0));

	wostringstream oss;
	oss << fixed << setprecision(2) << GetRemainingTime() << endl;
	wstring remainingTime = L"Time Left: " + oss.str();
	graphics->DrawString(remainingTime.c_str(), -1, &font, PointF(-600, 10), &heavyGreen);
}

void CDisplayTimer::Update(double elapsed)
{
	CTimer::Update(elapsed);
	if (IsTimeUp())
	{
		GetGame()->SetGameOver(true);
	}
}



