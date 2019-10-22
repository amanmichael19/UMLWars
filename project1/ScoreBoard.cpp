/**
 * \file ScoreBoard.cpp
 *
 * \author Amanuel
 */

#include "pch.h"
#include <string>
#include "ScoreBoard.h"


using namespace Gdiplus;
using namespace std;

CScoreBoard::CScoreBoard(CGame* game) : CGameObject(game)
{
}

/**
 * Draws the scoreboard
 * \param graphics Graphics device this object is being drawn on
 */
void CScoreBoard::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily font(L"Arial");
	Gdiplus::Font fontNumber(&font, 60, FontStyleBold);
	Gdiplus::Font fontLabel(&font, 30, FontStyleBold);
	SolidBrush heavyGreen(Color(0, 206, 209));

	graphics->DrawString(to_wstring(mCorrect).c_str(), -1, &fontNumber, PointF(-312.5-30, 20), &heavyGreen);
	graphics->DrawString(to_wstring(mMissed).c_str(), -1, &fontNumber, PointF(-30, 20), &heavyGreen);
	graphics->DrawString(to_wstring(mUnfair).c_str(), -1, &fontNumber, PointF(312.5 -30, 20), &heavyGreen);
	
	graphics->DrawString(L"Correct		Missed		Unfair", -1, &fontLabel, PointF(-312.5 - 5 * 30 / 2, 20+60+15), &heavyGreen);
}


