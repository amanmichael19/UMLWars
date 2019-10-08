/**
 * \file Player.h
 *
 * \author Funakoshi Silva
 *
 *
 */


#pragma once
#include "GameObject.h"
#include <memory>
#include <string>
#include <vector>


 /**
  * class implementing player
  */
class CRedPen : public CGameObject
{
public:
	/// Default constructor
	CRedPen(CGame* game);

	void OnDraw(Gdiplus::Graphics* graphics);

	/// Default constructor (disabled)
	CRedPen() = delete;

	//virtual void Draw(Gdiplus::Graphics* graphics);

private:
	std::unique_ptr<Gdiplus::Bitmap> mPenImage;

	//similar idea could be used
	// All of the items to populate our aquarium
	//std::vector<std::shared_ptr<CGameObject> > mItems;
};















