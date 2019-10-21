/**
 * \file Timer.h
 *
 * \author Ziyuan Zhang
 *
 *
 */

#pragma once
#include "GameObject.h"
#include "Game.h"
#include <ctime>

class CTimer : public CGameObject
{
public:
	/// scroreboard constructor
	/// \param game
	CTimer(CGame* game, double duratio);

	/// default constructor disabled
	CTimer() = delete;

	/// default copy constructor disabled
	CTimer(const CTimer&) = delete;

	virtual void Update(double elapsed) {
		if (mIsStart) {
			mTimeLeft = (mTimeTotal - (clock() - mStart) / 1000);
			if (mTimeLeft <= 0) { mTimeLeft = 0; mIsStart = false; }
		}
	}

	virtual void Accept(CGameObjectVisitor* visitor) override {}

	virtual void Draw(Gdiplus::Graphics* graphics) {};

	/// set total time
	virtual void SetUp(double time) {
		mTimeLeft = time;
		mTimeTotal = time;
	}

	/// get reamining time
	virtual int GetRemainingTime() { return mTimeLeft; }

	/// get reamining time
	virtual int IsTimeUp() { return mTimeLeft == 0; }

	virtual void Start() {
		mIsStart = true;
		mStart = clock();
	}

private:
	double mTimeTotal = 0;
	double mTimeLeft = mTimeTotal;
	bool mIsStart = false;
	clock_t mStart;
};
