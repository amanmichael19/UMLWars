/**
 * \file ScoreBoardVisitor.h
 *
 * \author Ziyuan Zhang
 *
 * 
 */
#pragma once
#include "GameObjectVisitor.h"
#include "GameObject.h"


class CScoreBoardVisitor : public CGameObjectVisitor
{
	public:
		void CScoreBoardVisitor::VisitScoreBoard(CScoreBoard* scoreBoard) override { 
			if (mBoard == false) {
				mBoard = true; mSB = scoreBoard;
			}
		}

		/// Report if object was a scoreboard
		/// \return bool
		bool IsScoreboard() { return mBoard; }

		void Increment(bool correct);

	private:
		bool mBoard = false; ///Boolean for IsScoreboard
		CScoreBoard* mSB = nullptr;
		
};
