
// snake2View.h : interface of the Csnake2View class
//

#pragma once


class Csnake2View : public CView
{
protected: // create from serialization only
	Csnake2View() noexcept;
	DECLARE_DYNCREATE(Csnake2View)

// Attributes
public:
	Csnake2Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~Csnake2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	CPoint a[6];
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	void WriteToScreen();
	int n;
	
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	char lastchar;
};

#ifndef _DEBUG  // debug version in snake2View.cpp
inline Csnake2Doc* Csnake2View::GetDocument() const
   { return reinterpret_cast<Csnake2Doc*>(m_pDocument); }
#endif

