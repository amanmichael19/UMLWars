#include "pch.h"
#include "PenHandler.h"
#include "RedPen.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;

CPenHandler::CPenHandler(CGame* game, double xlocation, double ylocation) : mGame(game)
{
	mPenImage = shared_ptr<Bitmap>(Bitmap::FromFile(L"images/images/redpen.png"));
	if (mPenImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/redpen.png");
	}
	mPen = make_shared<CRedPen>(game, mPenImage);
	mLoadX = xlocation + mXOffset;
	mLoadY = ylocation - mYOffset;
	mPen->SetLocation(mLoadX, mLoadY);
	game->Add(mPen);
}

void CPenHandler::SetPenAngle(double angle)
{
	mPen->SetAngle(angle);
}
