
// CPageNotes




#include "stdafx.h"
#include "Music.h"
#include "PageNotes.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif





BEGIN_MESSAGE_MAP(CPageNotes, CPage)
	//{{AFX_MSG_MAP(CPageNotes)
	ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
	ON_BN_CLICKED(IDC_BTN_PAUSE, OnBtnPause)
	ON_BN_CLICKED(IDC_BTN_STOP, OnBtnStop)
	ON_CBN_SELCHANGE(IDC_CBO_STAFF, OnSelChangeCboStaff)
	ON_BN_CLICKED(IDC_CHK_LOG, OnChkLog)
	ON_CBN_SELCHANGE(IDC_CBO_LEVEL, OnSelchangeCboLevel)
	ON_MESSAGE(WM_NOTE_CLICKED, OnNoteClicked)
	ON_CBN_SELCHANGE(IDC_CBO_INPUT, OnSelchangeCboInput)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



CPageNotes::CPageNotes(CWnd* pParent /*=NULL*/)
	: CPage(CPageNotes::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPageNotes)
	//}}AFX_DATA_INIT
	m_bLog = FALSE;
}




BOOL CPageNotes::OnInitDialog() 
{
	CPage::OnInitDialog();

	// Fill combo with staff names
	m_cboStaff.AddString("Treble and Bass");
	m_cboStaff.AddString("Treble");
	m_cboStaff.AddString("Bass");
//	m_cboStaff.AddString("C Cleff (eg for cello)");
//	m_cboStaff.SetCurSel(0);
	m_cboStaff.SetCurSel(1);
	OnSelChangeCboStaff();

	// Fill levels
//	m_cboLevel.AddString("1 - Beginner");
//	m_cboLevel.AddString("2 - Intermediate");
//	m_cboLevel.AddString("3 - Advanced");
	m_cboLevel.AddString("Level 1: CDEFG"); //.
	m_cboLevel.AddString("Level 2: GABCD"); //.
	m_cboLevel.AddString("No Ledger Lines");
	m_cboLevel.AddString("1 Ledger Line");
	m_cboLevel.AddString("2 Ledger Lines");
	m_cboLevel.AddString("3 Ledger Lines");
	m_cboLevel.AddString("4 Ledger Lines");
	m_cboLevel.AddString("5 Ledger Lines");
	m_cboLevel.SetCurSel(0);
//	m_cboLevel.SetCurSel(6);
	OnSelchangeCboLevel();

	m_cboInput.AddString("Names");
	m_cboInput.AddString("Piano");
	m_cboInput.SetCurSel(0);

	// Set up the CLogTrace object
	m_log.m_strAppName = "Music";
	m_log.SetFileName("_Log.txt");
	m_log.OnStartup(TRUE, FALSE);	


	m_wndNotes.Init();

	// Start
	OnBtnStart();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CPageNotes::DoDataExchange(CDataExchange* pDX)
{
	CPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPageNotes)
	DDX_Control(pDX, IDC_CBO_INPUT, m_cboInput);
	DDX_Control(pDX, IDC_PIC_STAFF, m_wndStaff);
	DDX_Control(pDX, IDC_PIC_NOTES, m_wndNotes);
	DDX_Control(pDX, IDC_CBO_LEVEL, m_cboLevel);
	DDX_Control(pDX, IDC_CBO_STAFF, m_cboStaff);
	DDX_Control(pDX, IDC_CHK_LOG, m_chkLog);
	DDX_Control(pDX, IDC_BTN_STOP, m_btnStop);
	DDX_Control(pDX, IDC_BTN_START, m_btnStart);
	DDX_Control(pDX, IDC_BTN_PAUSE, m_btnPause);
	//}}AFX_DATA_MAP
}




void CPageNotes::OnBtnStart() 
{
	// Show a random note
	m_wndStaff.RandomNote();

	// Save time
	m_dwTime = ::GetTickCount();
}


void CPageNotes::OnBtnPause() 
{
}

void CPageNotes::OnBtnStop() 
{
}



// User chose treble, bass or both staffs - tell control
void CPageNotes::OnSelChangeCboStaff() 
{
	int nStaff = m_cboStaff.GetCurSel();
	m_wndStaff.ShowStaff((CCtrlStaff::eStaff) nStaff);
	// Show a new note and start timer
	OnBtnStart();
	m_wndNotes.SetFocus();
}



//. User chose a new difficulty level - tell control
void CPageNotes::OnSelchangeCboLevel() 
{
	int nLevel = m_cboLevel.GetCurSel();
//	m_wndStaff.SetLedgerLines(nLevel);
	m_wndStaff.SetLevel(nLevel);
	// Show a new note and start timer
	OnBtnStart();
	m_wndNotes.SetFocus();
}



void CPageNotes::OnSelchangeCboInput() 
{
	int nMode = m_cboInput.GetCurSel();
	m_wndNotes.SetMode(nMode);	
	m_wndNotes.SetFocus();
}



// Turn log on/off
void CPageNotes::OnChkLog() 
{
	m_bLog = m_chkLog.GetCheck();	

	// Save time if turning log on
	if (m_bLog)
		m_dwTime = ::GetTickCount();
}




// User clicked on a note name - see if it's correct
LRESULT CPageNotes::OnNoteClicked(WPARAM wParam, LPARAM lParam)
{
	// Get time elapsed
	DWORD dwTimeElapsed = ::GetTickCount() - m_dwTime;

	TCHAR cCorrect = m_wndStaff.GetNoteName();
	TCHAR cSelected = 'A' + wParam;
	BOOL bCorrect = (cCorrect == cSelected);

	// Display message in staff control
	if (bCorrect)
	{
		CString strMsg;
		strMsg.Format("Right! Time elapsed: %.1f s.", (float) dwTimeElapsed / 1000.0f);
		m_wndStaff.DisplayMessage(strMsg);
		UINT uSound = IDR_RIGHT1 + rand() % RIGHTSOUNDS;
		theApp.PlaySound(uSound);
//		m_wndNotes.FlashNote(wParam);
	}
	else
	{
		CString strMsg;
		strMsg.Format("Sorry, this note is %c. Click on it below to continue.", cCorrect);
		m_wndStaff.DisplayMessage(strMsg);
//		UINT uSound = IDR_WRONG1 + rand() % WRONGSOUNDS;
		UINT uSound = IDR_WRONG6;
		theApp.PlaySound(uSound);
	}

	// Record to file if option specified
	// Date, Time, Staff, Notenum, Notename, Time elapsed, Correct
	if (m_bLog)
	{
		CString strLine;
		COleDateTime dt;
		dt = COleDateTime::GetCurrentTime();
		//. use 2012-05-19 21:05:02 format
		CString strDate = dt.Format("%#d %b %Y");  // eg "5 May 2001"
		CString strTime = dt.Format("%#I:%M:%S %p"); // eg "9:05:02 PM"
		int nStaff = (int) m_wndStaff.GetStaff();
		int nNote = m_wndStaff.GetNoteNumber();
		strLine.Format(
						"%s\t" // date
						"%s\t" // time
						"%u\t" // staff
						"%i\t" // notenum
						"%c\t" // notename
						"%u\t" // timeelapsed
						"%i",  // correct?
						(LPCTSTR) strDate, 
						(LPCTSTR) strTime,
						nStaff,
						nNote,
						cCorrect,
						dwTimeElapsed,
						bCorrect
						);
		m_log.WriteLine(strLine);
	}

	// Go on to next note if this was correct
	if (bCorrect)
		OnBtnStart();

	return 0;
}



