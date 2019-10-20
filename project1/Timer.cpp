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
		auto a = (clock() - mStart);
		mTimeLeft = (mTimeTotal * 1000 - (clock() - mStart)) / 1000;
		if (mTimeLeft < 0) { mTimeLeft = 0; }
	}
	else {
		mStart = clock();
	}
}