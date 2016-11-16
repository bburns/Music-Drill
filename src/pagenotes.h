
// CPageNotes
//-----------------------------------------------------------------------------------------------------------------



#pragma once


#include "CtrlNotes.h"
#include "CtrlStaff.h"
#include "LogTrace.h"
#include "Page.h"


class CPageNotes : public CPage
{
// Construction
public:
	CPageNotes(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPageNotes)
	enum { IDD = IDD_PAGE_NOTES };
	CComboBox	m_cboInput;
	CCtrlStaff	m_wndStaff;
	CCtrlNotes	m_wndNotes;
	CComboBox	m_cboLevel;
	CComboBox	m_cboStaff;
	CButton	m_chkLog;
	CButton	m_btnStop;
	CButton	m_btnStart;
	CButton	m_btnPause;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageNotes)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPageNotes)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnStart();
	afx_msg void OnBtnPause();
	afx_msg void OnBtnStop();
	afx_msg void OnSelChangeCboStaff();
	afx_msg void OnChkLog();
	afx_msg void OnSelchangeCboLevel();
	afx_msg void OnSelchangeCboInput();
	//}}AFX_MSG
	afx_msg LRESULT OnNoteClicked(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()

private:
	DWORD m_dwTime;
	CLogTrace m_log;
	BOOL m_bLog; // log to file on/off
};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
