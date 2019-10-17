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

void CScoreBoard::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily font(L"Arial");
	Gdiplus::Font fontNumber(&font, 60, FontStyleBold);
	Gdiplus::Font fontLabel(&font, 30, FontStyleBold);
	SolidBrush heavyGreen(Color(0, 206, 209));
	/// String to draw
	/// String length, -1 means it figures it out on its own
	/// The font to use
	/// Where to draw (top left corner)
	/// The brush to draw the text with

	graphics->DrawString(to_wstring(mCorrect).c_str(), -1, &fontNumber, PointF(-312.5-30, 20), &heavyGreen);
	graphics->DrawString(to_wstring(mMissed).c_str(), -1, &fontNumber, PointF(-30, 20), &heavyGreen);
	graphics->DrawString(to_wstring(mUnfair).c_str(), -1, &fontNumber, PointF(312.5 -30, 20), &heavyGreen);
	
	/// TODO: position can be scaled with size of window
	graphics->DrawString(L"Correct		Missed		Unfair", -1, &fontLabel, PointF(-312.5 - 5 * 30 / 2, 20+60+15), &heavyGreen);
	//graphics->DrawString(L"Missed", -1, &fontLabel, PointF(0-5*30/2, 200 - 20), &heavyGreen);
	//graphics->DrawString(L"Unfair", -1, &fontLabel, PointF(312.5- 5 * 30 / 2, 200 - 20), &heavyGreen);
}


