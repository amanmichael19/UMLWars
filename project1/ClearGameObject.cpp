/**
 * \file ClearGameObject.cpp
 *
 * \author Funakoshi Silva
 */

#include "pch.h"
#include "ClearGameObject.h"
#include "Game.h"
#include "UMLPiece.h"

CClearGameObject::CClearGameObject(CGame* game):CGameObject(game)
{
}

void CClearGameObject::clear(CUMLPiece m, CGame* game)

{	// Using function from UMLPiece
	// to check if UML Pice left the screen
	// if then it is true,
	// will erase game object

	if (m.LeaveScreenCheck() == TRUE) {

		// this will need improvements
		delete game;
	}


}
