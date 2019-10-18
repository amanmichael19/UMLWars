/**
 * \file Timer.h
 *
 * \author Ziyuan Zhang
 *
 * 
 */

#pragma once
#include "GameObject.h"
#include <ctime>

class CTimer : public CGameObject
{
public:
	/// scroreboard constructor
	/// \param game
	CTimer(CGame* game);

	/// default constructor disabled
	CTimer() = delete;

	/// default copy constructor disabled
	CTimer(const CTimer&) = delete;

	virtual void Update(double elapsed) { 
		mTimeLeft = mTimeTotal - (clock() - start) / 1000;
		if (mTimeLeft < 0) { mTimeLeft = 0; }
	};

	virtual void Accept(CGameObjectVisitor* visitor) override {}

	/// set total time
	virtual void SetTotalTime(int time) { mTimeTotal = time;}

	/// get reamining time
	virtual int GetRemainingTime() { return mTimeLeft; }

	/// get reamining time
	virtual int IsTimeUp() { return mTimeLeft == 0; }

private:
	int mTimeTotal = 0;
	int mTimeLeft = mTimeTotal;
	clock_t start = clock();
};

