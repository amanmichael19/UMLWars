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

class CGame;
class CGameObjectVisitor;

/**
 * GameObject class to hold various game objects
 */

class CGameObject
{
public:

	/// Creates all objects in the game
	CGameObject(CGame* game);

public:

	/// Default constructor (disabled)
	CGameObject() = delete;

	/// Copy constructor (disabled)
	CGameObject(const CGameObject&) = delete;

	


	/** The X location of the item
	 * \returns X location in pixels
	 */
	double GetX() const { return mX; }

	/** The Y location of the item
	 * \returns Y location in pixels
	 */
	double GetY() const { return mY; }

	/// Set the object location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Set the object dimensions
	/// \param x width
	/// \param y height
	virtual void SetDimensions(double wid, double hit) { mWidth = wid; mHeight = hit; }

	/** The Width of the item
	 * \returns double of Width 
	 */
	double GetWidth() const { return mWidth; }

	/** The height of the item
	 * \returns double of height
	 */
	double GetHeight() const { return mHeight; }

	bool HitTest(int x, int y);

	/** Accept a visitor
	* \param visitor
	*/
	virtual void Accept(CGameObjectVisitor* visitor) {};

private:

	//GameObject location and center of object
	double mX = 0; ///< X location of object
	double mY = 0; ///< Y location of object

	//GameObject dimensions
	double mWidth = 0; ///< Width of object
	double mHeight = 0; ///< Height of object

	/// The Game for this object
	CGame* mGame;
};

