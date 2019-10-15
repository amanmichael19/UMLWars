#pragma once
#include "GameObject.h"

class CCountDownTimer : public CGameObject
{
public:
	/// scroreboard constructor
	/// \param game
	CCountDownTimer(CGame* game);

	/// default constructor disabled
	CCountDownTimer() = delete;

	/// default copy constructor disabled
	CCountDownTimer(const CCountDownTimer&) = delete;

	virtual void Update(double elapsed) { mTimeLeft=mTimeTotal-(clock()-start)/1000; }

	/// draw
	/// \param graphics
	virtual void Draw(Gdiplus::Graphics* graphics);

	/// get reamining time
	int GetRemainingTime() { return mTimeLeft; }
private:
	int mTimeTotal = 60;
	int mTimeLeft = mTimeTotal;
	clock_t start = clock();
};

