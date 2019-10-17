/**
 * \file ScoreBoardVisitor.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include "ScoreBoardVisitor.h"
#include "ScoreBoard.h"


/** Increments the board when a uml is hit
 * \param correct bool of if uml was correctly hit
 */
void CScoreBoardVisitor::Increment(bool correct)
{
		if (correct)
		{
			mSB->IncrementCorrectScore();
		}
		else
		{
			mSB->IncrementUnfairScore();
		}
}
