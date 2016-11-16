
// CPageSymbols



#include "stdafx.h"
#include "music.h"
#include "PageSymbols.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



BEGIN_MESSAGE_MAP(CPageSymbols, CPage)
	//{{AFX_MSG_MAP(CPageSymbols)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CPageSymbols::CPageSymbols(CWnd* pParent /*=NULL*/)
	: CPage(CPageSymbols::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageSymbols)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPageSymbols::DoDataExchange(CDataExchange* pDX)
{
	CPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageSymbols)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}



