/**
 * \file RedPenVisitor.h
 *
 * \author Ziyuan Zhang
 *
 * 
 */

#pragma once
#include "GameObjectVisitor.h"
class CRedPenVisitor :
	public CGameObjectVisitor
{
public:
	void CRedPenVisitor::VisitPen(CRedPen* pen) override {


	}

	/// Report if object was a scoreboard
	/// \return bool
	bool IsPen() { return mIsPen; }

private:
	bool mIsPen = false; ///Boolean for IsScoreboard
	//CScoreBoard* mSB = nullptr;
};

