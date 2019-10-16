#include "pch.h"
#include "UmlVisitor.h"

/** Tries to strike the piece
 */
bool CUmlVisitor::TryHit(int x, int y)
{
	if (mPiece->HitTest(x, y))
	{
		mPiece->DisplayHitMessage();
		return true;
	}
	return false;
}
