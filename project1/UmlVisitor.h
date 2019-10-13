

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
	void VisitUMLPiece(CUMLPiece* piece) override { mIsUml = true; }

	void Reset() { mIsUml = false; }
	bool IsUML() { return mIsUml; }

private:
	bool mIsUml = false;
};

