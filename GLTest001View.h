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

	HGLRC m_hRC;		// ��Ⱦ�������
	CDC * m_pDC;		// �豸ָ��

	GLdouble aspect_ratio;		//View���ڿ�߱�
	GLdouble Win_Size;			//��ͼ����ϵ�Ķ̰��᳤��
	GLfloat winWidth,winHeight;	//��¼view���ڵĿ�͸ߣ�һ�룩

	GLfloat m_iR;			//��
	GLfloat m_iG;			//��
	GLfloat m_iB;			//��
	GLfloat m_iAlpha;		//��ɫ͸����
	GLfloat m_PtCurSize;	//��Ĵ�С
	GLfloat m_LineWidth;	//�߿�
	GLshort m_LinePattern;	//����
	BOOL m_bPolygonFill;	//�Ƿ����
	int m_flag;				//��ͼ�����ʶ
	int m_Rflag;			//�Ƿ�ʰȡ������0������1����
	CArray<GLPoint,GLPoint> m_Point_Array;	//ʰȡ���㼯��

	//���α任
	GLfloat m_lrMove,m_btMove;	//���������ƶ�����
	GLfloat m_rAngle;			//��ת�Ƕ�
	GLfloat m_Scale;			//���ű���
	BOOL m_bAnimation;			//�Ƿ���ö����ı�ʶ

	//��ά
	GLdouble m_3DRadius;

// Operations
public:
	BOOL InitializeOpenGL();		// OpenGL��ʼ��
	BOOL SetupPixelFormat();		// �������ظ�ʽ

	void RenderScene();				//��Ⱦ����
	void InitOperation();			//��ͼ������ʼ������

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
