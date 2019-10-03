/**
 * \file ChildView.h
 *
 * \author Daniel Anderson
 *
 * Class that displays the program window
 */


// ChildView.h : interface of the CChildView class
//


#pragma once


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
protected:
	afx_msg void OnPaint();
	DECLARE_MESSAGE_MAP()
};

