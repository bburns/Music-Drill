

// CCtrlNotes
// This is a custom control that displays a list of the note names for the user to click on.
//-----------------------------------------------------------------------------------------------------------------




#pragma once



//const int m_nNotes = 7;
const int m_nOctaves = 2;

// Note: Using WM_USER causes problems because some controls use these messages - use WM_APP instead!
//const int WM_NOTE_CLICKED = WM_USER + 0;
#define WM_NOTE_CLICKED WM_APP + 0



class CCtrlNotes : public CStatic
{
// Construction
public:
	CCtrlNotes();
	virtual ~CCtrlNotes();

public:
	void SetMode(int nMode);
	void FlashNote(int nNote);
	void Init();

private:
	void GetRects(int cx, int cy);
	void DrawNames();
	void DrawPiano();
//	void DrawCello();
	void GetPianoRects(int cx, int cy);


	CArray <CRect, CRect&> m_arNames;
	CArray <CRect, CRect&> m_arPiano;
	BOOL m_bRectsInitialized;

	int m_nNotes;
	int m_nNotesWhite;

	CFont m_font;
	int m_nWindowWidth;
	int m_nWindowHeight;
	int m_nCurrentNote;
	COLORREF m_clrBackground;
	COLORREF m_clrBorder;
	COLORREF m_clrHighlight;
	COLORREF m_clrFlash;
	COLORREF m_clrPianoKeyBorder;
	COLORREF m_clrBlackKey;

	CRect m_rClient;
	UINT m_nTimerID;
	UINT m_nTimerMs;
	UINT m_nTimerFlashID;
	UINT m_nTimerFlashMs;
	UINT m_nTimerFlashMax;
	UINT m_nTimerFlashes;
	int m_nFlashNote;
	int m_nMode; // type of control to draw: note names, piano keyboard, cello fretboard, etc.

	CPen m_penBorder;
	CPen m_penPianoKeyBorder;
	CBrush m_brushNormal;
	CBrush m_brushHighlight;
	CBrush m_brushFlash;
	CBrush m_brushBlackKey;
	UINT m_nTextFormat;

	enum eModes {modeNames, modePiano, modeCello};

//	HDC m_hdcMem;
//	CDC m_dcMem;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtrlNotes)
	public:
	protected:
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CCtrlNotes)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


