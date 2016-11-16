
// CPageRhythms




#include "stdafx.h"
#include "music.h"
#include "PageRhythms.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




CPageRhythms::CPageRhythms(CWnd* pParent /*=NULL*/)
	: CPage(CPageRhythms::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageRhythms)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPageRhythms::DoDataExchange(CDataExchange* pDX)
{
	CPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageRhythms)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageRhythms, CPage)
	//{{AFX_MSG_MAP(CPageRhythms)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPageRhythms message handlers
