#if !defined(AFX_OORDSETDLG_H__1264BC9B_4357_4F36_95CA_B9C0C565103B__INCLUDED_)
#define AFX_OORDSETDLG_H__1264BC9B_4357_4F36_95CA_B9C0C565103B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// oordSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CoordSetDlg form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CoordSetDlg : public CFormView
{
protected:
	DECLARE_DYNCREATE(CoordSetDlg)

// Form Data
public:
	//{{AFX_DATA(CoordSetDlg)
	enum { IDD = IDD_COORDSETDLG_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CoordSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CoordSetDlg();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CoordSetDlg)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OORDSETDLG_H__1264BC9B_4357_4F36_95CA_B9C0C565103B__INCLUDED_)
