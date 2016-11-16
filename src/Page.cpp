
// CPage




#include "stdafx.h"
#include "music.h"
#include "Page.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif





CPage::CPage(UINT nID, CWnd* pParent /*=NULL*/)
//	: CDialog(CPage::IDD, pParent)
	: CDialog(nID, pParent)
{
	//{{AFX_DATA_INIT(CPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPage, CDialog)
	//{{AFX_MSG_MAP(CPage)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPage message handlers
