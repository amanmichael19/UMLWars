/**
 * \file UMLStruck.h
 *
 * \author Ziyuan Zhang
 *
 * 
 */

#pragma once
#include "GameObject.h"
#include <string>


class CUMLStruck : public CGameObject
{
public:
	/// scroreboard constructor
	/// \param game
	CUMLStruck(CGame* game, std::wstring msg): CGameObject(game), mMsg(msg) {}

	/// default constructor disabled
	CUMLStruck() = delete;

	/// default copy constructor disabled
	CUMLStruck(const CUMLStruck&) = delete;

	/// accepts visitor
	virtual void Accept(CGameObjectVisitor* visitor) override {}

	/// draw
	/// \param graphics
	virtual void Draw(Gdiplus::Graphics* graphics);

private:
	double mX = 0;
	double mY = 0;
	std::wstring mMsg;
};

