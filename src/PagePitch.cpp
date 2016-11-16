
// CPagePitch




#include "stdafx.h"
#include "music.h"
#include "PagePitch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif



BEGIN_MESSAGE_MAP(CPagePitch, CPage)
	//{{AFX_MSG_MAP(CPagePitch)
	ON_BN_CLICKED(IDC_BTN_PLAY, OnBtnPlay)
	ON_BN_CLICKED(IDC_BTN_PLAY2, OnBtnPlay2)
	ON_CBN_EDITCHANGE(IDC_CBO_TEST, OnEditchangeCboTest)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()





CPagePitch::CPagePitch(CWnd* pParent /*=NULL*/)
	: CPage(CPagePitch::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPagePitch)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}



BOOL CPagePitch::OnInitDialog() 
{
	CPage::OnInitDialog();

	// Fill combo with staff names
	m_cboTest.AddString("Intervals");
	m_cboTest.AddString("Chords");
	m_cboTest.AddString("Pitch");
	m_cboTest.SetCurSel(0);

	// intervals - play two notes and ask for interval (eg up 1/2 step, down 2 steps, etc)
	// or give them the name of the first note and ask for the second (eg C#)

	// chords - play a chord (# of notes depends on skill level)
	// ask user to identify it (eg minor triad, major 7th, etc.)
	// bonus - identify root note pitch

	// pitch - play a note and ask user to identify it (absolute pitch)




	// Fill levels
//	m_cboLevel.AddString("1 - Beginner");
//	m_cboLevel.AddString("2 - Intermediate");
//	m_cboLevel.AddString("3 - Advanced");
//	m_cboLevel.SetCurSel(0);

	// Set up the CLogTrace object
//	m_log.m_strAppName = "Music";
//	m_log.SetFileName("_Log.txt");
//	m_log.OnStartup(TRUE, FALSE);	

//	m_wndNotes.Init();

	// Start
//	OnBtnStart();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}




void CPagePitch::DoDataExchange(CDataExchange* pDX)
{
	CPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPagePitch)
	DDX_Control(pDX, IDC_CBO_TEST, m_cboTest);
	DDX_Control(pDX, IDC_LBL_NOTE, m_lblNote);
	//}}AFX_DATA_MAP
}



// Midi
//	const int nChars = 255;
//	TCHAR pszBuffer[nChars];
//	mciSendString("open new type sequencer alias anote", pszBuffer, nChars, NULL);
//	mciSendString("set anote time format milliseconds", pszBuffer, nChars, NULL);
//	mciSendString("play anote from 0 to 100 wait", pszBuffer, nChars, NULL);
//	mciSendString("close anote", pszBuffer, nChars, NULL);



// Play a random note
void CPagePitch::OnBtnPlay() 
{
	int nNote = rand() & 0x7f;

	CString str;
	str.Format("Note played: %d", nNote);
	m_lblNote.SetWindowText(str);

	theApp.PlayNote(nNote);
}



void CPagePitch::OnBtnPlay2() 
{
	theApp.PlayNote(60); // play middle c	
}




void CPagePitch::OnEditchangeCboTest() 
{
	
}

