#if !defined(AFX_ENVIRONMENTSETDLG_H__FEDCF42B_5ECC_46A1_AD28_7748680DED1E__INCLUDED_)
#define AFX_ENVIRONMENTSETDLG_H__FEDCF42B_5ECC_46A1_AD28_7748680DED1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// EnvironmentSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CEnvironmentSetDlg dialog
#include "GLTest001Doc.h"
#include "GLTest001View.h"

class CEnvironmentSetDlg : public CDialog
{
// Construction
public:
	CEnvironmentSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CEnvironmentSetDlg)
	enum { IDD = IDD_ENVIRONMENTSETDLG_DIALOG };
	BOOL	m_depthFlag;
	BOOL	m_lightFlag;
	BOOL	m_light0;
	BOOL	m_light1;
	BOOL	m_lightModelFlag;
	BOOL	m_colorMaterialFlag;
	BOOL	m_emissionFlag;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnvironmentSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CEnvironmentSetDlg)
	afx_msg void OnCheckDepth();
	afx_msg void OnCheckLighting();
	afx_msg void OnCheckLight0();
	afx_msg void OnCheckLight1();
	afx_msg void OnCheckLightModel();
	afx_msg void OnCheckMatColor();
	afx_msg void OnCheckEmission();
	afx_msg void OnBGColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CGLTest001View * m_pView;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENVIRONMENTSETDLG_H__FEDCF42B_5ECC_46A1_AD28_7748680DED1E__INCLUDED_)
