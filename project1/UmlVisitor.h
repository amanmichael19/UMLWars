

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

	/// Resets the visitor after a uml piece was hit
	void Reset() { mIsUml = false; }

	/// Reports whether Uml was hit
	/// \return bool 
	bool IsUML() { return mIsUml; }

private:
	bool mIsUml = false;
};

