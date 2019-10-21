/**
 * \file Timer.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include "Timer.h"


void CTimer::Update(double elapsed)
{
	if (mIsStarted) {
		clock_t diff = clock() - mStart;
		mTimeLeft = (mTimeTotal * 1000 - float(diff)) / 1000;
		if (mTimeLeft <= 0) 
		{
			mTimeLeft = 0; mIsStarted = false;
		}
	}
	else 
	{
		// resetting mStart at every update
		mStart = clock();
	}
}


