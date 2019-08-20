#if !defined(AFX_PATTERNDLG_H__D2D99740_655C_4072_9D8B_87C9E01F5C90__INCLUDED_)
#define AFX_PATTERNDLG_H__D2D99740_655C_4072_9D8B_87C9E01F5C90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PatternDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPatternDlg dialog

class CPatternDlg : public CDialog
{
// Construction
public:
	CPatternDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPatternDlg)
	enum { IDD = IDD_PATTERNDLG_DIALOG };
	int		m_iPattern;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPatternDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPatternDlg)
	afx_msg void OnRadio1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PATTERNDLG_H__D2D99740_655C_4072_9D8B_87C9E01F5C90__INCLUDED_)
