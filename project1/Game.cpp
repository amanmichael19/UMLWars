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
#include "CountDownTimer.h"
#include "EndScreen.h"
#include "UMLPieceEmitter.h"
#include <cstdlib>
#include "UmlVisitor.h"
#include "ScoreBoardVisitor.h"
#include <vector>


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
	// Seed random for the game using time
	srand(unsigned(time(NULL)));

	// Create the scoreboard
	auto scoreBoard = make_shared<CScoreBoard>(this);
	Add(scoreBoard);

	// Create the player
	auto player = make_shared<CPlayer>(this);
	Add(player);

	// Create the countdown timer
	auto countDownTimer = make_shared<CCountDownTimer>(this);
	Add(countDownTimer);

	auto emitter = make_shared<CUMLPieceEmitter>(this); //TEMPORARY
	Add(emitter->EmitPiece());
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

	mXOffset = width / 2.0;
	//mXOffset = (width - mScale * width) / 2 ;
	mYOffset = 0;
	if (height > Height * mScale) {
		mYOffset = (float)((height - Height * mScale) / 2);
	}

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// Fill the background with white
	SolidBrush new_brush(Color::White);
	graphics->FillRectangle(&new_brush, -Width/2.0, 0, Width, Height);
	
	/// TODO: EndScreen teasting.
	//CEndScreen EndScreen();
	//EndScreen->Draw(graphics);

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
	// Pushback as normal if empty
	if (mGameObjects.empty())
	{
		mGameObjects.push_back(gob);
	}

	// Else move scoreboard so it is always drawn last.
	else
	{
		auto lastObject = mGameObjects.back();
		mGameObjects.pop_back();
		mGameObjects.push_back(gob);
		mGameObjects.push_back(lastObject);
	}
	
}

void CGame::OnMouseMove(int x, int y)
{
	double mouseX = (x - mXOffset) / mScale;
	double mouseY = (y - mYOffset) / mScale;

	CPlayerVisitor visitor(mouseX, mouseY, false);
	Accept(&visitor);
}

void CGame::OnLeftClick(int x, int y)
{
	double mouseX = (x - mXOffset) / mScale;
	double mouseY = (y - mYOffset) / mScale;

	CPlayerVisitor visitor(mouseX, mouseY, true);
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


/**
 * Detects whether a given position has hit a UML piece
 * \param x X position of point
 * \param y Y position of point
 */
void CGame::HitUml(int x, int y)
{
	CUmlVisitor umlVisitor;
	CScoreBoardVisitor scoVisitor;
	std::vector<std::shared_ptr<CGameObject> > hitUml;


	for (auto object : mGameObjects)
	{
		object->Accept(&scoVisitor);
		if (scoVisitor.IsScoreboard())
		{
			break;
		}
	}


	for (auto object : mGameObjects)
	{
		object->Accept(&umlVisitor);
		if (umlVisitor.IsUML())
		{
			if (umlVisitor.TryHit(x, y))
			{
				if (std::find(hitUml.begin(), hitUml.end(), object) == 
					hitUml.end())
				{
					hitUml.push_back(object);

					if (umlVisitor.IsBad())
					{
						scoVisitor.Increment(true);
					}
					else
					{
						scoVisitor.Increment(false);
					}
				}
			}
			umlVisitor.Reset();
		}
	}

	
}
