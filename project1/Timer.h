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
		if (mIsUpdate) {
			mTimeLeft = mTimeTotal - (clock() - start) / 1000;
			if (mTimeLeft < 0) { mTimeLeft = 0; }
		}
		else {
			start = clock();
		}
	};

	virtual void Accept(CGameObjectVisitor* visitor) override {}

	virtual void Draw(Gdiplus::Graphics* graphics) {};

	/// set total time
	virtual void SetTotalTime(int time) { mTimeLeft = time;  mTimeTotal = time;}

	/// get reamining time
	virtual int GetRemainingTime() { return mTimeLeft; }

	/// get reamining time
	virtual int IsTimeUp() { return mTimeLeft == 0; }

	virtual void SetIsUpdate(bool is) { mIsUpdate = is; }

private:
	int mTimeTotal = 0;
	int mTimeLeft = mTimeTotal;
	bool mIsUpdate = false;
	clock_t start = clock();;
};

