/**
 * \file Timer.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include "Timer.h"

CTimer::CTimer(CGame* game) : CGameObject(game)
{
}

void CTimer::Update(double elapsed)
{

	if (mIsUpdate) {
		mTimeLeft = mTimeTotal - (clock() - start) / 1000;
		if (mTimeLeft < 0) { mTimeLeft = 0; }
	}
	else {
		start = clock();
	}

	if (mTimeLeft == 0)
	{
		GetGame()->SetGameOver(true);
	}
}