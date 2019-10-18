/**
 * \file Game.h
 *
 * \author Caleb Jenkins
 *
 * Class that implements a Game
 *
 *
 */

#pragma once
#include <vector>
#include <memory>
#include "ScoreBoard.h"

class CGameObject;
class CGameObjectVisitor;
class CUMLPieceEmitter;
class CUmlHitDetector;

class CGame
{
	public:
		/// Game constructor
		CGame();
		/// Destructor
		virtual ~CGame();

		/**
		 * Draw the game area
		 * \param graphics The GDI+ graphics context to draw on
		 * \param width Width of the client window
		 * \param height Height of the client window
		 */
		void OnDraw(Gdiplus::Graphics* graphics, int width, int height);
		/// Allows adding CGameObjects
		void Add(std::shared_ptr<CGameObject> gob);

		/// update time counter
		/// \param elapsed time
		void Update(double elapsed);

		void HitUml(CGameObject* fire);

		//void HitUml(int x, int y);

		/**
		 *  Test to see if we hit this GameObject.
		 * \param x X position to test
		 * \param y Y position to test
		 * \return std::shared_ptr<CGameObject> 
		 */
		std::shared_ptr<CGameObject> CGame::HitTest(int x, int y);

		/// populate game on launch
		void OnLaunch();

		/// get width
		/// \return int
		static int GetWidth() { return Width; }

		/// get height
		/// \return int
		static int GetHeight() { return Height; }

		/// act on mouse movement
		void OnMouseMove(int x, int y);

		/// act on left click
		void OnLeftClick(int x, int y);

		/// accepts visitor
		/// \param visitor
		void Accept(CGameObjectVisitor* visitor);


		void CheckGameOver();

		void SetGameOver(bool gameover) { mGameOver = gameover; }

		auto GetPenImage() {return mPenImage; }

	private:

		/// All of the gameobjects to populate our game
		std::vector<std::shared_ptr<CGameObject> > mGameObjects;

		std::shared_ptr<CScoreBoard> mScoreBoard;

		std::shared_ptr<CPlayer> mPlayer;

		std::shared_ptr<Gdiplus::Bitmap> mPenImage;


		/// Game area in virtual pixels
		const static int Width = 1250;

		/// Game area height in virtual pixels
		const static int Height = 1000;

		/// value to scale screen size by
		double mScale = 1.0;

		/// x offset to indicate the origin
		double mXOffset = 0.0;

		/// y offset to indicate the origin
		double mYOffset = 0.0;

		/// Emitter for UMLPieces
		std::shared_ptr<CUMLPieceEmitter> mEmitter;

		/// Time until emitter emits next piece
		double mEmitterTime = 0;

		/// game over check
		bool mGameOver = false;
};

