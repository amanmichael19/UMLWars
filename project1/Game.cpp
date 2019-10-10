/**
 * \file Game.cpp
 *
 * \author Caleb Jenkins
 */

#include "pch.h"
#include "Game.h"


/**
 * Game constructor
 */
CGame::CGame()
{
}

CGame::~CGame()
{
}

void CGame::OnDraw(Gdiplus::Graphics* graphics)
{
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