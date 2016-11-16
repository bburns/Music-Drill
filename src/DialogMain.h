
// CDialogMain
//-----------------------------------------------------------------------------------------------------------------


#pragma once


#include "PageWelcome.h"
#include "PageNotes.h"
#include "PageRhythms.h"
#include "PagePitch.h"
#include "PageSymbols.h"
#include "PageProgress.h"
#include "PageAbout.h"



class CDialogMain : public CDialog
{
// Construction
public:
	CDialogMain(CWnd* pParent = NULL);   // standard constructor


private:
	HICON m_hIcon;

	CObArray m_aPages;
	CPageWelcome m_pgWelcome;
	CPageNotes m_pgNotes;
	CPageRhythms m_pgRhythms;
	CPagePitch m_pgPitch;
	CPageSymbols m_pgSymbols;
	CPageProgress m_pgProgress;
	CPageAbout m_pgAbout;
	UINT m_nPages;

// Dialog Data
	//{{AFX_DATA(CDialogMain)
	enum { IDD = IDD_MAIN };
	CTabCtrl	m_tbs;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogMain)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	virtual void OnOK();
	virtual void OnCancel();

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDialogMain)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnClose();
	afx_msg void OnSelchangeTbc(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



