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

	/// Allows adding CGameObjects
	void Add(std::shared_ptr<CGameObject> gob);

	std::shared_ptr<CGameObject> CGame::HitTest(int x, int y);

private:

	/// All of the gameobjects to populate our game
	std::vector<std::shared_ptr<CGameObject> > mGameObjects;
};

