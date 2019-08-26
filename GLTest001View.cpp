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
#include "EnvironmentSetDlg.h"
#include "ImageModeDlg.h"

#pragma comment(lib,"glaux")
#pragma comment(lib,"glut32")
#pragma comment(lib,"glu32")

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//����λͼ
GLubyte Zebra[] = {
	0x00,0x00,0x00,0x00,
	0x37,0x20,0x00,0x00,
	0x13,0x60,0x00,0x00,
	0x10,0x60,0x00,0x00,
	0x14,0x60,0x00,0x00,
	0x06,0x18,0x00,0x00,
	0x07,0x10,0x00,0x00,
	0x07,0x40,0x00,0x00,
	0x03,0x60,0x00,0x00,
	0x03,0x70,0x00,0x00,
	0x01,0x70,0x00,0x3e,
	0x02,0x78,0x00,0x78,
	0x01,0x18,0x01,0x60,
	0x01,0x48,0x0a,0x08,
	0x00,0x62,0x14,0x00,
	0x00,0xf6,0x43,0xe0,
	0x00,0x3d,0xcb,0x60,
	0x00,0x19,0x9d,0x40,
	0x00,0x08,0x22,0xc0,
	0x00,0x00,0x09,0x80,
	0x00,0x02,0x40,0x80,
	0x00,0x01,0x1b,0x80,
	0x00,0x00,0x00,0x00,
	0x00,0x00,0x28,0x00,
	0x00,0x00,0x29,0x00,
	0x00,0x00,0x49,0x80,
	0x00,0x01,0x99,0x80,
	0x00,0x00,0x00,0x00
};

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
	ON_COMMAND(ID_ENVIRONMENTSET, OnEnvironmentset)
	ON_COMMAND(ID_STRETCH, OnStretch)
	ON_UPDATE_COMMAND_UI(ID_STRETCH, OnUpdateStretch)
	ON_COMMAND(ID_BLEND, OnBlend)
	ON_COMMAND(ID_TRANSPARENT, OnTransparent)
	ON_COMMAND(ID_ANTIALIASING, OnAntialiasing)
	ON_COMMAND(ID_SELECT, OnSelect)
	ON_COMMAND(ID_BITMAP, OnBitmap)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_IMAGEFLAG, OnImageflag)
	ON_COMMAND(ID_IMAGE_MAP_2D, OnImageMap2d)
	ON_COMMAND(ID_TEXTRUE_MAP_OBJECT, OnTextrueMapObject)
	ON_COMMAND(ID_ImageMapBlend, OnImageMapBlend)
	ON_COMMAND(ID_TEXTURE_1D, OnTexture1d)
	ON_COMMAND(ID_TEXTURE_SPHERE, OnTextureSphere)
	ON_COMMAND(ID_QUADRICOBJ, OnQuadricobj)
	ON_COMMAND(ID_BEZIERLINE, OnBezierline)
	ON_COMMAND(ID_BEZIERSURF, OnBeziersurf)
	ON_COMMAND(ID_NURBSLINE, OnNurbsline)
	ON_COMMAND(ID_NURBSSURF, OnNurbssurf)
	ON_COMMAND(ID_NURBSTRIM, OnNurbstrim)
	ON_COMMAND(ID_NURBSTEXTUREMAP, OnNurbstexturemap)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGLTest001View construction/destruction

CGLTest001View::CGLTest001View()
{
	// TODO: add construction code here
	Win_Size = 6.0;
	m_iR=1;			//���û�ͼ��ɫ
	m_iG=1;
	m_iB=1;
	m_iAlpha=1.0;
	m_PtCurSize=4.0;
	m_LineWidth=1.0;
	m_LinePattern=(GLshort)0xFFFF;
	m_flag=0;
	m_Rflag=0;
	m_bPolygonFill=FALSE;
	//���α任
	m_lrMove=0.0;
	m_btMove=0.0;
	m_rAngle=0.0;
	m_Scale=1.0;
	m_bAnimation=FALSE;
	//��ʵ����Ⱦ
	m_DepthFlag=FALSE;			//��ȼ��
	m_LightFlag=FALSE;			//���ù���״̬
	m_Light0Flag=FALSE;			//0�ŵ�״̬
	m_Light1Flag=FALSE;			//1�ŵ�״̬
	m_LightModelFlag=FALSE;		//�Ƿ����ù���ģ��
	m_MaterialColorFlag=FALSE;	//�Ƿ���ٵ�ǰ��ͼ��ɫ
	m_MatEmissionFlag=FALSE;		//���ò����Ƿ��Է���
	m_iR_BG=0;			//���ñ�����ɫ
	m_iG_BG=0;
	m_iB_BG=0;
	//��ɫ���
	m_BlendFlag=0;
	//��Ч
	m_FogMode=0;
	//ͼ��
	m_pImage=NULL;
	m_pImageModefied=NULL;
	m_ImageFlag=GLNULL;
	//NURB��������  �ü���־
	m_NurbsTrimFlag=0;
}

CGLTest001View::~CGLTest001View()
{
	if(m_pImageModefied!=NULL)
		delete m_pImageModefied;
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
	//Draw_Image();
	Draw_line();  //ˮӡ������
	Draw_TextureSphereBG();
	
	//���α任. �� ModelView ����ı任
	glPushMatrix();  //����ǰ�������ѹ���ջ
	glTranslatef(m_lrMove,m_btMove,0);
	glRotatef(m_rAngle,1.0,0.0,0.0);
	glRotatef(m_rAngle,.0,1.0f,.0);
	glRotatef(m_rAngle,.0,.0,1.f);
	glScalef(m_Scale,m_Scale,m_Scale);

	glColor3f(m_iR,m_iG,m_iB);
	glLineWidth(m_LineWidth);	//�߿�
	if(m_LinePattern!=-1){		//���� 
		glEnable(GL_LINE_STIPPLE);
		glLineStipple(1,m_LinePattern);
	}
	//Draw_LineStrip();
	//Draw_Point();
	
	//BOOL setRawVertexes=TRUE;   //�Ƿ��gl����ԭʼʰȡ��
	if(m_flag==GLPOINTS){
		glPointSize(m_PtCurSize); //��Ĵ�С
	}
	//else if((m_flag>=GLLINES && m_flag<=GLPOLYGON) || m_flag==STRETCH){
		//����Ƿ��ͼ�Σ��Ƿ����
		if(m_bPolygonFill==TRUE)
			glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
		else
			glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
	//}

	switch(m_flag)
	{
		case GLPOINTS:
			glBegin(GL_POINTS);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLLINES:
			glBegin(GL_LINES);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLLINESTRIP:
			glBegin(GL_LINE_STRIP);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLLINELOOP:
			glBegin(GL_LINE_LOOP);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLTRIANGLES:
			glBegin(GL_TRIANGLES);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLTRIANGLESTRIP:
			glBegin(GL_TRIANGLE_STRIP);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLTRIANGLEFAN:
			glBegin(GL_TRIANGLE_FAN);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLQUADS:
			glBegin(GL_QUADS);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLQUADSTRIP:
			glBegin(GL_QUAD_STRIP);
			SetVertexesToGL();  // ���Ͷ����GL
			glEnd();
			break;
		case GLPOLYGON:
			if(m_bPolygonFill){
				Util::PolygonTesslator(m_Point_Array);
			}
			else{
				glBegin(GL_POLYGON);
				SetVertexesToGL();  // ���Ͷ����GL
				glEnd();
			}
			break;
		case CONE:			//Բ׶��
			m_3DRadius=Win_Size/4.0;
			if(m_bPolygonFill)
				glutSolidCone(m_3DRadius,m_3DRadius*2,30,30);
			else
				glutWireCone(m_3DRadius,m_3DRadius*2,30,30);
			break;
		case TETRAHEDRON:	//������
			m_3DRadius=Win_Size/4.0;
			glScaled(m_3DRadius,m_3DRadius,m_3DRadius);  //���ű任
			if(m_bPolygonFill)
				glutSolidTetrahedron();
			else
				glutWireTetrahedron();
			break;
		case CUBE:			//������
			m_3DRadius=Win_Size/4.0;
			if(m_bPolygonFill)
				glutSolidCube(m_3DRadius);
			else
				glutWireCube(m_3DRadius);
			break;
		case DODECAHEDRON:	//��ʮ������
			m_3DRadius=Win_Size/4.0;
			glScaled(m_3DRadius,m_3DRadius,m_3DRadius);  //���ű任
			if(m_bPolygonFill)
				glutSolidDodecahedron();
			else
				glutWireDodecahedron();
			break;
		case ICOSAHEDRON:	//����ʮ����
			m_3DRadius=Win_Size/4.0;
			glScaled(m_3DRadius,m_3DRadius,m_3DRadius);  //���ű任
			if(m_bPolygonFill)
				glutSolidIcosahedron();
			else
				glutWireIcosahedron();
			break;
		case OCTAHEDRON:	//��������
			m_3DRadius=Win_Size/4.0;
			glScaled(m_3DRadius,m_3DRadius,m_3DRadius);  //���ű任
			if(m_bPolygonFill)
				glutSolidOctahedron();
			else
				glutWireOctahedron();
			break;
		case SPHERE:		//����
			m_3DRadius=Win_Size/4.0;
			if(m_bPolygonFill)
				glutSolidSphere(m_3DRadius,30,30);
			else
				glutWireSphere(m_3DRadius,30,30);
			break;
		case TORUS:			//Բ����
			m_3DRadius=Win_Size/4.0;
			if(m_bPolygonFill)
				glutSolidTorus(m_3DRadius/2.0,m_3DRadius,30,30);
			else
				glutWireTorus(m_3DRadius/2.0,m_3DRadius,30,30);
			break;
		case TEAPOT:		//���
			m_3DRadius=Win_Size/4.0;
			if(m_bPolygonFill)
				glutSolidTeapot(m_3DRadius);
			else
				glutWireTeapot(m_3DRadius);
			break;
		case STRETCH:		//����
			Draw_Stretch();
			break;
		case SELECT:
			Draw_Select();
			break;
		case BITMAP:	//λͼ
			//glRasterPos3f(.0,.0,0.0);
			GLfloat x,y;
			if(aspect_ratio<1){		
				x=-Win_Size;
				y=Win_Size/aspect_ratio-32/winHeight*Win_Size;
			}else{
				x=-Win_Size*aspect_ratio;
				y=Win_Size-32/winHeight*Win_Size;
			}
			glRasterPos2f(x,y);  //���Ͻ�
			glBitmap(32,32,0.0,0.0,0.0,0.0,Zebra);
			break;
		case IMAGE_FILE:
			Draw_Image();
			//if(m_pImage)
				//glDrawPixels(m_iWidth,m_iHeight,GL_RGB,GL_UNSIGNED_BYTE,m_pImage);
			break;
		case TEXTURE_MAP_2D:
			glEnable(GL_TEXTURE_2D);
			glBegin(GL_QUADS);
				glTexCoord2f(0.0f,0.0f);
				glVertex3f(-Win_Size/3.0,-Win_Size/3.0,0.0);
				glTexCoord2f(1.0f,0.0f);
				glVertex3f(Win_Size/3.0,-Win_Size/3.0,0.0);
				glTexCoord2f(1.0f,1.0f);
				glVertex3f(Win_Size/3.0,Win_Size/3.0,0.0);
				glTexCoord2f(0.0f,1.0f);
				glVertex3f(-Win_Size/3.0,Win_Size/3.0,0.0);
			glEnd();
			glDisable(GL_TEXTURE_2D);
			break;
		case IMAGE_MAP_OBJECT:
			Draw_ImageMapObject();
			break;
		case TEXTURE_MAP_1D:
			glBindTexture(GL_TEXTURE_1D,m_texture1D);
			glBegin(GL_QUADS);
				glNormal3f(0.0,0.0,1.0);
				glVertex3f(-Win_Size/6.0,-Win_Size/6.0,0.0);
				glVertex3f(Win_Size/6.0,-Win_Size/6.0,0.0);
				glVertex3f(Win_Size/6.0,Win_Size/6.0,0.0);
				glVertex3f(-Win_Size/6.0,Win_Size/6.0,0.0);
			glEnd();
			break;
		case TEXTURE_SPHERE:
			glEnable(GL_TEXTURE_GEN_S);		//����������������
			glEnable(GL_TEXTURE_GEN_T);		//����������������
			glDepthMask(GL_TRUE);
			glBindTexture(GL_TEXTURE_2D,m_ImageSphere[1]);
			glutSolidTorus(Win_Size/8.0,Win_Size/4.0,30,30);
			glDisable(GL_TEXTURE_GEN_S);
			glDisable(GL_TEXTURE_GEN_T);
			break;
		case QUADRICOBJ:
			Draw_QuadricObj();
			break;
		case BEZIERLINE:
			if(m_Point_Array.GetSize()>1){
				glEnable(GL_MAP1_VERTEX_3);		//������ֵ��
				glMapGrid1f(100,0,1);			//����һά����
				glEvalMesh1(GL_LINE,0,100);		//����һά���񣬼� Bezier ����
				glDisable(GL_MAP1_VERTEX_3);
			}
			break;
		case BEZIERSURF:
			if(m_Point_Array.GetSize()>1){	
				glEnable(GL_MAP2_VERTEX_3);			//������ֵ��
				glEnable(GL_AUTO_NORMAL);			//�����Զ����������ɹ���
				glMapGrid2f(50,0.0,1.0,10,0,1.0);	//���ö�ά����
				glEvalMesh2(GL_LINE,0,50,0,50);		//���ƶ�ά����
				glDisable(GL_MAP2_VERTEX_3);
				glDisable(GL_AUTO_NORMAL);
			}
			break;
		case NURBSLINE:
			Draw_NURBSLine();
			break;
		case NURBSSURF:
			Draw_NURBSSurf();
			break;
		default:
			break;
	}

	if(m_LinePattern!=-1){
		glDisable(GL_LINE_STIPPLE);
	}

	Draw_Blend();

	glPopMatrix();  //�ָ�ԭ���������
}

void CGLTest001View::InitOperation(){
	//����ÿ��ͼ��ʱ����ز�������Ϊ��ʼֵ
	//m_Rflag=1;  //ʰȡ����
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

void CGLTest001View::SetVertexesToGL(){
	for(int i=0;i<m_Point_Array.GetSize();i++){
		GLPoint pt(m_Point_Array[i]);
		glVertex3f(pt.x,pt.y,pt.z);
	}
}
//��ʵ�����ú���
void CGLTest001View::RealEnvironmentSet(){
	if(m_DepthFlag==TRUE)
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);
	if(m_LightFlag)
		glEnable(GL_LIGHTING);
	else
		glDisable(GL_LIGHTING);
	//���õƹ�
	GLfloat ambientLight[] = {.1f,.1f,.1f,1.f};
	GLfloat diffuseLight[] = {0.9f,0.9f,0.9f,1.0f};
	GLfloat specularLight[] = {1.0f,1.0f,1.0f,1.0f};
	GLfloat light0Pos[] = {-Win_Size,-Win_Size,-Win_Size,1.0f};
	GLfloat light1Pos[] = {Win_Size,Win_Size,Win_Size,1.0f};
	//0�ŵ�
	glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT0,GL_SPECULAR,specularLight);
	glLightfv(GL_LIGHT0,GL_POSITION,light0Pos);
	if(m_Light0Flag)
		glEnable(GL_LIGHT0);
	else
		glDisable(GL_LIGHT0);
	//1�ŵ�
	glLightfv(GL_LIGHT1,GL_AMBIENT,ambientLight);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,diffuseLight);
	glLightfv(GL_LIGHT1,GL_SPECULAR,specularLight);
	glLightfv(GL_LIGHT1,GL_POSITION,light1Pos);
	if(m_Light1Flag)
		glEnable(GL_LIGHT1);
	else
		glDisable(GL_LIGHT1);
	//�Ƿ����ù���ģ�ͣ�������ã����ʲ��ٸ��ٵ�ǰ��ɫ
	if(m_LightModelFlag==TRUE){  //���ù���ģ��
		glDisable(GL_COLOR_MATERIAL);
		glLightModelf(GL_LIGHT_MODEL_TWO_SIDE,1.0f);	//˫�����
		GLfloat lmodel_ambient[]={0.4f,0.4f,0.4f,1.0f};
		GLfloat local_view[]={0.0f};
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);
		glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER,local_view);
	}
	else{
		if(m_MaterialColorFlag==TRUE){		//�Ƿ���ٵ�ǰ��ͼ��ɫ
			glEnable(GL_COLOR_MATERIAL);
			glColorMaterial(GL_FRONT_AND_BACK,GL_AMBIENT_AND_DIFFUSE);
		}
		else
			glDisable(GL_COLOR_MATERIAL);
	}
	//��������
	GLfloat mat_ambient[]={0.2f,0.2f,0.2f,1.0f};		//��������Ի�����ķ���
	GLfloat mat_diffuse[]={0.1f,0.5f,0.6f,1.0f};		//����������������ķ���
	GLfloat mat_specular[]={0.5f,0.5f,0.5f,1.0f};		//��������Ծ����ķ���
	GLfloat mat_back_ambient[]={0.1f,0.1f,0.1f,1.0f};	//���ʱ���Ի�����ķ���
	GLfloat mat_back_diffuse[]={0.1f,0.4f,0.5f,1.0f};	//���ʱ�����������ķ���
	GLfloat mat_back_specular[]={0.3f,0.3f,0.3f,1.0f};	//���ʱ���Ծ����ķ���
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
	glMaterialf(GL_FRONT,GL_SHININESS,50.0);
	glMaterialfv(GL_BACK,GL_AMBIENT,mat_back_ambient);
	glMaterialfv(GL_BACK,GL_DIFFUSE,mat_back_diffuse);
	glMaterialfv(GL_BACK,GL_SPECULAR,mat_back_specular);
	if(m_MatEmissionFlag==TRUE){	//���ò����Է���
		GLfloat mat_emission[]={0.3f,0.2f,0.2f,1.0f};
		glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);	//�����Է���
	}
	else{
		GLfloat mat_emission[]={0.0f,0.0f,0.0f,1.0f};
		glMaterialfv(GL_FRONT,GL_EMISSION,mat_emission);
	}
	//���ñ�����ɫ
	glClearColor(m_iR_BG,m_iG_BG,m_iB_BG,1.0f);
}
//ѡȡ
void CGLTest001View::DoSelection(GLfloat xPos,GLfloat yPos){
	GLint hits,viewport[4];
	int cx,cy;
	GLuint SelBuff[64];
	////����ѡ�񻺳���
	glSelectBuffer(64,SelBuff);

	////���þ�������������л���ͶӰ����ģʽ��Ȼ����ѹջ������Ϊ��λ����
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();

	////����ʰȡ����
	glGetIntegerv(GL_VIEWPORT,viewport);		//��ô�������
	gluPickMatrix(xPos,viewport[3]-yPos+viewport[1],2,2,viewport);	//����ʰȡ����

	//��������Ⱦģʽ����ͬ��ͶӰ����
	cx=winWidth*2;
	cy=winHeight*2;
	glViewport(0,0,cx,cy);
	if(cx<cy){
		winWidth=Win_Size;
		winHeight=Win_Size/aspect_ratio;
	}
	else{
		winWidth=Win_Size*aspect_ratio;
		winHeight=Win_Size;
	}
	glOrtho(-winWidth,winWidth,-winHeight,winHeight,-Win_Size*5,Win_Size*5);
	winWidth=cx/2.0;
	winHeight=cy/2.0;

	//�л���Ⱦģʽ�� SELECT ģʽ
	glRenderMode(GL_SELECT);
	////��Ⱦ���Ѽ�����
	RenderScene();
	hits=glRenderMode(GL_RENDER);

	////����ͶӰģʽ
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	////����ģ�ͻ�ͼģʽ
	glMatrixMode(GL_MODELVIEW);

	//����ѡ��ʰȡ����
	if(hits==1){
		int count=0;
		switch(SelBuff[3]){
			case SPHERE:
				count=SelBuff[0];
				if(count==2){
					if(SelBuff[4]==CUBE)
						AfxMessageBox("��������-������");
					else if(SelBuff[4]==SPHERE)
						AfxMessageBox("��������-��");
				}
				else
					AfxMessageBox("��������");
				break;
			case CUBE:
				AfxMessageBox("������������");
				break;
			case CONE:
				AfxMessageBox("������Բ׶��");
				break;
			case TEAPOT:
				AfxMessageBox("�����˲��");
				break;
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

void CGLTest001View::Draw_Stretch(){
	GLfloat ver[3][3],nor[3];
	GLPoint pt,pt1,pt2,pt3;
	//�������������ף����Ȼ����µ��棬���趥������ʱ������
	if(m_fLength>0)
		glNormal3f(0.0,0.0,-1.0);
	else
		glNormal3f(0.0,0.0,1.0);
	Util::PolygonTesslator(m_Pt_Array_Polygon);  //���ö��������ϸ�ֶ����
	//�����ϵ���
	if(m_fLength>0)
		glNormal3f(0.0,0.0,1.0);
	else
		glNormal3f(0.0,0.0,-1.0);
	CArray<GLPoint,GLPoint> m_Pt_Array_up;
	for(int i=this->m_Pt_Array_Polygon.GetSize()-1;i>=0;i--){
		pt=m_Pt_Array_Polygon[i];
		pt.z+=m_fLength;
		m_Pt_Array_up.Add(pt);
	}
	Util::PolygonTesslator(m_Pt_Array_up);
	//���Ʋ��棬���ȼ����ⷨ����
	for(i=0;i<this->m_Pt_Array_Polygon.GetSize();i++){
		pt=m_Pt_Array_Polygon[i];
		if(i<this->m_Pt_Array_Polygon.GetSize()-1)
			pt1=m_Pt_Array_Polygon[i+1];
		else
			pt1=m_Pt_Array_Polygon[0];
		pt2=pt1;
		pt2.z+=m_fLength;
		pt3=pt;
		pt3.z+=m_fLength;
		//����������
		ver[0][0]=pt.x; ver[0][1]=pt.y; ver[0][2]=pt.z;
		ver[1][0]=pt1.x; ver[1][1]=pt1.y; ver[1][2]=pt1.z;
		ver[2][0]=pt2.x; ver[2][1]=pt2.y; ver[2][2]=pt2.z;
		Util::CalCulateNormal(ver,nor);
		glBegin(GL_POLYGON);
			glNormal3fv(nor);
			glVertex3f(pt.x,pt.y,pt.z);
			glVertex3f(pt1.x,pt1.y,pt1.z);
			glVertex3f(pt2.x,pt2.y,pt2.z);
			glVertex3f(pt3.x,pt3.y,pt3.z);
		glEnd();
	}
}

void CGLTest001View::Draw_Blend(){
	if(m_BlendFlag==0)
		return;
	else if(m_BlendFlag==1){	//���
		GLUquadricObj * obj;	//����һ����������ָ��
		obj = gluNewQuadric();  //���ɶ����������

		glPushMatrix();
		glTranslatef(0.0,Win_Size/3,0.0);
		glColor4f(1.0,0.0,0.0,1.0);
		gluDisk(obj,0,Win_Size/3,30,1);		////����һ��Բ��
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-Win_Size/5.0,0,-Win_Size/5);
		glColor4f(0.0,1.0,0.0,1.0);
		gluDisk(obj,0,Win_Size/3,30,1);		//����һ��Բ��
		glPopMatrix();

		glPushMatrix();
		glTranslatef(Win_Size/5.0,0,-Win_Size/3.0);
		glColor4f(0.0,0.0,1.0,1.0);
		gluDisk(obj,0,Win_Size/3,30,1);		//����һ��Բ��
		glPopMatrix();

		gluDeleteQuadric(obj);		//ɾ�������������
	}
	else if(m_BlendFlag==2){  //͸��
		glPushMatrix();
		glTranslatef(0.0,0.0,-Win_Size/2.0);
		glColor4f(1.0,0.0,0.0,1.0);
		m_3DRadius=Win_Size/4.0;
		if(m_bPolygonFill)		//����һ��Բ��
			glutSolidTorus(m_3DRadius/2.0,m_3DRadius,30,30);
		else
			glutWireTorus(m_3DRadius/2.0,m_3DRadius,30,30);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(Win_Size/4.0,Win_Size/4.0,Win_Size/2.0);
		glColor4f(0.0,1.0,0.0,0.4f);
		glutSolidSphere(Win_Size/2.0,30.0,30.0);	//����һ����
		glPopMatrix();
	}
}
//ѡȡ
void CGLTest001View::Draw_Select(){
	if(m_flag!=SELECT)
		return;

	glPushMatrix();
		glInitNames();						//�������ֶ�ջ
		glPushName(0);						//���ֶ�ջ��ѹ��0
		glColor3f(1.0f,1.0f,0.0f);
		glPushMatrix();	
			glTranslatef(-Win_Size/2.0,Win_Size/2.0,0.0f);
			glLoadName(SPHERE);				//�����������ѹ���ջ
			glutSolidSphere(Win_Size/4.0,30,30);	//��������
			glTranslatef(-Win_Size/4.0,-Win_Size/4.0,0.0f);
			glColor3f(0.0,0.0,0.5);
			glPushName(CUBE);				//�����в�ι�ϵ������������ѹ���ջ
			glutSolidCube(Win_Size/5.0);	//����������
			glPopName();					//��ջ�е�����������
			glTranslatef(Win_Size/2.0,0.0,0.0);
			glColor3f(0.0,0.0,0.5);			
			glPushName(SPHERE);				//�����в�ι�ϵ����������ѹ���ջ
			glutSolidSphere(Win_Size/5.0,30,30);	//��������
			glPopName();					//��ջ�е�����������
		glPopMatrix();
		
		glColor3f(0.5f,0.0,0.0);
		glPushMatrix();						
			glTranslatef(Win_Size/2.0,Win_Size/2.0,0.0);
			glLoadName(CUBE);				//�������������ѹ���ջ
			glutSolidCube(Win_Size/4.0);	//����������
		glPopMatrix();

		glColor3f(0.5,0.5,1.0);
		glPushMatrix();
			glTranslatef(-Win_Size/2.0,-Win_Size/2.0,0.0);
			glLoadName(CONE);				//��Բ׶������ѹ���ջ/
			glutSolidCone(Win_Size/4.0,Win_Size/4.0,20,20);		//����Բ׶��
		glPopMatrix();

		glColor3f(0.0,0.0,1.0);
		glPushMatrix();
			glTranslatef(Win_Size/2.0,-Win_Size/2.0,0.0);
			glLoadName(TEAPOT);				//�����������ѹ���ջ
			glutSolidTeapot(Win_Size/4.0);	//���Ʋ��
		glPopMatrix();
	glPopMatrix();
}

void CGLTest001View::Draw_Image(){
	if(m_pImage){ //����ͼ��
		GLfloat halfW,halfH; //ͶӰ�ռ��߼����꣬����������ͨ��ͶӰ�����໥ӳ��
		if(aspect_ratio<1){	//�������Կ�Ϊ��׼�������䣬������
			halfW=m_iWidth/winWidth/2.0*Win_Size;
			halfH=m_iHeight/winWidth/2.0*Win_Size;
		}
		else{	//�߲������Ը�Ϊ��׼�����߲�����������
			halfW=m_iWidth/winHeight/2.0*Win_Size;
			halfH=m_iHeight/winHeight/2.0*Win_Size;
		}
		
		switch(m_ImageFlag){
			default:
			glRasterPos2f(-halfW,-halfH);
			break;
		case IMAGEZOOM:
			glPixelZoom(0.5,0.5f);
			glRasterPos2f(-halfW*0.5f,-halfH*0.5f);
			break;
		case IMAGEREVERSE:
			glPixelZoom(-1.0f,-1.0f);	//���ᷴ����ô���Ʒ���Ҳ�ᷴ��
			glRasterPos2f(halfW,halfH); //����Ϊ���Ͻ�
			break;
		case IMAGERED:
			glRasterPos2f(-halfW,-halfH);
			glPixelTransferf(GL_RED_SCALE,1.0f);
			glPixelTransferf(GL_GREEN_SCALE,0.0f);
			glPixelTransferf(GL_BLUE_SCALE,0.0f);
			break;
		case IMAGEGREEN:
			glRasterPos2f(-halfW,-halfH);
			glPixelTransferf(GL_RED_SCALE,0.0f);
			glPixelTransferf(GL_GREEN_SCALE,1.0f);
			glPixelTransferf(GL_BLUE_SCALE,0.0f);
			break;
		case IMAGEBLUE:
			glRasterPos2f(-halfW,-halfH);
			glPixelTransferf(GL_RED_SCALE,0.0f);
			glPixelTransferf(GL_GREEN_SCALE,0.0f);
			glPixelTransferf(GL_BLUE_SCALE,1.0f);
			break;
		case IMAGEGRAYMAP:
			glRasterPos2f(-halfW,-halfH);
			if(m_pImageModefied==NULL){
				m_pImageModefied=(GLubyte *)new GLubyte[m_iWidth*m_iHeight];
				glDrawPixels(m_iWidth,m_iHeight,GL_RGB,GL_UNSIGNED_BYTE,m_pImage);
				
				glPixelTransferf(GL_RED_SCALE,0.3f);
				glPixelTransferf(GL_GREEN_SCALE,0.59f);
				glPixelTransferf(GL_BLUE_SCALE,0.11f);
				//��ȡ�����Ϊ�������꣬����ԭ������Ļ����
				glReadPixels(winWidth-m_iWidth/2.0,winHeight-m_iHeight/2.0,m_iWidth,m_iHeight,GL_LUMINANCE,GL_UNSIGNED_BYTE,m_pImageModefied);  

				glPixelTransferf(GL_RED_SCALE,1.0f);
				glPixelTransferf(GL_GREEN_SCALE,1.0f);
				glPixelTransferf(GL_BLUE_SCALE,1.0f);
			}
			break;
		case IMAGEINVERSE:
			glRasterPos2f(-halfW,-halfH);
			GLfloat invert[256];
			invert[0]=0;
			int i=1;
			for(i=1;i<256;i++)
				invert[i]=1.0-i/255.0;
			glPixelMapfv(GL_PIXEL_MAP_R_TO_R,255,invert); //��ɫͨ��ӳ��
			glPixelMapfv(GL_PIXEL_MAP_G_TO_G,255,invert);
			glPixelMapfv(GL_PIXEL_MAP_B_TO_B,255,invert);
			glPixelTransferi(GL_MAP_COLOR,GL_TRUE);
			break;
		}

		if(m_ImageFlag==IMAGEGRAYMAP)
		{
			if(m_pImageModefied)
				glDrawPixels(m_iWidth,m_iHeight,GL_LUMINANCE,GL_UNSIGNED_BYTE,m_pImageModefied);
		}
		else
			glDrawPixels(m_iWidth,m_iHeight,GL_RGB,GL_UNSIGNED_BYTE,m_pImage);

		//Ϊ��Ӱ���Ժ�Ļ�ͼ�������ٵ���ͼ���������ָ��ֳ�
		glPixelZoom(1.0f,1.0f);
		glPixelTransferi(GL_MAP_COLOR,GL_FALSE);
		glPixelTransferf(GL_RED_SCALE,1.0f);
		glPixelTransferf(GL_GREEN_SCALE,1.0f);
		glPixelTransferf(GL_BLUE_SCALE,1.0f);
		if(aspect_ratio<1)
			glRasterPos2f(-Win_Size,-Win_Size/aspect_ratio);
		else
			glRasterPos2f(-Win_Size * aspect_ratio,-Win_Size);
	}		
}

void CGLTest001View::Draw_ImageMapObject(){
	if(m_flag!=IMAGE_MAP_OBJECT)
		return;
	GLfloat sizeScale=0.5f;
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glColor4f(1.0f,1.0f,1.0f,0.4f);		////����͸����
	glBindTexture(GL_TEXTURE_2D,m_imageIDs[0]);   ////�󶨵�ǰ��
	glBegin(GL_POLYGON);
		glNormal3f(0.0,0.0,1.0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-Win_Size*sizeScale,-Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(1.0,0.0);
		glVertex3f(Win_Size*sizeScale,-Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(1.0,1.0);
		glVertex3f(Win_Size*sizeScale,Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-Win_Size*sizeScale,Win_Size*sizeScale,Win_Size*sizeScale);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,m_imageIDs[0]);   //����
	glBegin(GL_POLYGON);
		glNormal3f(0.0,0.0,-1.0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-Win_Size*sizeScale,-Win_Size*sizeScale,-Win_Size*sizeScale);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-Win_Size*sizeScale,Win_Size*sizeScale,-Win_Size*sizeScale);
		glTexCoord2f(1.0,1.0);
		glVertex3f(Win_Size*sizeScale,Win_Size*sizeScale,-Win_Size*sizeScale);
		glTexCoord2f(1.0,0.0);
		glVertex3f(Win_Size*sizeScale,-Win_Size*sizeScale,-Win_Size*sizeScale);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,m_imageIDs[1]);   //����
	glBegin(GL_POLYGON);
		glNormal3f(1.0,0.0,0.0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(Win_Size*sizeScale,-Win_Size*sizeScale,-Win_Size*sizeScale);
		glTexCoord2f(1.0,0.0);
		glVertex3f(Win_Size*sizeScale,-Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(1.0,1.0);
		glVertex3f(Win_Size*sizeScale,Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(0.0,1.0);
		glVertex3f(Win_Size*sizeScale,Win_Size*sizeScale,-Win_Size*sizeScale);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,m_imageIDs[1]);   //����
	glBegin(GL_POLYGON);
		glNormal3f(-1.0,0.0,0.0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-Win_Size*sizeScale,-Win_Size*sizeScale,-Win_Size*sizeScale);
		glTexCoord2f(1.0,0.0);
		glVertex3f(-Win_Size*sizeScale,-Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(1.0,1.0);
		glVertex3f(-Win_Size*sizeScale,Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-Win_Size*sizeScale,Win_Size*sizeScale,-Win_Size*sizeScale);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,m_imageIDs[2]);   //����
	glBegin(GL_POLYGON);
		glNormal3f(0.0,1.0,0.0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-Win_Size*sizeScale,Win_Size*sizeScale,-Win_Size*sizeScale);
		glTexCoord2f(1.0,0.0);
		glVertex3f(-Win_Size*sizeScale,Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(1.0,1.0);
		glVertex3f(Win_Size*sizeScale,Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(0.0,1.0);
		glVertex3f(Win_Size*sizeScale,Win_Size*sizeScale,-Win_Size*sizeScale);
	glEnd();

	glBindTexture(GL_TEXTURE_2D,m_imageIDs[2]);   //����
	glBegin(GL_POLYGON);
		glNormal3f(0.0,-1.0,0.0);
		glTexCoord2f(0.0f,0.0f);
		glVertex3f(-Win_Size*sizeScale,-Win_Size*sizeScale,-Win_Size*sizeScale);
		glTexCoord2f(1.0,0.0);
		glVertex3f(Win_Size*sizeScale,-Win_Size*sizeScale,-Win_Size*sizeScale);
		glTexCoord2f(1.0,1.0);
		glVertex3f(Win_Size*sizeScale,-Win_Size*sizeScale,Win_Size*sizeScale);
		glTexCoord2f(0.0,1.0);
		glVertex3f(-Win_Size*sizeScale,-Win_Size*sizeScale,Win_Size*sizeScale);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	if(m_DepthFlag==FALSE)
		glDisable(GL_DEPTH_TEST);
}

void CGLTest001View::Draw_TextureSphereBG(){
	if(m_flag!=TEXTURE_SPHERE)
		return;
	glPushMatrix();
	int cx,cy;
	cx=(int)winWidth*2;
	cy=(int)winHeight*2;
	::glViewport(0,0,cx,cy);	//���û�ͼ���ڴ�С
	if(aspect_ratio<1){
		winWidth=Win_Size;
		winHeight=Win_Size/aspect_ratio;
	}
	else{
		winWidth=Win_Size * aspect_ratio;
		winHeight=Win_Size;
	}
	glBindTexture(GL_TEXTURE_2D,m_ImageSphere[0]);
	glDisable(GL_TEXTURE_GEN_S);	//����������������
	glDisable(GL_TEXTURE_GEN_T);	//����������������
	glDepthMask(GL_FALSE);			//������ͼ����Ȼ�����
	glBegin(GL_QUADS);
		glTexCoord2f(0.0,0.0);
		glVertex2f(-winWidth,-winHeight);
		glTexCoord2f(1.0,0.0);
		glVertex2f(winWidth,-winHeight);
		glTexCoord2f(1.0,1.0);
		glVertex2f(winWidth,winHeight);
		glTexCoord2f(0.0,1.0);
		glVertex2f(-winWidth,winHeight);
	glEnd();
	winWidth=cx/2.0;
	winHeight=cy/2.0;
	glPopMatrix();
}

void CGLTest001View::Draw_QuadricObj(){
	if(m_flag!=QUADRICOBJ)
		return;
	GLUquadricObj * pObj;
	pObj = gluNewQuadric();			//�����ͳ�ʼ�������������
	gluQuadricDrawStyle(pObj,GLU_FILL);			//���Ʒ�ʽ�� ��/�߿�/ʵ��/����	
	gluQuadricOrientation(pObj,GLU_OUTSIDE);	//������ ����/����
	gluQuadricNormals(pObj,GL_SMOOTH);			//����ȼ�����/��ƽ��/�𶥵�
	glEnable(GL_NORMALIZE);						//���÷���λ��

	GLfloat offset=Win_Size*0.5f;
	glPushMatrix();
		glTranslatef(-offset,offset,0.0);
		glColor3f(1.0f,0.0f,0.0f);
		gluSphere(pObj,Win_Size/4.0,20,20);		//������
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,offset,0.0);
		glColor3f(1.0f,1.0f,0.0f);
		gluDisk(pObj,Win_Size/6.0,Win_Size/4.0,20,20);	//Բ��
	glPopMatrix();

	glPushMatrix();
		glTranslatef(offset,offset,0.0);
		glColor3f(0.0f,1.0f,1.0f);
		gluPartialDisk(pObj,Win_Size/6.0,Win_Size/4.0,20,20,30,300);	//������
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-offset,0.0,0.0);
		glColor3f(1.0f,0.0f,0.0f);
		gluCylinder(pObj,Win_Size/5.0,Win_Size/5.0,Win_Size/5.0,20,20);	//Բ��
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0f,0.0f,0.0f);
		glColor3f(1.0f,1.0f,0.0f);
		gluCylinder(pObj,Win_Size/5.0,0.0,Win_Size/5.0,20,20);			//Բ׶
	glPopMatrix();

	glPushMatrix();
		glTranslatef(offset,0.0,0.0);
		glColor3f(0.0f,1.0f,1.0f);
		gluCylinder(pObj,Win_Size/5.0,Win_Size/6.0,Win_Size/5.0,20,20); //Բ׶
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-offset,-offset,0.0);
		glColor3f(1.0f,0.0f,0.0f);
		glScalef(0.5f,1.0f,1.0f);
		gluSphere(pObj,Win_Size/4.0,20,20);			//�����
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0,-offset,0.0);
		glScalef(0.5f,1.0f,1.0f);
		glColor3f(1.0f,1.0f,0.0f);
		gluCylinder(pObj,Win_Size/5.0,Win_Size/5.0,Win_Size/5.0,20,20);	//����Բ��
	glPopMatrix();

	glPushMatrix();
		glTranslatef(offset,-offset,0.0);
		glScalef(1.0f,0.5f,1.0f);
		glColor3f(0.0f,1.0f,1.0f);
		gluDisk(pObj,Win_Size/6.0,Win_Size/4.0,20,20);		//����Բ��
	glPopMatrix();

	gluDeleteQuadric(pObj);		//ɾ�������������
}

void CGLTest001View::Draw_NURBSLine(){
	if(m_flag!=NURBSLINE)
		return;
	int pt_num=m_Point_Array.GetSize();
	if(pt_num>1){
		GLUnurbsObj * pNurb;
		pNurb = gluNewNurbsRenderer();		////����NURBS����
		//
		GLPoint pt;
		GLfloat (* ctrlPoints)[3];		////���ƶ�������
		GLfloat *Knots;					//�ڵ�����
		ctrlPoints=new GLfloat[pt_num][3];
		for(int i=0;i<pt_num;i++){
			pt=m_Point_Array[i];
			pt.z=0.0;
			ctrlPoints[i][0]=pt.x;
			ctrlPoints[i][1]=pt.y;
			ctrlPoints[i][2]=pt.z;
		}
		////�����ڵ�����
		if(pt_num==2){	//һ��NURBS
			Knots=new GLfloat[pt_num+2];
			for(i=0;i<pt_num+2;i++){
				if(i<2)
					Knots[i]=0;
				else
					Knots[i]=1;
			}
			////���ƶ��ף�һ�Σ�NURBS����
			gluBeginCurve(pNurb);
			gluNurbsCurve(pNurb,4,Knots,3,&ctrlPoints[0][0],2,GL_MAP1_VERTEX_3);
			gluEndCurve(pNurb);
			delete [] Knots;
		}
		else if(pt_num==3){		//����NURBS
			Knots=new GLfloat[pt_num+3];
			////����׼���Ƚڵ��������˽ڵ��ظ���3���м��ظ���1
			for(i=0;i<pt_num+3;i++){
				if(i<3)
					Knots[i]=0;
				else if(i>=3&& i<=pt_num)
					Knots[i]=i-2;
				else
					Knots[i]=pt_num-2;
			}
			////�������ף����Σ�NURBS����
			gluBeginCurve(pNurb);
			gluNurbsCurve(pNurb,pt_num+3,Knots,3,&ctrlPoints[0][0],3,GL_MAP1_VERTEX_3);
			gluEndCurve(pNurb);
			delete [] Knots;
		}
		else {		//����NURBS
			Knots = new GLfloat[pt_num+4];
			////����׼���Ƚڵ��������˽ڵ��ظ���4���м��ظ���1
			for(i=0;i<pt_num+4;i++){
				if(i<4)
					Knots[i]=0;
				else if(i>=4 && i<=pt_num)
					Knots[i]=i-3;
				else 
					Knots[i]=pt_num-3;
			}
			////�����Ľף��� �Σ�NURBS����
			gluBeginCurve(pNurb);
			gluNurbsCurve(pNurb,pt_num+4,Knots,3,&ctrlPoints[0][0],4,GL_MAP1_VERTEX_3);
			gluEndCurve(pNurb);
			delete [] Knots;
		}
		delete [] ctrlPoints;
		gluDeleteNurbsRenderer(pNurb);	//ɾ��NURBS����
	}
}
//NURB��������
void CGLTest001View::Draw_NURBSSurf(){
	if(m_flag!=NURBSSURF)
		return;
	int pt_num=m_Point_Array.GetSize();
	if(pt_num>1){
		//MessageBox("nurbssurf");
		glEnable(GL_AUTO_NORMAL);
		GLUnurbsObj * pNurb;
		pNurb = gluNewNurbsRenderer();		////����NURBS����
		gluNurbsProperty(pNurb,GLU_SAMPLING_TOLERANCE,20);
		gluNurbsProperty(pNurb,GLU_DISPLAY_MODE,GLU_FILL);
		//
		GLPoint pt;
		GLfloat (* ctrlPoints)[3];		////���ƶ�������
		GLfloat *Knots;					//�ڵ�����
		GLfloat trimPoints_out[5][3];
		GLfloat trimPoints_in[5][3];
		ctrlPoints=new GLfloat[pt_num*4][3];
		GLfloat Knott[8]={0.0f,0.0f,0.0f,0.0f,1.0f,1.0f,1.0f,1.0f};
		GLfloat texpts[2][2][2]={{{0,0},{0,1}},{{1,0},{1,1}}};
		for(int i=0;i<pt_num;i++){
			pt=m_Point_Array[i];
			pt.z=0.0;
			ctrlPoints[i][0]=pt.x;
			ctrlPoints[i][1]=pt.y;
			ctrlPoints[i][2]=pt.z;
			pt.z=Win_Size*0.33;		//��z��ƽ��һ�����룬����¿��ƶ���
			ctrlPoints[i+pt_num][0]=pt.x;
			ctrlPoints[i+pt_num][1]=pt.y;
			ctrlPoints[i+pt_num][2]=pt.z;
			pt.z=Win_Size*0.66;		//��z��ƽ��һ�����룬����¿��ƶ���
			ctrlPoints[i+pt_num*2][0]=pt.x;
			ctrlPoints[i+pt_num*2][1]=pt.y;
			ctrlPoints[i+pt_num*2][2]=pt.z;
			pt.z=Win_Size;			//��z��ƽ��һ�����룬����¿��ƶ���
			ctrlPoints[i+pt_num*3][0]=pt.x;
			ctrlPoints[i+pt_num*3][1]=pt.y;
			ctrlPoints[i+pt_num*3][2]=pt.z;
		}
		if(m_NurbsTrimFlag==1){
			trimPoints_out[0][0]=trimPoints_out[4][0]=0.1;
			trimPoints_out[0][1]=trimPoints_out[4][1]=0.1;
			trimPoints_out[1][0]=0.9;
			trimPoints_out[1][1]=0.1;
			trimPoints_out[2][0]=0.9;
			trimPoints_out[2][1]=0.9;
			trimPoints_out[3][0]=0.1;
			trimPoints_out[3][1]=0.9;
			trimPoints_in[0][0]=trimPoints_in[4][0]=0.35;
			trimPoints_in[0][1]=trimPoints_in[4][1]=0.35;
			trimPoints_in[1][0]=0.35;
			trimPoints_in[1][1]=0.7;
			trimPoints_in[2][0]=0.7;
			trimPoints_in[2][1]=0.7;
			trimPoints_in[3][0]=0.7;
			trimPoints_in[3][1]=0.35;
		}
		if(Surf_Texture_flag==1){
			glBindTexture(GL_TEXTURE_2D,Surf_texture);
			glMap2f(GL_MAP2_TEXTURE_COORD_2,0,1,2,2,0,1,4,2,&texpts[0][0][0]);
			glEnable(GL_MAP2_TEXTURE_COORD_2);
		}
		////�����ڵ�����
		if(pt_num==2){	//һ��NURBS
			Knots=new GLfloat[pt_num+2];
			for(i=0;i<pt_num+2;i++){
				if(i<2)
					Knots[i]=0;
				else
					Knots[i]=1;
			}
			////����NURBS����
			gluBeginCurve(pNurb);
			gluNurbsCurve(pNurb,4,Knots,3,&ctrlPoints[0][0],2,GL_MAP1_VERTEX_3);
			gluNurbsSurface(pNurb,4,Knots,8,Knott,3,pt_num*3,&ctrlPoints[0][0],2,4,GL_MAP2_VERTEX_3);
			if(m_NurbsTrimFlag==1){
				gluBeginTrim(pNurb);
				gluPwlCurve(pNurb,5,&trimPoints_out[0][0],2,GLU_MAP1_TRIM_2);
				gluEndTrim(pNurb);
				gluBeginTrim(pNurb);
				gluPwlCurve(pNurb,5,&trimPoints_in[0][0],2,GLU_MAP1_TRIM_2);
				gluEndTrim(pNurb);
			}
			gluEndCurve(pNurb);
			delete [] Knots;
		}
		else if(pt_num==3){		//����NURBS
			Knots=new GLfloat[pt_num+3];
			////����׼���Ƚڵ��������˽ڵ��ظ���3���м��ظ���1
			for(i=0;i<pt_num+3;i++){
				if(i<3)
					Knots[i]=0;
				else if(i>=3&& i<=pt_num)
					Knots[i]=i-2;
				else
					Knots[i]=pt_num-2;
			}
			////����NURBS����
			gluBeginCurve(pNurb);
			gluNurbsCurve(pNurb,pt_num+3,Knots,3,&ctrlPoints[0][0],3,GL_MAP1_VERTEX_3);
			gluNurbsSurface(pNurb,6,Knots,8,Knott,3,pt_num*3,&ctrlPoints[0][0],3,4,GL_MAP2_VERTEX_3);
			if(m_NurbsTrimFlag==1){
				gluBeginTrim(pNurb);
				gluPwlCurve(pNurb,5,&trimPoints_out[0][0],2,GLU_MAP1_TRIM_2);
				gluEndTrim(pNurb);
				gluBeginTrim(pNurb);
				gluPwlCurve(pNurb,5,&trimPoints_in[0][0],2,GLU_MAP1_TRIM_2);
				gluEndTrim(pNurb);
			}
			gluEndCurve(pNurb);
			delete [] Knots;
		}
		else {		//����NURBS
			Knots = new GLfloat[pt_num+4];
			////����׼���Ƚڵ��������˽ڵ��ظ���m+1���м��ظ���С��m
			for(i=0;i<pt_num+4;i++){
				if(i<4)
					Knots[i]=0;
				else if(i>=4 && i<=pt_num)
					Knots[i]=i-3;
				else 
					Knots[i]=pt_num-3;
			}
			////����NURBS����
			gluBeginCurve(pNurb);
			gluNurbsCurve(pNurb,pt_num+4,Knots,3,&ctrlPoints[0][0],4,GL_MAP1_VERTEX_3);
			gluNurbsSurface(pNurb,pt_num+4,Knots,8,Knott,3,pt_num*3,&ctrlPoints[0][0],4,4,GL_MAP2_VERTEX_3);
			if(m_NurbsTrimFlag==1){
				gluBeginTrim(pNurb);
				gluPwlCurve(pNurb,5,&trimPoints_out[0][0],2,GLU_MAP1_TRIM_2);
				gluEndTrim(pNurb);
				gluBeginTrim(pNurb);
				gluPwlCurve(pNurb,5,&trimPoints_in[0][0],2,GLU_MAP1_TRIM_2);
				gluEndTrim(pNurb);
			}
			gluEndCurve(pNurb);
			delete [] Knots;
		}
		delete [] ctrlPoints;
		gluDeleteNurbsRenderer(pNurb);	//ɾ��NURBS����
	}
}

void CGLTest001View::SetFogMode(){
	if(m_FogMode==0){
		glDisable(GL_FOG);
	}
	else{
		glEnable(GL_FOG);
		if(m_FogMode==1)
			glFogi(GL_FOG_MODE,GL_LINEAR);
		else if(m_FogMode==2)
			glFogi(GL_FOG_MODE,GL_EXP);
		else if(m_FogMode==3)
			glFogi(GL_FOG_MODE,GL_EXP2);
		GLfloat fogColor[]={1,1,1,1.0};
		glFogfv(GL_FOG_COLOR,fogColor);
		glFogf(GL_FOG_DENSITY,0.6f);
		glHint(GL_FOG_HINT,GL_DONT_CARE);
		glFogf(GL_FOG_START,-Win_Size);
		glFogf(GL_FOG_END,Win_Size);
	}
	Invalidate();
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
	RealEnvironmentSet();
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

void CGLTest001View::OnPoint() 
{
	// TODO: Add your command handler code here
	m_flag=GLPOINTS;
	m_Rflag=1;  //ʰȡ����
	InitOperation();
}

void CGLTest001View::OnLine() 
{
	// TODO: Add your command handler code here
	m_flag=GLLINES;
	m_Rflag=1;  //ʰȡ����
	InitOperation();
}

void CGLTest001View::OnLineStrip() 
{
	// TODO: Add your command handler code here
	m_flag=GLLINESTRIP;
	m_Rflag=1;  //ʰȡ����
	InitOperation();
}

void CGLTest001View::OnLineLoop() 
{
	// TODO: Add your command handler code here
	m_flag=GLLINELOOP;
	m_Rflag=1;  //ʰȡ����
	InitOperation();
}

void CGLTest001View::OnTriangle() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLES;
	m_Rflag=1;  //ʰȡ����
	//MessageBox("����");
	InitOperation();
}

void CGLTest001View::OnTriangleStrip() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLESTRIP;
	m_Rflag=1;  //ʰȡ����
	//MessageBox("����-��");
	InitOperation();
}

void CGLTest001View::OnTriangleFan() 
{
	// TODO: Add your command handler code here
	m_flag=GLTRIANGLEFAN;
	m_Rflag=1;  //ʰȡ����
	//MessageBox("����-��");
	InitOperation();
}

void CGLTest001View::OnQuad() 
{
	// TODO: Add your command handler code here
	m_flag=GLQUADS;
	m_Rflag=1;  //ʰȡ����
	//MessageBox("�ı���");
	InitOperation();
}

void CGLTest001View::OnQuadStrip() 
{
	// TODO: Add your command handler code here
	m_flag=GLQUADSTRIP;
	m_Rflag=1;  //ʰȡ����
	//MessageBox("�ı���-��");
	InitOperation();
}

void CGLTest001View::OnPolygon() 
{
	// TODO: Add your command handler code here
	m_flag=GLPOLYGON;
	m_Rflag=1;  //ʰȡ����
	//MessageBox("�����");
	InitOperation();
}
//Բ׶��
void CGLTest001View::OnCone() 
{
	// TODO: Add your command handler code here
	m_flag=CONE;
	InitOperation();
}
//������
void CGLTest001View::OnCube() 
{
	// TODO: Add your command handler code here
	m_flag=CUBE;
	InitOperation();
}
//������
void CGLTest001View::OnTetrahedron() 
{
	// TODO: Add your command handler code here
	m_flag=TETRAHEDRON;
	InitOperation();
}
//��ʮ������
void CGLTest001View::OnDodecahedron() 
{
	// TODO: Add your command handler code here
	m_flag=DODECAHEDRON;
	InitOperation();
}
//����ʮ����
void CGLTest001View::OnIcosahedron() 
{
	// TODO: Add your command handler code here
	m_flag=ICOSAHEDRON;
	InitOperation();
}
//��������
void CGLTest001View::OnOctahedron() 
{
	// TODO: Add your command handler code here
	m_flag=OCTAHEDRON;
	InitOperation();
}

//����
void CGLTest001View::OnSphere() 
{
	// TODO: Add your command handler code here
	m_flag=SPHERE;
	InitOperation();
}
//Բ����
void CGLTest001View::OnTorus() 
{
	// TODO: Add your command handler code here
	m_flag=TORUS;
	InitOperation();
}
//���
void CGLTest001View::OnTeapot() 
{
	// TODO: Add your command handler code here
	m_flag=TEAPOT;
	InitOperation();
}

//�Ҽ�
void CGLTest001View::OnRButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_Rflag=0;  //����ʰȡ����
	Invalidate();
	CView::OnRButtonDown(nFlags, point);
}

//���
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

		int pt_num=m_Point_Array.GetSize();
		if(m_flag==BEZIERLINE){  //Bezier ���߿��Ƶ�
			if(pt_num>1){
				GLfloat (* quad)[3];
				quad = new GLfloat[pt_num][3];
				for(int i=0;i<pt_num;i++){
					pt=m_Point_Array[i];
					pt.z=0.0;
					quad[i][0]=pt.x;
					quad[i][1]=pt.y;
					quad[i][2]=pt.z;
				}
				////������ֵ��
				glMap1f(GL_MAP1_VERTEX_3,0.0,1.0,3,pt_num,&quad[0][0]);
				delete []quad;
			}
		}
		else if(m_flag==BEZIERSURF){
			if(pt_num>1){
				GLfloat (* quad)[3];
				quad=new GLfloat[pt_num*2][3];	//Bezier ������Ƶ�
				for(int i=0;i<pt_num;i++){
					pt=m_Point_Array[i];
					pt.z=0.0;
					quad[i][0]=pt.x;
					quad[i][1]=pt.y;
					quad[i][2]=pt.z;
					pt.z=1.0;
					quad[i+pt_num][0]=pt.x;
					quad[i+pt_num][1]=pt.y;
					quad[i+pt_num][2]=pt.z;
				}
				//������ֵ��
				glMap2f(GL_MAP2_VERTEX_3,0,1,3,pt_num,0,1,pt_num*3,2,&quad[0][0]);
				delete [] quad;
			}
		}
		Invalidate();
	}
	else if(m_Rflag==0){
		if(m_flag==SELECT){
			DoSelection(point.x,point.y);
		}
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
	RealEnvironmentSet();
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

//��������
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

//����������������-�˵���
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
//���������������� -������
void CGLTest001View::OnPolygonFillTool() 
{
	// TODO: Add your command handler code here
	m_bPolygonFill=!m_bPolygonFill;
	Invalidate();
}

//����
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
		if(GetAsyncKeyState(VK_LSHIFT)&&0x8000)  //Shift���Ƿ񱻰���
			m_Scale+=0.1;		//�������ű���
		else
			m_btMove+=0.1;		//���������ƶ�
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
		m_lrMove-=0.1;		//����ˮƽ�ƶ�
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
	m_rAngle+=1.0;		//��ת�Ƕ�
	Invalidate();
	CView::OnTimer(nIDEvent);
}

//��������
void CGLTest001View::OnEnvironmentset() 
{
	// TODO: Add your command handler code here
	CEnvironmentSetDlg dlg;
	dlg.m_pView=this;
	dlg.m_depthFlag=this->m_DepthFlag;
	dlg.m_lightFlag=this->m_LightFlag;
	dlg.m_light0=this->m_Light0Flag;
	dlg.m_light1=this->m_Light1Flag;
	dlg.m_lightModelFlag=this->m_LightModelFlag;
	dlg.m_colorMaterialFlag=this->m_MaterialColorFlag;
	dlg.m_emissionFlag=this->m_MatEmissionFlag;
	dlg.m_fogMode=this->m_FogMode;
	dlg.DoModal();
}
//����
void CGLTest001View::OnStretch() 
{
	// TODO: Add your command handler code here
	m_Pt_Array_Polygon.RemoveAll();
	m_Pt_Array_Polygon.Append(this->m_Point_Array);
	m_fLength=Win_Size/2.0;
	m_flag=STRETCH;
	m_Rflag=0;
	InitOperation();
}
//����UI
void CGLTest001View::OnUpdateStretch(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_flag==GLLINELOOP&&m_Point_Array.GetSize()>=3);
}
//��ɫ���
void CGLTest001View::OnBlend() 
{
	// TODO: Add your command handler code here
	if(m_BlendFlag==0){
		glBlendFunc(GL_ONE_MINUS_DST_COLOR,GL_ONE_MINUS_SRC_COLOR);
		glEnable(GL_BLEND);
		m_BlendFlag=1;
	}
	else{
		glDisable(GL_BLEND);
		m_BlendFlag=0;
	}
	Invalidate();
}

//͸��
void CGLTest001View::OnTransparent() 
{
	// TODO: Add your command handler code here
	if(m_BlendFlag==0){
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		m_BlendFlag=2;
	}
	else{
		glDisable(GL_BLEND);
		m_BlendFlag=0;
	}
	Invalidate();
}
//��������������
void CGLTest001View::OnAntialiasing() 
{
	// TODO: Add your command handler code here
	if(m_BlendFlag==0){
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_BLEND);
		glEnable(GL_LINE_SMOOTH);
		glHint(GL_LINE_SMOOTH_HINT,GL_NICEST);
		glHint(GL_POINT_SMOOTH_HINT,GL_NICEST);
		m_BlendFlag=3;
	}
	else{
		glDisable(GL_BLEND);
		glDisable(GL_LINE_SMOOTH);
		m_BlendFlag=0;
	}
	Invalidate();
}

void CGLTest001View::OnSelect() 
{
	// TODO: Add your command handler code here
	m_flag=SELECT;
	InitOperation();
	m_Rflag=0;
}

void CGLTest001View::OnBitmap() 
{
	// TODO: Add your command handler code here
	m_flag=BITMAP;
	InitOperation();
	m_Rflag=0;
}

BOOL CGLTest001View::OpenBmpImageFile(){
	////�����ļ��Ի����ͼ���ļ�
	CFileDialog hFileDlg(true,NULL,NULL,OFN_FILEMUSTEXIST|OFN_READONLY|OFN_PATHMUSTEXIST,
		TEXT("bmp �ļ�(*.bmp)|*.bmp|"),NULL);
	int action = hFileDlg.DoModal();
	if(action ==IDOK){
		/*if(m_pImage){
			delete m_pImage;
			m_pImage=NULL;
		}*/
		if(m_pImageModefied){
			delete m_pImageModefied;
			m_pImageModefied=NULL;
		}
		AUX_RGBImageRec * m_image;
		glPixelStorei(GL_UNPACK_ALIGNMENT,1);		//�������ش洢��ʽ
		m_image=auxDIBImageLoad(hFileDlg.GetPathName());	//����ͼ��
		m_iWidth=m_image->sizeX;	//����ͼ������
		m_iHeight=m_image->sizeY;
		m_pImage=m_image->data;
		return TRUE;
	}
	else if(action == IDCANCEL){
		if(m_pImage){
			delete m_pImage;
			m_pImage=NULL;
			Invalidate();
		}
		if(m_pImageModefied){
			delete m_pImageModefied;
			m_pImageModefied=NULL;
		}
		return FALSE;
	}
	return FALSE;
}

void CGLTest001View::OnFileOpen() 
{
	// TODO: Add your command handler code here
	////�����ļ��Ի����ͼ���ļ�
	if(this->OpenBmpImageFile()){
		m_flag=IMAGE_FILE;			//����Ϊ��������ͼ��
		m_ImageFlag=GLNULL;
		InitOperation();
	}
	else{
		m_flag=GLNULL;
		m_ImageFlag=GLNULL;
	}
}

void CGLTest001View::OnImageflag() 
{
	// TODO: Add your command handler code here
	CImageModeDlg dlg;
	dlg.m_pView=this;
	if(m_ImageFlag==GLNULL)
		dlg.m_imageFlag=this->m_ImageFlag;
	else
		dlg.m_imageFlag=this->m_ImageFlag-IMAGEZOOM + 1;
	dlg.DoModal();
}

void CGLTest001View::OnImageMap2d() 
{
	// TODO: Add your command handler code here
	////����ͼ���ļ�
	if(this->OpenBmpImageFile()){
		////��������ͼ�񣬴��ݸ�GL��GPU
		glTexImage2D(GL_TEXTURE_2D,0,3,m_iWidth,m_iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,m_pImage);
		////������������ͻ�������
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);

		m_flag=TEXTURE_MAP_2D;
		InitOperation();
	}
}

//���������
void CGLTest001View::OnTextrueMapObject() 
{
	// TODO: Add your command handler code here
	glGenTextures(3,m_imageIDs);	////�����������ID
	for(int i=0;i<3;i++){
		if(this->OpenBmpImageFile()){
			glBindTexture(GL_TEXTURE_2D,m_imageIDs[i]);  //��Ϊ��ǰ����
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);  //�����������
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);		//����������
			glTexImage2D(GL_TEXTURE_2D,0,3,m_iWidth,m_iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,m_pImage); //���͸�GPU
		}
		else{
			CString str;
			str.Format("��ѡ���%d��ͼƬ",i+1);
			MessageBox(str);
			i--;
		}
	}
	m_flag=IMAGE_MAP_OBJECT;
	InitOperation();
}
//����͸��
void CGLTest001View::OnImageMapBlend() 
{
	// TODO: Add your command handler code here
	if(m_flag==IMAGE_MAP_OBJECT){
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
		glShadeModel(GL_SMOOTH);
		glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
		Invalidate();
	}
}
//һά����
void CGLTest001View::OnTexture1d() 
{
	// TODO: Add your command handler code here
	////����һά����λͼͼ��
	GLubyte image_tex_1D[4*32];
	for(int i=0;i<32;i++){
		image_tex_1D[4*i]=GLubyte((i<=4)?255:0);
		image_tex_1D[4*i+1]=GLubyte((i>4)?255:0);
		image_tex_1D[4*i+2]=GLubyte(0);
		image_tex_1D[4*i+3]=GLubyte(255);
	}
	////�����Ͱ�һά�������
	glGenTextures(1,&m_texture1D);
	glBindTexture(GL_TEXTURE_1D,m_texture1D);
	////�����������
	glTexParameteri(GL_TEXTURE_1D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_1D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_1D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);	//����������
	////��������ͼ��
	glTexImage1D(GL_TEXTURE_1D,0,GL_RGBA,32,0,GL_RGBA,GL_UNSIGNED_BYTE,image_tex_1D);
	////�Զ�������������
	GLfloat fzero[] = {1.0,0.0,0.0,0.0};
	glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
	glTexGenfv(GL_S,GL_OBJECT_PLANE,fzero);
	glEnable(GL_TEXTURE_GEN_S);		//������������
	glEnable(GL_TEXTURE_1D);		//����һά����ӳ��
	glEnable(GL_AUTO_NORMAL);		//���÷�����
	glEnable(GL_NORMALIZE);			//�������淶��
	glFrontFace(GL_CW);				//���ö�������
	m_flag=TEXTURE_MAP_1D;			//����һά����ӳ���
	InitOperation();
}
//�����������
void CGLTest001View::OnTextureSphere() 
{
	// TODO: Add your command handler code here
	if(this->OpenBmpImageFile()){
		glGenTextures(2,m_ImageSphere);		////�����������
		for(int i=0;i<2;i++){
			glBindTexture(GL_TEXTURE_2D,m_ImageSphere[i]);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
			glTexImage2D(GL_TEXTURE_2D,0,3,m_iWidth,m_iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,m_pImage);
		}
		m_flag=TEXTURE_SPHERE;
		InitOperation();
		glEnable(GL_TEXTURE_2D);	//��������
		////������������
		glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
		glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_SPHERE_MAP);
		glEnable(GL_DEPTH_TEST);
	}
}
//�����������
void CGLTest001View::OnQuadricobj() 
{
	// TODO: Add your command handler code here
	m_flag=QUADRICOBJ;
	InitOperation();
}
//����������
void CGLTest001View::OnBezierline() 
{
	// TODO: Add your command handler code here
	m_flag=BEZIERLINE;
	m_Rflag=1;
	InitOperation();
}
//Bezier ����
void CGLTest001View::OnBeziersurf() 
{
	// TODO: Add your command handler code here
	m_flag=BEZIERSURF;
	m_Rflag=1;
	InitOperation();
}
//NURB��������
void CGLTest001View::OnNurbsline() 
{
	// TODO: Add your command handler code here
	m_flag=NURBSLINE;
	m_Rflag=1;
	InitOperation();
}
//NURB��������
void CGLTest001View::OnNurbssurf() 
{
	// TODO: Add your command handler code here
	m_flag=NURBSSURF;
	m_Rflag=1;
	m_NurbsTrimFlag=0;
	Surf_Texture_flag=0;
	InitOperation();
}
//NURB��������  �ü�
void CGLTest001View::OnNurbstrim() 
{
	// TODO: Add your command handler code here
	m_NurbsTrimFlag=m_NurbsTrimFlag==0?1:0;
	Invalidate();
}
//��������ӳ��
void CGLTest001View::OnNurbstexturemap() 
{
	// TODO: Add your command handler code here
	if(m_flag==NURBSSURF){
		if(this->OpenBmpImageFile()){
			glGenTextures(1,&Surf_texture);
			glBindTexture(GL_TEXTURE_2D,Surf_texture);
			glTexImage2D(GL_TEXTURE_2D,0,3,m_iWidth,m_iHeight,0,GL_RGB,GL_UNSIGNED_BYTE,m_pImage);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
			glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_DECAL);
			glEnable(GL_TEXTURE_2D);
			Surf_Texture_flag=1;
			Invalidate();
		}
	}
}
