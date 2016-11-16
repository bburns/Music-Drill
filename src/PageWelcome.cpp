
// CPageWelcome
//-----------------------------------------------------------------------------------------------------------------


#include "stdafx.h"
#include "music.h"
#include "PageWelcome.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



BEGIN_MESSAGE_MAP(CPageWelcome, CPage)
	//{{AFX_MSG_MAP(CPageWelcome)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CPageWelcome::CPageWelcome(CWnd* pParent /*=NULL*/)
	: CPage(CPageWelcome::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageWelcome)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CPageWelcome::DoDataExchange(CDataExchange* pDX)
{
	CPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageWelcome)
	DDX_Control(pDX, IDC_CBO_NAME, m_cboName);
	DDX_Control(pDX, IDC_LBL_WELCOME, m_lblWelcome);
	//}}AFX_DATA_MAP
}








int CPageWelcome::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CPage::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	
	return 0;
}
