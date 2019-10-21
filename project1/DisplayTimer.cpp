/**
 * \file ScoreBoard.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include <string>
#include "DisplayTimer.h"


using namespace Gdiplus;
using namespace std;

CDisplayTimer::CDisplayTimer(CGame* game) : CTimer(game)
{
	SetIsUpdate(true);
	SetTotalTime(40);
}


void CDisplayTimer::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 20);
	SolidBrush heavyGreen(Color(0, 0, 0));

	char buffer[15];
	sprintf_s(buffer, "Time Left: %d", GetRemainingTime());
	wstring output(&buffer[0], &buffer[14]);
	graphics->DrawString(output.c_str(), -1, &font, PointF(-600, 10), &heavyGreen);
}

void CDisplayTimer::Update(double elapsed)
{
	CTimer::Update(elapsed);
	if (IsTimeUp())
	{
		GetGame()->SetGameOver(true);
	}
}



