/**
 * \file ChildView.h
 *
 * \author Ziyuan Zhang
 *
 * Class that displays the program window
 */


// ChildView.h : interface of the CChildView class
//


#pragma once
#include "Game.h"


// CChildView window

/**
 * Class that displays the program window
 */
class CChildView : public CWnd
{
// Construction
public:
	CChildView();

// Attributes
public:

// Operations
public:

// Overrides
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// Implementation
public:
	virtual ~CChildView();

	// Generated message map functions

private:
	/// An object that is the Game
	CGame mGame;


protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()


public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

