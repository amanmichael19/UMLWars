/**
 * \file EndScreen.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include "EndScreen.h"


using namespace Gdiplus;
using namespace std;

using std::wstring;

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

/// Text for Rank 1
const wstring RANK_ONE_TEXT = L"A SQUIRREL WITH A PEN\nSquirrels are good at many things, but grading UML is not one of them.";

/// Text for Rank 2
const wstring RANK_TWO_TEXT = L"A FIRST YEAR CS STUDENT\nA good try, but a lot of room for improvement.";

/// Text for Rank 3
const wstring RANK_THREE_TEXT = L"A SEASONED ULA\nYou have seen your fair share of UML, but your not quite an expert yet.";

/// Text for Rank 4
const wstring RANK_FOUR_TEXT = L"THE HEAD TA\nAn impressive display. Surely this is the final rank?";

/// Text for Rank 5
const wstring RANK_FIVE_TEXT = L"LIVING LEGEND : GRADY BOOCH\nIt was not.";

/**
 * Constructor for CEndScreen
 * \param game The game this end screen is part of
 */
CEndScreen::CEndScreen(CGame* game) : CGameObject(game)
{
}

/**
 * Calculate the final score of the game
 * \param correct Number of UML Correctly Graded
 * \param missed Number of UML Missed
 * \param unfair Number of UML Uncorrectly Graded
 */
void CEndScreen::SetFinalScore(int correct, int missed, int unfair)
{
	// Clear current score value
	mFinalScore = 0;

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
		mRankText = RANK_ONE_TEXT;
	}

	// Rank 2
	else if (mFinalScore < RANK_TWO_CUTOFF)
	{
		mRankText = RANK_TWO_TEXT;
	}

	// Rank 3
	else if (mFinalScore < RANK_THREE_CUTOFF)
	{
		mRankText = RANK_THREE_TEXT;
	}

	// Rank 4
	else if (mFinalScore < RANK_FOUR_CUTOFF)
	{
		mRankText = RANK_FOUR_TEXT;
	}

	// Rank 5
	else
	{
		mRankText = RANK_FIVE_TEXT;
	}
}


void CEndScreen::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 100);
	SolidBrush heavyGreen(Color(256, 256, 256));

	/// TODO: clean all other objects and display inthe center, wii finish this when the time of score is done.
	graphics->DrawString(L"Final Score:", -1, &font, PointF(-500, 200), &heavyGreen);

	graphics->DrawString(to_wstring(mFinalScore).c_str(), -1, &font, PointF(500, 200), &heavyGreen);

	graphics->DrawString(L"RANK:", -1, &font, PointF(-500, 500), &heavyGreen);
	graphics->DrawString(mRankText.c_str(), -1, &font, PointF(-200, 500), &heavyGreen);
}
