
// CPagePitch


#pragma once


#include "Page.h"



class CPagePitch : public CPage
{
// Construction
public:
	CPagePitch(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPagePitch)
	enum { IDD = IDD_PAGE_PITCH };
	CComboBox	m_cboTest;
	CStatic	m_lblNote;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPagePitch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPagePitch)
	virtual BOOL OnInitDialog();
	afx_msg void OnBtnPlay();
	afx_msg void OnBtnPlay2();
	afx_msg void OnEditchangeCboTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

