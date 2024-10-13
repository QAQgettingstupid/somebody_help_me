
// sokoban2View.cpp : implementation of the Csokoban2View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "sokoban2.h"
#endif

#include "sokoban2Doc.h"
#include "sokoban2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Csokoban2View

IMPLEMENT_DYNCREATE(Csokoban2View, CView)

BEGIN_MESSAGE_MAP(Csokoban2View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// Csokoban2View construction/destruction

Csokoban2View::Csokoban2View() noexcept
{
	// TODO: add construction code here
	xlimit = 0;
	ylimit = 0;
	size = 30;
	round = 150;
	pass = 0;
	temp = 0;
	destination = 0;
}

Csokoban2View::~Csokoban2View()
{
}

BOOL Csokoban2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// Csokoban2View drawing

void Csokoban2View::OnDraw(CDC* pDC)
{
	Csokoban2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	
	test();
	
	
	
	// TODO: add draw code for native data here
}


// Csokoban2View printing

BOOL Csokoban2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void Csokoban2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void Csokoban2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// Csokoban2View diagnostics

#ifdef _DEBUG
void Csokoban2View::AssertValid() const
{
	CView::AssertValid();
}

void Csokoban2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Csokoban2Doc* Csokoban2View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Csokoban2Doc)));
	return (Csokoban2Doc*)m_pDocument;
}
#endif //_DEBUG


// Csokoban2View message handlers


void Csokoban2View::readmap(int n)
{
	// TODO: Add your implementation code here.
	memset(map, 'A', sizeof(map));
	TCHAR szDirectory[MAX_PATH];
	GetCurrentDirectory(MAX_PATH, szDirectory);
	CString folderPath(szDirectory);
	CString filePath;
	filePath.Format(L"%s\\map%03d.txt", folderPath, n);
	int x = 0, y = 0;
	CFile file;

	if (file.Open(filePath, NULL, NULL))
	{
		char ch;
		CString buf;

		while (file.Read(&ch, 1) == 1)
		{
			switch (ch) {
			case 'H':
				map[y][x] = ch;
				x++;
				break;
			case 'D':
				map[y][x] = ch;
				x++;
				pass++;
				destination++;
				break;
			case 'B':
				map[y][x] = ch;
				x++;
				break;
			case 'W':
				map[y][x] = ch;
				worker.x = x;
				worker.y = y;
				x++;
				break;
			case 'C':
				map[y][x] = ch;
				x++;
				destination++;
				break;
			case ' ':
				map[y][x] = ch;
				x++;
				break;
			case '\n':
				y++;
				if (x > xlimit)    xlimit = x;
				x = 0;
				break;
			}
		}
		file.Close();
	}
	ylimit = y;
	for (int i = 0; i <= ylimit; i++)
	{
		for (int j = 0; j <= xlimit; j++)
		{
			if (map[i][j] == 'A')    map[i][j] = ' ';
			if(j==(xlimit-1))   map[i][j + 1] = '\n';
		}
		
	}
}


void Csokoban2View::photo()
{
	// TODO: Add your implementation code here.
	int xnow = 0;
	int ynow = 0;

	CClientDC aDC(this);
	Csokoban2Doc* pDoc = GetDocument();
	CDC memDC;
	memDC.CreateCompatibleDC(&aDC);

	CBitmap HBitmap;
	HBitmap.LoadBitmap(IDB_BITMAP6);

	CBitmap DBitmap;
	DBitmap.LoadBitmap(IDB_BITMAP4);

	CBitmap BBitmap;
	BBitmap.LoadBitmap(IDB_BITMAP3);

	CBitmap WBitmap;
	WBitmap.LoadBitmap(IDB_BITMAP5);

	CBitmap cBitmap;
	cBitmap.LoadBitmap(IDB_BITMAP1);

	CBitmap aBitmap;
	aBitmap.LoadBitmap(IDB_BITMAP2);

	for (int i = 0; i <= ylimit; i++)
	{
		for (int j = 0; j <= xlimit; j++)
		{
			char ch = map[i][j];
			switch (ch) {
			case 'H':
				memDC.SelectObject(&HBitmap);
				aDC.BitBlt(xnow, ynow, xnow + size, ynow + size, &memDC, 0, 0, SRCCOPY);
				xnow += size;
				break;
			case 'D':
				memDC.SelectObject(&DBitmap);
				aDC.BitBlt(xnow, ynow, xnow + size, ynow + size, &memDC, 0, 0, SRCCOPY);
				xnow += size;
				break;
			case 'B':
				memDC.SelectObject(&BBitmap);
				aDC.BitBlt(xnow, ynow, xnow + size, ynow + size, &memDC, 0, 0, SRCCOPY);
				xnow += size;
				break;
			case 'W':
				memDC.SelectObject(&WBitmap);
				aDC.BitBlt(xnow, ynow, xnow + size, ynow + size, &memDC, 0, 0, SRCCOPY);
				xnow += size;
				break;
			case 'C':
				memDC.SelectObject(&cBitmap);
				aDC.BitBlt(xnow, ynow, xnow + size, ynow + size, &memDC, 0, 0, SRCCOPY);
				xnow += size;
				break;
			case ' ':
				memDC.SelectObject(&aBitmap);
				aDC.BitBlt(xnow, ynow, xnow + size, ynow + size, &memDC, 0, 0, SRCCOPY);
				xnow += size;
				break;
			case '\n':
				ynow += size;
				xnow = 0;
				break;
			}
		}
	}
	
}


void Csokoban2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
	
	if (nChar == 37)
	{
		if (map[worker.y ][worker.x - 1] != 'H')
		{
			if (map[worker.y ][worker.x - 1] == 'B')
			{
				if (map[worker.y ][worker.x - 2] == 'B' || map[worker.y][worker.x - 2] == 'H' || map[worker.y][worker.x - 2] == 'C');

				else
				{

					if (map[worker.y][worker.x - 2] == 'D')
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x - 1] = 'W';
						map[worker.y][worker.x - 2] = 'C';
						worker.x -= 1;
						pass--;
					}
					else
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x - 1] = 'W';
						map[worker.y ][worker.x - 2] = 'B';
						worker.x-= 1;
					}
				}
			}
			else if (map[worker.y][worker.x - 1] == 'D')
			{
				if (temp == 1)
				{
					map[worker.y][worker.x] = 'D';
					temp = 0;
				}
				else    map[worker.y][worker.x] = ' ';
				map[worker.y][worker.x - 1] = 'W';
				worker.x -= 1;

				temp = 1;
			}
			else if (map[worker.y][worker.x - 1] == 'C')
			{
				
				if (map[worker.y][worker.x - 2] == 'B' || map[worker.y][worker.x - 2] == 'H' || map[worker.y ][worker.x - 2] == 'C');

				else
				{
					if (map[worker.y ][worker.x - 2] == 'D')
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x - 1] = 'W';
						map[worker.y][worker.x - 2] = 'C';
						worker.x -= 1;
					}
					else
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x - 1] = 'W';
						map[worker.y][worker.x - 2] = 'B';
						worker.x -= 1;
						pass++;
					}
					temp = 1;
				}
				
			}

			else
			{
				if (temp == 1)
				{
					map[worker.y][worker.x] = 'D';
					temp = 0;
				}
				else    map[worker.y][worker.x] = ' ';
				map[worker.y][worker.x - 1] = 'W';
				worker.x -= 1;
			}
		}
		
	}
	if (nChar == 38) 
	{
		if (map[worker.y-1][worker.x] != 'H')
		{
			if (map[worker.y-1][worker.x] == 'B')
			{
				if (map[worker.y-2][worker.x] == 'B' || map[worker.y-2][worker.x ] == 'H' || map[worker.y-2][worker.x] == 'C');

				else
				{
					
					if (map[worker.y - 2][worker.x] == 'D')
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y-1][worker.x ] = 'W';
						map[worker.y-2][worker.x ] = 'C';
						worker.y -= 1;
						pass --;
					}
					else
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y - 1][worker.x] = 'W';
						map[worker.y - 2][worker.x] = 'B';
						worker.y -= 1;
					}
				}
			}
			else if (map[worker.y - 1][worker.x] == 'D')
			{
				if (temp == 1)
				{
					map[worker.y][worker.x] = 'D';
					temp = 0;
				}
				else    map[worker.y][worker.x] = ' ';
				map[worker.y-1][worker.x] = 'W';
				worker.y -= 1;

				temp = 1;
			}
			else if (map[worker.y - 1][worker.x] == 'C') 
			{
				
				if (map[worker.y - 2][worker.x] == 'B' || map[worker.y - 2][worker.x] == 'H' || map[worker.y - 2][worker.x] == 'C');
				
				else
				{
					if (map[worker.y - 2][worker.x] == 'D')
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y - 1][worker.x] = 'W';
						map[worker.y - 2][worker.x] = 'C';
						worker.y -= 1;
					}
					else
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y - 1][worker.x] = 'W';
						map[worker.y - 2][worker.x] = 'B';
						worker.y -= 1;
						pass++;
					}
					temp = 1;
				}
				
			}
		
			else
			{
				if (temp == 1)
				{
					map[worker.y][worker.x] = 'D';
					temp = 0;
				}
				else    map[worker.y][worker.x] = ' ';
				map[worker.y-1][worker.x] = 'W';
				worker.y -= 1;
			}
		}
	}
	if (nChar == 39) 
	{
		if (map[worker.y][worker.x + 1] != 'H')
		{
			if (map[worker.y][worker.x + 1] == 'B')
			{
				if (map[worker.y][worker.x + 2] == 'B' || map[worker.y][worker.x + 2] == 'H' || map[worker.y][worker.x + 2] == 'C');

				else
				{

					if (map[worker.y][worker.x + 2] == 'D')
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x + 1] = 'W';
						map[worker.y][worker.x + 2] = 'C';
						worker.x += 1;
						pass --;
					}
					else
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x + 1] = 'W';
						map[worker.y][worker.x + 2] = 'B';
						worker.x += 1;
					}
				}
			}
			else if (map[worker.y][worker.x + 1] == 'D')
			{
				if (temp == 1)
				{
					map[worker.y][worker.x] = 'D';
					temp = 0;
				}
				else    map[worker.y][worker.x] = ' ';
				map[worker.y][worker.x + 1] = 'W';
				worker.x += 1;

				temp = 1;
			}
			else if (map[worker.y][worker.x + 1] == 'C')
			{
				
				if (map[worker.y][worker.x + 2] == 'B' || map[worker.y][worker.x + 2] == 'H' || map[worker.y][worker.x + 2] == 'C');

				else
				{
					if (map[worker.y][worker.x + 2] == 'D')
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x + 1] = 'W';
						map[worker.y][worker.x + 2] = 'C';
						worker.x += 1;
					}
					else
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x + 1] = 'W';
						map[worker.y][worker.x + 2] = 'B';
						worker.x += 1;
						pass++;
					}
					temp = 1;
				}
				
			}

			else
			{
				if (temp == 1)
				{
					map[worker.y][worker.x] = 'D';
					temp = 0;
				}
				else    map[worker.y][worker.x] = ' ';
				map[worker.y][worker.x + 1] = 'W';
				worker.x += 1;
			}
		}

	}
	if (nChar == 40)
	{
		if (map[worker.y + 1][worker.x] != 'H')
		{
			if (map[worker.y + 1][worker.x] == 'B')
			{
				if (map[worker.y + 2][worker.x] == 'B' || map[worker.y + 2][worker.x] == 'H' || map[worker.y+2][worker.x] == 'C');

				else
				{

					if (map[worker.y + 2][worker.x] == 'D')
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y + 1][worker.x] = 'W';
						map[worker.y + 2][worker.x] = 'C';
						worker.y += 1;
						pass --;
					}
					else
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y][worker.x] = ' ';
						map[worker.y + 1][worker.x] = 'W';
						map[worker.y + 2][worker.x] = 'B';
						worker.y += 1;
					}
				}
			}
			else if (map[worker.y + 1][worker.x] == 'D')
			{
				if (temp == 1)
				{
					map[worker.y][worker.x] = 'D';
					temp = 0;
				}
				else    map[worker.y][worker.x] = ' ';
				map[worker.y + 1][worker.x] = 'W';
				worker.y += 1;

				temp = 1;
			}
			else if (map[worker.y + 1][worker.x] == 'C')
			{
				
				if (map[worker.y + 2][worker.x] == 'B' || map[worker.y + 2][worker.x] == 'H' || map[worker.y + 2][worker.x] == 'C');

				else
				{
					if (map[worker.y + 2][worker.x] == 'D')
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y + 1][worker.x] = 'W';
						map[worker.y + 2][worker.x] = 'C';
						worker.y += 1;
					}
					else
					{
						if (temp == 1)
						{
							map[worker.y][worker.x] = 'D';
							temp = 0;
						}
						else    map[worker.y][worker.x] = ' ';
						map[worker.y + 1][worker.x] = 'W';
						map[worker.y + 2][worker.x] = 'B';
						worker.y += 1;
						pass++;
					}
					temp = 1;
				}
				
			}

			else
			{
				if (temp == 1)
				{
					map[worker.y][worker.x] = 'D';
					temp = 0;
				}
				else    map[worker.y][worker.x] = ' ';
				map[worker.y + 1][worker.x] = 'W';
				worker.y += 1;
			}
		}
	}
	photo();

	CClientDC aDC(this);
	CString str2, text2;
	str2.Format(_T("%d"), destination-pass);
	text2.Format(L"arrival: %s", str2);
	aDC.TextOut(1500, 300, text2);


	if (pass == 0)
	{
		AfxMessageBox(L"PASS", MB_OK);
		round++; pass = 0;
		test();
	}
	
}


void Csokoban2View::test()
{
	pass = 0;
	temp = 0;
	readmap(round);
	CClientDC aDC(this);

	CString str, text;
	str.Format(_T("%d"), round);
	text.Format(L"Leval: %s", str);
	aDC.TextOut(1500, 200, text);

	CString str1, text1;
	str1.Format(_T("%d"), destination);
	text1.Format(L"destination: %s", str1);
	aDC.TextOut(1500, 250, text1);

	CString str2, text2;
	str2.Format(_T("%d"), destination - pass);
	text2.Format(L"arrival: %s", str2);
	aDC.TextOut(1500, 300, text2);

	photo();

	// TODO: Add your implementation code here.
}
