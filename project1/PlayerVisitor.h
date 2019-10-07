/**
 * \file PlayerVisitor.h
 *
 * \author Amanuel
 *
 * 
 */


#pragma once
#include "GameObjectVisitor.h"

/**
 * class implementing player visitor
 */
class CPlayerVisitor : public CGameObjectVisitor
{
	public:
		/// visit player object
		/// \param player
		virtual void VisitPlayer(CPlayer* player) override {}
};

