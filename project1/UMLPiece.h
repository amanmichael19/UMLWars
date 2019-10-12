/**
 * \file UMLPiece.h
 *
 * \author Daniel Anderson
 *
 * Class that describes a single class of UML
 */

#pragma once
#include "GameObject.h"
#include <vector>
#include <string>
#include <memory>

/**
 * Class that descibes a single UML object on screen
 */
class CUMLPiece : public CGameObject
{
public:

	CUMLPiece(CGame* game, double x, double y, int speed);

	/// Setter for mBad
	/// \param bad The new value for mBad
	void SetBad(std::wstring bad) { mBad = bad; }

	/// Getter for mBad
	/// \returns The current vlaue of mBad
	std::wstring GetBad() { return mBad; }

	/// Draw this object
	/// \param graphics The graphics device this object is being drawn on
	virtual void Draw(Gdiplus::Graphics* graphics) {}

	virtual void Update(double elapsed);

	/// TODO: Hit Test

private:
	std::wstring mBad = L""; ///< The reason, if any, why this UMLPiece is bad
	double mXDirection; ///< The X direction this UMLPiece is moving
	double mYDirection; ///< The Y direction this UMLPiece is moving
	int mSpeed; ///< The speed at which this UMLPiece is moving
};

