/**
 * \file Game.h
 *
 * \author Caleb Jenkins
 *
 * Class that implements a Game
 *
 *
 */

#pragma once
#include <vector>
#include <memory>
#include "GameObject.h"


class CGame
{
public:
	/// Game constructor
	CGame();

private:

	/// All of the gameobjects to populate our game
	std::vector<std::shared_ptr<CGameObject> > mGameObjects;
};

