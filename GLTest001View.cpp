// GLTest001View.cpp : implementation of the CGLTest001View class
//

#include "stdafx.h"
#include "GLTest001.h"

#include "GLTest001Doc.h"
#include "GLTest001View.h"

#pragma comment(lib,"glaux")
#pragma comment(lib,"glut32")
#pragma comment(lib,"glu32")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGLTest001View

IMPLEMENT_DYNCREATE(CGLTest001View, CView)

BEGIN_MESSAGE_MAP(CGLTest001View, CView)
	//{{AFX_MSG_MAP(CGLTest001View)
	ON_WM_CREATE()
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_DESTROY()
	ON_COMMAND(ID_POLYGON_FILL, OnPolygonFill)
	ON_COMMAND(ID_POINT, OnPoint)
	ON_COMMAND(ID_LINE, OnLine)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGLTest001View construction/destruction

CGLTest001View::CGLTest001View()
{
	// TODO: add construction code here
	Win_Size = 6.0;
	m_iR=0;
	m_iG=0;
	m_iB=0;
	m_iAlpha=1.0;
	m_PtCurSize=1.0;
	m_LineWidth=1.0;
	m_LinePatten=(GLshort)0xFFFF;
	m_flag=0;
	m_Rflag=0;
	m_bPolygonFill=FALSE;
}

CGLTest001View::~CGLTest001View()
{
}

BOOL CGLTest001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN;
	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CGLTest001View drawing

void CGLTest001View::OnDraw(CDC* pDC)
{
	CGLTest001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	RenderScene();		//渲染函数
	glFinish();			//执行绘图函数
	SwapBuffers(m_pDC->GetSafeHdc());	//将缓冲区内容输出给设备环境
}

/////////////////////////////////////////////////////////////////////////////
// CGLTest001View diagnostics

#ifdef _DEBUG
void CGLTest001View::AssertValid() const
{
	CView::AssertValid();
}

void CGLTest001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGLTest001Doc* CGLTest001View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGLTest001Doc)));
	return (CGLTest001Doc*)m_pDocument;
}
#endif //_DEBUG

BOOL CGLTest001View::InitializeOpenGL(){
	//获得视图窗口的设备环境指针
	m_pDC = new CClientDC(this);
	if(m_pDC == NULL){
		MessageBox("获得视图窗口的设备环境指针失败");
		return FALSE;
	}
	if(!SetupPixelFormat()){
		return FALSE;
	}
	//创建渲染环境句柄
	m_hRC=::wglCreateContext(m_pDC->GetSafeHdc());
	if(m_hRC==0){
		MessageBox("创建渲染环境失败");
		return FALSE;
	}
	// 将RC与DC关联起来
	if(::wglMakeCurrent(m_pDC->GetSafeHdc(),m_hRC)==FALSE){
		MessageBox("RC与DC关联失败");
		return FALSE;
	}
	return TRUE;
}

BOOL CGLTest001View::SetupPixelFormat(){
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),		//结构大小
		1,									//版本号
		PFD_DRAW_TO_WINDOW |				//支持windows
		PFD_SUPPORT_OPENGL |				//支持opengl
		PFD_DOUBLEBUFFER,					//双缓冲
		PFD_TYPE_RGBA,						//指定像素类型
		24,									//颜色深度缓冲区
		0,0,0,0,0,0,						//忽略颜色位
		0,									//忽略Alpha缓冲
		0,									//忽略Shift位
		0,									//无累积缓冲
		0,0,0,0,							//无累积缓冲
		16,									//16位z缓冲
		0,									//保留恒为0
		0,									//保留恒为0
		PFD_MAIN_PLANE,						//保留恒值
		0,									//保留恒为0
		0,0,0								//保留恒为0
	};
	int m_nPixelFormat = ::ChoosePixelFormat(m_pDC->GetSafeHdc(),&pfd);
	if(m_nPixelFormat==0){
		return FALSE;
	}
	if( ::SetPixelFormat(m_pDC->GetSafeHdc(),m_nPixelFormat,&pfd)==FALSE){
		return FALSE;
	}
	return TRUE;
}

void CGLTest001View::RenderScene(){
	Draw_line();
}

void CGLTest001View::InitOperation(){
	//绘制每个图形时把相关参数设置为初始值
	m_Rflag=1;
	m_Point_Array.RemoveAll();
	glLoadIdentity();
	Invalidate();
}

// Draw graphics
void CGLTest001View::Draw_line(){
	glColor3f(1.0,0.0,1.0);
	glLineWidth(4.0);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1,0x33);
	glBegin(GL_LINES);
		glVertex2i(-2.0,-2.0);
		glVertex2i(0,2.0);
		glVertex2i(-2,0);
		glColor3f(0.0f,0.0f,1.0f);
		glVertex2i(2,2);
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}

/////////////////////////////////////////////////////////////////////////////
// CGLTest001View message handlers

int CGLTest001View::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	InitializeOpenGL();
	
	return 0;
}

BOOL CGLTest001View::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	
	//return CView::OnEraseBkgnd(pDC);
	return TRUE;
}

void CGLTest001View::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	::glViewport(0,0,cx,cy);
	::glMatrixMode(GL_PROJECTION);
	::glLoadIdentity();
	aspect_ratio=(GLfloat)cx/(GLfloat)cy;
	if(cx<=cy){
		winWidth=Win_Size;
		winHeight=Win_Size/aspect_ratio;
	}else{
		winWidth=Win_Size*aspect_ratio;
		winHeight=Win_Size;
	}
	//设置一个坐标原点在绘图窗口中心的立方体显示区域
	glOrtho(-winWidth,winWidth,-winHeight,winHeight,-Win_Size,Win_Size);
	winWidth=cx/2.0;
	winHeight=cy/2.0;
	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();
	glClearColor(1.0f,1.0f,1.0f,1.0f);
}

void CGLTest001View::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	//设置RC 和 DC 不再关联
	if(::wglMakeCurrent(0,0)==FALSE){
		MessageBox("设置RC 和 DC 不再关联失败");
	}
	//Delete render context handle
	if(::wglDeleteContext(m_hRC)==FALSE){
		MessageBox("Delete render context handle failed!");
	}
	//delete device pointer
	if(m_pDC){
		delete m_pDC;
	}
	m_pDC=NULL;
}

void CGLTest001View::OnPolygonFill() 
{
	// TODO: Add your command handler code here
	PolygonFillDlg polygonFillDlg;
	polygonFillDlg.m_bFill=m_bPolygonFill;
	if(polygonFillDlg.DoModal()==IDOK){
		m_bPolygonFill=polygonFillDlg.m_bFill;
		//Util::PolygonTesslator(m_Point_Array);
		Invalidate();
	}
}

void CGLTest001View::OnPoint() 
{
	// TODO: Add your command handler code here
	m_flag=GLPOINTS;
	MessageBox("画点");
	InitOperation();
}

void CGLTest001View::OnLine() 
{
	// TODO: Add your command handler code here
	m_flag=GLLINES;
	MessageBox("直线");
	InitOperation();
}
