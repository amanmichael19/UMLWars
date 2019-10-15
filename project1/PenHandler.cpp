/**
 * \file PenHandler.cpp
 *
 * \author Amanuel
 */

#include "pch.h"
#include "PenHandler.h"
#include "RedPen.h"
#include "Game.h"

using namespace std;
using namespace Gdiplus;


CPenHandler::CPenHandler(CGame* game, double xLocation, double yLocation) : mGame(game)
{
	mPenImage = shared_ptr<Bitmap>(Bitmap::FromFile(L"images/images/redpen.png"));
	if (mPenImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/redpen.png");
	}
	mPen = make_shared<CRedPen>(game, mPenImage, xLocation, yLocation);
	game->Add(mPen);
}

void CPenHandler::FirePen(double mouseX, double mouseY)
{
	mPen->Fire(mouseX, mouseY);
}

void CPenHandler::OnMouseMove(double angle)
{
	mPen->SetAngle(angle);
	mPen->TrackHand();
}

bool CPenHandler::OnHand()
{
	return mPen->GetOnHand();
}
