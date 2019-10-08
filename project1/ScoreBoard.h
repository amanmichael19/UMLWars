/**
 * \file ScoreBoard.h
 *
 * \author Amanuel
 *
 * 
 */


#pragma once
#include "GameObject.h"
/**
 * A class implementing score board
 */
class CScoreBoard : public CGameObject
{
	public:
		/// scroreboard constructor
		/// \param game
		CScoreBoard(CGame* game);

		/// default constructor disabled
		CScoreBoard() = delete;

		/// default copy constructor disabled
		CScoreBoard(const CScoreBoard&) = delete;

		/// accepts visitor
		virtual void Accept(CGameObjectVisitor* visitor) override {}

		/// draw
		/// \param graphics
		virtual void Draw(Gdiplus::Graphics* graphics);

	private:
		int mCorrect = 0;
		int mUnfair = 0;
		int mMissed = 0;
};

