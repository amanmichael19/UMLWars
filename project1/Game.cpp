/**
 * \file Game.cpp
 *
 * \author Caleb Jenkins
 */

#include "pch.h"
#include "Game.h"
#include "Player.h"
#include "PlayerVisitor.h"
#include "ScoreBoard.h"

using namespace std;
using namespace Gdiplus;
/**
 * Game constructor
 */
CGame::CGame()
{
	//can be refactored-for testing purposes
	OnLaunch();
}

CGame::~CGame()
{
}

void CGame::OnLaunch()
{
	auto player = make_shared<CPlayer>(this);
	auto scoreBoard = make_shared<CScoreBoard>(this);
	Add(player);
	Add(scoreBoard);
}

void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
	// Fill the background with black
	SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = (width - mScale * width) / 2 ;
	mYOffset = 0;
	if (height > Height * mScale) {
		mYOffset = (float)((height - Height * mScale) / 2);
	}

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// Fill the background with white
	SolidBrush new_brush(Color::White);
	graphics->FillRectangle(&new_brush, 0, 0, Width, Height);
	for (auto gameObjects : mGameObjects)
	{
		gameObjects->Draw(graphics);
	}
}

/**
 * Add a game object to the game
 * \param gob New game object to add
 */
void CGame::Add(std::shared_ptr<CGameObject> gob)
{
	mGameObjects.push_back(gob);
}

void CGame::OnMouseMove(int x, int y)
{
	double mouseX = (x - mXOffset) / mScale;
	double mouseY = (y - mYOffset) / mScale;

	CPlayerVisitor visitor(mouseX, mouseY);
	Accept(&visitor);
}

void CGame::Accept(CGameObjectVisitor* visitor)
{
	for (auto gameObject : mGameObjects)
	{
		gameObject->Accept(visitor);
	}
}

/** Test an x,y click location to see if it clicked
* on some GameObject.
* \param x X location
* \param y Y location
* \returns Pointer to item we clicked on or nullptr if none.
*/
std::shared_ptr<CGameObject> CGame::HitTest(int x, int y)
{
	for (auto i = mGameObjects.rbegin(); i != mGameObjects.rend(); i++)
	{
		if ((*i)->HitTest(x, y))
		{
			return *i;
		}
	}

	return  nullptr;
}

void CGame::Update(double elapsed)
{
	for (auto gameObjects : mGameObjects)
	{
		gameObjects->Update(elapsed);
	}
}