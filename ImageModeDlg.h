#if !defined(AFX_IMAGEMODEDLG_H__B6D2D646_3CB1_49D9_83AA_D75E7389A1D7__INCLUDED_)
#define AFX_IMAGEMODEDLG_H__B6D2D646_3CB1_49D9_83AA_D75E7389A1D7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ImageModeDlg.h : header file
//
#include "GLTest001Doc.h"
#include "GLTest001View.h"
/////////////////////////////////////////////////////////////////////////////
// CImageModeDlg dialog

class CImageModeDlg : public CDialog
{
// Construction
public:
	CImageModeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CImageModeDlg)
	enum { IDD = IDD_IMAGEMODEDLG_DIALOG };
	int		m_imageFlag;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageModeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CImageModeDlg)
	afx_msg void OnImageNone();
	afx_msg void OnImageScale();
	afx_msg void OnReverse();
	afx_msg void OnRed();
	afx_msg void OnGreen();
	afx_msg void OnBlue();
	afx_msg void OnGrayMap();
	afx_msg void OnInverse();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CGLTest001View * m_pView;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEMODEDLG_H__B6D2D646_3CB1_49D9_83AA_D75E7389A1D7__INCLUDED_)
