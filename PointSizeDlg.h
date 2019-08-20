#if !defined(AFX_POINTSIZEDLG_H__8A2664D1_DECD_4D1B_A358_4AA7CE667AD2__INCLUDED_)
#define AFX_POINTSIZEDLG_H__8A2664D1_DECD_4D1B_A358_4AA7CE667AD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PointSizeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPointSizeDlg dialog

class CPointSizeDlg : public CDialog
{
// Construction
public:
	CPointSizeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPointSizeDlg)
	enum { IDD = IDD_POINTSIZEDLG_DIALOG };
	float	m_Size;
	float	m_min;
	float	m_max;
	float	m_step;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointSizeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPointSizeDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTSIZEDLG_H__8A2664D1_DECD_4D1B_A358_4AA7CE667AD2__INCLUDED_)
