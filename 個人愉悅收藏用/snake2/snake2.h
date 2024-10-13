
// snake2.h : main header file for the snake2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Csnake2App:
// See snake2.cpp for the implementation of this class
//

class Csnake2App : public CWinApp
{
public:
	Csnake2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Csnake2App theApp;
