
// sokoban2.h : main header file for the sokoban2 application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Csokoban2App:
// See sokoban2.cpp for the implementation of this class
//

class Csokoban2App : public CWinApp
{
public:
	Csokoban2App() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Csokoban2App theApp;
