
// CPageProgress
//-----------------------------------------------------------------------------------------------------------------


#include "stdafx.h"
#include "music.h"
#include "PageProgress.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



BEGIN_MESSAGE_MAP(CPageProgress, CPage)
	//{{AFX_MSG_MAP(CPageProgress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CPageProgress::CPageProgress(CWnd* pParent /*=NULL*/)
	: CPage(CPageProgress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageProgress)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPageProgress::DoDataExchange(CDataExchange* pDX)
{
	CPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageProgress)
	//}}AFX_DATA_MAP
}









