

/**
 * \file UmlVisitor.h
 *
 * \author Funakoshi Silva
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
	/// \param piece
	virtual void VisitUML(CUMLPiece* piece);
};

