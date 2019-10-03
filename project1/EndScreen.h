/**
 * \file EndScreen.h
 *
 * \author Daniel Anderson
 *
 * Class that describes the end screen of the game
 */

#pragma once
#include "GameObject.h"

/**
 * Class that displays results of game
 */
class CEndScreen : public CGameObject
{
public:
	void SetFinalScore(int correct, int missed, int unfair);

private:
	void DisplayRank();
	int mFinalScore = 0; ///< The calculated final score achieved in the game, defaults to 0
};

