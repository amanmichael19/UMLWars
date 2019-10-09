/**
 * \file UMLClass.h
 *
 * \author Daniel Anderson
 *
 * Class that describes a UMLPiece made up of a single class
 */


#pragma once
#include "UMLPiece.h"
#include "UMLDisplay.h"

/**
 * Class that describes a single class UMLPiece object
 */
class CUMLClass : public CUMLPiece
{
public:
	CUMLClass(CGame* game, double x, double y, int speed);
	void Draw(Gdiplus::Graphics* graphics) override;
	void SetDisplay(std::shared_ptr<CUMLDisplay> display);

private:
	std::shared_ptr<CUMLDisplay> mClassDisplay; ///< The CUMLDisplay object that displays this class
};

