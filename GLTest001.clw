; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGLTest001View
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "GLTest001.h"
LastPage=0

ClassCount=12
Class1=CGLTest001App
Class2=CGLTest001Doc
Class3=CGLTest001View
Class4=CMainFrame

ResourceCount=8
Resource1=IDR_MAINFRAME
Resource2=IDD_POLYGONFILLDLG_DIALOG
Class5=CAboutDlg
Class6=PolygonFillDlg
Class7=CoordSetDlg
Resource3=IDD_PATTERNDLG_DIALOG
Class8=CCoordSetDlg
Resource4=IDD_COORDSETDLG_DIALOG
Class9=CPointSizeDlg
Resource5=IDD_LINEWIDTHDLG_DIALOG
Class10=CLineWidthDlg
Resource6=IDD_POINTSIZEDLG_DIALOG
Class11=CPatternDlg
Resource7=IDD_ABOUTBOX
Class12=CEnvironmentSetDlg
Resource8=IDD_ENVIRONMENTSETDLG_DIALOG

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
LastObject=ID_STRETCH


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_SELECT




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
Command14=ID_LINE
Command15=ID_LINE_STRIP
Command16=ID_LINE_LOOP
Command17=ID_TRIANGLE
Command18=ID_TRIANGLE_STRIP
Command19=ID_TRIANGLE_FAN
Command20=ID_QUAD
Command21=ID_QUAD_STRIP
Command22=ID_POLYGON
Command23=ID_CONE
Command24=ID_TETRAHEDRON
Command25=ID_CUBE
Command26=ID_DODECAHEDRON
Command27=ID_ICOSAHEDRON
Command28=ID_OCTAHEDRON
Command29=ID_SPHERE
Command30=ID_TORUS
Command31=ID_TEAPOT
Command32=ID_POLYGON_FILL
Command33=ID_COLOR_SET
Command34=ID_POINT_SIZE
Command35=ID_LINE_WIDTH
Command36=ID_LINETYPE
Command37=ID_DRAW_SIZE
Command38=ID_ENVIRONMENTSET
Command39=ID_APP_ABOUT
CommandCount=39

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
Class=CMainFrame
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
Command19=ID_STRETCH
Command20=ID_POLYGON_FILL_TOOL
Command21=ID_ANIMATION
Command22=ID_ENVIRONMENTSET
Command23=ID_BLEND
Command24=ID_TRANSPARENT
Command25=ID_ANTIALIASING
Command26=ID_SELECT
CommandCount=26

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

[CLS:CoordSetDlg]
Type=0
HeaderFile=oordSetDlg.h
ImplementationFile=oordSetDlg.cpp
BaseClass=CFormView
Filter=D
LastObject=CoordSetDlg

[DLG:IDD_COORDSETDLG_DIALOG]
Type=1
Class=CCoordSetDlg
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552

[CLS:CCoordSetDlg]
Type=0
HeaderFile=CoordSetDlg.h
ImplementationFile=CoordSetDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CCoordSetDlg

[DLG:IDD_POINTSIZEDLG_DIALOG]
Type=1
Class=CPointSizeDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT2,edit,1350633600
Control8=IDC_EDIT3,edit,1350633600
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT4,edit,1350633600

[CLS:CPointSizeDlg]
Type=0
HeaderFile=PointSizeDlg.h
ImplementationFile=PointSizeDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CPointSizeDlg

[DLG:IDD_LINEWIDTHDLG_DIALOG]
Type=1
Class=CLineWidthDlg
ControlCount=10
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT1,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT2,edit,1350633600
Control7=IDC_EDIT3,edit,1350633600
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_EDIT4,edit,1350633600

[CLS:CLineWidthDlg]
Type=0
HeaderFile=LineWidthDlg.h
ImplementationFile=LineWidthDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CLineWidthDlg

[DLG:IDD_PATTERNDLG_DIALOG]
Type=1
Class=CPatternDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_RADIO1,button,1342308361
Control5=IDC_RADIO2,button,1342177289
Control6=IDC_RADIO3,button,1342177289

[CLS:CPatternDlg]
Type=0
HeaderFile=PatternDlg.h
ImplementationFile=PatternDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RADIO1
VirtualFilter=dWC

[DLG:IDD_ENVIRONMENTSETDLG_DIALOG]
Type=1
Class=CEnvironmentSetDlg
ControlCount=15
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CHECK1,button,1342373891
Control4=IDC_CHECK2,button,1342373891
Control5=IDC_CHECK3,button,1342373891
Control6=IDC_CHECK4,button,1342373891
Control7=IDC_CHECK7,button,1342373891
Control8=IDC_CHECK8,button,1342373891
Control9=IDC_BUTTON1,button,1342242816
Control10=IDC_CHECK9,button,1342242819
Control11=IDC_RADIO2,button,1342308361
Control12=IDC_STATIC,button,1342177287
Control13=IDC_RADIO3,button,1342177289
Control14=IDC_RADIO4,button,1342177289
Control15=IDC_RADIO5,button,1342177289

[CLS:CEnvironmentSetDlg]
Type=0
HeaderFile=EnvironmentSetDlg.h
ImplementationFile=EnvironmentSetDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO5

