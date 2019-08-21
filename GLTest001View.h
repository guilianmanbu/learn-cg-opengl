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


class CGLTest001View : public CView
{
protected: // create from serialization only
	CGLTest001View();
	DECLARE_DYNCREATE(CGLTest001View)

// Attributes
public:
	CGLTest001Doc* GetDocument();

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

// Operations
public:
	BOOL InitializeOpenGL();		// OpenGL初始化
	BOOL SetupPixelFormat();		// 设置像素格式

	void RenderScene();				//渲染函数
	void InitOperation();			//绘图操作初始化设置

// Draw graphic
public:
	void Draw_line();
	void Draw_LineStrip();
	void Draw_Point();
	void SetVertexesToGL(BOOL tessellate);

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
