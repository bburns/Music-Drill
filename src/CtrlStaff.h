

// CCtrlStaff
// This is a custom control that displays the treble and bass staffs with notes on it.
//-----------------------------------------------------------------------------------------------------------------




#pragma once



class CCtrlStaff : public CStatic
{
// Construction
public:
	CCtrlStaff();
	virtual ~CCtrlStaff();

public:
	void SetLevel(int nLevel);
	enum eDuration {durWhole, durHalf, durQuarter};
	enum eStaff {staffBoth, staffTreble, staffBass, staffC};

	void DisplayMessage(CString& strMessage);
	eStaff GetStaff();
	int GetNoteNumber();
	TCHAR GetNoteName();
	void RandomNote();
	void ShowNote(BOOL bShowNote);
	void ShowStaff(eStaff nStaff);
	void SetStaff(eStaff nStaff);
	void SetNoteNumber(int nNote);

private:
	void DrawNote(BOOL bStemUp, int nX, int nY, CDC* pDC);
	int m_nNote;
	eStaff m_nStaff;
	eStaff m_nStaffsShown;
	BOOL m_bShowNote;
	CString m_strMessage;
	CFont m_font;
	int m_nMessageHeight;
//	int m_nLedgerLines; // number of ledger lines to use in generating random note
	int m_nLevel; 


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCtrlStaff)
	//}}AFX_VIRTUAL

	// Generated message map functions
protected:
	//{{AFX_MSG(CCtrlStaff)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


