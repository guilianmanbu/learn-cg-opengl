#if !defined(AFX_COORDSETDLG_H__4AD5F8CA_E1D8_40E0_96E6_A7A2A44BE2CC__INCLUDED_)
#define AFX_COORDSETDLG_H__4AD5F8CA_E1D8_40E0_96E6_A7A2A44BE2CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CoordSetDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCoordSetDlg dialog

class CCoordSetDlg : public CDialog
{
// Construction
public:
	CCoordSetDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCoordSetDlg)
	enum { IDD = IDD_COORDSETDLG_DIALOG };
	float	m_WinSize;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCoordSetDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCoordSetDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COORDSETDLG_H__4AD5F8CA_E1D8_40E0_96E6_A7A2A44BE2CC__INCLUDED_)
