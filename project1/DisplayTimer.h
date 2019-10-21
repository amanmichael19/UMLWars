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


class CDisplayTimer : public CTimer
{
public:
	/// Display timer constructor
	/// \param game
	CDisplayTimer(CGame* game);

	/// default constructor disabled
	CDisplayTimer() = delete;

	/// default copy constructor disabled
	CDisplayTimer(const CDisplayTimer&) = delete;

	/// draw
	/// \param graphics
	virtual void Draw(Gdiplus::Graphics* graphics);

	virtual void Update(double elapsed);

	virtual void Accept(CGameObjectVisitor* visitor) override {}
};

