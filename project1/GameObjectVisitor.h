/**
 * \file GameObjectVisitor.h
 *
 * \author Amanuel
 *
 * 
 */


#pragma once

//forward reference game object types
class CPlayer;
class CPen;
class CUMLPiece;

/**
 * Class implementing game object visitor
 */
class CGameObjectVisitor
{
	public:
		virtual ~CGameObjectVisitor(){}

		/// visit player object
		/// \param player
		virtual void VisitPlayer(CPlayer* player){}

		/// visit pen object
		/// \param pen
		virtual void VisitPen(CPen* pen) {}

		/// visit uml piece
		/// \param umlPiece
		virtual void VisitUMLPiece(CUMLPiece* umlPiece) {}
};

