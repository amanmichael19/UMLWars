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
class CRedPen;
class CUMLPiece;
class CScoreBoard;
class CCountDownTimer;

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
		virtual void VisitPen(CRedPen* pen) {}

		/// visit uml piece
		/// \param umlPiece
		virtual void VisitUMLPiece(CUMLPiece* umlPiece) {}

		/// visit score board
		/// \param scoreboard
		virtual void VisitScoreBoard(CScoreBoard* scoreBoard) {}


};

