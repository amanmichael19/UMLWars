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
	CUMLStruck(CGame* game);

	/// default constructor disabled
	CUMLStruck() = delete;

	/// default copy constructor disabled
	CUMLStruck(const CUMLStruck&) = delete;

	/// accepts visitor
	virtual void Accept(CGameObjectVisitor* visitor) override {}

	/// draw
	/// \param graphics
	virtual void Draw(Gdiplus::Graphics* graphics);

	/// draw
	/// \param graphics
	void Set(int x, int y, std::wstring msg);
private:
	int mX = 0;
	int mY = 0;
	std::wstring mMsg;
};

