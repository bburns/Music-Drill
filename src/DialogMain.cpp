
// CDialogMain




#include "stdafx.h"
#include "music.h"
#include "DialogMain.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



BEGIN_MESSAGE_MAP(CDialogMain, CDialog)
	//{{AFX_MSG_MAP(CDialogMain)
	ON_BN_CLICKED(IDC_BTN_CLOSE, OnBtnClose)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TBC, OnSelchangeTbc)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CDialogMain::CDialogMain(CWnd* pParent /*=NULL*/)
	: CDialog(CDialogMain::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDialogMain)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}



BOOL CDialogMain::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// Create pages as children of the tab control
	m_pgWelcome.Create(IDD_PAGE_WELCOME, &m_tbs);
	m_pgNotes.Create(IDD_PAGE_NOTES, &m_tbs);
	m_pgRhythms.Create(IDD_PAGE_RHYTHM, &m_tbs);
	m_pgPitch.Create(IDD_PAGE_PITCH, &m_tbs);
	m_pgSymbols.Create(IDD_PAGE_SYMBOLS, &m_tbs);
	m_pgProgress.Create(IDD_PAGE_PROGRESS, &m_tbs);
	m_pgAbout.Create(IDD_PAGE_ABOUT, &m_tbs);

	// Add pages to array 
	m_aPages.Add(&m_pgWelcome);
	m_aPages.Add(&m_pgNotes);
	m_aPages.Add(&m_pgRhythms);
	m_aPages.Add(&m_pgPitch);
	m_aPages.Add(&m_pgSymbols);
	m_aPages.Add(&m_pgProgress);
	m_aPages.Add(&m_pgAbout);

	m_nPages = m_aPages.GetSize();

	// Add tabs 
	LPCTSTR pszTabNames[] = {"Welcome", "Notes", "Rhythms", "Pitch", "Symbols", "Progress", "About"}; 
	m_tbs.DeleteAllItems();
	for (UINT i = 0; i < m_nPages; i++)
	{
		m_tbs.InsertItem(i, pszTabNames[i]);
	}

	// Position pages
	CRect r;
	m_tbs.GetClientRect(&r);
	m_tbs.AdjustRect(FALSE, &r);
	for (int i = 0; i < m_nPages; i++)
	{
		CPage* pg = (CPage*) m_aPages.GetAt(i);
		pg->MoveWindow(&r);
	}

	// Show first tab pane
//	m_tbs.SetCurSel(0);
//	m_pgWelcome.ShowWindow(SW_SHOW);
	m_tbs.SetCurSel(1);
	m_pgNotes.ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void CDialogMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogMain)
	DDX_Control(pDX, IDC_TBC, m_tbs);
	//}}AFX_DATA_MAP
}


void CDialogMain::OnBtnClose() 
{
	// Destroy child windows
	for (UINT i = 0; i < m_nPages; i++)
	{
		CPage* pg = (CPage*) m_aPages.GetAt(i);
		pg->DestroyWindow();
	}

//	CDialog::EndDialog(0);

	// We call OnOK to safely close the application
	CDialog::OnOK();
}


// OnOK and OnCancel are declared here to prevent the CDialog functions from being called,
// thus preventing closing the dialog when clicking ENTER or ESC
//?
void CDialogMain::OnOK()
{
	CDialog::OnOK();
}
void CDialogMain::OnCancel()
{
	CDialog::OnOK();
}




void CDialogMain::OnSelchangeTbc(NMHDR* pNMHDR, LRESULT* pResult) 
{
	static int nLastTab = 1; //.

	// Show the page associated with the tab and hide the last displayed one
	int nTab = m_tbs.GetCurSel();
	CPage* pg = (CPage*) m_aPages.GetAt(nTab);
	pg->ShowWindow(SW_SHOW);
	pg = (CPage*) m_aPages.GetAt(nLastTab);
	pg->ShowWindow(SW_HIDE);
	nLastTab = nTab;

	*pResult = 0;
}



void CDialogMain::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// Exit if tab window not created yet
	if (m_tbs.m_hWnd == NULL)
		return;

	// Resize tabstrip
	CRect r;
	GetClientRect(&r);
	m_tbs.AdjustRect(FALSE, &r);
	m_tbs.MoveWindow(&r);

	//. Resize all pages also

}



