
// Music.h : main header file for the MUSIC application



#pragma once


#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

//#include "LogTrace.h"


#define RIGHTSOUNDS 10
#define WRONGSOUNDS 6


class CMusicApp : public CWinApp
{
public:
	CMusicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMusicApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMusicApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


public:
	void PlaySound(UINT uSoundID);
	void PlayNote(int nNote);
//	static CLogTrace m_log; // static object
	HMIDIOUT m_hmo;

private:
	UINT sendMIDIEvent(HMIDIOUT hmo, BYTE bStatus, BYTE bData1, BYTE bData2);
};



//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.


// This lets other modules access the global application object
extern CMusicApp theApp;


