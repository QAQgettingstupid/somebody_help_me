
// sokoban2View.h : interface of the Csokoban2View class
//

#pragma once


class Csokoban2View : public CView
{
protected: // create from serialization only
	Csokoban2View() noexcept;
	DECLARE_DYNCREATE(Csokoban2View)

// Attributes
public:
	Csokoban2Doc* GetDocument() const;

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
	virtual ~Csokoban2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	void readmap(int n);
	void photo();
	int xlimit;
	char map[100][100];
	int round;
	int size;
	int ylimit;
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	CPoint worker;
	int pass;
	void test();
	int temp;
	int destination;
};

#ifndef _DEBUG  // debug version in sokoban2View.cpp
inline Csokoban2Doc* Csokoban2View::GetDocument() const
   { return reinterpret_cast<Csokoban2Doc*>(m_pDocument); }
#endif

