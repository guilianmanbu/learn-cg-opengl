// GLTest001View.cpp : implementation of the CGLTest001View class
//

#include "stdafx.h"
#include "GLTest001.h"

#include "GLTest001Doc.h"
#include "GLTest001View.h"

#include "PolygonFillDlg.h"
#include "CoordSetDlg.h"
#include "PointSizeDlg.h"
#include "LineWidthDlg.h"
#include "PatternDlg.h"

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
	ON_COMMAND(ID_LINE_STRIP, OnLineStrip)
	ON_COMMAND(ID_LINE_LOOP, OnLineLoop)
	ON_COMMAND(ID_TRIANGLE, OnTriangle)
	ON_COMMAND(ID_TRIANGLE_STRIP, OnTriangleStrip)
	ON_COMMAND(ID_TRIANGLE_FAN, OnTriangleFan)
	ON_COMMAND(ID_QUAD, OnQuad)
	ON_COMMAND(ID_QUAD_STRIP, OnQuadStrip)
	ON_COMMAND(ID_POLYGON, OnPolygon)
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_COLOR_SET, OnColorSet)
	ON_COMMAND(ID_DRAW_SIZE, OnDrawSize)
	ON_COMMAND(ID_POINT_SIZE, OnPointSize)
	ON_COMMAND(ID_LINE_WIDTH, OnLineWidth)
	ON_COMMAND(ID_LINETYPE, OnLinetype)
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
	m_PtCurSize=4.0;
	m_LineWidth=1.0;
	m_LinePattern=(GLshort)0xFFFF;
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
	RenderScene();		//��Ⱦ����
	glFinish();			//ִ�л�ͼ����
	SwapBuffers(m_pDC->GetSafeHdc());	//������������������豸����
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
	//�����ͼ���ڵ��豸����ָ��
	m_pDC = new CClientDC(this);
	if(m_pDC == NULL){
		MessageBox("�����ͼ���ڵ��豸����ָ��ʧ��");
		return FALSE;
	}
	if(!SetupPixelFormat()){
		return FALSE;
	}
	//������Ⱦ�������
	m_hRC=::wglCreateContext(m_pDC->GetSafeHdc());
	if(m_hRC==0){
		MessageBox("������Ⱦ����ʧ��");
		return FALSE;
	}
	// ��RC��DC��������
	if(::wglMakeCurrent(m_pDC->GetSafeHdc(),m_hRC)==FALSE){
		MessageBox("RC��DC����ʧ��");
		return FALSE;
	}
	return TRUE;
}

BOOL CGLTest001View::SetupPixelFormat(){
	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),		//�ṹ��С
		1,									//�汾��
		PFD_DRAW_TO_WINDOW |				//֧��windows
		PFD_SUPPORT_OPENGL |				//֧��opengl
		PFD_DOUBLEBUFFER,					//˫����
		PFD_TYPE_RGBA,						//ָ����������
		24,									//��ɫ��Ȼ�����
		0,0,0,0,0,0,						//������ɫλ
		0,									//����Alpha����
		0,									//����Shiftλ
		0,									//���ۻ�����
		0,0,0,0,							//���ۻ�����
		16,									//16λz����
		0,									//������Ϊ0
		0,									//������Ϊ0
		PFD_MAIN_PLANE,						//������ֵ
		0,									//������Ϊ0
		0,0,0								//������Ϊ0
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

	glColor3f(m_iR,m_iG,m_iB);
	//Draw_LineStrip();
	//Draw_Point();

	
	if(m_flag==GLPOINTS){
		glPointSize(m_PtCurSize); //��Ĵ�С
	}
	else if(m_flag>=2){
		glLineWidth(m_LineWidth);  //�߿�
		if(m_LinePattern!=-1){  //���� 
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1,m_LinePattern);
		}
		//����Ƿ��ͼ�Σ��Ƿ����
		if(m_bPolygonFill==TRUE)
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	}
	BOOL tessellate=FALSE;
	switch(m_flag)
	{
		case GLPOINTS:
			glBegin(GL_POINTS);
			break;
		case GLLINES:
			glBegin(GL_LINES);
			break;
		case GLLINESTRIP:
			glBegin(GL_LINE_STRIP);
			break;
		case GLLINELOOP:
			glBegin(GL_LINE_LOOP);
			break;
		case GLTRIANGLES:
			glBegin(GL_TRIANGLES);
			break;
		case GLTRIANGLESTRIP:
			glBegin(GL_TRIANGLE_STRIP);
			break;
		case GLTRIANGLEFAN:
			glBegin(GL_TRIANGLE_FAN);
			break;
		case GLQUADS:
			glBegin(GL_QUADS);
			break;
		case GLQUADSTRIP:
			glBegin(GL_QUAD_STRIP);
			break;
		case GLPOLYGON:
			glBegin(GL_POLYGON);
			tessellate=m_bPolygonFill;
			break;
	}
	SetVertexesToGL(tessellate);  // ���Ͷ����GL
	glEnd();

	if(m_LinePattern!=-1){
		glDisable(GL_LINE_STIPPLE);
	}
}

void CGLTest001View::InitOperation(){
	//����ÿ��ͼ��ʱ����ز�������Ϊ��ʼֵ
	m_Rflag=1;  //ʰȡ����
	m_Point_Array.RemoveAll();
	glLoadIdentity();
	Invalidate();
}

void CGLTest001View::SetVertexesToGL(BOOL tessellate){
	if(tessellate){
		//MessageBox("���");
		Util::PolygonTesslator(m_Point_Array);
	}
	else{
		//MessageBox("�����");
		for(int i=0;i<m_Point_Array.GetSize();i++){
			GLPoint pt(m_Point_Array[i]);
			glVertex3f(pt.x,pt.y,pt.z);
		}
	}
}

// Draw graphics
void CGLTest001View::Draw_Point(){
	if(m_flag!=GLPOINTS)
		return;
	
	int pt_num=m_Point_Array.GetSize();
	if(pt_num==0)
		return;
	
	//glColor3f(m_iR,m_iG,m_iB);
	glPointSize(m_PtCurSize);
	glBegin(GL_POINTS);
	for(int i=0;i<pt_num;i++){
		glVertex2f(m_Point_Array[i].x,m_Point_Array[i].y);
	}
	glEnd();
}
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

void CGLTest001View::Draw_LineStrip(){
	if(m_flag == GLLINESTRIP && m_Point_Array.GetSize()>1){
		//glColor3f(m_iR,m_iG,m_iB);
		glLineWidth(m_LineWidth);
		if(m_LinePattern!=-1){
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1,m_LinePattern);
		}

		glBegin(GL_LINE_STRIP);
		for(int i=0;i<m_Point_Array.GetSize();i++){
			GLPoint pt=m_Point_Array[i];
			glVertex2f(pt.x,pt.y);
		}
		glEnd();

		if(m_LinePattern!=-1){
			glDisable(GL_LINE_STIPPLE);
		}
	}
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
	//����һ������ԭ���ڻ�ͼ�������ĵ���������ʾ����
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
	//����RC �� DC ���ٹ���
	if(::wglMakeCurrent(0,0)==FALSE){
		MessageBox("����RC �� DC ���ٹ���ʧ��");
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
		Invalidate();
	}
}

void CGLTest001View::OnPoint() 
{
	// TODO: Add your command handler code here
	m_flag=GLPOINTS;
	InitOperation();
}

void CGLTest001View::OnLine() 
{
	// TODO: Add your command handler code here
	m_flag=GLLINES;
	//MessageBox("ֱ��");
	InitOperation();
}

void CGLTest001View::OnLineStrip() 
{
	// TODO: Add your command handler code here
	m_flag=GLLINESTRIP;
	InitOperation();
}

void CGLTest001View::OnLineLoop() 
{
	// TODO: Add your command handler code here
	m_flag=GLLINELOOP;
	//MessageBox("��Ȧ");
	InitOperation();
}

void CGLTest001View::OnTriangle() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLES;
	//MessageBox("����");
	InitOperation();
}

void CGLTest001View::OnTriangleStrip() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLESTRIP;
	//MessageBox("����-��");
	InitOperation();
}

void CGLTest001View::OnTriangleFan() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLEFAN;
	//MessageBox("����-��");
	InitOperation();
}

void CGLTest001View::OnQuad() 
{
	// TODO: Add your command handler code here
	m_flag=GLQUADS;
	//MessageBox("�ı���");
	InitOperation();
}

void CGLTest001View::OnQuadStrip() 
{
	// TODO: Add your command handler code here
	m_flag=GLQUADSTRIP;
	//MessageBox("�ı���-��");
	InitOperation();
}

void CGLTest001View::OnPolygon() 
{
	// TODO: Add your command handler code here
	m_flag=GLPOLYGON;
	//MessageBox("�����");
	InitOperation();
}

//���
void CGLTest001View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Rflag=0;  //����ʰȡ����
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

//�Ҽ�
void CGLTest001View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_Rflag==1){  // ʰȡ�㣬��ת��Ϊ��ͼ����ϵ��
		GLPoint pt;
		if(aspect_ratio<1){
			pt.x=(point.x-winWidth)/winWidth * Win_Size;
			pt.y=(winHeight-point.y)/winHeight/aspect_ratio*Win_Size;
			pt.z=0.0;
		}
		else{
			pt.x=(point.x-winWidth)/winWidth*aspect_ratio*Win_Size;
			pt.y=(winHeight-point.y)/winHeight*Win_Size;
			pt.z=0.0;
		}
		m_Point_Array.Add(pt);
		Invalidate();
	}
	CView::OnLButtonDown(nFlags, point);
}

//���û�ͼ��ɫ
void CGLTest001View::OnColorSet() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT|CC_FULLOPEN;
	dlg.m_cc.rgbResult=RGB(m_iR*255,m_iG*255,m_iB*255);
	if(IDOK==dlg.DoModal()){
		COLORREF m_clr=dlg.m_cc.rgbResult;  //�õ�ʰȡ����ɫ
		m_iR=GetRValue(m_clr)/255.0;
		m_iG=GetGValue(m_clr)/255.0;
		m_iB=GetBValue(m_clr)/255.0;
		Invalidate();
	}
}

//���û�ͼ��������곤�ȡ��������������ֶ���ͼ������
void CGLTest001View::OnDrawSize() 
{
	// TODO: Add your command handler code here
	//���û�ͼ�������ĳߴ磬�൱�ڰ� OnSize()�е�����ת������ʵ��һ��
	//OnSize()�������Ŵ����ǵ��ã����˺�������Ϊһ�����������������
	CCoordSetDlg coordSetDlg;
	coordSetDlg.m_WinSize=Win_Size;
	if(coordSetDlg.DoModal()!=IDOK)
		return;
	if(Win_Size==coordSetDlg.m_WinSize)
		return;
	Win_Size=coordSetDlg.m_WinSize;
	int cx,cy;
	cx=(int)winWidth*2;
	cy=(int)winHeight*2;
	::glViewport(0,0,cx,cy);
	::glMatrixMode(GL_PROJECTION);
	::glLoadIdentity();
	if(aspect_ratio<1){
		winWidth=Win_Size;
		winHeight=Win_Size/aspect_ratio;
	}
	else{
		winWidth=Win_Size*aspect_ratio;
		winHeight=Win_Size;
	}
	::glOrtho(-winWidth,winWidth,-winHeight,winHeight,-Win_Size,Win_Size);
	winWidth=cx/2.0;
	winHeight=cy/2.0;
	::glMatrixMode(GL_MODELVIEW);
	::glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	glClearColor(1.0f,1.0,1.0,1.0);
	Invalidate();
}

//���õ�Ĵ�С
void CGLTest001View::OnPointSize() 
{
	// TODO: Add your command handler code here
	GLfloat ptSize[2],step;
	::glGetFloatv(GL_POINT_SIZE_RANGE,ptSize);
	::glGetFloatv(GL_POINT_SIZE_GRANULARITY,&step);
	CPointSizeDlg dlg;
	dlg.m_min=ptSize[0];
	dlg.m_max=ptSize[1];
	dlg.m_step=step;
	dlg.m_Size=this->m_PtCurSize;
	if(dlg.DoModal()==IDOK && dlg.m_Size>=ptSize[0] && dlg.m_Size<=ptSize[1]){
		this->m_PtCurSize=dlg.m_Size;
		Invalidate();
	}
}

//�����߿�
void CGLTest001View::OnLineWidth() 
{
	// TODO: Add your command handler code here
	GLfloat lineSize[2],step;
	::glGetFloatv(GL_LINE_WIDTH_RANGE,lineSize);
	::glGetFloatv(GL_LINE_WIDTH_GRANULARITY,&step);
	CLineWidthDlg dlg;
	dlg.m_min=lineSize[0];
	dlg.m_max=lineSize[1];
	dlg.m_step=step;
	dlg.m_LineWidth=this->m_LineWidth;
	if(dlg.DoModal()==IDOK){
		this->m_LineWidth=dlg.m_LineWidth;
		Invalidate();
	}
}

void CGLTest001View::OnLinetype() 
{
	// TODO: Add your command handler code here
	CPatternDlg dlg;
	if(this->m_LinePattern==-1)  //ʵ��
		dlg.m_iPattern=0;
	else if(this->m_LinePattern==0x3F3F)  //����
		dlg.m_iPattern=1;
	else if(this->m_LinePattern==0x33FF)  //������
		dlg.m_iPattern=2;

	if(dlg.DoModal()==IDOK){
		if(dlg.m_iPattern==0)
			this->m_LinePattern=-1;
		else if(dlg.m_iPattern==1)
			this->m_LinePattern=0x3F3F;
		else if(dlg.m_iPattern==2)
			this->m_LinePattern=0x33FF;
		Invalidate();
	}
}
