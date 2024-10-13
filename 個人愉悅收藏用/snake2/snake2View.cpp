
// snake2View.cpp : implementation of the Csnake2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "snake2.h"
#endif

#include "snake2Doc.h"
#include "snake2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Csnake2View

IMPLEMENT_DYNCREATE(Csnake2View, CView)

BEGIN_MESSAGE_MAP(Csnake2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// Csnake2View construction/destruction

Csnake2View::Csnake2View() noexcept
{
	// TODO: add construction code here
	lastchar = 0;
	n = 1;
	for(int i = 0; i <=4; ++i)
	{
		a[i] = CPoint(100, 100);
	}
}

Csnake2View::~Csnake2View()
{
}

BOOL Csnake2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Csnake2View drawing

void Csnake2View::OnDraw(CDC* pDC)
{
	Csnake2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	

	
	WriteToScreen();
	
	// TODO: add draw code for native data here
}


// Csnake2View printing

BOOL Csnake2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Csnake2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Csnake2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Csnake2View diagnostics

#ifdef _DEBUG
void Csnake2View::AssertValid() const
{
	CView::AssertValid();
}

void Csnake2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csnake2Doc* Csnake2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csnake2Doc)));
	return (Csnake2Doc*)m_pDocument;
}
#endif //_DEBUG


// Csnake2View message handlers


void Csnake2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	CClientDC aDC(this);

	const int width = 100;
	

	if (n < 5) {
		if (nChar == 37)
		{
			a[n].x = a[n - 1].x - width;
			a[n].y = a[n - 1].y;
			n++;
			lastchar = 37;
		}
		if (nChar == 38) {
			a[n].y = a[n - 1].y - width;
			a[n].x = a[n - 1].x;
			n++;
			lastchar = 38;
		}
		if (nChar == 39) {
			a[n].x = a[n - 1].x + width;
			a[n].y = a[n - 1].y;
			n++;
			lastchar = 39;
		}
		if (nChar == 40) {
			a[n].y = a[n - 1].y + width;
			a[n].x = a[n - 1].x;
			n++;
			lastchar = 40;
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			a[i] = a[i + 1];
		}
		if (nChar == 37)
		{
			a[4].x = a[3].x - width;
			lastchar = 37;
		}
		if (nChar == 38) {
			a[4].y = a[3].y - width;
			lastchar = 38;
		}
		if (nChar == 39) {
			a[4].x = a[3].x + width;
			lastchar = 39;
		}
		if (nChar == 40) {
			a[4].y = a[3].y + width;
			lastchar = 40;
		}
	}

	if (nChar == 'T') { SetTimer(1, 500, NULL); }

	if (nChar == 'P') 
	{ 
		KillTimer(1);
		for (int i = 0; i <= 4; ++i)
	    {
			a[i] = CPoint(100, 100);
	    }
		lastchar = 0;
		n = 1;
	}
	Csnake2Doc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL);
	
	WriteToScreen();
	
}


void Csnake2View::WriteToScreen()
{
	// TODO: Add your implementation code here.

	CClientDC aDC(this);
	
	const int width = 100;
	CBrush aBrush(RGB(0, 255, 255));
	aDC.SelectObject(&aBrush);
	
	for (int i = 0; i <= 4; i++) {
		aDC.Rectangle(a[i].x, a[i].y,
			a[i].x + width, a[i].y + width);
		
	}
	
}


void Csnake2View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	
	const int width = 100;
	
	char t = lastchar;

	if (n < 5) {
		if (t == 37)
		{
			a[n].x = a[n - 1].x - width;
			a[n].y = a[n - 1].y;
			n++;
		}
		if (t == 38) {
			a[n].y = a[n - 1].y - width;
			a[n].x = a[n - 1].x;
			n++;
		}
		if (t == 39) {
			a[n].x = a[n - 1].x + width;
			a[n].y = a[n - 1].y;
			n++;
		}
		if (t == 40) {
			a[n].y = a[n - 1].y + width;
			a[n].x = a[n- 1].x;
			n++;
		}
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			a[i] = a[i + 1];
		}
		if (t == 37)
		{
			a[4].x = a[3].x - width;
		}
		if (t == 38) {
			a[4].y = a[3].y - width;
		}
		if (t == 39) {
			a[4].x = a[3].x + width;
		}
		if (t == 40) {
			a[4].y = a[3].y + width;
		}
	}
	Csnake2Doc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL);
	WriteToScreen();
	CView::OnTimer(nIDEvent);
	
}
