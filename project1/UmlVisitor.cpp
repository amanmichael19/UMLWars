/**
 * \file UmlVisitor.cpp
 *
 * \author Ziyuan Zhang
 */

#include "pch.h"
#include "UmlVisitor.h"

using namespace std;


/** Tries to strike the piece
 */
bool CUmlVisitor::TryHit(int x, int y)
{
	if (mPiece->HitTest(x, y) && !mPiece->GetWasHit())
	{
		mPiece->SetWasHit();
		mPiece->DisplayHitMessage();
		return true;
	}
	return false;
}

void CUmlVisitor::VisitUMLPiece(CUMLPiece* piece)
{
	mIsUml = true;
	mPiece = piece;
	mBad = (L"" != mPiece->GetBad());
}
