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
		///constructor
		/// \param mouseX
		/// \param mouseY
		CPlayerVisitor(double mouseX, double mouseY, bool shoot) { mMouseX = mouseX; mMouseY = mouseY; mShoot = shoot; }
		/// visit player object
		/// \param player
		virtual void VisitPlayer(CPlayer* player) override;

		/// reset the boolean
		void Reset();

		/// check if it is player
		/// \return bool
		bool IsPlayer() { return mIsPlayer; }

	private:
		/// memeber bool true if player visited
		bool mIsPlayer = false;
		/// mouse x
		double mMouseX = 0.0;
		/// mouse y
		double mMouseY = 0.0;
		/// shoot or rotate
		bool mShoot = false;
};

