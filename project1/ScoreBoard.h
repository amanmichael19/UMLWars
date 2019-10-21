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
		virtual void Accept(CGameObjectVisitor* visitor) override { visitor->VisitScoreBoard(this); }

		/// draw
		/// \param graphics
		virtual void Draw(Gdiplus::Graphics* graphics);

		virtual void Update(double elapsed) {}


		/// increment correct score
		void IncrementCorrectScore() { mCorrect++; }

		/// increment unfair score
		void IncrementUnfairScore() { mUnfair++; }

		/// increment missed score
		void IncrementMissedScore() { mMissed++; }

		/// Getter for mCorrect
		/// \returns Number of correct UML hits
		int GetCorrect() { return mCorrect; }

		/// Getter for mUnfair
		/// \returns Number of unfair UML hits
		int GetUnfair() { return mUnfair; }

		/// Getter for mMissed
		/// \returns Number of bad UML missed
		int GetMissed() { return mMissed; }

	private:
		int mCorrect = 0;
		int mUnfair = 0;
		int mMissed = 0;
};

