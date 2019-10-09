/**
 * \file UMLPiece.cpp
 *
 * \author Daniel Anderson
 */

#include "pch.h"
#include "UMLPiece.h"

CUMLPiece::CUMLPiece(CGame* game, double x, double y, int speed) : CGameObject(game)
{
	mDirection.push_back(x);
	mDirection.push_back(y);
	mSpeed = speed;
}
