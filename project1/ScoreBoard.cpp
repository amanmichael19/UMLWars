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
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 20);
	SolidBrush heavyGreen(Color(64, 102, 93));
	/// String to draw
	/// String length, -1 means it figures it out on its own
	/// The font to use
	/// Where to draw (top left corner)
	/// The brush to draw the text with

	/// TODO: position can be scaled with size of window
	graphics->DrawString(L"Correct", -1, &font, PointF(312, 200), &heavyGreen);    
	graphics->DrawString(L"Missed", -1, &font, PointF(612, 200), &heavyGreen);
	graphics->DrawString(L"Unfair", -1, &font, PointF(912, 200), &heavyGreen);

	graphics->DrawString(to_wstring(mCorrect).c_str(), -1, &font, PointF(312, 200), &heavyGreen);
	graphics->DrawString(to_wstring(mMissed).c_str(), -1, &font, PointF(612, 200), &heavyGreen);
	graphics->DrawString(to_wstring(mUnfair).c_str(), -1, &font, PointF(912, 200), &heavyGreen);

}