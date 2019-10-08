/**
 * \file ScoreBoardVisitor.h
 *
 * \author Amanuel
 *
 * 
 */



#pragma once
#include "GameObjectVisitor.h"

/**
 * class implementing score board visitor
 */
class CScoreBoardVisitor : public CGameObjectVisitor
{
	public:
		virtual void VisitScoreBoard(CScoreBoard* scoreBoard) override {}
};

