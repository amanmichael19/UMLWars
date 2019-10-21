/**
 * \file Timer.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include "Timer.h"


void CTimer::Update(double elapsed)
{
	if (mIsStart) {
		clock_t diff = clock() - mStart;
		mTimeLeft = mTimeTotal - (float(diff) / CLOCKS_PER_SEC);
		if (mTimeLeft <= 0)
		{
			mTimeLeft = 0.0; mIsStart = false;
		}
	}
	else
	{
		// resetting mStart at every update
		mStart = clock();
	}
}
