// GLTest001View.h : interface of the CGLTest001View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLTEST001VIEW_H__640434F7_94C4_4222_86D5_A107944A5F0F__INCLUDED_)
#define AFX_GLTEST001VIEW_H__640434F7_94C4_4222_86D5_A107944A5F0F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define GLUT_DISABLE_ATEXIT_HACK
#include<gl/gl.h>		// 
#include<gl/glu.h>
#include<gl/glut.h>
#include<gl/glaux.h>
#include<math.h>
#include<afxtempl.h>
#include "Util.h"

// graphic macro
#define GLNULL			0
#define GLPOINTS		1
#define GLLINES			2
#define GLLINESTRIP		3
#define GLLINELOOP		4
#define GLTRIANGLES		5
#define GLTRIANGLESTRIP	6
#define GLTRIANGLEFAN	7
#define GLQUADS			8
#define GLQUADSTRIP		9
#define	GLPOLYGON		10
#define CONE			11
#define TETRAHEDRON		12
#define CUBE			13
#define DODECAHEDRON	14
#define ICOSAHEDRON		15
#define OCTAHEDRON		16
#define SPHERE			17
#define TORUS			18
#define TEAPOT			19
#define STRETCH			20
#define SELECT			21
#define BITMAP			22
#define IMAGE_FILE		23
#define IMAGEZOOM		24
#define IMAGEREVERSE	25
#define IMAGERED		26
#define IMAGEGREEN		27
#define IMAGEBLUE		28
#define IMAGEGRAYMAP	29
#define IMAGEINVERSE	30
#define TEXTURE_MAP_2D	31
#define IMAGE_MAP_OBJECT	32
#define TEXTURE_MAP_1D	33
#define TEXTURE_SPHERE	34
#define QUADRICOBJ		35
#define BEZIERLINE		36
#define BEZIERSURF		37
#define NURBSLINE		38
#define NURBSSURF		39


class CGLTest001View : public CView
{
protected: // create from serialization only
	CGLTest001View();
	DECLARE_DYNCREATE(CGLTest001View)

// Attributes
public:
	CGLTest001Doc * GetDocument();

	HGLRC m_hRC;		// 渲染环境句柄
	CDC * m_pDC;		// 设备指针

	GLdouble aspect_ratio;		//View窗口宽高比
	GLdouble Win_Size;			//绘图坐标系的短半轴长度
	GLfloat winWidth,winHeight;	//记录view窗口的宽和高（一半）

	GLfloat m_iR;			//红
	GLfloat m_iG;			//绿
	GLfloat m_iB;			//蓝
	GLfloat m_iAlpha;		//颜色透明度
	GLfloat m_PtCurSize;	//点的大小
	GLfloat m_LineWidth;	//线宽
	GLshort m_LinePattern;	//线型
	BOOL m_bPolygonFill;	//是否填充
	int m_flag;				//绘图命令标识
	int m_Rflag;			//是否拾取操作，0：不，1：是
	CArray<GLPoint,GLPoint> m_Point_Array;	//拾取顶点集合

	//几何变换
	GLfloat m_lrMove,m_btMove;	//左右上下移动变量
	GLfloat m_rAngle;			//旋转角度
	GLfloat m_Scale;			//缩放比例
	BOOL m_bAnimation;			//是否采用动画的标识

	//三维
	GLdouble m_3DRadius;

	//真实感渲染
	BOOL m_DepthFlag;			//深度检测
	BOOL m_LightFlag;			//启用光照状态
	BOOL m_Light0Flag;			//0号灯状态
	BOOL m_Light1Flag;			//1号灯状态
	BOOL m_LightModelFlag;		//是否启用光照模型
	BOOL m_MaterialColorFlag;	//是否跟踪当前绘图颜色
	BOOL m_MatEmissionFlag;		//设置材质是否自发光
	GLfloat m_iR_BG;			//设置背景颜色
	GLfloat m_iG_BG;
	GLfloat m_iB_BG;

	//拉伸
	CArray<GLPoint,GLPoint> m_Pt_Array_Polygon;	//多边形顶点集合
	GLfloat m_fLength;			//拉伸长度

	//颜色混合
	int m_BlendFlag;			//颜色混合模式

	//雾效
	int m_FogMode;

	//图像
	GLint m_iWidth,m_iHeight;	//图像宽度和高度
	GLubyte * m_pImage;			//图像字节数据
	GLubyte * m_pImageModefied;	//缓存由图像绘制得到的灰度图
	int m_ImageFlag;			//图像操作标识
	//多纹理对象
	GLuint m_imageIDs[3];		//纹理对象的数组
	GLuint m_texture1D;			//一维纹理
	GLuint m_ImageSphere[2];	//球体纹理对象
	//NURB样条曲面
	int m_NurbsTrimFlag;		//NURB样条曲面裁剪标志
	int Surf_Texture_flag;		////曲面纹理加载的变量
	GLuint Surf_texture;		////纹理对象变量

// Operations
public:
	BOOL InitializeOpenGL();		// OpenGL初始化
	BOOL SetupPixelFormat();		// 设置像素格式

	void RenderScene();				//渲染函数
	void InitOperation();			//绘图操作初始化设置
	void RealEnvironmentSet();		//真实感设置函数
	void DoSelection(GLfloat xPos,GLfloat yPos);	//选取
	BOOL OpenBmpImageFile();

// Draw graphic
public:
	void Draw_line();
	void Draw_LineStrip();
	void Draw_Point();
	void Draw_Stretch();
	void Draw_Blend();
	void Draw_Select();
	void Draw_Image();
	void Draw_ImageMapObject();
	void Draw_TextureSphereBG();
	void Draw_QuadricObj();
	void Draw_NURBSLine();
	void Draw_NURBSSurf();
	void SetFogMode();
	void SetVertexesToGL();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGLTest001View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGLTest001View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGLTest001View)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	afx_msg void OnPolygonFill();
	afx_msg void OnPoint();
	afx_msg void OnLine();
	afx_msg void OnLineStrip();
	afx_msg void OnLineLoop();
	afx_msg void OnTriangle();
	afx_msg void OnTriangleStrip();
	afx_msg void OnTriangleFan();
	afx_msg void OnQuad();
	afx_msg void OnQuadStrip();
	afx_msg void OnPolygon();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnColorSet();
	afx_msg void OnDrawSize();
	afx_msg void OnPointSize();
	afx_msg void OnLineWidth();
	afx_msg void OnLinetype();
	afx_msg void OnAnimation();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCone();
	afx_msg void OnCube();
	afx_msg void OnTetrahedron();
	afx_msg void OnDodecahedron();
	afx_msg void OnIcosahedron();
	afx_msg void OnOctahedron();
	afx_msg void OnSphere();
	afx_msg void OnTorus();
	afx_msg void OnTeapot();
	afx_msg void OnPolygonFillTool();
	afx_msg void OnEnvironmentset();
	afx_msg void OnStretch();
	afx_msg void OnUpdateStretch(CCmdUI* pCmdUI);
	afx_msg void OnBlend();
	afx_msg void OnTransparent();
	afx_msg void OnAntialiasing();
	afx_msg void OnSelect();
	afx_msg void OnBitmap();
	afx_msg void OnFileOpen();
	afx_msg void OnImageflag();
	afx_msg void OnImageMap2d();
	afx_msg void OnTextrueMapObject();
	afx_msg void OnImageMapBlend();
	afx_msg void OnTexture1d();
	afx_msg void OnTextureSphere();
	afx_msg void OnQuadricobj();
	afx_msg void OnBezierline();
	afx_msg void OnBeziersurf();
	afx_msg void OnNurbsline();
	afx_msg void OnNurbssurf();
	afx_msg void OnNurbstrim();
	afx_msg void OnNurbstexturemap();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GLTest001View.cpp
inline CGLTest001Doc* CGLTest001View::GetDocument()
   { return (CGLTest001Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLTEST001VIEW_H__640434F7_94C4_4222_86D5_A107944A5F0F__INCLUDED_)
