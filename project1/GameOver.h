

#pragma once
#include "GameObject.h"
#include "DisplayTimer.h"
#include <memory>
#include <string>



class CGameOver : public CGameObject
{

	/// constructor
	/// \param game
	CGameOver(CGame* game);

	/// default constructor disabled
	CGameOver() = delete;

	/// default copy constructor disabled
	CGameOver(const CGameOver&) = delete;


	void clear(CDisplayTimer t, CGame* game);

private:
	
		int mcheck = 55;
};

