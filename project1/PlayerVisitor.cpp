#include "pch.h"
#include "PlayerVisitor.h"
#include "Player.h"

void CPlayerVisitor::VisitPlayer(CPlayer* player)
{
	mIsPlayer = true;
	player->OnMouseMove(mMouseX, mMouseY);
}

void CPlayerVisitor::Reset()
{
	mIsPlayer = false;
}
