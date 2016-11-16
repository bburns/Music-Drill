
// CCtrlStaff



#include "stdafx.h"
#include "Music.h"
#include "CtrlStaff.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




BEGIN_MESSAGE_MAP(CCtrlStaff, CStatic)
	//{{AFX_MSG_MAP(CCtrlStaff)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CCtrlStaff::CCtrlStaff()
{
	m_nStaff = staffBoth;
	m_nStaffsShown = staffBoth;
//	m_nLedgerLines = 0;
	m_nLevel = 0;
	m_nNote = 0;
	m_bShowNote = FALSE;
	m_nMessageHeight = 20;

	m_font.CreatePointFont(90, "Arial");

	// Seed the random-number generator with current time so that
	// the numbers will be different every time we run.
	srand((unsigned) time(NULL));
}


CCtrlStaff::~CCtrlStaff()
{
}



// Draw routines
//--------------------------------------------------------------------------------------------------------------

BOOL CCtrlStaff::OnEraseBkgnd(CDC* pDC) 
{
//	CRect r;
//	GetClientRect(&r);
//	COLORREF clrBackground = 0x00ffffff;
//	pDC->FillSolidRect(&r, clrBackground);
//	return TRUE; // painted the background - no further processing needed
//	return CStatic::OnEraseBkgnd(pDC);
	return FALSE;
}


void CCtrlStaff::OnPaint() 
{
	// Exit if show note is false
	if (!m_bShowNote) return;

	CRect rClient;
	GetClientRect(&rClient);

	// Do not call CStatic::OnPaint() for painting messages
//	CPaintDC dc(this); // device context for painting
	CPaintDC dcPaint(this); // device context for painting
	CMemDC dc(&dcPaint, &rClient);


	// Get window size
	CRect r;
	GetClientRect(&r);
	int nWindowWidth = r.right - r.left;
	int nWindowHeight = r.bottom - r.top;
	nWindowHeight -= m_nMessageHeight; // leave room for messages at bottom

	int nStartX = 0;
	int nStartY = 0;

	// Draw staff bitmap

	CBitmap bmp;
	if (bmp.LoadBitmap(IDB_STAFF))
	{
		// Get the size of the bitmap
		BITMAP bmpInfo;
		bmp.GetBitmap(&bmpInfo);

		// Create an in-memory DC compatible with the display DC we're using to paint
		CDC dcMemory;
		dcMemory.CreateCompatibleDC(&dc);

		// Select the bitmap into the in-memory DC
		CBitmap* pOldBitmap = dcMemory.SelectObject(&bmp);

		// Find a centerpoint for the bitmap in the client area
//		CRect rect;
//		GetClientRect(&rect);
//		nStartX = rect.left + (rect.Width() - bmpInfo.bmWidth) / 2;
//		nStartY = rect.top + (rect.Height() - bmpInfo.bmHeight) / 2;
		nStartX = (nWindowWidth - bmpInfo.bmWidth) / 2;
		nStartY = (nWindowHeight - bmpInfo.bmHeight) / 2;

		// Copy the bits from the in-memory DC into the on-screen DC to actually 
		// do the painting. Use the centerpoint we computed for the target offset.
		dc.BitBlt(nStartX, nStartY, bmpInfo.bmWidth, bmpInfo.bmHeight, &dcMemory, 0, 0, SRCCOPY);

		dcMemory.SelectObject(pOldBitmap);
	}


	int nLineHeight = 7;
	int nNoteHeight = nLineHeight;
	int nNoteWidth = (int) (nNoteHeight * 1.2f);
	int nLedgerWidth = nNoteWidth + 6;

	int nTrebleTop = nStartY + 20;
	int nBassTop = nStartY + 101;
	int nTrebleCenterY = nTrebleTop + 2 * nLineHeight;
	int nBassCenterY = nBassTop + 2 * nLineHeight;
	int nStaffCenterY = (m_nStaff == staffTreble) ? nTrebleCenterY : nBassCenterY;
	int nStaffCenterX = nStartX + 150;
//	int nMessageTop = nBassTop + nLineHeight * 6;
//	int nMessageBottom = nMessageTop + nLineHeight * 4;
	int nMessageTop = nWindowHeight;
	int nMessageBottom = nMessageTop + m_nMessageHeight;

	// Draw note
	int nNoteCenterY = nStaffCenterY - (m_nNote * nLineHeight) / 2;
	BOOL bStemUp = (m_nNote > 0) ? FALSE : TRUE;
	DrawNote(bStemUp, nStaffCenterX, nNoteCenterY, &dc);

	// Draw ledger lines if necessary 
	int nLedgerLines = (abs(m_nNote) - 4) / 2;
	if (nLedgerLines > 0)
	{
		int nLedgerLeft = nStaffCenterX - nLedgerWidth / 2;
		int nLedgerRight = nLedgerLeft + nLedgerWidth;
		int nDir = (m_nNote > 0) ? -1 : 1;
		for (int i = 0; i < nLedgerLines; i++)
		{
			int y = nStaffCenterY + nDir * (3 + i) * nLineHeight;
			dc.MoveTo(nLedgerLeft, y);
			dc.LineTo(nLedgerRight, y);
		}
	}
	
	// Draw message if there is one
	if (!m_strMessage.IsEmpty())
	{
		CFont* pOldFont = dc.SelectObject(&m_font);
		r.SetRect(0, nMessageTop, nWindowWidth, nMessageBottom);
		UINT nFormat = DT_CENTER + DT_VCENTER;
		dc.DrawText(m_strMessage, r, nFormat);
		dc.SelectObject(pOldFont);
	}

}



// Draw a note at the specified coordinates
// Note: Drawing a bitmap transparently is a pain in the ass, so use an icon!
// Specify stem up or down
void CCtrlStaff::DrawNote(BOOL bStemUp, int nX, int nY, CDC *pDC)
{
	int nNoteCenterX = bStemUp ? 14 : 17;
	int nNoteCenterY = bStemUp ? 25 : 6;
	UINT nIconID = bStemUp ? IDI_NOTE : IDI_NOTE_2;

	int nStartX = nX - nNoteCenterX;
	int nStartY = nY - nNoteCenterY;

	HICON hIcon = AfxGetApp()->LoadIcon(nIconID);
	pDC->DrawIcon(nStartX, nStartY, hIcon);

}







// Methods
//--------------------------------------------------------------------------------------------------------------


// Show the specified staff eg staffGrand
void CCtrlStaff::ShowStaff(eStaff nStaffToShow)
{
	m_nStaffsShown = nStaffToShow;
	
	// If treble or bass, set control to that staff
	if (nStaffToShow != staffBoth)
		m_nStaff = nStaffToShow;

	RedrawWindow();
}


// Set the current staff number, eg staffBass.
// Note this is different from ShowStaff.
void CCtrlStaff::SetStaff(eStaff nStaff)
{
	m_nStaff = nStaff;
}


// Set the current note number, where 0 is the center of the staff
void CCtrlStaff::SetNoteNumber(int nNote)
{
	m_nNote = nNote;

	// Make sure note is shown
	m_bShowNote = TRUE;

	RedrawWindow();
}


// Show a random note
void CCtrlStaff::RandomNote()
{
	// Select a random staff if both staffs are shown
	if (m_nStaffsShown == staffBoth)
		m_nStaff = (eStaff) ((rand() % 2) + 1); // 1 or 2 = treble or bass

	int nNote = m_nNote;
	if (m_nLevel == 0) // cdefg
	{
		int nC = (m_nStaff == staffBass) ? -1 : -6;
		while (nNote == m_nNote)
			nNote = nC + (rand() % 5);
	}
	else if (m_nLevel == 1) // gabcd
	{
		int nG = (m_nStaff == staffBass) ? -4 : -2;
		while (nNote == m_nNote)
			nNote = nG + (rand() % 5);
	}
	else // set number of ledger lines (for now)
	{
		int nLedgerLines = m_nLevel - 2;
		// Select a random note (make sure it's different from current note though)
		int nPossible = 11 + nLedgerLines * 4; // 11, 15, 19, 23, 27, 31
		int nHalf = (nPossible - 1) / 2; // 5, 7, 9, 11, 13, 15
		while (nNote == m_nNote)
			nNote = (rand() % nPossible) - nHalf;
	}

	m_nNote = nNote;

	// Make sure note is shown
	m_bShowNote = TRUE;

	// Refresh the window
	RedrawWindow();
}


// Show or hide the current note
void CCtrlStaff::ShowNote(BOOL bShowNote)
{
	m_bShowNote = bShowNote;
	RedrawWindow();
}


// Get the current staff number eg staffTreble
CCtrlStaff::eStaff CCtrlStaff::GetStaff()
{
	return m_nStaff;
}


// Get number of current note, with 0 being the middle of the staff.
int CCtrlStaff::GetNoteNumber()
{
	return m_nNote;
}


// Get name of current note eg "D"
TCHAR CCtrlStaff::GetNoteName()
{
	TCHAR c;
	// Get the note name based on the current staff and note number
	int nOffsetToA = (m_nStaff == staffTreble) ? 14 + 1 : 14 + 3;
	c = 'A' + ((m_nNote + nOffsetToA) % 7);
	return c;
}



// Display a message below the staffs
void CCtrlStaff::DisplayMessage(CString& strMessage)
{
	m_strMessage = strMessage;
	RedrawWindow();
}



void CCtrlStaff::SetLevel(int nLevel)
{
//	m_nLedgerLines = nLedgers;
	m_nLevel = nLevel;
}



