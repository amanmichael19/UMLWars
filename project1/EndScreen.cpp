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
const wstring RANK_ONE_TEXT = L"A SQUIRREL WITH A PEN";
const wstring DESCRIPTION_RANK_ONE = L"Squirrels are good at many things,\nbut grading UML is not one of them.";
/// Text for Rank 2
const wstring RANK_TWO_TEXT = L"A FIRST YEAR CS STUDENT";
const wstring DESCRIPTION_RANK_TWO = L"A good try, but a lot\nof room for improvement.";
/// Text for Rank 3
const wstring RANK_THREE_TEXT = L"A SEASONED ULA";
const wstring DESCRIPTION_RANK_THREE = L"You have seen your fair share of\nUML, but you're not quite an expert yet.";
/// Text for Rank 4
const wstring RANK_FOUR_TEXT = L"THE HEAD TA";
const wstring DESCRIPTION_RANK_FOUR = L"An impressive display.\nSurely this is the final rank?";
/// Text for Rank 5
const wstring RANK_FIVE_TEXT = L"LIVING LEGEND";
const wstring DESCRIPTION_RANK_FIVE = L"GRADY BOOCH\nIt was not.";
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
		mDescription = DESCRIPTION_RANK_ONE;
	}

	// Rank 2
	else if (mFinalScore < RANK_TWO_CUTOFF)
	{
		mRankText = RANK_TWO_TEXT;
		mDescription = DESCRIPTION_RANK_TWO;
	}

	// Rank 3
	else if (mFinalScore < RANK_THREE_CUTOFF)
	{
		mRankText = RANK_THREE_TEXT;
		mDescription = DESCRIPTION_RANK_THREE;
	}

	// Rank 4
	else if (mFinalScore < RANK_FOUR_CUTOFF)
	{
		mRankText = RANK_FOUR_TEXT;
		mDescription = DESCRIPTION_RANK_FOUR;
	}

	// Rank 5
	else
	{
		mRankText = RANK_FIVE_TEXT;
		mDescription = DESCRIPTION_RANK_FIVE;
	}
}


void CEndScreen::Draw(Gdiplus::Graphics* graphics)
{
	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 40);
	Gdiplus::Font font2(&fontFamily, 30);
	SolidBrush heavyGreen(Color(256, 256, 256));
	SolidBrush red(Color(255, 0, 0));

	/// TODO: clean all other objects and display inthe center, wii finish this when the time of score is done.
	graphics->DrawString(L"Final Score:", -1, &font, PointF(-500, 200), &heavyGreen);

	graphics->DrawString(to_wstring(mFinalScore).c_str(), -1, &font, PointF(-130, 200), &red);

	graphics->DrawString(L"RANK:", -1, &font, PointF(-500, 350), &heavyGreen);

	graphics->DrawString( mRankText.c_str(), -1, &font, PointF(-130, 350), &red);

	graphics->DrawString(mDescription.c_str(), -1, &font2, PointF(-300, 650), &heavyGreen);


	
}
