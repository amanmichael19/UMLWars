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

	/// draw
	/// \param graphics
	virtual void Draw(Gdiplus::Graphics* graphics);

private:
	int mTimeLeft = 60;
};

