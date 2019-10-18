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
#include "DisplayTimer.h"
#include "EndScreen.h"
#include "UMLPieceEmitter.h"
#include <cstdlib>
#include "UmlVisitor.h"
#include "ScoreBoardVisitor.h"
#include <vector>
#include "UMLStruck.h"

using namespace std;
using namespace Gdiplus;

/// Time between UMLPiece emissions
const double EMITTER_INTERVAL = 4;

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

	// Load pen image
	mPenImage = std::shared_ptr<Bitmap>(Bitmap::FromFile(L"images/images/redpen.png"));
	if (mPenImage->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/redpen.png");
	}

	// Create the scoreboard
	mScoreBoard = make_shared<CScoreBoard>(this);
	//Add(scoreBoard);

	// Create the player
	mPlayer = make_shared<CPlayer>(this);
	//Add(mPlayer);

	// Create the countdown timer
	auto DisplayTimer = make_shared<CDisplayTimer>(this);
	Add(DisplayTimer);

	// Create emitter
	mEmitter = make_shared<CUMLPieceEmitter>(this);

	//auto struck = make_shared<CUMLStruck>(this);
	//struck->Set(0, 0, L"Not good UML");
	////auto mGame = CGameObject::GetGame();
	////mGame->Add(struck);
	//Add(struck);
}

/**
 * Draw the game area
 * \param graphics The GDI+ graphics context to draw on
 * \param width Width of the client window
 * \param height Height of the client window
 */
void CGame::OnDraw(Gdiplus::Graphics* graphics, int width, int height)
{
	// Fill the background with black
	/*SolidBrush brush(Color::Black);
	graphics->FillRectangle(&brush, 0, 0, width, height);*/

	//
	// Automatic Scaling
	//
	float scaleX = float(width) / float(Width);
	float scaleY = float(height) / float(Height);
	mScale = min(scaleX, scaleY);

	mXOffset = width / 2.0f;
	//mXOffset = (width - mScale * width) / 2 ;
	mYOffset = 0;
	if (height > Height * mScale) {
		mYOffset = (float)((height - Height * mScale) / 2);
	}

	graphics->TranslateTransform(mXOffset, mYOffset);
	graphics->ScaleTransform(mScale, mScale);

	// Fill the background with white
	/*SolidBrush new_brush(Color::White);
	graphics->FillRectangle(&new_brush, -Width/2.0, 0, Width, Height);*/
	
	/// TODO: EndScreen teasting.
	//CEndScreen EndScreen();
	//EndScreen->Draw(graphics);

	for (auto gameObjects : mGameObjects)
	{
		gameObjects->Draw(graphics);
	}
	mPlayer->Draw(graphics);

	// This will prevent the scoreboard 
	//to be Drawn at the end of the game
	// when the end screen gets drawm
	if (!mGameOver)
	{
		mScoreBoard->Draw(graphics);
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
	mPlayer->Accept(&visitor);
}

void CGame::OnLeftClick(int x, int y)
{
	double mouseX = (x - mXOffset) / mScale;
	double mouseY = (y - mYOffset) / mScale;

	CPlayerVisitor visitor(mouseX, mouseY, true);
	mPlayer->Accept(&visitor);

}

void CGame::Accept(CGameObjectVisitor* visitor)
{
	for (auto gameObject : mGameObjects)
	{
		gameObject->Accept(visitor);
	}
}

void CGame::CheckGameOver()
{
	if (mGameOver) 
	{
		mGameObjects.clear();

		auto theEnd = make_shared<CEndScreen>(this);

		Add(theEnd);
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
	if (!mGameOver)
	{
		mEmitterTime -= elapsed;

		// Emits a new UMLPiece if the emit time interval is over
		if (mEmitterTime <= 0)
		{
			Add(mEmitter->EmitPiece());

			mEmitterTime += EMITTER_INTERVAL;
		}
	}

	if (mPlayer->IfGetPen()) {
		mPlayer->GetAPen();
	}

	// Do not do ADD or DELETE during looping, will cause crashing
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
void CGame::HitUml(CGameObject* pen)
{
	CUmlVisitor umlVisitor;
	CScoreBoardVisitor scoVisitor;
	//auto scoreBoard = make_shared<CScoreBoard>(this);
	std::vector<std::shared_ptr<CGameObject> > hitUml;

	double penX = pen->GetX();
	double penY = pen->GetY();

	// this is a very naive to solve it. We do not know the position of scoreboard.
	// The other ways to solve: 
	// 1) always make sure the scorebaord is the first in the game object list 
	// 2)
		//for (auto object : mGameObjects)
		//{
		//	object->Accept(&scoVisitor);
		//}
	mScoreBoard->Accept(&scoVisitor);

	for (auto object : mGameObjects)
	{
		object->Accept(&umlVisitor);
		if (umlVisitor.IsUML())
		{
			if (umlVisitor.TryHit(penX, penY))
			{
				if (std::find(hitUml.begin(), hitUml.end(), object) == 
					hitUml.end())
				{
					hitUml.push_back(object);

					if (umlVisitor.IsBad())
					{
						scoVisitor.Increment(true);
						break;
					}
					else
					{
						scoVisitor.Increment(false);
						break;
					}
				}
			}
			umlVisitor.Reset();
		}
	}


}
