/**
 * \file EndScreen.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include "EndScreen.h"

/// Value of a Correct UML
const int CORRECT_VALUE = 2;

/// Value of a Missed UML
const int MISSED_VALUE = -1;

/// Value of a Unfair UML
const int UNFAIR_VALUE = -2;

/// Final Score cutoff for rank 1
const int RANK_ONE_CUTOFF = 5;

/// Final Score cutoff for rank 2
const int RANK_TWO_CUTOFF = 10;

/// Final Score cutoff for rank 3
const int RANK_THREE_CUTOFF = 15;

/// Final Score cutoff for rank 4
const int RANK_FOUR_CUTOFF = 20;

/**
 * Calculate the final score of the game
 * \param correct Number of UML Correctly Graded
 * \param missed Number of UML Missed
 * \param unfair Number of UML Uncorrectly Graded
 */
void CEndScreen::SetFinalScore(int correct, int missed, int unfair)
{
	// Add points for correct UML
	mFinalScore += correct * CORRECT_VALUE;
	
	// Deduct points for missed UML
	mFinalScore += missed * MISSED_VALUE;

	// Deduct points for unfair UML
	mFinalScore += unfair * UNFAIR_VALUE;
	
	// Ensure that minimum final score is not less than zero.
	if (mFinalScore < 0)
	{
		mFinalScore = 0;
	}

	// Display the final rank
	DisplayRank();
}

/**
 * Displays the earned based on the final score
 */
void CEndScreen::DisplayRank()
{
	// Rank 1
	if (mFinalScore < RANK_ONE_CUTOFF)
	{

	}

	// Rank 2
	else if (mFinalScore < RANK_TWO_CUTOFF)
	{

	}

	// Rank 3
	else if (mFinalScore < RANK_THREE_CUTOFF)
	{

	}

	// Rank 4
	else if (mFinalScore < RANK_FOUR_CUTOFF)
	{

	}

	// Rank 5
	else
	{

	}
}
