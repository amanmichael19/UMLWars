#include "pch.h"
#include "PlayerVisitor.h"
#include "Player.h"

using namespace std;

void CPlayerVisitor::VisitPlayer(CPlayer* player)
{
	mIsPlayer = true;
	if (mShoot)
	{
		player->OnLeftClick(mMouseX, mMouseY);
	}
	else
	{
		player->OnMouseMove(mMouseX, mMouseY);
	}
}

void CPlayerVisitor::Reset()
{
	mIsPlayer = false;
}
