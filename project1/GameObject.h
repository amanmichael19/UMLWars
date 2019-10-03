/**
 * \file GameObject.h
 *
 * \author Caleb Jenkins
 *
 * Class that implements a GameObject
 *
 *
 */

#pragma once
class CGameObject
{
public:



	/** The X location of the item
	 * \returns X location in pixels
	 */
	double GetX() const { return mX; }

	/** The Y location of the item
	 * \returns Y location in pixels
	 */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }


private:

	//GameObject location 
	double mX = 0; ///< X location of object
	double mY = 0; ///< Y location of object
};

