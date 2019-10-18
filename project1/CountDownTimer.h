/**
 * \file CountDownTimer.h
 *
 * \author Ziyuan Zhang
 *
 * 
 */

#pragma once
#include "Timer.h"
#include "Game.h"


class CCountDownTimer : public CTimer
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
};

