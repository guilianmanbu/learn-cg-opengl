// GLTest001Doc.cpp : implementation of the CGLTest001Doc class
//

#include "stdafx.h"
#include "GLTest001.h"

#include "GLTest001Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGLTest001Doc

IMPLEMENT_DYNCREATE(CGLTest001Doc, CDocument)

BEGIN_MESSAGE_MAP(CGLTest001Doc, CDocument)
	//{{AFX_MSG_MAP(CGLTest001Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGLTest001Doc construction/destruction

CGLTest001Doc::CGLTest001Doc()
{
	// TODO: add one-time construction code here

}

CGLTest001Doc::~CGLTest001Doc()
{
}

BOOL CGLTest001Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	SetTitle("OpenGL Test");

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CGLTest001Doc serialization

void CGLTest001Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CGLTest001Doc diagnostics

#ifdef _DEBUG
void CGLTest001Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CGLTest001Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CGLTest001Doc commands
