
// CMusicApp



#include "stdafx.h"
#include "Music.h"
#include "DialogMain.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




BEGIN_MESSAGE_MAP(CMusicApp, CWinApp)
	//{{AFX_MSG_MAP(CMusicApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()



CMusicApp::CMusicApp()
{
}



// The one and only CMusicApp object
CMusicApp theApp;




BOOL CMusicApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Open midi device
	m_hmo = 0;
	UINT nRet = midiOutOpen(&m_hmo, 0, NULL, 0, CALLBACK_NULL);
	if (nRet != MMSYSERR_NOERROR)
	{
		AfxMessageBox("midi error!");
	}

	// Seed random number generator
	srand((unsigned) time(NULL));

	// Show the main window
	CDialogMain dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}




int CMusicApp::ExitInstance() 
{
	// Close midi device
	if (m_hmo) 
		midiOutClose(m_hmo);

	return CWinApp::ExitInstance();
}



// Send a short MIDI event to the MIDI device.
UINT CMusicApp::sendMIDIEvent(HMIDIOUT hmo, BYTE bStatus, BYTE bData1, BYTE bData2) 
{ 
	// The midiOutOpen and midiOutClose functions respectively open and close the MIDI devices to 
	// receive MIDI instructions. The midiOutShortMsg function is used to send the MIDI instruction. 

	union 
	{ 
		DWORD dwData; 
		BYTE bData[4]; 
	} u; 

	// Construct the MIDI message. 
	u.bData[0] = bStatus;  // MIDI status byte 
	u.bData[1] = bData1;   // first MIDI data byte 
	u.bData[2] = bData2;   // second MIDI data byte 
	u.bData[3] = 0; 

	// Send the message. 
	return midiOutShortMsg(hmo, u.dwData); 
} 




// Play a note (60 = middle C)
void CMusicApp::PlayNote(int nNote)
{
	BYTE byteNoteOn = 0x90; // channel 1 note on
	BYTE byteNoteOff = 0x80; // channel 1 note off
	BYTE byteNote = nNote; // 60 = middle c;
	BYTE byteVelocity = 0x40; // medium volume

	sendMIDIEvent(m_hmo, byteNoteOn, byteNote, byteVelocity); 
}







// Sample code to demonstrate SND_MEMORY flag and memory files.
void CMusicApp::PlaySound(UINT uSoundID)
{
	// Cancel any currently playing sound
	sndPlaySound(NULL, 0);

	// Sound resource bound within executable.
	HRSRC hSound = ::FindResource(m_hInstance, MAKEINTRESOURCE(uSoundID), "WAVE");
	if (hSound)
	{
		// Resource intact; load into GLOBAL MEMORY/GMEM_SHARED memory
		// The return type of LoadResource is HGLOBAL for backward compatibility, not because 
		// the function returns a handle to a global memory block. Do not pass this handle to the 
		// GlobalLock or GlobalFree function. 
		// To obtain a pointer to the resource data, call the LockResource function. 
		HGLOBAL hGlobal = ::LoadResource(m_hInstance, hSound);
		if (hGlobal)
		{  
			// Load resource into global memory and play.
			// Play sound resource via sndPlaySound() using SND_MEMORY flag.
			// Application waits until sndPlaySound completes given SND_SYNC.
			// SND_MEMORY (first parameter is ptr to memory image vs. filename).
//			sndPlaySound((LPSTR) LockResource(hGlobal), SND_SYNC | SND_MEMORY);
			sndPlaySound((LPSTR) LockResource(hGlobal), SND_ASYNC | SND_MEMORY);
		}  
	}

}
