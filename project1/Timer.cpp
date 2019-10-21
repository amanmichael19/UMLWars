/**
 * \file Timer.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include "Timer.h"

CTimer::CTimer(CGame* game, double duratio) : CGameObject(game)
{
	SetUp(duratio);
}
