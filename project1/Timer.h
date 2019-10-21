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
	/// timer constructor
	/// \param game
	/// \param duration
	CTimer(CGame* game, double duration): CGameObject(game), mTimeTotal(duration), mTimeLeft(duration) {}

	/// default constructor disabled
	CTimer() = delete;

	/// default copy constructor disabled
	CTimer(const CTimer&) = delete;

	virtual void Update(double elapsed);

	virtual void Accept(CGameObjectVisitor* visitor) override {}

	virtual void Draw(Gdiplus::Graphics* graphics) {};

	/// set total time
	virtual void SetUp(double time) {
		mTimeLeft = time;
		mTimeTotal = time;
	}

	/// get reamining time
	virtual double GetRemainingTime() { return mTimeLeft; }

	/// get reamining time
	virtual bool IsTimeUp() { return mTimeLeft == 0.0; }

	virtual void Start() {
		mIsStart = true;
		mStart = clock();
	}

private:
	double mTimeTotal = 0;
	double mTimeLeft = 0;
	bool mIsStart = false;
	// initializing to remove warnings
	clock_t mStart = clock();
};
