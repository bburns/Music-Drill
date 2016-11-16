; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CPageNotes
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "music.h"
LastPage=0

ClassCount=12
Class1=CCtrlNotes
Class2=CCtrlStaff
Class3=CDialogMain
Class4=CMusicApp
Class5=CPage
Class6=CPageAbout
Class7=CPageNotes
Class8=CPagePitch
Class9=CPageProgress
Class10=CPageRhythms
Class11=CPageSymbols
Class12=CPageWelcome

ResourceCount=9
Resource1=IDD_PAGE_SYMBOLS
Resource2=IDD_PAGE_WELCOME
Resource3=IDD_PAGE_PROGRESS
Resource4=IDD_PAGE_RHYTHM
Resource5=IDD_PAGE_ABOUT
Resource6=IDD_PAGE_NOTES
Resource7=IDD_PAGE_PITCH
Resource8=IDD_MAIN
Resource9=IDR_MAIN_MENU

[CLS:CCtrlNotes]
Type=0
BaseClass=CStatic
HeaderFile=CtrlNotes.h
ImplementationFile=CtrlNotes.cpp
Filter=W
VirtualFilter=WC
LastObject=CCtrlNotes

[CLS:CCtrlStaff]
Type=0
BaseClass=CStatic
HeaderFile=CtrlStaff.h
ImplementationFile=CtrlStaff.cpp

[CLS:CDialogMain]
Type=0
BaseClass=CDialog
HeaderFile=DialogMain.h
ImplementationFile=DialogMain.cpp
LastObject=CDialogMain

[CLS:CMusicApp]
Type=0
BaseClass=CWinApp
HeaderFile=Music.h
ImplementationFile=Music.cpp

[CLS:CPage]
Type=0
BaseClass=CDialog
HeaderFile=Page.h
ImplementationFile=Page.cpp

[CLS:CPageAbout]
Type=0
BaseClass=CPage
HeaderFile=PageAbout.h
ImplementationFile=PageAbout.cpp

[CLS:CPageNotes]
Type=0
BaseClass=CPage
HeaderFile=pagenotes.h
ImplementationFile=pagenotes.cpp
LastObject=IDC_CBO_INPUT

[CLS:CPagePitch]
Type=0
BaseClass=CPage
HeaderFile=PagePitch.h
ImplementationFile=PagePitch.cpp

[CLS:CPageProgress]
Type=0
BaseClass=CPage
HeaderFile=PageProgress.h
ImplementationFile=PageProgress.cpp

[CLS:CPageRhythms]
Type=0
BaseClass=CPage
HeaderFile=PageRhythms.h
ImplementationFile=PageRhythms.cpp

[CLS:CPageSymbols]
Type=0
BaseClass=CPage
HeaderFile=PageSymbols.h
ImplementationFile=PageSymbols.cpp

[CLS:CPageWelcome]
Type=0
BaseClass=CPage
HeaderFile=pagewelcome.h
ImplementationFile=PageWelcome.cpp
LastObject=IDC_CBO_NAME

[DLG:IDD_MAIN]
Type=1
Class=CDialogMain
ControlCount=2
Control1=IDC_TBC,SysTabControl32,1342177344
Control2=IDC_BTN_CLOSE,button,1342242816

[DLG:IDD_PAGE_ABOUT]
Type=1
Class=CPageAbout
ControlCount=4
Control1=IDC_STATIC,static,1342181379
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342181379

[DLG:IDD_PAGE_NOTES]
Type=1
Class=CPageNotes
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_CBO_LEVEL,combobox,1344339971
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CBO_STAFF,combobox,1344339971
Control5=IDC_STATIC,static,1342308352
Control6=IDC_CBO_INPUT,combobox,1344339971
Control7=IDC_PIC_STAFF,static,1342177286
Control8=IDC_PIC_NOTES,static,1342177542
Control9=IDC_BTN_START,button,1073807360
Control10=IDC_BTN_PAUSE,button,1073807360
Control11=IDC_BTN_STOP,button,1073807360
Control12=IDC_CHK_LOG,button,1073807363

[DLG:IDD_PAGE_PITCH]
Type=1
Class=CPagePitch
ControlCount=6
Control1=IDC_BTN_PLAY,button,1342242816
Control2=IDC_LBL_NOTE,static,1342308352
Control3=IDC_BTN_PLAY2,button,1342242816
Control4=IDC_LBL_INSTRUCTIONS,static,1342308352
Control5=IDC_CBO_TEST,combobox,1344340227
Control6=IDC_STATIC,static,1342308352

[DLG:IDD_PAGE_PROGRESS]
Type=1
Class=CPageProgress
ControlCount=1
Control1=IDC_STATIC,static,1342308352

[DLG:IDD_PAGE_RHYTHM]
Type=1
Class=CPageRhythms
ControlCount=1
Control1=IDC_PIC_STAFF,static,1342177286

[DLG:IDD_PAGE_SYMBOLS]
Type=1
Class=CPageSymbols
ControlCount=0

[DLG:IDD_PAGE_WELCOME]
Type=1
Class=CPageWelcome
ControlCount=5
Control1=IDC_LBL_WELCOME,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_CBO_NAME,combobox,1075904770
Control4=IDC_STATIC,static,1073872896
Control5=IDC_STATIC,static,1073872896

[MNU:IDR_MAIN_MENU]
Type=1
Class=?
Command1=ID_OPTIONS
Command2=ID_VIEW_OPTIONS
CommandCount=2

