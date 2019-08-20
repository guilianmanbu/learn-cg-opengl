#if !defined(AFX_POLYGONFILLDLG_H__AAFE0293_CFE8_4589_83DF_B8D3746BC6A2__INCLUDED_)
#define AFX_POLYGONFILLDLG_H__AAFE0293_CFE8_4589_83DF_B8D3746BC6A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PolygonFillDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PolygonFillDlg dialog

class PolygonFillDlg : public CDialog
{
// Construction
public:
	PolygonFillDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PolygonFillDlg)
	enum { IDD = IDD_POLYGONFILLDLG_DIALOG };
	BOOL	m_bFill;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PolygonFillDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PolygonFillDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POLYGONFILLDLG_H__AAFE0293_CFE8_4589_83DF_B8D3746BC6A2__INCLUDED_)
