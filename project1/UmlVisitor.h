

/**
 * \file UmlVisitor.h
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
class CUmlVisitor : public CGameObjectVisitor
{
public:
	/// visit UML object
	/// \param player
	virtual void VisitUML(CUMLPiece* piece);
};

