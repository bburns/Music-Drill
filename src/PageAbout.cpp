
// CPageAbout



#include "stdafx.h"
#include "music.h"
#include "PageAbout.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



CPageAbout::CPageAbout(CWnd* pParent /*=NULL*/)
	: CPage(CPageAbout::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageAbout)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPageAbout::DoDataExchange(CDataExchange* pDX)
{
	CPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageAbout)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPageAbout, CPage)
	//{{AFX_MSG_MAP(CPageAbout)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



