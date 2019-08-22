// Util.h: interface for the Util class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTIL_H__68E220E0_978F_4C55_AE67_F9DC05CA593C__INCLUDED_)
#define AFX_UTIL_H__68E220E0_978F_4C55_AE67_F9DC05CA593C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include<gl/gl.h>		// 
#include<gl/glu.h>
#include<gl/glut.h>
#include<gl/glaux.h>
#include<math.h>
#include<afxtempl.h>

class GLPoint
{
public:
	GLPoint(){
		x=0.0;
		y=0.0;
		z=0.0;
	}
	GLPoint(GLfloat x,GLfloat y,GLfloat z){
		this->x=x;
		this->y=y;
		this->z=y;
	}
	GLPoint(const GLPoint & glpt){
		x=glpt.x;
		y=glpt.y;
		z=glpt.z;
	}
	~GLPoint(){}
public:
	GLfloat x;
	GLfloat y;
	GLfloat z;

public:
	void operator =(const GLPoint &glpt);
	BOOL operator ==(const GLPoint &glpt);
};

class Util
{
public:
	Util();
	virtual ~Util();
public:
	static BOOL PolygonTesslator(CArray<GLPoint,GLPoint> &m_Point_Array);//多边形网格化细分
	static void Unitlize(GLfloat vertex[3]);  //向量规范化处理
	static void CalCulateNormal(const GLfloat Vertices[3][3],GLfloat Normal[3]);  //计算法向量
};



#endif // !defined(AFX_UTIL_H__68E220E0_978F_4C55_AE67_F9DC05CA593C__INCLUDED_)
