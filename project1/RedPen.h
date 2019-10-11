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


 /**
  * class implementing player
  */
class CRedPen : public CGameObject
{
public:
	/// Default constructor
	CRedPen(CGame* game, std::shared_ptr<Gdiplus::Bitmap> penImage);

	/// Default constructor (disabled)
	CRedPen() = delete;

	/// default copy constructor disabled
	CRedPen(const CRedPen&) = delete;

	/// draw pen
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/// set angle
	void SetAngle(double angle) { mAngle = angle; }

	/// set Rotation
	void SetRotateBool(bool rotate) { mRotate = rotate; }

private:
	/// pen image
	std::shared_ptr<Gdiplus::Bitmap> mPenImage;
	/// angle of rotation
	double mAngle = 0.0;
	/// bool to dictate rotation
	bool mRotate = true;
};
















