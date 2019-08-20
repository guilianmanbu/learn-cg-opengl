#if !defined(AFX_LINEWIDTHDLG_H__109CB29F_45CE_4F83_BCA0_2F309B84C7D2__INCLUDED_)
#define AFX_LINEWIDTHDLG_H__109CB29F_45CE_4F83_BCA0_2F309B84C7D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LineWidthDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLineWidthDlg dialog

class CLineWidthDlg : public CDialog
{
// Construction
public:
	CLineWidthDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLineWidthDlg)
	enum { IDD = IDD_LINEWIDTHDLG_DIALOG };
	float	m_LineWidth;
	float	m_min;
	float	m_max;
	float	m_step;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineWidthDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLineWidthDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEWIDTHDLG_H__109CB29F_45CE_4F83_BCA0_2F309B84C7D2__INCLUDED_)
