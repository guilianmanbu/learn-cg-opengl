// LineWidthDlg.cpp : implementation file
//

#include "stdafx.h"
#include "GLTest001.h"
#include "LineWidthDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLineWidthDlg dialog


CLineWidthDlg::CLineWidthDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLineWidthDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLineWidthDlg)
	m_LineWidth = 0.0f;
	m_min = 0.0f;
	m_max = 0.0f;
	m_step = 0.0f;
	//}}AFX_DATA_INIT
}


void CLineWidthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLineWidthDlg)
	DDX_Text(pDX, IDC_EDIT1, m_LineWidth);
	DDX_Text(pDX, IDC_EDIT2, m_min);
	DDX_Text(pDX, IDC_EDIT3, m_max);
	DDX_Text(pDX, IDC_EDIT4, m_step);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLineWidthDlg, CDialog)
	//{{AFX_MSG_MAP(CLineWidthDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLineWidthDlg message handlers
