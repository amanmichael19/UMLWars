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
	void Fire(double xDirection, double yDirection) { mXDirection = xDirection; mYDirection = yDirection; mOnHand = false; }

	/// update time counter
	/// \param elapsed time
	virtual void Update(double elapsed) override;

private:
	/// pen image
	std::shared_ptr<Gdiplus::Bitmap> mPenImage;
	/// angle of rotation
	double mAngle = -PI / 2;
	///angle offset
	double mAngleOffset = PI / 2;
	/// bool to dictate rotation
	bool mOnHand = true;
	/// x direction
	double mXDirection = 0.0;
	/// y direction
	double mYDirection = 0.0;
	/// speed
	double mSpeed = 2.0;
};
















