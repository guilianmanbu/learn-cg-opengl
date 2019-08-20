// GLTest001Doc.h : interface of the CGLTest001Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GLTEST001DOC_H__088C508F_A3D6_4393_8C0D_9EC909BBD2E2__INCLUDED_)
#define AFX_GLTEST001DOC_H__088C508F_A3D6_4393_8C0D_9EC909BBD2E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGLTest001Doc : public CDocument
{
protected: // create from serialization only
	CGLTest001Doc();
	DECLARE_DYNCREATE(CGLTest001Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGLTest001Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CGLTest001Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGLTest001Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GLTEST001DOC_H__088C508F_A3D6_4393_8C0D_9EC909BBD2E2__INCLUDED_)
