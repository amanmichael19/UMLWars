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
	bool IsPen() { return mBoard; }

private:
	bool mBoard = false; ///Boolean for IsScoreboard
	long TinyTimer;
	//CScoreBoard* mSB = nullptr;
};

