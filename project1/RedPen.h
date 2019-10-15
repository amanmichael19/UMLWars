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

const double PI = 3.141592653;

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
	void SetAngle(double angle) { mAngle = angle - mAngleOffset; }

	/// set Rotation
	void SetRotateBool(bool rotate) { mRotate = rotate; }

private:
	/// pen image
	std::shared_ptr<Gdiplus::Bitmap> mPenImage;
	/// angle of rotation
	double mAngle = -PI/2;
	///angle offset
	double mAngleOffset = PI / 2;
	/// bool to dictate rotation
	bool mRotate = true;
};
















