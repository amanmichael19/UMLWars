/**
 * \file Timer.h
 *
 * \author Ziyuan Zhang
 *
 *
 */

#pragma once
#include <ctime>
#include "GameObject.h"

class CTimer : public CGameObject
{
public:
	/// timer constructor
	/// \param game
	CTimer(CGame* game, double duration): CGameObject(game), mTimeTotal(duration) {}

	/// default constructor disabled
	CTimer() = delete;

	/// default copy constructor disabled
	CTimer(const CTimer&) = delete;

	virtual void Update(double elapsed);

	virtual void Accept(CGameObjectVisitor* visitor) override {}

	virtual void Draw(Gdiplus::Graphics* graphics) {};

	/// set total time
	virtual void SetTotalTime(int time) { mTimeLeft = time;  mTimeTotal = time; mStart = clock(); }

	/// get reamining time
	virtual double GetRemainingTime() { return mTimeLeft; }

	/// is time up
	virtual bool IsTimeUp() { return mTimeLeft == 0; }

	virtual void StartTimer() { mIsStarted = true; }

	virtual void ResetTimer() { mTimeLeft = 60; }
	

private:
	double mTimeTotal = 60;
	double mTimeLeft = mTimeTotal;
	bool mIsStarted = false;
	/// initializing mStart 
	clock_t mStart = clock();
};

