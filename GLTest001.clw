; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGLTest001View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GLTest001.h"
LastPage=0

ClassCount=6
Class1=CGLTest001App
Class2=CGLTest001Doc
Class3=CGLTest001View
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=PolygonFillDlg
Resource3=IDD_POLYGONFILLDLG_DIALOG

[CLS:CGLTest001App]
Type=0
HeaderFile=GLTest001.h
ImplementationFile=GLTest001.cpp
Filter=N

[CLS:CGLTest001Doc]
Type=0
HeaderFile=GLTest001Doc.h
ImplementationFile=GLTest001Doc.cpp
Filter=N

[CLS:CGLTest001View]
Type=0
HeaderFile=GLTest001View.h
ImplementationFile=GLTest001View.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_POLYGON_FILL


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=GLTest001.cpp
ImplementationFile=GLTest001.cpp
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
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_MRU_FILE1
Command6=ID_APP_EXIT
Command7=ID_EDIT_UNDO
Command8=ID_EDIT_CUT
Command9=ID_EDIT_COPY
Command10=ID_EDIT_PASTE
Command11=ID_VIEW_TOOLBAR
Command12=ID_VIEW_STATUS_BAR
Command13=ID_POINT
Command14=ID_POLYGON_FILL
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_UNDO
Command5=ID_EDIT_CUT
Command6=ID_EDIT_COPY
Command7=ID_EDIT_PASTE
Command8=ID_EDIT_UNDO
Command9=ID_EDIT_CUT
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_NEXT_PANE
Command13=ID_PREV_PANE
CommandCount=13

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_POINT
Command10=ID_LINE
Command11=ID_LINE_STRIP
Command12=ID_LINE_LOOP
Command13=ID_TRIANGLE
Command14=ID_TRIANGLE_STRIP
Command15=ID_TRIANGLE_FAN
Command16=ID_QUAD
Command17=ID_QUAD_STRIP
Command18=ID_POLYGON
Command19=ID_POLYGON_FILL
CommandCount=19

[DLG:IDD_POLYGONFILLDLG_DIALOG]
Type=1
Class=PolygonFillDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK1,button,1342242819

[CLS:PolygonFillDlg]
Type=0
HeaderFile=PolygonFillDlg.h
ImplementationFile=PolygonFillDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CHECK1
VirtualFilter=dWC

