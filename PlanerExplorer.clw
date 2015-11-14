; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CStatDialogBar
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "PlanerExplorer.h"
LastPage=0

ClassCount=7
Class1=CPlanerExplorerApp
Class2=CPlanerExplorerDoc
Class3=CPlanerExplorerView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDD_ABOUTBOX
Class6=COptionDialog
Resource3=IDD_OPTIONS_DIALOG
Class7=CStatDialogBar
Resource4=IDD_STATISTICS_DIALOGBAR

[CLS:CPlanerExplorerApp]
Type=0
HeaderFile=PlanerExplorer.h
ImplementationFile=PlanerExplorer.cpp
Filter=N

[CLS:CPlanerExplorerDoc]
Type=0
HeaderFile=PlanerExplorerDoc.h
ImplementationFile=PlanerExplorerDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=CPlanerExplorerDoc

[CLS:CPlanerExplorerView]
Type=0
HeaderFile=PlanerExplorerView.h
ImplementationFile=PlanerExplorerView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CPlanerExplorerView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=PlanerExplorer.cpp
ImplementationFile=PlanerExplorer.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_STEP
Command2=ID_APP_EXIT
Command3=ID_OPTIONS_OPTIONS
Command4=ID_APP_ABOUT
CommandCount=4

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_FILE_NEW
Command3=ID_FILE_OPEN
Command4=ID_FILE_PRINT
Command5=ID_STEP
Command6=ID_EDIT_PASTE
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_NEXT_PANE
Command10=ID_PREV_PANE
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_EDIT_CUT
Command14=ID_EDIT_UNDO
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_INIT
Command2=ID_STEP
Command3=ID_LOOP
Command4=ID_STOP
CommandCount=4

[CLS:COptionDialog]
Type=0
HeaderFile=OptionDialog.h
ImplementationFile=OptionDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC

[DLG:IDD_OPTIONS_DIALOG]
Type=1
Class=COptionDialog
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308354
Control4=IDC_SAMPLES,edit,1350639744
Control5=IDC_STATIC,static,1342308354
Control6=IDC_EXPLORERS,edit,1350639744

[DLG:IDD_STATISTICS_DIALOGBAR]
Type=1
Class=CStatDialogBar
ControlCount=4
Control1=IDC_STATIC,static,1342308354
Control2=IDC_MOVES,static,1342308352
Control3=IDC_STATIC,static,1342308354
Control4=IDC_AVERAGE_MOVES,static,1342308352

[CLS:CStatDialogBar]
Type=0
HeaderFile=StatDialogBar.h
ImplementationFile=StatDialogBar.cpp
BaseClass=CDialog
Filter=D
LastObject=CStatDialogBar
VirtualFilter=dWC

