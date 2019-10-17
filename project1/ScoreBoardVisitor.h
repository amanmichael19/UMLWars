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
	/** Visit a CGameObject object
	* \param object we are visiting
	*/
	void CScoreBoardVisitor::VisitUML(CUMLPiece* UML)
	{
		// I need to wait for the hitting and reutrning status of good, bad or missing to update the statusof the board.
	}


	public:
		void CScoreBoardVisitor::VisitScoreBoard(CScoreBoard* scoreBoard) override { mBoard = true; mSB = scoreBoard; }

		/// Report if object was a scoreboard
		/// \return bool
		bool IsScoreboard() { return mBoard; }

		void Increment(bool correct);

	private:
		bool mBoard = false; ///Boolean for IsScoreboard
		CScoreBoard* mSB = nullptr;
		
};
