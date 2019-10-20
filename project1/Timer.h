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
	CTimer(CGame* game);

	/// default constructor disabled
	CTimer() = delete;

	/// default copy constructor disabled
	CTimer(const CTimer&) = delete;

	virtual void Update(double elapsed);

	virtual void Accept(CGameObjectVisitor* visitor) override {}

	virtual void Draw(Gdiplus::Graphics* graphics) {};

	/// set total time
	virtual void SetTotalTime(int time) { mTimeLeft = time;  mTimeTotal = time; mStart = clock();}

	/// get reamining time
	virtual int GetRemainingTime() { return mTimeLeft; }

	/// get reamining time
	virtual int IsTimeUp() { return mTimeLeft == 0; }

	virtual void SetIsUpdate(bool is) { 
		mIsUpdate = is; 
		if (is == false) { mTimeLeft = 60; }
	}

private:
	double mTimeTotal = 60;
	double mTimeLeft = mTimeTotal;
	bool mIsUpdate = false;
	clock_t mStart;
};

