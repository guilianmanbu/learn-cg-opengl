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
	ON_COMMAND(ID_ANIMATION, OnAnimation)
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_COMMAND(ID_CONE, OnCone)
	ON_COMMAND(ID_CUBE, OnCube)
	ON_COMMAND(ID_TETRAHEDRON, OnTetrahedron)
	ON_COMMAND(ID_DODECAHEDRON, OnDodecahedron)
	ON_COMMAND(ID_ICOSAHEDRON, OnIcosahedron)
	ON_COMMAND(ID_OCTAHEDRON, OnOctahedron)
	ON_COMMAND(ID_SPHERE, OnSphere)
	ON_COMMAND(ID_TORUS, OnTorus)
	ON_COMMAND(ID_TEAPOT, OnTeapot)
	ON_COMMAND(ID_POLYGON_FILL_TOOL, OnPolygonFillTool)
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
	//几何变换
	m_lrMove=0.0;
	m_btMove=0.0;
	m_rAngle=0.0;
	m_Scale=1.0;
	m_bAnimation=FALSE;
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
	
	//几何变换. 对 ModelView 矩阵的变换
	glPushMatrix();  //将当前坐标矩阵压入堆栈
	glTranslatef(m_lrMove,m_btMove,0);
	glRotatef(m_rAngle,1.0,0.0,0.0);
	glRotatef(m_rAngle,.0,1.0f,.0);
	glRotatef(m_rAngle,.0,.0,1.f);
	glScalef(m_Scale,m_Scale,m_Scale);

	glColor3f(m_iR,m_iG,m_iB);
	//Draw_LineStrip();
	//Draw_Point();
	
	BOOL setRawVertexes=TRUE;   //是否给gl发送原始拾取点
	if(m_flag==GLPOINTS){
		glPointSize(m_PtCurSize); //点的大小
	}
	else if(m_flag>=GLLINES && m_flag<=GLPOLYGON){
		glLineWidth(m_LineWidth);  //线宽
		if(m_LinePattern!=-1){  //线型 
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1,m_LinePattern);
		}
		//如果是封闭图形，是否填充
		if(m_bPolygonFill==TRUE)
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	}
	else if(m_flag>=CONE){
		glLineWidth(m_LineWidth);  //线宽
		if(m_LinePattern!=-1){  //线型 
			glEnable(GL_LINE_STIPPLE);
			glLineStipple(1,m_LinePattern);
		}
		setRawVertexes=FALSE;
		m_3DRadius=Win_Size/4.0;
	}
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
			if(m_bPolygonFill){
				Util::PolygonTesslator(m_Point_Array);
				setRawVertexes=FALSE;
			}
			else{
				glBegin(GL_POLYGON);
			}
			break;
		case CONE:			//圆锥体
			if(m_bPolygonFill)
				glutSolidCone(m_3DRadius,m_3DRadius*2,30,30);
			else
				glutWireCone(m_3DRadius,m_3DRadius*2,30,30);
			break;
		case TETRAHEDRON:	//四面体
			glScaled(m_3DRadius,m_3DRadius,m_3DRadius);  //缩放变换
			if(m_bPolygonFill)
				glutSolidTetrahedron();
			else
				glutWireTetrahedron();
			break;
		case CUBE:			//立方体
			if(m_bPolygonFill)
				glutSolidCube(m_3DRadius);
			else
				glutWireCube(m_3DRadius);
			break;
		case DODECAHEDRON:	//正十二面体
			glScaled(m_3DRadius,m_3DRadius,m_3DRadius);  //缩放变换
			if(m_bPolygonFill)
				glutSolidDodecahedron();
			else
				glutWireDodecahedron();
			break;
		case ICOSAHEDRON:	//正二十面体
			glScaled(m_3DRadius,m_3DRadius,m_3DRadius);  //缩放变换
			if(m_bPolygonFill)
				glutSolidIcosahedron();
			else
				glutWireIcosahedron();
			break;
		case OCTAHEDRON:	//正八面体
			glScaled(m_3DRadius,m_3DRadius,m_3DRadius);  //缩放变换
			if(m_bPolygonFill)
				glutSolidOctahedron();
			else
				glutWireOctahedron();
			break;
		case SPHERE:		//球体
			if(m_bPolygonFill)
				glutSolidSphere(m_3DRadius,30,30);
			else
				glutWireSphere(m_3DRadius,30,30);
			break;
		case TORUS:			//圆环体
			if(m_bPolygonFill)
				glutSolidTorus(m_3DRadius/2.0,m_3DRadius,30,30);
			else
				glutWireTorus(m_3DRadius/2.0,m_3DRadius,30,30);
			break;
		case TEAPOT:		//茶壶
			if(m_bPolygonFill)
				glutSolidTeapot(m_3DRadius);
			else
				glutWireTeapot(m_3DRadius);
			break;
		default:
			setRawVertexes=FALSE;
			break;
	}
	if(setRawVertexes){
		SetVertexesToGL(FALSE);  // 传送顶点给GL
	}
	glEnd();

	if(m_LinePattern!=-1){
		glDisable(GL_LINE_STIPPLE);
	}
	glPopMatrix();  //恢复原有坐标矩阵
}

void CGLTest001View::InitOperation(){
	//绘制每个图形时把相关参数设置为初始值
	m_Rflag=1;  //拾取操作
	m_Point_Array.RemoveAll();
	glLoadIdentity();
	m_lrMove=0.0;
	m_btMove=0.0;
	m_rAngle=0.0;
	m_Scale=1.0;
	if(m_bAnimation==TRUE){
		m_bAnimation=FALSE;
		KillTimer(0);
	}
	
	Invalidate();
}

void CGLTest001View::SetVertexesToGL(BOOL tessellate){
	if(tessellate){
		//MessageBox("填充");
		Util::PolygonTesslator(m_Point_Array);
	}
	else{
		//MessageBox("不填充");
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
	//MessageBox("直线");
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
	//MessageBox("线圈");
	InitOperation();
}

void CGLTest001View::OnTriangle() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLES;
	//MessageBox("三角");
	InitOperation();
}

void CGLTest001View::OnTriangleStrip() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLESTRIP;
	//MessageBox("三角-链");
	InitOperation();
}

void CGLTest001View::OnTriangleFan() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLEFAN;
	//MessageBox("三角-扇");
	InitOperation();
}

void CGLTest001View::OnQuad() 
{
	// TODO: Add your command handler code here
	m_flag=GLQUADS;
	//MessageBox("四边形");
	InitOperation();
}

void CGLTest001View::OnQuadStrip() 
{
	// TODO: Add your command handler code here
	m_flag=GLQUADSTRIP;
	//MessageBox("四边形-链");
	InitOperation();
}

void CGLTest001View::OnPolygon() 
{
	// TODO: Add your command handler code here
	m_flag=GLPOLYGON;
	//MessageBox("多边形");
	InitOperation();
}
//圆锥体
void CGLTest001View::OnCone() 
{
	// TODO: Add your command handler code here
	m_flag=CONE;
	InitOperation();
	m_Rflag=0;  //拾取操作
}
//立方体
void CGLTest001View::OnCube() 
{
	// TODO: Add your command handler code here
	m_flag=CUBE;
	InitOperation();
	m_Rflag=0;  //拾取操作
}
//四面体
void CGLTest001View::OnTetrahedron() 
{
	// TODO: Add your command handler code here
	m_flag=TETRAHEDRON;
	InitOperation();
	m_Rflag=0;  //拾取操作
}
//正十二面体
void CGLTest001View::OnDodecahedron() 
{
	// TODO: Add your command handler code here
	m_flag=DODECAHEDRON;
	InitOperation();
	m_Rflag=0;  //拾取操作
}
//正二十面体
void CGLTest001View::OnIcosahedron() 
{
	// TODO: Add your command handler code here
	m_flag=ICOSAHEDRON;
	InitOperation();
	m_Rflag=0;  //拾取操作
}
//正八面体
void CGLTest001View::OnOctahedron() 
{
	// TODO: Add your command handler code here
	m_flag=OCTAHEDRON;
	InitOperation();
	m_Rflag=0;  //拾取操作
}

//球体
void CGLTest001View::OnSphere() 
{
	// TODO: Add your command handler code here
	m_flag=SPHERE;
	InitOperation();
	m_Rflag=0;  //拾取操作
}
//圆环体
void CGLTest001View::OnTorus() 
{
	// TODO: Add your command handler code here
	m_flag=TORUS;
	InitOperation();
	m_Rflag=0;  //拾取操作
}
//茶壶
void CGLTest001View::OnTeapot() 
{
	// TODO: Add your command handler code here
	m_flag=TEAPOT;
	InitOperation();
	m_Rflag=0;  //拾取操作
}

//左键
void CGLTest001View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Rflag=0;  //不再拾取操作
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

//右键
void CGLTest001View::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_Rflag==1){  // 拾取点，并转换为绘图坐标系点
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

//设置绘图颜色
void CGLTest001View::OnColorSet() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT|CC_FULLOPEN;
	dlg.m_cc.rgbResult=RGB(m_iR*255,m_iG*255,m_iB*255);
	if(IDOK==dlg.DoModal()){
		COLORREF m_clr=dlg.m_cc.rgbResult;  //拿到拾取的颜色
		m_iR=GetRValue(m_clr)/255.0;
		m_iG=GetGValue(m_clr)/255.0;
		m_iB=GetBValue(m_clr)/255.0;
		Invalidate();
	}
}

//设置绘图区域的坐标长度。作用类似鼠标滚轮对视图的缩放
void CGLTest001View::OnDrawSize() 
{
	// TODO: Add your command handler code here
	//设置绘图区域短轴的尺寸，相当于把 OnSize()中的坐标转换重新实现一次
	//OnSize()仅在缩放窗口是调用，而此函数是作为一个命令可以主动调用
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

//设置点的大小
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

//设置线宽
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

//设置线型
void CGLTest001View::OnLinetype() 
{
	// TODO: Add your command handler code here
	CPatternDlg dlg;
	if(this->m_LinePattern==-1)  //实线
		dlg.m_iPattern=0;
	else if(this->m_LinePattern==0x3F3F)  //虚线
		dlg.m_iPattern=1;
	else if(this->m_LinePattern==0x33FF)  //中心线
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

//多边形区域填充设置-菜单项
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
//多边形区域填充设置 -工具栏
void CGLTest001View::OnPolygonFillTool() 
{
	// TODO: Add your command handler code here
	m_bPolygonFill=!m_bPolygonFill;
	Invalidate();
}

//动画
void CGLTest001View::OnAnimation() 
{
	// TODO: Add your command handler code here
	if(m_bAnimation==FALSE){
		if(m_flag>=GLLINES && m_flag<=GLPOLYGON)
			if(m_Point_Array.GetSize()<2)
				return;
		SetTimer(0,10,NULL);
		m_bAnimation=TRUE;
	}
	else{
		KillTimer(0);
		m_bAnimation=FALSE;
	}
	Invalidate();
}

void CGLTest001View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	int invalidate=1;
	switch(nChar){
	case VK_UP:
		if(GetAsyncKeyState(VK_LSHIFT)&&0x8000)  //Shift键是否被按下
			m_Scale+=0.1;		//设置缩放比例
		else
			m_btMove+=0.1;		//设置上下移动
		break;
	case VK_DOWN:
		if(GetAsyncKeyState(VK_LSHIFT)&&0x8000){
			m_Scale-=0.1;
			if(m_Scale<=0)
				m_Scale=0.05;
		}
		else
			m_btMove-=0.1;
		break;
	case VK_LEFT:
		m_lrMove-=0.1;		//设置水平移动
		break;
	case VK_RIGHT:
		m_lrMove+=0.1;
		break;
	default:
		invalidate=0;
		break;
	}
	if(invalidate==1)
		Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CGLTest001View::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_rAngle+=1.0;		//旋转角度
	Invalidate();
	CView::OnTimer(nIDEvent);
}

