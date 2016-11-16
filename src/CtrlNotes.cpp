
// CCtrlNotes
//-----------------------------------------------------------------------------------------------------------------



#include "stdafx.h"
#include "music.h"
#include "CtrlNotes.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


BEGIN_MESSAGE_MAP(CCtrlNotes, CStatic)
	//{{AFX_MSG_MAP(CCtrlNotes)
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CCtrlNotes::CCtrlNotes()
{
	m_bRectsInitialized = FALSE;
//	m_arNoteNames.SetSize(m_nNotes, 10);
	m_clrBackground = RGB(255, 255, 255);
	m_clrBorder = RGB(192, 192, 192);
	m_clrPianoKeyBorder = 0x00808080;
	m_clrHighlight = RGB(170, 255, 30);
	m_clrFlash = RGB(100, 100, 220);
	m_clrBlackKey = 0x00404040;

	m_nCurrentNote = -1;
	m_nTimerID = 0;
	m_nTimerFlashID = 0;
	m_nTimerMs = 200;
	m_nTimerFlashMs = 80;
	m_nTimerFlashMax = 5;
	m_nTimerFlashes = 0;
	m_nMode = modeNames;
//	m_nMode = modePiano;

	m_penBorder.CreatePen(PS_SOLID, 1, m_clrBorder);
	m_penPianoKeyBorder.CreatePen(PS_SOLID, 1, m_clrPianoKeyBorder);
	m_brushNormal.CreateSolidBrush(m_clrBackground);
	m_brushHighlight.CreateSolidBrush(m_clrHighlight);
	m_brushFlash.CreateSolidBrush(m_clrFlash);
	m_brushBlackKey.CreateSolidBrush(m_clrBlackKey);

	m_nTextFormat = DT_SINGLELINE + DT_CENTER + DT_VCENTER;
	m_nNotes = 7;

//	m_hdcMem = 0;
}


CCtrlNotes::~CCtrlNotes()
{

}


BOOL CCtrlNotes::OnEraseBkgnd(CDC* pDC) 
{
//	CRect r;
//	GetClientRect(&r);
//	pDC->FillSolidRect(&r, m_clrBackground);
//	return TRUE; // painted the background - no further processing needed	
//	return CStatic::OnEraseBkgnd(pDC);
	return FALSE;
}



void CCtrlNotes::OnPaint() 
{
	switch (m_nMode)
	{
		case modeNames:
			DrawNames();
			break;
		case modePiano:
			DrawPiano();
			break;
//		case modeCello:
//			DrawCello();
//			break;
	}

	// Do not call CStatic::OnPaint() for painting messages
}



void CCtrlNotes::DrawNames()
{
	CRect rClient;
	GetClientRect(&rClient);

//	CPaintDC dc(this); // device context for painting
	CPaintDC dcPaint(this); // device context for painting
	CMemDC dc(&dcPaint, &rClient);

	if (m_bRectsInitialized == FALSE) 
//	if (m_arNames.GetSize() == 0)
		GetRects(0, 0);

	CRect r;
	TCHAR c[2];
	c[1] = 0;

	CBrush* pOldBrush = dc.SelectObject(&m_brushNormal);
   	CPen* pOldPen = dc.SelectObject(&m_penBorder);
	CFont* pOldFont = dc.SelectObject(&m_font);
	
	dc.SetBkMode(TRANSPARENT);
	
	// Draw rectangular areas for each note with letter inside
	for (int i = 0; i < m_nNotes; i++)
	{
		r = m_arNames.GetAt(i);

//		if (m_nTimerFlashes > 0)
//		{
//			if ((i == m_nFlashNote) && (m_nTimerFlashes & 1))
//				dc.SelectObject(&m_brushFlash);
//			else
//				dc.SelectObject(&m_brushNormal);
//		}
//		else
//		{
			// Highlight if current note
			if (i == m_nCurrentNote) 
				dc.SelectObject(&m_brushHighlight);
			else
				dc.SelectObject(&m_brushNormal);
//		}
		dc.Rectangle(&r); // Draw border and fill with current brush
		c[0] = 'A' + i;
		dc.DrawText((LPCTSTR) &c, &r, m_nTextFormat);
	}	
	
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldFont);
	dc.SelectObject(pOldPen);

}






void CCtrlNotes::OnSize(UINT nType, int cx, int cy) 
{
	CStatic::OnSize(nType, cx, cy);

	// Create offscreen bitmap for flicker-free drawing
//	m_hdcMem = CreateCompatibleDC(lpPS->hdc);
//	m_hdcMem = ::CreateCompatibleDC(NULL);


	switch (m_nMode)
	{
		case modeNames:
			GetRects(cx, cy);
			break;
		case modePiano:
			GetRects(cx, cy);
			break;
	}
}




// Get rectangles to use in drawing note names
void CCtrlNotes::GetRects(int cx, int cy)
{
	// Init array
	m_nNotes = 7;
	m_arNames.SetSize(m_nNotes, 10);

	// Get window size
	GetClientRect(&m_rClient);
	m_nWindowWidth = m_rClient.right - m_rClient.left;
	m_nWindowHeight = m_rClient.bottom - m_rClient.top;

	// Get array of rectangles for notes
	int nBoxWidth = m_nWindowWidth / m_nNotes;
//	int nBoxHeight = m_nWindowHeight;
	int nBoxHeight = nBoxWidth;
	int nBoxWidthMargin = (int) (nBoxWidth * 0.1f);
	int nBoxHeightMargin = (int) (nBoxHeight * 0.1f);
	int nBoxWidthInner = nBoxWidth - 2 * nBoxWidthMargin;
	int nBoxHeightInner = nBoxHeight - 2 * nBoxHeightMargin;

	// Create rectangular areas for each note
//	int nXStart = nBoxWidthMargin;
//	int nYStart = nBoxHeightMargin;
	int nXStart = (m_nWindowWidth - m_nNotes * nBoxWidth) / 2 + nBoxWidthMargin;
	int nYStart = (m_nWindowHeight - nBoxHeight) / 2 + nBoxHeightMargin;
	CRect r;
	for (int i = 0; i < m_nNotes; i++)
	{
		r.SetRect(nXStart, nYStart, nXStart + nBoxWidthInner, nYStart + nBoxHeightInner);
		nXStart += nBoxWidth;
		m_arNames.SetAt(i, r);
	}

	//. Get font for letters
	int nLetterHeight = (int) (nBoxHeightInner * 0.8f);
	m_font.DeleteObject();
//	m_font.CreatePointFont(160, "Times New Roman");
	m_font.CreatePointFont(180, "Times New Roman");

	m_bRectsInitialized = TRUE;
//	m_bNoteNameRectsInitialized = TRUE;

}




void CCtrlNotes::DrawPiano()
{
	CRect rClient;
	GetClientRect(&rClient);

//	CPaintDC dc(this); // device context for painting
	CPaintDC dcPaint(this); // device context for painting
	CMemDC dc(&dcPaint, &rClient);


/*
	// Create a compatible DC
    HDC hdcMem = ::CreateCompatibleDC(dc.m_hDC);
	// Create a bitmap big enough for our client rectangle
	HBITMAP hbmMem = ::CreateCompatibleBitmap(dc.m_hDC, m_nWindowWidth, m_nWindowHeight);
	// Select the bitmap into the off-screen DC.
	HBITMAP hbmOld = ::SelectObject(hdcMem, hbmMem);
	// Erase the background.
	HBRUSH hbrBkGnd = ::CreateSolidBrush(GetSysColor(COLOR_WINDOW));
	::FillRect(hdcMem, &rc, hbrBkGnd);
	::DeleteObject(hbrBkGnd);
	// draw to hdcMem
	// Blt the changes to the screen DC.
	BitBlt(lpPS->hdc, rc.left, rc.top, rc.right-rc.left, rc.bottom-rc.top, hdcMem, 0, 0, SRCCOPY);
	// Done with off-screen bitmap and DC.
	SelectObject(hdcMem, hbmOld);
	DeleteObject(hbmMem);
	DeleteDC(hdcMem);
*/




	if (m_bRectsInitialized == FALSE) 
//	if (m_arPiano.GetSize() == 0)
		GetPianoRects(0, 0);

	CRect r;
	TCHAR c[2];
	c[1] = 0;

	CBrush* pOldBrush = dc.SelectObject(&m_brushNormal);
   	CPen* pOldPen = dc.SelectObject(&m_penPianoKeyBorder);
	CFont* pOldFont = dc.SelectObject(&m_font);
	
	dc.SetBkMode(TRANSPARENT);
	
	// Draw rectangular areas for each note with letter inside
	for (int i = 0; i < m_nNotes; i++)
	{
		r = m_arPiano.GetAt(i);

//		if (m_nTimerFlashes > 0)
//		{
//			if ((i == m_nFlashNote) && (m_nTimerFlashes & 1))
//				dc.SelectObject(&m_brushFlash);
//			else
//				dc.SelectObject(&m_brushNormal);
//		}
//		else
//		{
			// Highlight if current note
			if (i == m_nCurrentNote) 
				dc.SelectObject(&m_brushHighlight);
			else
			{
				if (i < m_nNotesWhite)
					dc.SelectObject(&m_brushNormal);
				else
					dc.SelectObject(&m_brushBlackKey);
			}
//		}
		dc.Rectangle(&r); // Draw border and fill with current brush
	}	
	
	dc.SelectObject(pOldBrush);
	dc.SelectObject(pOldFont);
	dc.SelectObject(pOldPen);

}


// Get rectangles to use in drawing note names
void CCtrlNotes::GetPianoRects(int cx, int cy)
{
	// Init array
	int nOctaves = 4;
	int nNotesWhite = 7 * nOctaves;
	int nNotesBlack = 5 * nOctaves;
	m_nNotes = nNotesWhite + nNotesBlack;
	m_nNotesWhite = nNotesWhite;

	m_arPiano.SetSize(m_nNotes, 10);

	// Get window size
	GetClientRect(&m_rClient);
	m_nWindowWidth = m_rClient.right - m_rClient.left;
	m_nWindowHeight = m_rClient.bottom - m_rClient.top;

	// Get array of rectangles for notes
	float fBlackWidth = 0.6f;
	float fBlackHeight = 0.6f;
	int nMargin = 4;
	int nKeyWidth = m_nWindowWidth / nNotesWhite;
	int nKeyHeight = m_nWindowHeight - nMargin * 2;
	int nKeyWidthBlack = (int) (nKeyWidth * fBlackWidth);
	int nKeyHeightBlack = (int) (nKeyHeight * fBlackHeight);

	// Create rectangular areas for each note
	CRect r;

	// Get white notes
	int nXStart = (m_nWindowWidth - (nNotesWhite * nKeyWidth)) / 2 ;
	int nYStart = nMargin;
	for (int i = 0; i < nNotesWhite; i++)
	{
		r.SetRect(nXStart, nYStart, nXStart + nKeyWidth + 1, nYStart + nKeyHeight + 1);
		nXStart += nKeyWidth;
		m_arPiano.SetAt(i, r);
	}

	// Get black notes
	int nNote = nNotesWhite;
	double dPos[] = {0.8, 0.5, 0.3, 0.8, 0.3};
	for (i = 0; i < nOctaves; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int nWhiteNote = i * 7 + j + (j > 2 ? 1 : 0);
			r = m_arPiano.GetAt(nWhiteNote);
			double d = dPos[j];
			int nX = r.right - (int) (d * nKeyWidthBlack + .5);
			r.SetRect(nX, nYStart, nX + nKeyWidthBlack + 1, nYStart + nKeyHeightBlack + 1);
			m_arPiano.SetAt(nNote, r);
			nNote++;
		}
	}

	m_bRectsInitialized = TRUE;
}



void CCtrlNotes::OnMouseMove(UINT nFlags, CPoint point) 
{
	// Highlight note mouse is over

	switch (m_nMode)
	{
		case modeNames:
			{
				int nNote = (int) (7 * ((float) point.x / (float) m_nWindowWidth));
				if (nNote != m_nCurrentNote)
				{
					m_nCurrentNote = nNote;
					RedrawWindow();
				}
				break;
			}
		case modePiano:
			{
				CRect r;
				for (int i = m_nNotes - 1; i >=0; i--)
				{
					r = m_arPiano.GetAt(i);
					if (r.PtInRect(point))
					{
						m_nCurrentNote = i;
						RedrawWindow(NULL, NULL, RDW_INVALIDATE | RDW_NOERASE | RDW_UPDATENOW);
						break;
					}
				}
			}
			break;
	}
	CStatic::OnMouseMove(nFlags, point);
}




void CCtrlNotes::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// User clicked on a note
	int nNote = 0;
	switch (m_nMode)
	{
		case modeNames:
			nNote = (int) (7 * ((float) point.x / (float) m_nWindowWidth));
			break;
		case modePiano:
			if (m_nCurrentNote >= m_nNotesWhite)
			{
				nNote = -1; // ignore black for now
			}
			else
			{
				nNote = (m_nCurrentNote + 7 - 2) % 7 ;
//				theApp.PlayNote(60 + m_nCurrentNote - 11); // 60 = middle c
			}

			break;
	}

	// Raise event (send message to parent window)
	CWnd* pParent = GetParent();
	pParent->SendMessage(WM_NOTE_CLICKED, nNote);

	CStatic::OnLButtonDown(nFlags, point);
}




// Had to do this because OnCreate wasn't being called for some reason
void CCtrlNotes::Init()
{
	// Start timer
	m_nTimerID = SetTimer(1, m_nTimerMs, 0);
}


// See if mouse is still over control
void CCtrlNotes::OnTimer(UINT nIDEvent) 
{
//	if (nIDEvent == m_nTimerID)
//	{
		CPoint ptScreen(::GetMessagePos()); // Get position of message source
		CPoint ptClient = ptScreen;
		ScreenToClient(&ptClient);

		// If mouse is no longer over control, clear the highlight over the note
		if (!m_rClient.PtInRect(ptClient))
		{
			if (m_nCurrentNote != -1)
			{
				m_nCurrentNote = -1;
				RedrawWindow();
			}
		}
//	}
//	else if (nIDEvent == m_nTimerFlashID)
//	{
//		RedrawWindow();
//		m_nTimerFlashes--;
//		if (m_nTimerFlashes == 0)
//			KillTimer(m_nTimerFlashID);
//	}

	// Call base class
	CStatic::OnTimer(nIDEvent);
}





void CCtrlNotes::FlashNote(int nNote)
{
//	m_nFlashNote = nNote;
//	m_nTimerFlashes = m_nTimerFlashMax;
//	m_nTimerFlashID = SetTimer(2, m_nTimerFlashMs, 0);
}



void CCtrlNotes::OnDestroy() 
{
	CStatic::OnDestroy();
	
	if (m_nTimerID)
		KillTimer(m_nTimerID);
//	if (m_nTimerFlashID)
//		KillTimer(m_nTimerFlashID);
}





void CCtrlNotes::SetMode(int nMode)
{
	m_nMode = nMode;
	m_bRectsInitialized = FALSE;
	RedrawWindow();
}


