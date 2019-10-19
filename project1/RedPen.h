/**
 * \file Player.h
 *
 * \author Funakoshi Silva
 *
 *
 */


#pragma once
#include "GameObject.h"
#include "Game.h"
#include <memory>

const double PI = 3.141592653;

 /**
  * class implementing player
  */
class CRedPen : public CGameObject
{
public:
	/// Default constructor
	CRedPen(CGame* game, double xLocation, double yLocation);

	/// Default constructor (disabled)
	CRedPen() = delete;

	/// default copy constructor disabled
	CRedPen(const CRedPen&) = delete;

	/// draw pen
	virtual void Draw(Gdiplus::Graphics* graphics) override;

	/// set angle
	void SetAngle(double angle) { mAngleOfMovement = angle; mAngleOfRotation = angle - mAngleOffset; }

	/// set Rotation
	void FirePen(double xDirection, double yDirection);
	/// reload
	//void ReLoad();

	/// update time counter
	/// \param elapsed time
	virtual void Update(double elapsed) override;
	/// follow player hand
	void TrackHand();
	/// on mouse move
	void OnMouseMove(double angle);

	/// set location of the red pen
	/// \param x
	/// \param y
	void SetLocation(double x, double y) override;

	virtual void Accept(CGameObjectVisitor* visitor) override { visitor->VisitPen(this); }



private:
	/// pen image
	std::shared_ptr<Gdiplus::Bitmap> mPenImage;
	/// angle of rotation
	double mAngleOfRotation = -PI / 2;
	///angle offset
	double mAngleOffset = PI/2;
	/// angle of movement
	double mAngleOfMovement = 0.0;
	/// angle of pen after being fired
	double mAngleOnAir = 0.0;
	/// bool to dictate rotation
	bool mOnHand = true;
	/// initial load x location
	double mLoadX = 0.0;
	/// initial load y location
	double mLoadY = 0.0;
	/// the x center of the player to be used as origin for pen
	double mXOrigin = 0.0;
	/// the y center of the player to be used as origin for pen
	double mYOrigin = 0.0;
	/// offset x from player image center
	const double mXOffset = 29.0;
	/// offset y from player image center
	const double mYOffset = 54.0;
	/// x direction
	double mXDirection = 0.0;
	/// y direction
	double mYDirection = 0.0;
	/// speed
	double mSpeed = 300.0;
};
















